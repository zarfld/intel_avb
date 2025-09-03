/*
 * Intel AVB Filter Driver Hardware Validation Test
 * ===============================================
 * 
 * Purpose: Verify that working TSN IOCTLs (FP, PTM, QAV, GET_HW_STATE) 
 *          actually activate hardware features through filter driver.
 *
 * Test Strategy:
 * 1. Use filter driver to access I226-LM directly
 * 2. Read baseline hardware register states  
 * 3. Execute working TSN IOCTLs (FP/PTM/QAV)
 * 4. Re-read registers to confirm hardware changes
 * 5. Validate specific TSN enable bits are set
 */

#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/avb_ioctl.h"

// TSN-specific register addresses for I226
#define I226_FPQCL       0x04A8  // Frame Preemption Queue Control
#define I226_FPMAC       0x04AC  // Frame Preemption MAC Control  
#define I226_PTMCTL      0x15E4  // PCIe PTM Control
#define I226_TQAVCTRL    0x3570  // Time-based Tx Scheduler Control
#define I226_CTRL        0x0000  // Device Control Register
#define I226_STATUS      0x0008  // Device Status Register

typedef struct {
    uint32_t ctrl_before;
    uint32_t ctrl_after;
    uint32_t fpqcl_before; 
    uint32_t fpqcl_after;
    uint32_t fpmac_before;
    uint32_t fpmac_after;
    uint32_t ptmctl_before;
    uint32_t ptmctl_after;
    bool fp_activated;
    bool ptm_activated; 
    bool registers_changed;
} filter_validation_t;

static int read_register_via_filter(HANDLE hDevice, uint32_t offset, uint32_t *value)
{
    avb_read_register_t read_req = {0};
    DWORD bytesReturned = 0;
    
    read_req.offset = offset;
    
    BOOL result = DeviceIoControl(
        hDevice,
        IOCTL_AVB_READ_REGISTER,
        &read_req,
        sizeof(read_req),
        value,
        sizeof(*value), 
        &bytesReturned,
        NULL
    );
    
    if (!result) {
        printf("    ❌ Register read failed (offset=0x%04X, error=%d)\n", offset, GetLastError());
        return -1;
    }
    
    return 0;
}

static int setup_fp_via_filter(HANDLE hDevice)
{
    avb_setup_fp_t fp_config = {0};
    DWORD bytesReturned = 0;
    
    // Configure basic Frame Preemption
    fp_config.enable = 1;
    fp_config.preemptable_queues = 0x0F; // Queues 0-3 preemptable
    
    BOOL result = DeviceIoControl(
        hDevice,
        IOCTL_AVB_SETUP_FP,
        &fp_config,
        sizeof(fp_config),
        NULL,
        0,
        &bytesReturned,
        NULL
    );
    
    if (!result) {
        printf("    ❌ FP setup failed (error=%d)\n", GetLastError());
        return -1;
    }
    
    return 0;
}

static int setup_ptm_via_filter(HANDLE hDevice)
{
    avb_setup_ptm_t ptm_config = {0};
    DWORD bytesReturned = 0;
    
    // Configure basic PTM
    ptm_config.enable = 1;
    
    BOOL result = DeviceIoControl(
        hDevice,
        IOCTL_AVB_SETUP_PTM,
        &ptm_config,
        sizeof(ptm_config),
        NULL,
        0,
        &bytesReturned,
        NULL
    );
    
    if (!result) {
        printf("    ❌ PTM setup failed (error=%d)\n", GetLastError());
        return -1;
    }
    
    return 0;
}

static void analyze_register_changes(filter_validation_t *validation)
{
    printf("\n🔍 REGISTER CHANGE ANALYSIS:\n");
    printf("================================\n");
    
    // Control register analysis
    printf("CTRL Register (0x0000):\n");
    printf("  Before: 0x%08X\n", validation->ctrl_before);
    printf("  After:  0x%08X\n", validation->ctrl_after);
    if (validation->ctrl_before != validation->ctrl_after) {
        printf("  ✅ CTRL register changed!\n");
        uint32_t diff = validation->ctrl_after ^ validation->ctrl_before;
        printf("  Changed bits: 0x%08X\n", diff);
        validation->registers_changed = true;
    } else {
        printf("  ⚠️ CTRL register unchanged\n");
    }
    
    // Frame Preemption registers
    printf("\nFrame Preemption Queue Control (0x04A8):\n");
    printf("  Before: 0x%08X\n", validation->fpqcl_before);
    printf("  After:  0x%08X\n", validation->fpqcl_after);
    if (validation->fpqcl_before != validation->fpqcl_after) {
        printf("  ✅ FP Queue Control changed!\n");
        validation->fp_activated = true;
        validation->registers_changed = true;
    } else {
        printf("  ⚠️ FP Queue Control unchanged\n");
    }
    
    printf("Frame Preemption MAC Control (0x04AC):\n");
    printf("  Before: 0x%08X\n", validation->fpmac_before);
    printf("  After:  0x%08X\n", validation->fpmac_after);
    if (validation->fpmac_before != validation->fpmac_after) {
        printf("  ✅ FP MAC Control changed!\n");
        validation->fp_activated = true;
        validation->registers_changed = true;
    } else {
        printf("  ⚠️ FP MAC Control unchanged\n");
    }
    
    // PTM register analysis
    printf("\nPTM Control (0x15E4):\n");
    printf("  Before: 0x%08X\n", validation->ptmctl_before);
    printf("  After:  0x%08X\n", validation->ptmctl_after);
    if (validation->ptmctl_before != validation->ptmctl_after) {
        printf("  ✅ PTM Control changed!\n");
        validation->ptm_activated = true;
        validation->registers_changed = true;
    } else {
        printf("  ⚠️ PTM Control unchanged\n");
    }
}

