/* test_tsn_support.c - Check specific TSN IOCTL support */
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../include/avb_ioctl.h"

#define AVB_DEVICE_PATH "\\\\.\\IntelAvbFilter"

static int ioctl_direct(HANDLE h, DWORD code, void* buf, DWORD len){
    DWORD br=0; return DeviceIoControl(h, code, buf, len, buf, len, &br, NULL)?0:-1;
}

static const char* get_error_string(DWORD error) {
    switch(error) {
        case ERROR_INVALID_FUNCTION: return "Invalid function (IOCTL not implemented)";
        case ERROR_NOT_SUPPORTED: return "Operation not supported";
        case ERROR_INVALID_PARAMETER: return "Invalid parameter";
        case ERROR_ACCESS_DENIED: return "Access denied";
        default: return "Unknown error";
    }
}

int main(void){
    printf("Intel AVB TSN Support Verification\n");
    printf("==================================\n\n");
    
    HANDLE h=CreateFileA(AVB_DEVICE_PATH,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(h==INVALID_HANDLE_VALUE){ printf("❌ Device open failed: %lu\n", GetLastError()); return 1; }

    /* Initialize and select I226 */
    DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &(DWORD){0}, NULL);
    
    AVB_OPEN_REQUEST op;
    ZeroMemory(&op, sizeof(op));
    op.vendor_id = 0x8086;
    op.device_id = 0x125B; // I226-LM
    ioctl_direct(h, IOCTL_AVB_OPEN_ADAPTER, &op, sizeof(op));
    
    printf("Testing IOCTL Support on I226-LM:\n");
    printf("=================================\n\n");

    /* Test each TSN IOCTL individually */
    struct {
        DWORD ioctl;
        const char* name;
        void* test_data;
        DWORD data_size;
    } tests[] = {
        {IOCTL_AVB_SETUP_TAS, "SETUP_TAS", NULL, 0},
        {IOCTL_AVB_SETUP_FP, "SETUP_FP", NULL, 0},
        {IOCTL_AVB_SETUP_PTM, "SETUP_PTM", NULL, 0},
        {IOCTL_AVB_SETUP_QAV, "SETUP_QAV", NULL, 0},
        {IOCTL_AVB_GET_HW_STATE, "GET_HW_STATE", NULL, 0},
        {IOCTL_AVB_SET_TIMESTAMP, "SET_TIMESTAMP", NULL, 0}
    };
    
    /* Prepare test structures */
    AVB_TAS_REQUEST tas_req;
    AVB_FP_REQUEST fp_req;
    AVB_PTM_REQUEST ptm_req;
    AVB_QAV_REQUEST qav_req;
    AVB_HW_STATE_QUERY hw_state;
    AVB_TIMESTAMP_REQUEST ts_req;
    
    ZeroMemory(&tas_req, sizeof(tas_req));
    ZeroMemory(&fp_req, sizeof(fp_req));
    ZeroMemory(&ptm_req, sizeof(ptm_req));
    ZeroMemory(&qav_req, sizeof(qav_req));
    ZeroMemory(&hw_state, sizeof(hw_state));
    ZeroMemory(&ts_req, sizeof(ts_req));
    
    /* Simple TAS configuration */
    tas_req.config.cycle_time_ns = 1000000;
    tas_req.config.gate_states[0] = 0xFF;
    tas_req.config.gate_durations[0] = 500000;
    
    /* Simple FP configuration */
    fp_req.config.preemptable_queues = 0xFE;
    fp_req.config.min_fragment_size = 64;
    
    /* Simple PTM configuration */
    ptm_req.config.enabled = 1;
    ptm_req.config.clock_granularity = 16;
    
    /* Simple QAV configuration */
    qav_req.tc = 1;
    qav_req.idle_slope = 75000000;
    
    /* Update test data pointers */
    tests[0].test_data = &tas_req; tests[0].data_size = sizeof(tas_req);
    tests[1].test_data = &fp_req; tests[1].data_size = sizeof(fp_req);
    tests[2].test_data = &ptm_req; tests[2].data_size = sizeof(ptm_req);
    tests[3].test_data = &qav_req; tests[3].data_size = sizeof(qav_req);
    tests[4].test_data = &hw_state; tests[4].data_size = sizeof(hw_state);
    tests[5].test_data = &ts_req; tests[5].data_size = sizeof(ts_req);
    
    int supported = 0;
    int total = sizeof(tests) / sizeof(tests[0]);
    
    for(int i = 0; i < total; i++) {
        printf("Testing %s...\n", tests[i].name);
        
        DWORD bytesReturned = 0;
        if(DeviceIoControl(h, tests[i].ioctl, 
                          tests[i].test_data, tests[i].data_size,
                          tests[i].test_data, tests[i].data_size,
                          &bytesReturned, NULL)) {
            printf("  ✅ %s: Supported\n", tests[i].name);
            supported++;
            
            /* Show status if applicable */
            if(i < 3) { // TAS, FP, PTM have status fields
                uint32_t* status = (uint32_t*)((char*)tests[i].test_data + tests[i].data_size - 4);
                printf("     Status: 0x%08X\n", *status);
            }
        } else {
            DWORD error = GetLastError();
            printf("  ❌ %s: %s (Error: %lu)\n", tests[i].name, get_error_string(error), error);
            
            if(error == ERROR_INVALID_FUNCTION) {
                printf("     This IOCTL is not implemented in the filter driver\n");
            } else if(error == ERROR_NOT_SUPPORTED) {
                printf("     Hardware doesn't support this feature\n");
            } else if(error == ERROR_INVALID_PARAMETER) {
                printf("     Configuration parameters are invalid\n");
            }
        }
        printf("\n");
    }
    
    printf("Summary:\n");
    printf("========\n");
    printf("Supported IOCTLs: %d/%d\n", supported, total);
    
    if(supported == 0) {
        printf("❌ No TSN IOCTLs are implemented in the current filter driver\n");
        printf("   The filter driver may be a basic version without TSN support\n");
    } else if(supported < total) {
        printf("⚠️  Partial TSN support - some features may be missing\n");
    } else {
        printf("✅ Full TSN support available\n");
    }
    
    printf("\n📋 Recommendations:\n");
    if(supported == 0) {
        printf("1. Check if filter driver version supports TSN IOCTLs\n");
        printf("2. Verify I226 hardware is properly initialized\n");
        printf("3. Consider direct register access for TSN features\n");
    } else {
        printf("1. Debug individual IOCTL parameter formats\n");
        printf("2. Check hardware prerequisite setup\n");
        printf("3. Verify TSN feature activation sequence\n");
    }

    CloseHandle(h);
    return 0;
}
