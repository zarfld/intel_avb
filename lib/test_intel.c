/******************************************************************************

  Copyright (c) 2025, Intel Corporation
  All rights reserved.

  Intel AVB HAL Library Test Program

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intel.h"

int main(int argc, char *argv[])
{
    device_t dev;
    int ret;
    char info_buffer[256];
    
    printf("Intel AVB HAL Library Test\n");
    printf("==========================\n\n");
    
    /* Initialize device structure */
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = INTEL_VENDOR_ID;
    
    /* Test I225 device */
    printf("Testing I225 device identification:\n");
    dev.pci_device_id = 0x15f2; /* I225-LM */
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Device: %s\n", intel_get_device_name(&dev));
        printf("  Capabilities: 0x%08x\n", intel_get_capabilities(&dev));
        
        ret = intel_get_device_info(&dev, info_buffer, sizeof(info_buffer));
        if (ret == 0) {
            printf("  Info: %s\n", info_buffer);
        }
        
        printf("  TSN TAS: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_TSN_TAS) ? "Yes" : "No");
        printf("  TSN FP: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_TSN_FP) ? "Yes" : "No");
     printf("  PCIe PTM: %s\n", 
         intel_has_capability(&dev, INTEL_CAP_PCIe_PTM) ? "Yes" : "No");

     /* Exercise TAS/FP/PTM setup paths (no-op with simulated HW). */
     struct tsn_tas_config tas = {0};
     tas.base_time_s = 1;
     tas.base_time_ns = 0;
     tas.cycle_time_s = 0;
     tas.cycle_time_ns = 1000000; /* 1ms */
     for (int i = 0; i < 8; ++i) { tas.gate_states[i] = (i & 1); tas.gate_durations[i] = 125000; }
     (void)intel_setup_time_aware_shaper(&dev, &tas);

     struct tsn_fp_config fp = {0};
     fp.preemptable_queues = 0x0F; /* queues 0..3 */
     fp.min_fragment_size = 64;
     fp.verify_disable = 1;
     (void)intel_setup_frame_preemption(&dev, &fp);

     struct ptm_config ptm = {0};
     ptm.enabled = 1;
     ptm.clock_granularity = 16;
     (void)intel_setup_ptm(&dev, &ptm);
    } else {
        printf("  Failed to probe I225 device: %d\n", ret);
    }
    
    printf("\n");
    
    /* Test I217 device */
    printf("Testing I217 device identification:\n");
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = INTEL_VENDOR_ID;
    dev.pci_device_id = 0x153a; /* I217-LM */
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Device: %s\n", intel_get_device_name(&dev));
        printf("  Capabilities: 0x%08x\n", intel_get_capabilities(&dev));
        ret = intel_get_device_info(&dev, info_buffer, sizeof(info_buffer));
        if (ret == 0) {
            printf("  Info: %s\n", info_buffer);
        }
        printf("  MDIO: %s\n",
               intel_has_capability(&dev, INTEL_CAP_MDIO) ? "Yes" : "No");
        printf("  IEEE 1588: %s\n",
               intel_has_capability(&dev, INTEL_CAP_BASIC_1588) ? "Yes" : "No");
    } else {
        printf("  Failed to probe I217 device: %d\n", ret);
    }

    printf("\n");

    /* Test I219 device */
    printf("Testing I219 device identification:\n");
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = INTEL_VENDOR_ID;
    dev.pci_device_id = 0x15b7; /* I219-LM */
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Device: %s\n", intel_get_device_name(&dev));
        printf("  Capabilities: 0x%08x\n", intel_get_capabilities(&dev));
        
        ret = intel_get_device_info(&dev, info_buffer, sizeof(info_buffer));
        if (ret == 0) {
            printf("  Info: %s\n", info_buffer);
        }
        
        printf("  MDIO: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_MDIO) ? "Yes" : "No");
        printf("  IEEE 1588: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_BASIC_1588) ? "Yes" : "No");
    } else {
        printf("  Failed to probe I219 device: %d\n", ret);
    }
    
    printf("\n");
    
    /* Test I210 device */
    printf("Testing I210 device identification:\n");
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = INTEL_VENDOR_ID;
    dev.pci_device_id = 0x1533; /* I210 */
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Device: %s\n", intel_get_device_name(&dev));
        printf("  Capabilities: 0x%08x\n", intel_get_capabilities(&dev));
        
        ret = intel_get_device_info(&dev, info_buffer, sizeof(info_buffer));
        if (ret == 0) {
            printf("  Info: %s\n", info_buffer);
        }
        
        printf("  MMIO: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_MMIO) ? "Yes" : "No");
        printf("  IEEE 1588: %s\n", 
               intel_has_capability(&dev, INTEL_CAP_BASIC_1588) ? "Yes" : "No");
    } else {
        printf("  Failed to probe I210 device: %d\n", ret);
    }
    
    printf("\n");
    
    /* Test unknown device */
    printf("Testing unknown device:\n");
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = INTEL_VENDOR_ID;
    dev.pci_device_id = 0x9999; /* Unknown */
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Unexpected success for unknown device\n");
    } else {
        printf("  Correctly rejected unknown device: %d\n", ret);
    }
    
    printf("\n");
    
    /* Test non-Intel device */
    printf("Testing non-Intel device:\n");
    memset(&dev, 0, sizeof(dev));
    dev.pci_vendor_id = 0x1234; /* Non-Intel */
    dev.pci_device_id = 0x5678;
    ret = intel_probe(&dev);
    if (ret == 0) {
        printf("  Unexpected success for non-Intel device\n");
    } else {
        printf("  Correctly rejected non-Intel device: %d\n", ret);
    }
    
    printf("\nTest completed successfully!\n");
    
    return 0;
}
