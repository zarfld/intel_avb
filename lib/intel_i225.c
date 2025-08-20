/******************************************************************************

  Copyright (c) 2025, Intel Corporation
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of the Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "intel.h"
#include "intel_private.h"
#include "../spec/intel-ethernet-regs/gen/i225_regs.h" // Single source of truth for I225 register map
#include "../spec/intel-ethernet-regs/gen/i226_regs.h" // Single source of truth for I226 register map

/* Bitfields for TAS/FP/PTM are provided by generated header (i225_regs.h) */

/* I225/I226 private data structure */
struct i225_private {
    /* TAS configuration */
    uint8_t tas_enabled;
    uint64_t tas_base_time;
    uint32_t tas_cycle_time;
    
    /* Frame Preemption configuration */
    uint8_t fp_enabled;
    uint8_t fp_verify_disabled;
    uint32_t fp_min_fragment_size;
    
    /* PTM configuration */
    uint8_t ptm_enabled;
    uint32_t ptm_granularity;
};

/**
 * @brief Read register from I225/I226 device
 */
static int i225_read_reg(struct intel_private *priv, uint32_t offset, uint32_t *value)
{
    if (!priv || !priv->mmio_base || !value) {
        return -EINVAL;
    }
    
    /* Memory-mapped I/O read */
    *value = *((volatile uint32_t *)((char *)priv->mmio_base + offset));
    
    return 0;
}

/**
 * @brief Write register to I225/I226 device
 */
static int i225_write_reg(struct intel_private *priv, uint32_t offset, uint32_t value)
{
    if (!priv || !priv->mmio_base) {
        return -EINVAL;
    }
    
    /* Memory-mapped I/O write */
    *((volatile uint32_t *)((char *)priv->mmio_base + offset)) = value;
    
    return 0;
}

/**
 * @brief Get system time from I225/I226 device
 */
static int i225_get_systime(struct intel_private *priv, uint64_t *systime)
{
    uint32_t systiml, systimh;
    int ret;
    
    if (!priv || !systime) {
        return -EINVAL;
    }
    
    /* Read high part first to latch the time */
    ret = i225_read_reg(priv, I225_SYSTIMH, &systimh);
    if (ret < 0) {
        return ret;
    }
    
    ret = i225_read_reg(priv, I225_SYSTIML, &systiml);
    if (ret < 0) {
        return ret;
    }
    
    *systime = ((uint64_t)systimh << 32) | systiml;
    
    return 0;
}

/**
 * @brief Set system time on I225/I226 device
 */
static int i225_set_systime(struct intel_private *priv, uint64_t systime)
{
    uint32_t systiml, systimh;
    int ret;
    
    if (!priv) {
        return -EINVAL;
    }
    
    systiml = (uint32_t)(systime & 0xFFFFFFFF);
    systimh = (uint32_t)(systime >> 32);
    
    /* Write low part first */
    ret = i225_write_reg(priv, I225_SYSTIML, systiml);
    if (ret < 0) {
        return ret;
    }
    
    /* Write high part to commit the time */
    ret = i225_write_reg(priv, I225_SYSTIMH, systimh);
    if (ret < 0) {
        return ret;
    }
    
    return 0;
}

/**
 * @brief Adjust system time frequency on I225/I226 device
 */
static int i225_adjust_systime(struct intel_private *priv, int32_t ppb)
{
    uint32_t timinca;
    uint64_t incvalue;
    int ret;
    
    if (!priv) {
        return -EINVAL;
    }
    
    /* Calculate increment value based on PPB adjustment */
    /* Base increment for 2.5GHz clock is typically around 4ns */
    incvalue = 4000000000ULL; /* 4ns in picoseconds */
    
    /* Adjust for PPB */
    if (ppb != 0) {
        int64_t adj = (int64_t)incvalue * ppb / 1000000000LL;
        incvalue += adj;
    }
    
    /* Convert to TIMINCA register format */
    timinca = (uint32_t)(incvalue & 0xFFFFFFFF);
    
    ret = i225_write_reg(priv, I225_TIMINCA, timinca);
    if (ret < 0) {
        return ret;
    }
    
    return 0;
}

