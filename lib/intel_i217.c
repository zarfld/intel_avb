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

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define usleep(x) Sleep((x)/1000)
#endif

#include "intel.h"
#include "intel_private.h"

/* I217 specific register definitions */
#define I217_REG_SYSTIMH         0x0B604  /* System Time High */
#define I217_REG_SYSTIML         0x0B600  /* System Time Low */
#define I217_REG_TIMINCA         0x0B608  /* Time Increment */
#define I217_REG_MDIC            0x00020  /* MDI Control */
#define I217_REG_CTRL            0x00000  /* Device Control */

/* MDIC register bits (similar to I219 but I217 specific) */
#define I217_REG_MDIC_DATA_MASK  0x0000FFFF
#define I217_REG_MDIC_REG_MASK   0x001F0000
#define I217_REG_MDIC_REG_SHIFT  16
#define I217_REG_MDIC_PHY_MASK   0x03E00000
#define I217_REG_MDIC_PHY_SHIFT  21
#define I217_REG_MDIC_OP_MASK    0x0C000000
#define I217_REG_MDIC_OP_SHIFT   26
#define I217_REG_MDIC_R          0x10000000
#define I217_REG_MDIC_I          0x20000000
#define I217_REG_MDIC_E          0x40000000

/* MDIC operations */
#define I217_MDIC_OP_WRITE       0x1
#define I217_MDIC_OP_READ        0x2

/* I217 private data structure */
struct i217_private {
    uint8_t dual_interface;      /* PCIe + SMBus interfaces */
    uint8_t ieee1588_enabled;
    uint32_t phy_addr;
    
    /* Power management state */
    uint8_t power_state;         /* Current power state (D0, D3, etc.) */
    uint8_t smbus_mode;          /* SMBus interface active */
    
    /* MDIO access synchronization */
    int mdio_busy;
};

/**
 * @brief Wait for MDIC operation to complete
 */
static int i217_wait_mdic_ready(struct intel_private *priv)
{
    uint32_t mdic;
    int timeout = 1000;
    int ret;
    
    /* Wait for ready bit to be clear */
    do {
        ret = priv->read_reg(priv, I217_REG_MDIC, &mdic);
        if (ret < 0) {
            return ret;
        }
        
        if (!(mdic & I217_REG_MDIC_R)) {
            break;
        }
        
        /* Small delay */
        usleep(10);
        timeout--;
    } while (timeout > 0);
    
    if (timeout <= 0) {
        return -ETIMEDOUT;
    }
    
    /* Check for error */
    if (mdic & I217_REG_MDIC_E) {
        return -EIO;
    }
    
    return 0;
}

/**
 * @brief Read MDIO register from I217
 */
static int i217_mdio_read(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t *value)
{
    struct i217_private *i217_priv;
    uint32_t mdic;
    int ret;
    
    if (!priv || !priv->device_private || !value) {
        return -EINVAL;
    }
    
    i217_priv = (struct i217_private *)priv->device_private;
    
    /* Check if MDIO is busy */
    if (i217_priv->mdio_busy) {
        return -EBUSY;
    }
    
    i217_priv->mdio_busy = 1;
    
    /* Wait for MDIC to be ready */
    ret = i217_wait_mdic_ready(priv);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    /* Set up page select if needed */
    if (page != 0) {
        /* Write page select register */
        mdic = I217_MDIC_OP_WRITE << I217_REG_MDIC_OP_SHIFT |
               i217_priv->phy_addr << I217_REG_MDIC_PHY_SHIFT |
               22 << I217_REG_MDIC_REG_SHIFT |  /* Page select register */
               (page & I217_REG_MDIC_DATA_MASK) |
               I217_REG_MDIC_R;
        
        ret = priv->write_reg(priv, I217_REG_MDIC, mdic);
        if (ret < 0) {
            i217_priv->mdio_busy = 0;
            return ret;
        }
        
        ret = i217_wait_mdic_ready(priv);
        if (ret < 0) {
            i217_priv->mdio_busy = 0;
            return ret;
        }
    }
    
    /* Set up MDIO read operation */
    mdic = I217_MDIC_OP_READ << I217_REG_MDIC_OP_SHIFT |
           i217_priv->phy_addr << I217_REG_MDIC_PHY_SHIFT |
           (reg & 0x1F) << I217_REG_MDIC_REG_SHIFT |
           I217_REG_MDIC_R;
    
    ret = priv->write_reg(priv, I217_REG_MDIC, mdic);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    /* Wait for operation to complete */
    ret = i217_wait_mdic_ready(priv);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    /* Read the result */
    ret = priv->read_reg(priv, I217_REG_MDIC, &mdic);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    *value = (uint16_t)(mdic & I217_REG_MDIC_DATA_MASK);
    i217_priv->mdio_busy = 0;
    
    return 0;
}

