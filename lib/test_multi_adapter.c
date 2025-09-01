/* test_multi_adapter.c - Test all available Intel adapters */
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../include/avb_ioctl.h"

#define AVB_DEVICE_PATH "\\\\.\\IntelAvbFilter"

static void print_caps(uint32_t caps){
    struct { uint32_t bit; const char*name;} m[]={
        {INTEL_CAP_BASIC_1588,"BASIC_1588"},{INTEL_CAP_ENHANCED_TS,"ENH_TS"},{INTEL_CAP_TSN_TAS,"TAS"},
        {INTEL_CAP_TSN_FP,"FP"},{INTEL_CAP_PCIe_PTM,"PTM"},{INTEL_CAP_2_5G,"2_5G"},{INTEL_CAP_MDIO,"MDIO"},{INTEL_CAP_MMIO,"MMIO"},{INTEL_CAP_EEE,"EEE"}
    }; printf("Caps=0x%08X [",caps); int f=1; for(size_t i=0;i<sizeof(m)/sizeof(m[0]);++i) if(caps & m[i].bit){ printf("%s%s",f?"":"|",m[i].name); f=0;} puts("]"); }

static int ioctl_direct(HANDLE h, DWORD code, void* buf, DWORD len){
    DWORD br=0; return DeviceIoControl(h, code, buf, len, buf, len, &br, NULL)?0:-1;
}