/**
 * Read and optionally acknowledge I225 interrupts with rc/w1c semantics.
 * Uses EICR (extended causes) and ICR (legacy causes). Only write back
 * the observed bits to clear them (rc/w1c).
 * Reference: I225/I226 external spec (see spec/2407151103... PDF), Interrupts.
 */
static int i225_read_and_ack_interrupts(struct intel_private *priv,
                                        uint32_t *eicr_out,
                                        uint32_t *icr_out,
                                        int ack)
{
    uint32_t eicr = 0, icr = 0;
    int ret;
    if (!priv) return -EINVAL;

    ret = i225_read_reg(priv, I225_EICR, &eicr);
    if (ret < 0) return ret;

    /* Read ICR as well to capture any legacy causes (e.g., LSC). */
    ret = i225_read_reg(priv, I225_ICR, &icr);
    if (ret < 0) return ret;

    if (ack) {
        /* rc/w1c: write back the exact bits observed to clear */
        (void)i225_write_reg(priv, I225_ICR, icr);
        (void)i225_write_reg(priv, I225_EICR, eicr);
    }

    if (eicr_out) *eicr_out = eicr;
    if (icr_out) *icr_out = icr;
    return 0;
}

/* Public wrapper using device_t for I225/I226 interrupt read/ack */
int intel_i225_read_and_ack_interrupts(device_t *dev, uint32_t *eicr, uint32_t *icr, int ack)
{
    if (!dev || !dev->private_data) return -EINVAL;
    struct intel_private *priv = (struct intel_private *)dev->private_data;
    return i225_read_and_ack_interrupts(priv, eicr, icr, ack);
}

/**
 * @brief Configure Time Aware Shaper on I225/I226
 */
