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

#ifndef _INTEL_PRIVATE_H_
#define _INTEL_PRIVATE_H_

#include "intel.h"

/* Private device data structure */
struct intel_private {
    intel_device_type_t device_type;
    uint32_t capabilities;
    int initialized;
    
    /* Memory mapped I/O base address */
    void *mmio_base;
    size_t mmio_size;
    
    /* Device-specific handlers */
    int (*read_reg)(struct intel_private *priv, uint32_t offset, uint32_t *value);
    int (*write_reg)(struct intel_private *priv, uint32_t offset, uint32_t value);
    int (*get_systime)(struct intel_private *priv, uint64_t *systime);
    int (*set_systime)(struct intel_private *priv, uint64_t systime);
    int (*adjust_systime)(struct intel_private *priv, int32_t ppb);
    
    /* TSN-specific handlers (I225/I226) */
    int (*setup_tas)(struct intel_private *priv, struct tsn_tas_config *config);
    int (*setup_fp)(struct intel_private *priv, struct tsn_fp_config *config);
    int (*setup_ptm)(struct intel_private *priv, struct ptm_config *config);
    
    /* Platform-specific operations */
    const struct platform_ops *platform_ops;
    void *platform_data;  /* Platform-specific context (e.g., Windows HW context) */
    
    /* MDIO handlers (I219) */
    int (*mdio_read)(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t *value);
    int (*mdio_write)(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t value);
    
    /* Device-specific private data */
    void *device_private;
};

/* Common register offsets (shared across devices) */
#define INTEL_REG_CTRL         0x00000  /* Device Control */
#define INTEL_REG_STATUS       0x00008  /* Device Status */
#define INTEL_REG_EECD         0x00010  /* EEPROM/Flash Control */
#define INTEL_REG_EERD         0x00014  /* EEPROM Read */
#define INTEL_REG_FLA          0x0001C  /* Flash Access */
#define INTEL_REG_MDIC         0x00020  /* MDI Control */
#define INTEL_REG_SCTL         0x00024  /* SerDes Control */
#define INTEL_REG_FCAL         0x00028  /* Flow Control Address Low */
#define INTEL_REG_FCAH         0x0002C  /* Flow Control Address High */
#define INTEL_REG_FCT          0x00030  /* Flow Control Type */
#define INTEL_REG_VET          0x00038  /* VLAN EtherType */
#define INTEL_REG_ICR          0x000C0  /* Interrupt Cause Read */
#define INTEL_REG_ITR          0x000C4  /* Interrupt Throttling Rate */
#define INTEL_REG_ICS          0x000C8  /* Interrupt Cause Set */
#define INTEL_REG_IMS          0x000D0  /* Interrupt Mask Set */
#define INTEL_REG_IMC          0x000D8  /* Interrupt Mask Clear */

/* Time synchronization registers */
#define INTEL_REG_SYSTIML      0x0B600  /* System Time Low */
#define INTEL_REG_SYSTIMH      0x0B604  /* System Time High */
#define INTEL_REG_TIMINCA      0x0B608  /* Time Increment Attributes */
#define INTEL_REG_TSYNCTXCTL   0x0B344  /* TX Timestamp Control */
#define INTEL_REG_TSYNCRXCTL   0x0B348  /* RX Timestamp Control */
#define INTEL_REG_TSAUXC       0x0B640  /* Auxiliary Time Stamp Control */
#define INTEL_REG_TRGTTIML0    0x0B644  /* Target Time Low 0 */
#define INTEL_REG_TRGTTIMH0    0x0B648  /* Target Time High 0 */
#define INTEL_REG_TRGTTIML1    0x0B64C  /* Target Time Low 1 */
#define INTEL_REG_TRGTTIMH1    0x0B650  /* Target Time High 1 */
#define INTEL_REG_TSICR        0x0B66C  /* Timestamp Interrupt Cause */
#define INTEL_REG_TSIM         0x0B674  /* Timestamp Interrupt Mask */
#define INTEL_REG_AUXSTMPL0    0x0B65C  /* Auxiliary Time Stamp Low 0 */
#define INTEL_REG_AUXSTMPH0    0x0B660  /* Auxiliary Time Stamp High 0 */
#define INTEL_REG_RXPBSIZE     0x02404  /* RX Packet Buffer Size */
#define INTEL_REG_SRRCTL0      0x0C00C  /* Split Receive Control Queue 0 (stride: 0x40 per queue) */

