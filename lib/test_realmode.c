/* test_realmode.c - Real hardware IOCTL validation using avb_ioctl.h */
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
    printf("Intel AVB Realmode IOCTL Test (Corrected)\n==========================================\n");
    HANDLE h=CreateFileA(AVB_DEVICE_PATH,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if(h==INVALID_HANDLE_VALUE){ printf("Open %s failed (GLE=%lu)\n", AVB_DEVICE_PATH, GetLastError()); return 1; }

    /* INIT DEVICE */
    printf("Initializing device...\n");
    if(!DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &(DWORD){0}, NULL)) {
        printf("INIT failed (GLE=%lu)\n", GetLastError());
    } else {
        printf("INIT ok\n");
    }

    /* ENUM - Direct structure usage without headers */
    AVB_ENUM_REQUEST er; ZeroMemory(&er,sizeof(er)); er.index = 0;
    if(ioctl_direct(h, IOCTL_AVB_ENUM_ADAPTERS, &er, sizeof(er))!=0){ printf("ENUM failed (GLE=%lu)\n", GetLastError()); CloseHandle(h); return 1; }
    printf("Adapters: %u VID=0x%04X DID=0x%04X\n", er.count, er.vendor_id, er.device_id); print_caps(er.capabilities);

    /* OPEN - Direct structure usage */
    AVB_OPEN_REQUEST op; ZeroMemory(&op,sizeof(op)); op.vendor_id=er.vendor_id; op.device_id=er.device_id;
    if(ioctl_direct(h, IOCTL_AVB_OPEN_ADAPTER, &op, sizeof(op))!=0) puts("OPEN failed"); else printf("OPEN status=0x%08X\n", op.status);

    /* INIT (no body) */
    if(!DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL,0,NULL,0,&(DWORD){0},NULL)) printf("INIT failed (GLE=%lu)\n", GetLastError()); else puts("INIT ok");

    /* DEVICE INFO - Direct structure usage */
    AVB_DEVICE_INFO_REQUEST di; ZeroMemory(&di,sizeof(di)); di.buffer_size=sizeof(di.device_info);
    if(ioctl_direct(h, IOCTL_AVB_GET_DEVICE_INFO, &di, sizeof(di))==0){ di.device_info[ (di.buffer_size<sizeof(di.device_info))? di.buffer_size: sizeof(di.device_info)-1 ]='\0'; printf("INFO: %s\n", di.device_info);} else puts("INFO failed");

    /* REG reads - Direct structure usage */
    DWORD offs[2]={0x00000,0x00008};
    for(int i=0;i<2;i++){ AVB_REGISTER_REQUEST rr; ZeroMemory(&rr,sizeof(rr)); rr.offset=offs[i]; if(ioctl_direct(h, IOCTL_AVB_READ_REGISTER,&rr,sizeof(rr))==0) printf("REG[0x%05X]=0x%08X\n", rr.offset, rr.value); }

    /* TIMESTAMP - Direct structure usage */
    AVB_TIMESTAMP_REQUEST ts; ZeroMemory(&ts,sizeof(ts)); if(ioctl_direct(h, IOCTL_AVB_GET_TIMESTAMP,&ts,sizeof(ts))==0) printf("TS=0x%016llX\n", (unsigned long long)ts.timestamp);

    /* Conditional features - Direct structure usage */
    if(er.capabilities & INTEL_CAP_MDIO){ AVB_MDIO_REQUEST md; ZeroMemory(&md,sizeof(md)); md.page=0; md.reg=1; if(ioctl_direct(h, IOCTL_AVB_MDIO_READ,&md,sizeof(md))==0) printf("MDIO[0,1]=0x%04X\n", md.value); }
    if(er.capabilities & INTEL_CAP_TSN_TAS){ AVB_TAS_REQUEST tr; ZeroMemory(&tr,sizeof(tr)); tr.config.cycle_time_ns=125000; tr.config.gate_states[0]=1; tr.config.gate_durations[0]=62500; tr.config.gate_states[1]=0; tr.config.gate_durations[1]=62500; ioctl_direct(h, IOCTL_AVB_SETUP_TAS,&tr,sizeof(tr)); printf("TAS status=0x%08X\n", tr.status);}    
    if(er.capabilities & INTEL_CAP_TSN_FP){ AVB_FP_REQUEST fp; ZeroMemory(&fp,sizeof(fp)); fp.config.preemptable_queues=1; fp.config.min_fragment_size=128; ioctl_direct(h, IOCTL_AVB_SETUP_FP,&fp,sizeof(fp)); printf("FP status=0x%08X\n", fp.status);}    
    if(er.capabilities & INTEL_CAP_PCIe_PTM){ AVB_PTM_REQUEST pt; ZeroMemory(&pt,sizeof(pt)); pt.config.enabled=1; pt.config.clock_granularity=16; ioctl_direct(h, IOCTL_AVB_SETUP_PTM,&pt,sizeof(pt)); printf("PTM status=0x%08X\n", pt.status);}    

    CloseHandle(h); puts("Realmode test complete"); return 0; }