static int i225_setup_tas(struct intel_private *priv, struct tsn_tas_config *config)
{
    struct i225_private *i225_priv;
    uint32_t tas_ctrl, tas_config;
    int ret;
    
    if (!priv || !priv->device_private || !config) {
        return -EINVAL;
    }
    
    i225_priv = (struct i225_private *)priv->device_private;
    
    /* Disable TAS first */
    ret = i225_read_reg(priv, I225_TAS_CTRL, &tas_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    tas_ctrl = (uint32_t)I225_TAS_CTRL_SET(tas_ctrl, I225_TAS_CTRL_EN_MASK, I225_TAS_CTRL_EN_SHIFT, 0ULL);
    ret = i225_write_reg(priv, I225_TAS_CTRL, tas_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    /* Configure base time */
    ret = i225_write_reg(priv, I225_TAS_CONFIG0, 
                        (uint32_t)(config->base_time_s & 0xFFFFFFFF));
    if (ret < 0) {
        return ret;
    }
    
    ret = i225_write_reg(priv, I225_TAS_CONFIG1, 
                        (uint32_t)(config->base_time_s >> 32));
    if (ret < 0) {
        return ret;
    }
    
    /* Configure cycle time and gate states */
    tas_config = (config->cycle_time_s << 16) | (config->cycle_time_ns >> 16);
    ret = i225_write_reg(priv, I225_TAS_CONFIG0 + 8, tas_config);
    if (ret < 0) {
        return ret;
    }
    
    /* Program gate list (simplified implementation) */
    for (int i = 0; i < 8; i++) {
        uint32_t gate_entry = (config->gate_states[i] << 24) | 
                             config->gate_durations[i];
    ret = i225_write_reg(priv, I225_TAS_GATE_LIST + (i * 4), gate_entry);
        if (ret < 0) {
            return ret;
        }
    }
    
    /* Enable TAS */
    tas_ctrl = (uint32_t)I225_TAS_CTRL_SET(tas_ctrl, I225_TAS_CTRL_EN_MASK, I225_TAS_CTRL_EN_SHIFT, 1ULL);
    tas_ctrl = (uint32_t)I225_TAS_CTRL_SET(tas_ctrl, I225_TAS_CTRL_GATE_LIST_MASK, I225_TAS_CTRL_GATE_LIST_SHIFT, 1ULL);
    tas_ctrl = (uint32_t)I225_TAS_CTRL_SET(tas_ctrl, I225_TAS_CTRL_BASE_TIME_MASK, I225_TAS_CTRL_BASE_TIME_SHIFT, 1ULL);
    ret = i225_write_reg(priv, I225_TAS_CTRL, tas_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    /* Save configuration */
    i225_priv->tas_enabled = 1;
    i225_priv->tas_base_time = (config->base_time_s * NSEC_PER_SEC) + config->base_time_ns;
    i225_priv->tas_cycle_time = (config->cycle_time_s * NSEC_PER_SEC) + config->cycle_time_ns;
    
    return 0;
}

/**
 * @brief Configure Frame Preemption on I225/I226
 */
static int i225_setup_fp(struct intel_private *priv, struct tsn_fp_config *config)
{
    struct i225_private *i225_priv;
    uint32_t fp_ctrl;
    int ret;
    
    if (!priv || !priv->device_private || !config) {
        return -EINVAL;
    }
    
    i225_priv = (struct i225_private *)priv->device_private;
    
    /* Configure frame preemption */
    fp_ctrl = 0;
    if (config->verify_disable) {
        fp_ctrl = (uint32_t)I225_FP_CONFIG_SET(fp_ctrl, I225_FP_CONFIG_VERIFY_DIS_MASK, I225_FP_CONFIG_VERIFY_DIS_SHIFT, 1ULL);
    }
    
    /* Set preemptable queues (implementation specific) */
    fp_ctrl = (uint32_t)I225_FP_CONFIG_SET(fp_ctrl, I225_FP_CONFIG_PREEMPTABLE_QUEUES_MASK, I225_FP_CONFIG_PREEMPTABLE_QUEUES_SHIFT, (unsigned long long)config->preemptable_queues);
    
    /* Set minimum fragment size */
    fp_ctrl = (uint32_t)I225_FP_CONFIG_SET(fp_ctrl, I225_FP_CONFIG_MIN_FRAGMENT_SIZE_MASK, I225_FP_CONFIG_MIN_FRAGMENT_SIZE_SHIFT, (unsigned long long)config->min_fragment_size);
    
    ret = i225_write_reg(priv, I225_FP_CONFIG, fp_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    /* Enable frame preemption */
    fp_ctrl = (uint32_t)I225_FP_CONFIG_SET(fp_ctrl, I225_FP_CONFIG_EN_MASK, I225_FP_CONFIG_EN_SHIFT, 1ULL);
    ret = i225_write_reg(priv, I225_FP_CONFIG, fp_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    /* Save configuration */
    i225_priv->fp_enabled = 1;
    i225_priv->fp_verify_disabled = config->verify_disable;
    i225_priv->fp_min_fragment_size = config->min_fragment_size;
    
    return 0;
}

/**
 * @brief Configure PCIe PTM on I225/I226
 */
static int i225_setup_ptm(struct intel_private *priv, struct ptm_config *config)
{
    struct i225_private *i225_priv;
    uint32_t ptm_ctrl;
    int ret;
    
    if (!priv || !priv->device_private || !config) {
        return -EINVAL;
    }
    
    i225_priv = (struct i225_private *)priv->device_private;
    
    /* Configure PTM */
    ptm_ctrl = 0;
    if (config->enabled) {
        ptm_ctrl = (uint32_t)I225_PTM_CONFIG_SET(ptm_ctrl, I225_PTM_CONFIG_EN_MASK, I225_PTM_CONFIG_EN_SHIFT, 1ULL);
        ptm_ctrl = (uint32_t)I225_PTM_CONFIG_SET(ptm_ctrl, I225_PTM_CONFIG_AUTO_UPD_MASK, I225_PTM_CONFIG_AUTO_UPD_SHIFT, 1ULL);
    }
    
    /* Set clock granularity */
    ptm_ctrl = (uint32_t)I225_PTM_CONFIG_SET(ptm_ctrl, I225_PTM_CONFIG_CLOCK_GRANULARITY_MASK, I225_PTM_CONFIG_CLOCK_GRANULARITY_SHIFT, (unsigned long long)config->clock_granularity);
    
    ret = i225_write_reg(priv, I225_PTM_CONFIG, ptm_ctrl);
    if (ret < 0) {
        return ret;
    }
    
    /* Save configuration */
    i225_priv->ptm_enabled = config->enabled;
    i225_priv->ptm_granularity = config->clock_granularity;
    
    return 0;
}

/**
 * @brief Initialize I225 device
 */
int intel_i225_init(device_t *dev)
{
    struct intel_private *priv;
    struct i225_private *i225_priv;
    
    if (!dev || !dev->private_data) {
        return -EINVAL;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    /* Allocate I225-specific private data */
    i225_priv = calloc(1, sizeof(struct i225_private));
    if (!i225_priv) {
        return -ENOMEM;
    }
    
    priv->device_private = i225_priv;
    
    /* Set up function pointers */
    priv->read_reg = i225_read_reg;
    priv->write_reg = i225_write_reg;
    priv->get_systime = i225_get_systime;
    priv->set_systime = i225_set_systime;
    priv->adjust_systime = i225_adjust_systime;
    priv->setup_tas = i225_setup_tas;
    priv->setup_fp = i225_setup_fp;
    priv->setup_ptm = i225_setup_ptm;
    
    /* MMIO access handled through Windows platform layer (NDIS filter) */
    /* No direct MMIO mapping needed - hardware access via IOCTLs */
    
    return 0;
}

/* ========================= I226-specific path (generated macros) ========================= */

/**
 * @brief Get system time from I226 device
 */
static int i226_get_systime(struct intel_private *priv, uint64_t *systime)
{
    uint32_t systiml, systimh; int ret;
    if (!priv || !systime) return -EINVAL;
    ret = i225_read_reg(priv, I226_SYSTIMH, &systimh); if (ret < 0) return ret;
    ret = i225_read_reg(priv, I226_SYSTIML, &systiml); if (ret < 0) return ret;
    *systime = ((uint64_t)systimh << 32) | systiml; return 0;
}

/**
 * @brief Set system time on I226 device
 */
static int i226_set_systime(struct intel_private *priv, uint64_t systime)
{
    uint32_t l = (uint32_t)(systime & 0xFFFFFFFF), h = (uint32_t)(systime >> 32);
    int ret; if (!priv) return -EINVAL;
    ret = i225_write_reg(priv, I226_SYSTIML, l); if (ret < 0) return ret;
    return i225_write_reg(priv, I226_SYSTIMH, h);
}

/**
 * @brief Adjust system time frequency on I226 device
 */
static int i226_adjust_systime(struct intel_private *priv, int32_t ppb)
{
    if (!priv) return -EINVAL; uint64_t inc = 4000000000ULL; /* 4ns */
    if (ppb) { int64_t adj = (int64_t)inc * ppb / 1000000000LL; inc += adj; }
    return i225_write_reg(priv, I226_TIMINCA, (uint32_t)(inc & 0xFFFFFFFF));
}

/**
 * @brief Configure Time Aware Shaper on I226
 */
static int i226_setup_tas(struct intel_private *priv, struct tsn_tas_config *config)
{
    struct i225_private *p; uint32_t tas_ctrl, tas_cfg; int ret; if (!priv || !priv->device_private || !config) return -EINVAL; p = (struct i225_private *)priv->device_private;
    ret = i225_read_reg(priv, I226_TAS_CTRL, &tas_ctrl); if (ret < 0) return ret;
    tas_ctrl = (uint32_t)I226_TAS_CTRL_SET(tas_ctrl, I226_TAS_CTRL_EN_MASK, I226_TAS_CTRL_EN_SHIFT, 0ULL);
    ret = i225_write_reg(priv, I226_TAS_CTRL, tas_ctrl); if (ret < 0) return ret;
    ret = i225_write_reg(priv, I226_TAS_CONFIG0, (uint32_t)(config->base_time_s & 0xFFFFFFFF)); if (ret < 0) return ret;
    ret = i225_write_reg(priv, I226_TAS_CONFIG1, (uint32_t)(config->base_time_s >> 32)); if (ret < 0) return ret;
    tas_cfg = (config->cycle_time_s << 16) | (config->cycle_time_ns >> 16);
    ret = i225_write_reg(priv, I226_TAS_CONFIG0 + 8, tas_cfg); if (ret < 0) return ret;
    for (int i = 0; i < 8; i++) {
        uint32_t gate_entry = (config->gate_states[i] << 24) | config->gate_durations[i];
        ret = i225_write_reg(priv, I226_TAS_GATE_LIST + (i * 4), gate_entry); if (ret < 0) return ret;
    }
    tas_ctrl = (uint32_t)I226_TAS_CTRL_SET(tas_ctrl, I226_TAS_CTRL_EN_MASK, I226_TAS_CTRL_EN_SHIFT, 1ULL);
    tas_ctrl = (uint32_t)I226_TAS_CTRL_SET(tas_ctrl, I226_TAS_CTRL_GATE_LIST_MASK, I226_TAS_CTRL_GATE_LIST_SHIFT, 1ULL);
    tas_ctrl = (uint32_t)I226_TAS_CTRL_SET(tas_ctrl, I226_TAS_CTRL_BASE_TIME_MASK, I226_TAS_CTRL_BASE_TIME_SHIFT, 1ULL);
    ret = i225_write_reg(priv, I226_TAS_CTRL, tas_ctrl); if (ret < 0) return ret;
    p->tas_enabled = 1; p->tas_base_time = (config->base_time_s * NSEC_PER_SEC) + config->base_time_ns; p->tas_cycle_time = (config->cycle_time_s * NSEC_PER_SEC) + config->cycle_time_ns; return 0;
}

/**
 * @brief Configure Frame Preemption on I226
 */
static int i226_setup_fp(struct intel_private *priv, struct tsn_fp_config *config)
{
    struct i225_private *p; uint32_t fp = 0; int ret; if (!priv || !priv->device_private || !config) return -EINVAL; p = (struct i225_private *)priv->device_private;
    if (config->verify_disable) fp = (uint32_t)I226_FP_CONFIG_SET(fp, I226_FP_CONFIG_VERIFY_DIS_MASK, I226_FP_CONFIG_VERIFY_DIS_SHIFT, 1ULL);
    fp = (uint32_t)I226_FP_CONFIG_SET(fp, I226_FP_CONFIG_PREEMPTABLE_QUEUES_MASK, I226_FP_CONFIG_PREEMPTABLE_QUEUES_SHIFT, (unsigned long long)config->preemptable_queues);
    fp = (uint32_t)I226_FP_CONFIG_SET(fp, I226_FP_CONFIG_MIN_FRAGMENT_SIZE_MASK, I226_FP_CONFIG_MIN_FRAGMENT_SIZE_SHIFT, (unsigned long long)config->min_fragment_size);
    ret = i225_write_reg(priv, I226_FP_CONFIG, fp); if (ret < 0) return ret;
    fp = (uint32_t)I226_FP_CONFIG_SET(fp, I226_FP_CONFIG_EN_MASK, I226_FP_CONFIG_EN_SHIFT, 1ULL);
    ret = i225_write_reg(priv, I226_FP_CONFIG, fp); if (ret < 0) return ret;
    p->fp_enabled = 1; p->fp_verify_disabled = config->verify_disable; p->fp_min_fragment_size = config->min_fragment_size; return 0;
}

/**
 * @brief Configure PCIe PTM on I226
 */
static int i226_setup_ptm(struct intel_private *priv, struct ptm_config *config)
{
    struct i225_private *p; uint32_t ptm = 0; int ret; if (!priv || !priv->device_private || !config) return -EINVAL; p = (struct i225_private *)priv->device_private;
    if (config->enabled) {
        ptm = (uint32_t)I226_PTM_CONFIG_SET(ptm, I226_PTM_CONFIG_EN_MASK, I226_PTM_CONFIG_EN_SHIFT, 1ULL);
        ptm = (uint32_t)I226_PTM_CONFIG_SET(ptm, I226_PTM_CONFIG_AUTO_UPD_MASK, I226_PTM_CONFIG_AUTO_UPD_SHIFT, 1ULL);
    }
    ptm = (uint32_t)I226_PTM_CONFIG_SET(ptm, I226_PTM_CONFIG_CLOCK_GRANULARITY_MASK, I226_PTM_CONFIG_CLOCK_GRANULARITY_SHIFT, (unsigned long long)config->clock_granularity);
    ret = i225_write_reg(priv, I226_PTM_CONFIG, ptm); if (ret < 0) return ret;
    p->ptm_enabled = config->enabled; p->ptm_granularity = config->clock_granularity; return 0;
}

/**
 * Read and optionally acknowledge I226 interrupts with rc/w1c semantics.
 */
static int i226_read_and_ack_interrupts(struct intel_private *priv,
                                        uint32_t *eicr_out,
                                        uint32_t *icr_out,
                                        int ack)
{
    if (!priv) return -EINVAL; uint32_t eicr=0, icr=0; int ret;
    ret = i225_read_reg(priv, I226_EICR, &eicr); if (ret < 0) return ret;
    ret = i225_read_reg(priv, I226_ICR, &icr); if (ret < 0) return ret;
    if (ack) { (void)i225_write_reg(priv, I226_ICR, icr); (void)i225_write_reg(priv, I226_EICR, eicr); }
    if (eicr_out) *eicr_out = eicr; if (icr_out) *icr_out = icr; return 0;
}

/* Public wrapper */
int intel_i226_read_and_ack_interrupts(device_t *dev, uint32_t *eicr, uint32_t *icr, int ack)
{
    if (!dev || !dev->private_data) return -EINVAL; struct intel_private *priv = (struct intel_private *)dev->private_data; return i226_read_and_ack_interrupts(priv, eicr, icr, ack);
}

/**
 * @brief Initialize I226 device
 */
int intel_i226_init(device_t *dev)
{
    struct intel_private *priv; struct i225_private *i_priv;
    if (!dev || !dev->private_data) return -EINVAL;
    priv = (struct intel_private *)dev->private_data;
    i_priv = calloc(1, sizeof(struct i225_private)); if (!i_priv) return -ENOMEM;
    priv->device_private = i_priv;
    /* Assign I226-specific handlers using generated macros */
    priv->read_reg = i225_read_reg; /* same basic MMIO */
    priv->write_reg = i225_write_reg;
    priv->get_systime = i226_get_systime;
    priv->set_systime = i226_set_systime;
    priv->adjust_systime = i226_adjust_systime;
    priv->setup_tas = i226_setup_tas;
    priv->setup_fp = i226_setup_fp;
    priv->setup_ptm = i226_setup_ptm;
    return 0;
}

/**
 * @brief Cleanup I225 device
 */
void intel_i225_cleanup(device_t *dev)
{
    struct intel_private *priv;
    
    if (!dev || !dev->private_data) {
        return;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    if (priv->device_private) {
        free(priv->device_private);
        priv->device_private = NULL;
    }
    
    /* MMIO access handled through Windows platform layer (NDIS filter) */
    /* No direct MMIO unmapping needed - cleanup via platform layer */
}

/**
 * @brief Cleanup I226 device (same as I225)
 */
void intel_i226_cleanup(device_t *dev)
{
    intel_i225_cleanup(dev);
}

/**
 * @brief Setup Time Aware Shaper (public API)
 */
int intel_setup_time_aware_shaper(device_t *dev, struct tsn_tas_config *config)
{
    struct intel_private *priv;
    
    if (!dev || !dev->private_data || !config) {
        return -EINVAL;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    if (!intel_has_capability(dev, INTEL_CAP_TSN_TAS)) {
        return -ENOTSUP;
    }
    
    if (!priv->setup_tas) {
        return -ENOTSUP;
    }
    
    return priv->setup_tas(priv, config);
}

/**
 * @brief Setup Frame Preemption (public API)
 */
int intel_setup_frame_preemption(device_t *dev, struct tsn_fp_config *config)
{
    struct intel_private *priv;
    
    if (!dev || !dev->private_data || !config) {
        return -EINVAL;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    if (!intel_has_capability(dev, INTEL_CAP_TSN_FP)) {
        return -ENOTSUP;
    }
    
    if (!priv->setup_fp) {
        return -ENOTSUP;
    }
    
    return priv->setup_fp(priv, config);
}

/**
 * @brief Setup PCIe PTM (public API)
 */
int intel_setup_ptm(device_t *dev, struct ptm_config *config)
{
    struct intel_private *priv;
    
    if (!dev || !dev->private_data || !config) {
        return -EINVAL;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    if (!intel_has_capability(dev, INTEL_CAP_PCIe_PTM)) {
        return -ENOTSUP;
    }
    
    if (!priv->setup_ptm) {
        return -ENOTSUP;
    }
    
    return priv->setup_ptm(priv, config);
}