int main(void){
    printf("Intel AVB Multi-Adapter Test\n============================\n");
    HANDLE h=CreateFileA(AVB_DEVICE_PATH,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(h==INVALID_HANDLE_VALUE){ printf("Open %s failed (GLE=%lu)\n", AVB_DEVICE_PATH, GetLastError()); return 1; }

    /* Initialize device subsystem */
    printf("Initializing device subsystem...\n");
    if(!DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &(DWORD){0}, NULL)) {
        printf("INIT failed (GLE=%lu)\n", GetLastError());
        CloseHandle(h); return 1;
    }
    printf("✅ Device subsystem initialized\n\n");

    /* Enumerate ALL adapters */
    printf("=== ADAPTER ENUMERATION ===\n");
    AVB_ENUM_REQUEST er; 
    ZeroMemory(&er, sizeof(er)); 
    er.index = 0;
    
    if(ioctl_direct(h, IOCTL_AVB_ENUM_ADAPTERS, &er, sizeof(er)) != 0) {
        printf("❌ ENUM failed (GLE=%lu)\n", GetLastError()); 
        CloseHandle(h); 
        return 1;
    }
    
    printf("Found %u Intel AVB adapters:\n", er.count);
    
    /* Test each adapter */
    for(uint32_t i = 0; i < er.count; i++) {
        er.index = i;
        if(ioctl_direct(h, IOCTL_AVB_ENUM_ADAPTERS, &er, sizeof(er)) == 0) {
            printf("\n--- Adapter #%u ---\n", i);
            printf("Vendor ID: 0x%04X\n", er.vendor_id);
            printf("Device ID: 0x%04X", er.device_id);
            
            /* Identify device */
            switch(er.device_id) {
                case 0x1533: printf(" (Intel I210)\n"); break;
                case 0x125B: printf(" (Intel I226-LM)\n"); break;
                case 0x125C: printf(" (Intel I226-V)\n"); break;
                case 0x15F2: printf(" (Intel I225-LM)\n"); break;
                case 0x15F3: printf(" (Intel I225-V)\n"); break;
                case 0x15B7: printf(" (Intel I219-LM)\n"); break;
                case 0x15B8: printf(" (Intel I219-V)\n"); break;
                default: printf(" (Unknown Intel device)\n"); break;
            }
            
            print_caps(er.capabilities);
            
            /* Select this adapter for testing */
            AVB_OPEN_REQUEST op;
            ZeroMemory(&op, sizeof(op));
            op.vendor_id = er.vendor_id;
            op.device_id = er.device_id;
            
            if(ioctl_direct(h, IOCTL_AVB_OPEN_ADAPTER, &op, sizeof(op)) == 0) {
                printf("✅ Adapter selected (status=0x%08X)\n", op.status);
                
                /* Get device info */
                AVB_DEVICE_INFO_REQUEST di;
                ZeroMemory(&di, sizeof(di));
                di.buffer_size = sizeof(di.device_info);
                
                if(ioctl_direct(h, IOCTL_AVB_GET_DEVICE_INFO, &di, sizeof(di)) == 0) {
                    di.device_info[sizeof(di.device_info)-1] = '\0';
                    printf("📝 Info: %s\n", di.device_info);
                }
                
                /* Test register access */
                AVB_REGISTER_REQUEST rr;
                ZeroMemory(&rr, sizeof(rr));
                rr.offset = 0x00000; // Device Control register
                
                if(ioctl_direct(h, IOCTL_AVB_READ_REGISTER, &rr, sizeof(rr)) == 0) {
                    printf("📖 CTRL Register: 0x%08X\n", rr.value);
                }
                
                /* Test timestamp if supported */
                if(er.capabilities & INTEL_CAP_BASIC_1588) {
                    AVB_TIMESTAMP_REQUEST ts;
                    ZeroMemory(&ts, sizeof(ts));
                    
                    if(ioctl_direct(h, IOCTL_AVB_GET_TIMESTAMP, &ts, sizeof(ts)) == 0) {
                        printf("🕒 Timestamp: 0x%016llX\n", (unsigned long long)ts.timestamp);
                    }
                }
                
                /* Test TSN features if supported */
                if(er.capabilities & INTEL_CAP_TSN_TAS) {
                    printf("🔧 Testing Time-Aware Shaper...\n");
                    AVB_TAS_REQUEST tr;
                    ZeroMemory(&tr, sizeof(tr));
                    tr.config.cycle_time_ns = 125000; // 125µs cycle
                    tr.config.gate_states[0] = 0xFF; // All queues open
                    tr.config.gate_durations[0] = 62500; // 50% of cycle
                    tr.config.gate_states[1] = 0x01; // Only queue 0
                    tr.config.gate_durations[1] = 62500; // 50% of cycle
                    
                    if(ioctl_direct(h, IOCTL_AVB_SETUP_TAS, &tr, sizeof(tr)) == 0) {
                        printf("   TAS setup status: 0x%08X\n", tr.status);
                    } else {
                        printf("   TAS setup failed: %lu\n", GetLastError());
                    }
                }
                
                if(er.capabilities & INTEL_CAP_TSN_FP) {
                    printf("🔧 Testing Frame Preemption...\n");
                    AVB_FP_REQUEST fp;
                    ZeroMemory(&fp, sizeof(fp));
                    fp.config.preemptable_queues = 0xFE; // Queues 1-7 preemptable
                    fp.config.min_fragment_size = 64;
                    
                    if(ioctl_direct(h, IOCTL_AVB_SETUP_FP, &fp, sizeof(fp)) == 0) {
                        printf("   FP setup status: 0x%08X\n", fp.status);
                    } else {
                        printf("   FP setup failed: %lu\n", GetLastError());
                    }
                }
                
                if(er.capabilities & INTEL_CAP_MDIO) {
                    printf("🔧 Testing MDIO PHY access...\n");
                    AVB_MDIO_REQUEST md;
                    ZeroMemory(&md, sizeof(md));
                    md.page = 0;
                    md.reg = 1; // PHY Status register
                    
                    if(ioctl_direct(h, IOCTL_AVB_MDIO_READ, &md, sizeof(md)) == 0) {
                        printf("   PHY Status [0,1]: 0x%04X", md.value);
                        if(md.value & 0x0004) printf(" (Link UP)");
                        else printf(" (Link DOWN)");
                        if(md.value & 0x0020) printf(" (Auto-neg complete)");
                        printf("\n");
                    } else {
                        printf("   MDIO read failed: %lu\n", GetLastError());
                    }
                }
                
            } else {
                printf("❌ Failed to select adapter\n");
            }
            
            printf("\n");
        }
    }

    CloseHandle(h);
    printf("=== MULTI-ADAPTER TEST COMPLETE ===\n");
    return 0;
}
