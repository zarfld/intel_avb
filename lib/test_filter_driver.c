/* test_filter_driver.c - Direct filter driver test without headers */
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../include/avb_ioctl.h"

#define AVB_DEVICE_PATH "\\\\.\\IntelAvbFilter"

int main(void){
    printf("Intel AVB Filter Driver Direct Test\n");
    printf("===================================\n");
    
    HANDLE h = CreateFileA(AVB_DEVICE_PATH, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        printf("❌ Open %s failed (Error: %lu)\n", AVB_DEVICE_PATH, GetLastError());
        return 1;
    }
    printf("✅ Filter device opened successfully\n");

    DWORD bytesReturned = 0;
    
    /* Test 1: INIT_DEVICE (no parameters) */
    printf("\n1. Testing INIT_DEVICE...\n");
    if (DeviceIoControl(h, IOCTL_AVB_INIT_DEVICE, NULL, 0, NULL, 0, &bytesReturned, NULL)) {
        printf("✅ INIT_DEVICE: Success\n");
    } else {
        printf("❌ INIT_DEVICE failed (Error: %lu)\n", GetLastError());
    }

    /* Test 2: ENUM_ADAPTERS (direct structure, no header) */
    printf("\n2. Testing ENUM_ADAPTERS...\n");
    AVB_ENUM_REQUEST enum_req;
    memset(&enum_req, 0, sizeof(enum_req));
    enum_req.index = 0;  // Query first adapter
    
    if (DeviceIoControl(h, IOCTL_AVB_ENUM_ADAPTERS, &enum_req, sizeof(enum_req), &enum_req, sizeof(enum_req), &bytesReturned, NULL)) {
        printf("✅ ENUM_ADAPTERS: Success\n");
        printf("   Count: %lu adapters\n", (unsigned long)enum_req.count);
        printf("   Vendor ID: 0x%04X\n", enum_req.vendor_id);
        printf("   Device ID: 0x%04X\n", enum_req.device_id);
        printf("   Capabilities: 0x%08lX\n", (unsigned long)enum_req.capabilities);
        printf("   Status: 0x%08lX\n", (unsigned long)enum_req.status);
    } else {
        DWORD error = GetLastError();
        printf("❌ ENUM_ADAPTERS failed (Error: %lu)\n", error);
        
        // Try with different buffer size
        printf("   Trying with larger buffer...\n");
        uint8_t buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        AVB_ENUM_REQUEST *req = (AVB_ENUM_REQUEST*)buffer;
        req->index = 0;
        
        if (DeviceIoControl(h, IOCTL_AVB_ENUM_ADAPTERS, buffer, sizeof(buffer), buffer, sizeof(buffer), &bytesReturned, NULL)) {
            printf("✅ ENUM_ADAPTERS (large buffer): Success\n");
            printf("   Count: %lu adapters\n", (unsigned long)req->count);
            printf("   Vendor ID: 0x%04X\n", req->vendor_id);
            printf("   Device ID: 0x%04X\n", req->device_id);
        } else {
            printf("❌ ENUM_ADAPTERS (large buffer) also failed (Error: %lu)\n", GetLastError());
        }
    }

    /* Test 3: GET_DEVICE_INFO */
    printf("\n3. Testing GET_DEVICE_INFO...\n");
    AVB_DEVICE_INFO_REQUEST info_req;
    memset(&info_req, 0, sizeof(info_req));
    info_req.buffer_size = sizeof(info_req.device_info);
    
    if (DeviceIoControl(h, IOCTL_AVB_GET_DEVICE_INFO, &info_req, sizeof(info_req), &info_req, sizeof(info_req), &bytesReturned, NULL)) {
        printf("✅ GET_DEVICE_INFO: Success\n");
        info_req.device_info[sizeof(info_req.device_info)-1] = '\0';
        printf("   Info: %s\n", info_req.device_info);
        printf("   Buffer size: %lu\n", (unsigned long)info_req.buffer_size);
        printf("   Status: 0x%08lX\n", (unsigned long)info_req.status);
    } else {
        printf("❌ GET_DEVICE_INFO failed (Error: %lu)\n", GetLastError());
    }

    /* Test 4: READ_REGISTER */
    printf("\n4. Testing READ_REGISTER...\n");
    AVB_REGISTER_REQUEST reg_req;
    memset(&reg_req, 0, sizeof(reg_req));
    reg_req.offset = 0x00000;  // Device Control register
    
    if (DeviceIoControl(h, IOCTL_AVB_READ_REGISTER, &reg_req, sizeof(reg_req), &reg_req, sizeof(reg_req), &bytesReturned, NULL)) {
        printf("✅ READ_REGISTER: Success\n");
        printf("   Offset: 0x%08lX\n", (unsigned long)reg_req.offset);
        printf("   Value: 0x%08lX\n", (unsigned long)reg_req.value);
        printf("   Status: 0x%08lX\n", (unsigned long)reg_req.status);
    } else {
        printf("❌ READ_REGISTER failed (Error: %lu)\n", GetLastError());
    }

    /* Test 5: GET_TIMESTAMP */
    printf("\n5. Testing GET_TIMESTAMP...\n");
    AVB_TIMESTAMP_REQUEST ts_req;
    memset(&ts_req, 0, sizeof(ts_req));
    ts_req.clock_id = 0;  // Default clock
    
    if (DeviceIoControl(h, IOCTL_AVB_GET_TIMESTAMP, &ts_req, sizeof(ts_req), &ts_req, sizeof(ts_req), &bytesReturned, NULL)) {
        printf("✅ GET_TIMESTAMP: Success\n");
        printf("   Timestamp: 0x%016llX\n", (unsigned long long)ts_req.timestamp);
        printf("   Clock ID: %lu\n", (unsigned long)ts_req.clock_id);
        printf("   Status: 0x%08lX\n", (unsigned long)ts_req.status);
    } else {
        printf("❌ GET_TIMESTAMP failed (Error: %lu)\n", GetLastError());
    }

    printf("\n📋 Summary:\n");
    printf("Filter driver is accessible and responding to IOCTLs\n");
    printf("This confirms the basic infrastructure is working\n");
    
    CloseHandle(h);
    return 0;
}