/**
 * @brief Write MDIO register to I217
 */
static int i217_mdio_write(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t value)
{
    struct i217_private *i217_priv;
    uint32_t mdic;
    int ret;
    
    if (!priv || !priv->device_private) {
        return -EINVAL;
    }
    
    i217_priv = (struct i217_private *)priv->device_private;
    
    /* Check if MDIO is busy */
    if (i217_priv->mdio_busy) {
        return -EBUSY;
    }
    
    i217_priv->mdio_busy = 1;
    
    /* Wait for MDIC to be ready */
    ret = i217_wait_mdic_ready(priv);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    /* Set up page select if needed */
    if (page != 0) {
        /* Write page select register */
        mdic = I217_MDIC_OP_WRITE << I217_REG_MDIC_OP_SHIFT |
               i217_priv->phy_addr << I217_REG_MDIC_PHY_SHIFT |
               22 << I217_REG_MDIC_REG_SHIFT |  /* Page select register */
               (page & I217_REG_MDIC_DATA_MASK) |
               I217_REG_MDIC_R;
        
        ret = priv->write_reg(priv, I217_REG_MDIC, mdic);
        if (ret < 0) {
            i217_priv->mdio_busy = 0;
            return ret;
        }
        
        ret = i217_wait_mdic_ready(priv);
        if (ret < 0) {
            i217_priv->mdio_busy = 0;
            return ret;
        }
    }
    
    /* Set up MDIO write operation */
    mdic = I217_MDIC_OP_WRITE << I217_REG_MDIC_OP_SHIFT |
           i217_priv->phy_addr << I217_REG_MDIC_PHY_SHIFT |
           (reg & 0x1F) << I217_REG_MDIC_REG_SHIFT |
           (value & I217_REG_MDIC_DATA_MASK) |
           I217_REG_MDIC_R;
    
    ret = priv->write_reg(priv, I217_REG_MDIC, mdic);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    /* Wait for operation to complete */
    ret = i217_wait_mdic_ready(priv);
    if (ret < 0) {
        i217_priv->mdio_busy = 0;
        return ret;
    }
    
    i217_priv->mdio_busy = 0;
    
    return 0;
}

/**
 * @brief Read register from I217 device
 */
static int i217_read_reg(struct intel_private *priv, uint32_t offset, uint32_t *value)
{
    if (!priv || !value) {
        return -EINVAL;
    }
    
    /* I217 has dual interface - PCIe when active, SMBus when in low power */
    /* Hardware access handled through Windows platform layer (NDIS filter) */
    if (priv->mmio_base) {
        *value = *((volatile uint32_t *)((char *)priv->mmio_base + offset));
        return 0;
    }
    
    return -ENODEV;
}

/**
 * @brief Write register to I217 device
 */
static int i217_write_reg(struct intel_private *priv, uint32_t offset, uint32_t value)
{
    if (!priv) {
        return -EINVAL;
    }
    
    /* I217 has dual interface - PCIe when active, SMBus when in low power */
    /* Hardware access handled through Windows platform layer (NDIS filter) */
    if (priv->mmio_base) {
        *((volatile uint32_t *)((char *)priv->mmio_base + offset)) = value;
        return 0;
    }
    
    return -ENODEV;
}

/**
 * @brief Get system time from I217 device
 */