/* Time synchronization bit masks */
#define INTEL_TSAUXC_DISABLE_SYSTIM  0x80000000U /* TSAUXC[31]: set=primary timer disabled */
#define INTEL_TSAUXC_DISABLE_SYSTIM3 0x20000000U /* TSAUXC[29]: set=timer 3 disabled */
#define INTEL_TSAUXC_DISABLE_SYSTIM2 0x10000000U /* TSAUXC[28]: set=timer 2 disabled */
#define INTEL_TSAUXC_DISABLE_SYSTIM1 0x08000000U /* TSAUXC[27]: set=timer 1 disabled */
#define INTEL_TSAUXC_EN_TS1          0x00000400U /* TSAUXC[10]: enable aux timestamp capture 1 */
#define INTEL_TSAUXC_EN_TS0          0x00000100U /* TSAUXC[8]:  enable aux timestamp capture 0 */
#define INTEL_TSAUXC_EN_TT1          0x00000010U /* TSAUXC[4]:  enable target time interrupt 1 */
#define INTEL_TSAUXC_EN_TT0          0x00000001U /* TSAUXC[0]:  enable target time interrupt 0 */
#define INTEL_TSYNC_VALID            0x80000000U /* TSYNCTXCTL/TSYNCRXCTL[31]: timestamp ready */
#define INTEL_TSYNC_TS_MASK          0x7FFFFFFFU /* Strip timestamp valid bit from TXSTMPH */
#define INTEL_TIMINCA_INCPERIOD      0x0E000000U /* TIMINCA increment period field (bits 28-25) */
#define INTEL_TIMINCA_DEFAULT        0x18000000U /* Default TIMINCA for 25 MHz clock devices */
#define INTEL_TIMINCA_SUBNS_MASK     0x00FFFFFFU /* TIMINCA sub-nanosecond fractional bits */

/* PCI / BAR address constants */
#define INTEL_BAR0_SIZE_128KB    0x00020000U /* 128 KB MMIO BAR size (all supported devices) */
#define INTEL_PCI_BAR_MMIO_MASK  0xFFFFFFF0U /* BAR address mask (strip PCI type/prefetch bits) */

/* Device-specific TIMINCA initialization values */
#define INTEL_TIMINCA_I210_INIT   0x08000000U  /* I210: 8ns per cycle for 125 MHz clock (8 * 2^24 fractional-ns units) */
#define INTEL_TIMINCA_I217_INIT   0x08000001U  /* I217: basic 1ns increment (PCH PHY timing) */
#define INTEL_TIMINCA_I219_INIT   0x02F42400U  /* I219: IP=2, IV=16,000,000 sub-ns steps for 1GbE clock */
#define INTEL_TIMINCA_I350_INIT   0x80000008U  /* I350: enhanced 8ns increment */
#define INTEL_TIMINCA_82580_INIT  0x80000006U  /* 82580: enhanced 6ns increment */

/* IEEE 1588 / PTP EtherType */
#define INTEL_ETHERTYPE_PTP       0x88F7U      /* IEEE 1588 PTP over Ethernet (L2 timestamping) */

/* General bit-width masks */
#define INTEL_MASK_16BIT         0x0000FFFFU /* Mask to extract/truncate to 16 bits */
#define INTEL_MASK_32BIT         0xFFFFFFFFU /* Mask to extract low 32 bits; also reg-invalid sentinel */
#define INTEL_SENTINEL_DEAD_BEEF 0xDEADBEEFU /* Debug / invalid-ID sentinel (never a valid ring handle) */

/* TSN registers (I225/I226 specific)
 * Note: Do not duplicate device-specific TSN/PTM/FP register offsets here.
 * Always include and use the generated headers under spec/intel-ethernet-regs/gen/
 * (e.g., i225_regs.h, i226_regs.h) as the single source of truth.
 */

/* Common control register bits */
#define INTEL_CTRL_RESET       (1 << 26)
#define INTEL_CTRL_PHY_RST     (1 << 31)

/* Common status register bits */
#define INTEL_STATUS_LU        (1 << 1)   /* Link Up */
#define INTEL_STATUS_TXOFF     (1 << 4)   /* Transmission Paused */
#define INTEL_STATUS_SPEED_10  (0 << 6)   /* 10 Mbps */
#define INTEL_STATUS_SPEED_100 (1 << 6)   /* 100 Mbps */
#define INTEL_STATUS_SPEED_1000 (2 << 6)  /* 1000 Mbps */
#define INTEL_STATUS_SPEED_2500 (3 << 6)  /* 2500 Mbps */

/* Function prototypes for internal use */
int intel_common_init(device_t *dev);
void intel_common_cleanup(device_t *dev);
int intel_has_capability(device_t *dev, uint32_t capability);
int intel_validate_packet(struct intel_packet *packet);

/* Device-specific initialization functions */
int intel_i210_init(device_t *dev);
int intel_i217_init(device_t *dev);
int intel_i219_init(device_t *dev);
int intel_i225_init(device_t *dev);
int intel_i226_init(device_t *dev);

/* Device-specific cleanup functions */
void intel_i210_cleanup(device_t *dev);
void intel_i217_cleanup(device_t *dev);
void intel_i219_cleanup(device_t *dev);
void intel_i225_cleanup(device_t *dev);
void intel_i226_cleanup(device_t *dev);

/* Utility macros */
#define INTEL_READ32(priv, reg) \
    ({ uint32_t val; (priv)->read_reg((priv), (reg), &val); val; })

#define INTEL_WRITE32(priv, reg, val) \
    (priv)->write_reg((priv), (reg), (val))

#define NSEC_PER_SEC   1000000000ULL
#define USEC_PER_SEC   1000000ULL
#define MSEC_PER_SEC   1000ULL

#endif /* _INTEL_PRIVATE_H_ */
