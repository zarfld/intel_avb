/* test_i226_priority.c - Test I226 preference and parallel adapter operation */
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

static const char* get_device_name(uint16_t device_id) {
    switch(device_id) {
        case 0x125B: return "I226-LM (Best - Full TSN + 2.5G)";
        case 0x125C: return "I226-V (Best - Full TSN + 2.5G)";
        case 0x15F2: return "I225-LM (Good - Full TSN)";
        case 0x15F3: return "I225-V (Good - Full TSN)";
        case 0x15B7: return "I219-LM (OK - Basic PTP + MDIO)";
        case 0x15B8: return "I219-V (OK - Basic PTP + MDIO)";
        case 0x1533: return "I210 (Basic - PTP only)";
        case 0x153A: return "I217-LM (Basic - PTP only)";
        default: return "Unknown Intel device";
    }
}

static int get_device_priority(uint16_t device_id) {
    switch(device_id) {
        case 0x125B: case 0x125C: return 100; // I226 - Highest
        case 0x15F2: case 0x15F3: return 90;  // I225 - High  
        case 0x15B7: case 0x15B8: return 60;  // I219 - Medium
        case 0x1533: return 50;               // I210 - Lower
        case 0x153A: return 40;               // I217 - Lowest
        default: return 10;
    }
}