static int i217_get_systime(struct intel_private *priv, uint64_t *systime)
{
    uint32_t systiml, systimh;
    int ret;
    
    if (!priv || !systime) {
        return -EINVAL;
    }
    
    /* Read high part first to latch the time */
    ret = i217_read_reg(priv, I217_REG_SYSTIMH, &systimh);
    if (ret < 0) {
        return ret;
    }
    
    ret = i217_read_reg(priv, I217_REG_SYSTIML, &systiml);
    if (ret < 0) {
        return ret;
    }
    
    *systime = ((uint64_t)systimh << 32) | systiml;
    
    return 0;
}

/**
 * @brief Set system time on I217 device
 */
static int i217_set_systime(struct intel_private *priv, uint64_t systime)
{
    uint32_t systiml, systimh;
    int ret;
    
    if (!priv) {
        return -EINVAL;
    }
    
    systiml = (uint32_t)(systime & 0xFFFFFFFF);
    systimh = (uint32_t)(systime >> 32);
    
    /* Write low part first */
    ret = i217_write_reg(priv, I217_REG_SYSTIML, systiml);
    if (ret < 0) {
        return ret;
    }
    
    /* Write high part to commit the time */
    ret = i217_write_reg(priv, I217_REG_SYSTIMH, systimh);
    if (ret < 0) {
        return ret;
    }
    
    return 0;
}

/**
 * @brief Adjust system time frequency on I217 device
 */
static int i217_adjust_systime(struct intel_private *priv, int32_t ppb)
{
    uint32_t timinca;
    uint64_t incvalue;
    int ret;
    
    if (!priv) {
        return -EINVAL;
    }
    
    /* Calculate increment value based on PPB adjustment */
    /* Base increment for I217 depends on link speed */
    /* For 1Gbps, typically 8ns increment */
    incvalue = 8000000000ULL; /* 8ns in picoseconds for 125MHz clock */
    
    /* Adjust for PPB */
    if (ppb != 0) {
        int64_t adj = (int64_t)incvalue * ppb / 1000000000LL;
        incvalue += adj;
    }
    
    /* Convert to TIMINCA register format */
    timinca = (uint32_t)(incvalue & 0xFFFFFFFF);
    
    ret = i217_write_reg(priv, I217_REG_TIMINCA, timinca);
    if (ret < 0) {
        return ret;
    }
    
    return 0;
}

/**
 * @brief Initialize I217 device
 */
int intel_i217_init(device_t *dev)
{
    struct intel_private *priv;
    struct i217_private *i217_priv;
    uint32_t ctrl;
    
    if (!dev || !dev->private_data) {
        return -EINVAL;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    /* Allocate I217-specific private data */
    i217_priv = calloc(1, sizeof(struct i217_private));
    if (!i217_priv) {
        return -ENOMEM;
    }
    
    priv->device_private = i217_priv;
    
    /* Set up function pointers */
    priv->read_reg = i217_read_reg;
    priv->write_reg = i217_write_reg;
    priv->get_systime = i217_get_systime;
    priv->set_systime = i217_set_systime;
    priv->adjust_systime = i217_adjust_systime;
    priv->mdio_read = i217_mdio_read;
    priv->mdio_write = i217_mdio_write;
    
    /* I217-specific initialization */
    i217_priv->dual_interface = 1;  /* Supports PCIe + SMBus */
    i217_priv->phy_addr = 2;        /* Default PHY address for I217 */
    i217_priv->power_state = 0;     /* D0 state initially */
    i217_priv->smbus_mode = 0;      /* PCIe mode initially */
    i217_priv->mdio_busy = 0;
    
    /* Hardware access handled through Windows platform layer (NDIS filter) */
    /* No direct MMIO mapping needed - hardware access via IOCTLs */
    
    /* Try to read control register to verify device access */
    if (priv->read_reg && priv->read_reg(priv, I217_REG_CTRL, &ctrl) == 0) {
        /* Device accessible, enable IEEE 1588 features if available */
        i217_priv->ieee1588_enabled = 1;
    }
    
    return 0;
}

/**
 * @brief Cleanup I217 device
 */
void intel_i217_cleanup(device_t *dev)
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
    
    /* Hardware access handled through Windows platform layer (NDIS filter) */
    /* No direct MMIO unmapping needed - cleanup via platform layer */
}