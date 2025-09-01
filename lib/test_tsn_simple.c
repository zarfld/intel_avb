/* test_tsn_simple.c - Simple TSN IOCTL validation */
#include <windows.h>
#include <stdio.h>
#include "../include/avb_ioctl.h"

int main(void){
    printf("Intel AVB Filter Driver - TSN Status Check\n");
    printf("==========================================\n\n");
    
    HANDLE h = CreateFileA("\\\\.\\IntelAvbFilter", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(h == INVALID_HANDLE_VALUE) {
        printf("❌ Filter driver not accessible\n");
        printf("   Error: %lu\n", GetLastError());
        return 1;
    }
    
    printf("✅ Filter driver accessible\n\n");
    
    // Test basic initialization
    DWORD bytesReturned = 0;
    BOOL result = DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &bytesReturned, NULL);
    printf("INIT_DEVICE: %s\n", result ? "✅ Success" : "❌ Failed");
    
    // Test adapter enumeration
    result = DeviceIoControl(h, IOCTL_AVB_ENUM_ADAPTERS, NULL, 0, NULL, 0, &bytesReturned, NULL);
    printf("ENUM_ADAPTERS: %s\n", result ? "✅ Success" : "❌ Failed");
    
    // Test TAS setup (will likely fail, but shows what error)
    result = DeviceIoControl(h, IOCTL_AVB_SETUP_TAS, NULL, 0, NULL, 0, &bytesReturned, NULL);
    DWORD tas_error = GetLastError();
    printf("SETUP_TAS: %s (Error: %lu)\n", result ? "✅ Success" : "❌ Failed", tas_error);
    
    // Test FP setup
    result = DeviceIoControl(h, IOCTL_AVB_SETUP_FP, NULL, 0, NULL, 0, &bytesReturned, NULL);
    DWORD fp_error = GetLastError();
    printf("SETUP_FP: %s (Error: %lu)\n", result ? "✅ Success" : "❌ Failed", fp_error);
    
    printf("\n📋 Error Analysis:\n");
    if(tas_error == 1 || tas_error == 87) {
        printf("• Error 1/87: IOCTL not implemented or invalid parameters\n");
        printf("• Filter driver may have basic support only\n");
    }
    if(fp_error == 1 || fp_error == 87) {
        printf("• Frame Preemption similarly not implemented\n");
    }
    
    printf("\n🔧 Recommendations:\n");
    printf("1. Use direct register access for TSN features\n");
    printf("2. Check I226 register programming sequence\n");
    printf("3. Consider hardware-specific TSN initialization\n");
    
    CloseHandle(h);
    return 0;
}