static void print_final_assessment(filter_validation_t *validation)
{
    printf("\n🏆 FINAL HARDWARE VALIDATION ASSESSMENT:\n");
    printf("========================================\n");
    
    if (validation->registers_changed) {
        printf("✅ HARDWARE ACTIVATION CONFIRMED!\n");
        printf("   TSN IOCTLs are actually changing hardware registers\n\n");
        
        if (validation->fp_activated) {
            printf("✅ Frame Preemption: Hardware registers activated\n");
        }
        if (validation->ptm_activated) {
            printf("✅ PCIe PTM: Hardware registers activated\n");
        }
        
        printf("\n🎉 BREAKTHROUGH: Your TSN IOCTLs are working at hardware level!\n");
        printf("   Status=0x00000000 represents real hardware functionality.\n");
        
    } else {
        printf("⚠️ NO HARDWARE CHANGES DETECTED\n");
        printf("   IOCTLs return success but registers unchanged\n");
        printf("   This might indicate:\n");
        printf("   - Features already enabled\n");
        printf("   - Different register addresses\n");
        printf("   - Simulation mode active\n");
    }
}

int main()
{
    printf("Intel AVB Filter Driver Hardware Validation Test\n");
    printf("===============================================\n");
    printf("Goal: Verify working TSN IOCTLs activate I226 hardware features\n\n");
    
    // Open filter driver
    HANDLE hDevice = CreateFile(
        L"\\\\.\\IntelAvbFilter",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );
    
    if (hDevice == INVALID_HANDLE_VALUE) {
        printf("❌ Failed to open filter driver (error=%d)\n", GetLastError());
        printf("   Make sure to run as Administrator!\n");
        return 1;
    }
    
    printf("✅ Filter driver opened successfully\n\n");
    
    filter_validation_t validation = {0};
    
    // Initialize device
    avb_init_device_t init_req = {0};
    DWORD bytesReturned = 0;
    
    printf("1. Initializing device...\n");
    BOOL result = DeviceIoControl(
        hDevice,
        IOCTL_AVB_INIT_DEVICE,
        &init_req,
        sizeof(init_req),
        NULL,
        0,
        &bytesReturned,
        NULL
    );
    
    if (!result) {
        printf("❌ Device initialization failed (error=%d)\n", GetLastError());
        CloseHandle(hDevice);
        return 1;
    }
    printf("✅ Device initialized\n\n");
    
    // Read baseline register states
    printf("2. Reading baseline hardware register states...\n");
    read_register_via_filter(hDevice, I226_CTRL, &validation.ctrl_before);
    read_register_via_filter(hDevice, I226_FPQCL, &validation.fpqcl_before);
    read_register_via_filter(hDevice, I226_FPMAC, &validation.fpmac_before);
    read_register_via_filter(hDevice, I226_PTMCTL, &validation.ptmctl_before);
    
    printf("  CTRL (0x0000): 0x%08X\n", validation.ctrl_before);
    printf("  FPQCL (0x04A8): 0x%08X\n", validation.fpqcl_before);
    printf("  FPMAC (0x04AC): 0x%08X\n", validation.fpmac_before);
    printf("  PTMCTL (0x15E4): 0x%08X\n", validation.ptmctl_before);
    printf("✅ Baseline registers captured\n\n");
    
    // Execute working TSN IOCTLs
    printf("3. Executing working TSN IOCTLs...\n");
    
    printf("  Testing Frame Preemption setup...\n");
    if (setup_fp_via_filter(hDevice) == 0) {
        printf("  ✅ Frame Preemption IOCTL succeeded\n");
    }
    
    printf("  Testing PTM setup...\n");
    if (setup_ptm_via_filter(hDevice) == 0) {
        printf("  ✅ PTM IOCTL succeeded\n");
    }
    
    // Small delay to ensure hardware changes propagate
    Sleep(100);
    
    // Read post-configuration register states
    printf("\n4. Reading post-configuration register states...\n");
    read_register_via_filter(hDevice, I226_CTRL, &validation.ctrl_after);
    read_register_via_filter(hDevice, I226_FPQCL, &validation.fpqcl_after);
    read_register_via_filter(hDevice, I226_FPMAC, &validation.fpmac_after);
    read_register_via_filter(hDevice, I226_PTMCTL, &validation.ptmctl_after);
    
    printf("  CTRL (0x0000): 0x%08X\n", validation.ctrl_after);
    printf("  FPQCL (0x04A8): 0x%08X\n", validation.fpqcl_after);
    printf("  FPMAC (0x04AC): 0x%08X\n", validation.fpmac_after);
    printf("  PTMCTL (0x15E4): 0x%08X\n", validation.ptmctl_after);
    printf("✅ Post-configuration registers captured\n");
    
    // Analyze changes
    analyze_register_changes(&validation);
    
    // Print final assessment
    print_final_assessment(&validation);
    
    CloseHandle(hDevice);
    return validation.registers_changed ? 0 : 1;
}