int main(void){
    printf("Intel AVB I226 Priority Test\n============================\n");
    printf("Goal: Prefer I226 over I210 for optimal TSN performance\n\n");
    
    HANDLE h=CreateFileA(AVB_DEVICE_PATH,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(h==INVALID_HANDLE_VALUE){ printf("❌ Open %s failed (GLE=%lu)\n", AVB_DEVICE_PATH, GetLastError()); return 1; }

    /* Initialize device subsystem */
    printf("1. Initializing AVB subsystem...\n");
    if(!DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &(DWORD){0}, NULL)) {
        printf("❌ INIT failed (GLE=%lu)\n", GetLastError());
        CloseHandle(h); return 1;
    }
    printf("✅ AVB subsystem initialized\n\n");

    /* Enumerate all adapters and find the best */
    printf("2. Discovering available Intel adapters...\n");
    AVB_ENUM_REQUEST er;
    ZeroMemory(&er, sizeof(er)); 
    er.index = 0;
    
    if(ioctl_direct(h, IOCTL_AVB_ENUM_ADAPTERS, &er, sizeof(er)) != 0) {
        printf("❌ ENUM failed (GLE=%lu)\n", GetLastError()); 
        CloseHandle(h); return 1;
    }
    
    printf("Found %u Intel AVB adapters:\n", er.count);
    
    /* Collect all adapters and find the best */
    typedef struct {
        uint16_t vendor_id;
        uint16_t device_id;
        uint32_t capabilities;
        int priority;
        int index;
    } adapter_info_t;
    
    adapter_info_t adapters[16];
    int adapter_count = 0;
    int best_index = -1;
    int best_priority = -1;
    
    for(uint32_t i = 0; i < er.count; i++) {
        er.index = i;
        if(ioctl_direct(h, IOCTL_AVB_ENUM_ADAPTERS, &er, sizeof(er)) == 0) {
            adapters[adapter_count].vendor_id = er.vendor_id;
            adapters[adapter_count].device_id = er.device_id;
            adapters[adapter_count].capabilities = er.capabilities;
            adapters[adapter_count].priority = get_device_priority(er.device_id);
            adapters[adapter_count].index = i;
            
            printf("   [%d] 0x%04X:0x%04X - %s (Priority: %d)\n", 
                   i, er.vendor_id, er.device_id, 
                   get_device_name(er.device_id), adapters[adapter_count].priority);
            print_caps(er.capabilities);
            
            if (adapters[adapter_count].priority > best_priority) {
                best_priority = adapters[adapter_count].priority;
                best_index = adapter_count;
            }
            
            adapter_count++;
        }
    }
    
    if (best_index < 0) {
        printf("❌ No suitable adapters found\n");
        CloseHandle(h); return 1;
    }
    
    printf("\n3. Selecting optimal adapter...\n");
    adapter_info_t *best = &adapters[best_index];
    printf("🎯 Selected: %s\n", get_device_name(best->device_id));
    printf("   Vendor ID: 0x%04X, Device ID: 0x%04X\n", best->vendor_id, best->device_id);
    printf("   Priority Score: %d\n", best->priority);
    print_caps(best->capabilities);
    
    /* Open the best adapter */
    AVB_OPEN_REQUEST op;
    ZeroMemory(&op, sizeof(op));
    op.vendor_id = best->vendor_id;
    op.device_id = best->device_id;
    
    if(ioctl_direct(h, IOCTL_AVB_OPEN_ADAPTER, &op, sizeof(op)) != 0) {
        printf("❌ Failed to open selected adapter\n");
        CloseHandle(h); return 1;
    }
    printf("✅ Adapter selected successfully (status=0x%08X)\n", op.status);
    
    /* Test the selected adapter */
    printf("\n4. Testing selected adapter capabilities...\n");
    
    /* Get device info */
    AVB_DEVICE_INFO_REQUEST di;
    ZeroMemory(&di, sizeof(di));
    di.buffer_size = sizeof(di.device_info);
    
    if(ioctl_direct(h, IOCTL_AVB_GET_DEVICE_INFO, &di, sizeof(di)) == 0) {
        di.device_info[sizeof(di.device_info)-1] = '\0';
        printf("📝 Device Info: %s\n", di.device_info);
    }
    
    /* Test register access */
    AVB_REGISTER_REQUEST rr;
    ZeroMemory(&rr, sizeof(rr));
    rr.offset = 0x00000; // Device Control
    
    if(ioctl_direct(h, IOCTL_AVB_READ_REGISTER, &rr, sizeof(rr)) == 0) {
        printf("📖 CTRL Register: 0x%08X\n", rr.value);
    }
    
    rr.offset = 0x00008; // Device Status
    if(ioctl_direct(h, IOCTL_AVB_READ_REGISTER, &rr, sizeof(rr)) == 0) {
        printf("📖 STATUS Register: 0x%08X", rr.value);
        if (rr.value & 0x02) printf(" (Link UP)");
        else printf(" (Link DOWN)");
        printf("\n");
    }
    
    /* Test PTP timestamp */
    if(best->capabilities & INTEL_CAP_BASIC_1588) {
        AVB_TIMESTAMP_REQUEST ts;
        ZeroMemory(&ts, sizeof(ts));
        
        if(ioctl_direct(h, IOCTL_AVB_GET_TIMESTAMP, &ts, sizeof(ts)) == 0) {
            printf("🕒 Hardware Timestamp: 0x%016llX\n", (unsigned long long)ts.timestamp);
        }
    }
    
    /* Test TSN features if available (I225/I226 only) */
    if(best->capabilities & INTEL_CAP_TSN_TAS) {
        printf("\n5. Testing TSN Time-Aware Shaper (TAS)...\n");
        AVB_TAS_REQUEST tr;
        ZeroMemory(&tr, sizeof(tr));
        
        // Configure 1ms cycle with 50/50 split
        tr.config.cycle_time_ns = 1000000; // 1ms
        tr.config.gate_states[0] = 0xFF;   // All queues open
        tr.config.gate_durations[0] = 500000; // 500µs
        tr.config.gate_states[1] = 0x01;   // Only queue 0
        tr.config.gate_durations[1] = 500000; // 500µs
        
        if(ioctl_direct(h, IOCTL_AVB_SETUP_TAS, &tr, sizeof(tr)) == 0) {
            printf("✅ TAS Configuration: status=0x%08X\n", tr.status);
        } else {
            printf("⚠️  TAS Configuration failed: %lu\n", GetLastError());
        }
    }
    
    if(best->capabilities & INTEL_CAP_TSN_FP) {
        printf("\n6. Testing Frame Preemption (FP)...\n");
        AVB_FP_REQUEST fp;
        ZeroMemory(&fp, sizeof(fp));
        
        fp.config.preemptable_queues = 0xFE; // Queues 1-7 preemptable
        fp.config.min_fragment_size = 64;    // 64-byte minimum
        
        if(ioctl_direct(h, IOCTL_AVB_SETUP_FP, &fp, sizeof(fp)) == 0) {
            printf("✅ Frame Preemption: status=0x%08X\n", fp.status);
        } else {
            printf("⚠️  Frame Preemption failed: %lu\n", GetLastError());
        }
    }
    
    if(best->capabilities & INTEL_CAP_MDIO) {
        printf("\n7. Testing MDIO PHY Access...\n");
        AVB_MDIO_REQUEST md;
        ZeroMemory(&md, sizeof(md));
        md.page = 0;
        md.reg = 1; // PHY Status
        
        if(ioctl_direct(h, IOCTL_AVB_MDIO_READ, &md, sizeof(md)) == 0) {
            printf("✅ PHY Status [0,1]: 0x%04X", md.value);
            if(md.value & 0x0004) printf(" (Link UP)");
            if(md.value & 0x0020) printf(" (Auto-neg complete)");
            printf("\n");
        } else {
            printf("⚠️  MDIO read failed: %lu\n", GetLastError());
        }
    }
    
    /* Show parallel operation potential */
    printf("\n8. Parallel Operation Summary:\n");
    printf("================================\n");
    printf("Selected Adapter: %s\n", get_device_name(best->device_id));
    printf("Available Features:\n");
    if (best->capabilities & INTEL_CAP_TSN_TAS) printf("  ✅ Time-Aware Shaper (TAS)\n");
    if (best->capabilities & INTEL_CAP_TSN_FP) printf("  ✅ Frame Preemption (FP)\n");
    if (best->capabilities & INTEL_CAP_PCIe_PTM) printf("  ✅ PCIe PTM\n");
    if (best->capabilities & INTEL_CAP_2_5G) printf("  ✅ 2.5 Gigabit support\n");
    if (best->capabilities & INTEL_CAP_MDIO) printf("  ✅ MDIO PHY management\n");
    if (best->capabilities & INTEL_CAP_BASIC_1588) printf("  ✅ IEEE 1588 PTP\n");
    
    printf("\nOther Adapters Available for Parallel Operation:\n");
    for (int i = 0; i < adapter_count; i++) {
        if (i == best_index) continue;
        printf("  - %s\n", get_device_name(adapters[i].device_id));
    }

    CloseHandle(h);
    printf("\n✅ I226 PRIORITY TEST COMPLETE\n");
    printf("Recommendation: Use %s for primary AVB/TSN operations\n", get_device_name(best->device_id));
    return 0;
}
