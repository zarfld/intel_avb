/******************************************************************************

  Copyright (c) 2025, Intel Corporation
  All rights reserved.

  Intel AVB HAL - Windows Driver Interface Implementation
  
  This module provides Windows-specific hardware access for Intel NICs,
  integrated with NDIS filter driver for real hardware access.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winioctl.h>

#include "intel.h"
#include "intel_private.h"
#include "intel_windows.h"
#include "../include/avb_ioctl.h" /* shared IOCTL ABI */

/* Windows-specific error mappings */
#define WIN_SUCCESS         0
#define WIN_ERROR_ACCESS    -1
#define WIN_ERROR_MAPPING   -2
#define WIN_ERROR_DEVICE    -3

/* Windows hardware access context */
struct windows_hw_context {
    HANDLE filter_device_handle;
    void *mmio_base;
    DWORD mmio_size;
    BOOL initialized;
    const struct platform_ops *ops;
    
    /* Multi-adapter support */
    uint16_t current_vendor_id;
    uint16_t current_device_id;
    uint32_t current_capabilities;
    int adapter_selected;
};

/* Forward declarations for platform operations */
static int windows_platform_init(device_t *dev);
static void windows_platform_cleanup(device_t *dev);
static int windows_pci_read_config(device_t *dev, DWORD offset, DWORD *value);
static int windows_pci_write_config(device_t *dev, DWORD offset, DWORD value);
static int windows_mmio_read(device_t *dev, uint32_t offset, uint32_t *value);
static int windows_mmio_write(device_t *dev, uint32_t offset, uint32_t value);
static int windows_mdio_read(device_t *dev, uint16_t phy_addr, uint16_t reg_addr, uint16_t *value);
static int windows_mdio_write(device_t *dev, uint16_t phy_addr, uint16_t reg_addr, uint16_t value);
static int windows_read_timestamp(device_t *dev, uint64_t *timestamp);
static int windows_enum_adapters(device_t *dev, int index, uint32_t *count, uint16_t *vendor_id, uint16_t *device_id, uint32_t *capabilities);
static int windows_open_adapter(device_t *dev, uint16_t vendor_id, uint16_t device_id);
static int windows_get_device_info(device_t *dev, char *info_buffer, uint32_t *buffer_size);
static int windows_select_best_adapter(device_t *dev);
static int windows_get_adapter_priority(uint16_t device_id);

/* Platform operations structure for Windows NDIS */
static const struct platform_ops windows_ndis_platform_ops = {
    .init = windows_platform_init,
    .cleanup = windows_platform_cleanup,
    .pci_read_config = windows_pci_read_config,
    .pci_write_config = windows_pci_write_config,
    .mmio_read = windows_mmio_read,
    .mmio_write = windows_mmio_write,
    .mdio_read = windows_mdio_read,
    .mdio_write = windows_mdio_write,
    .read_timestamp = windows_read_timestamp
};

/**
 * @brief Get Windows platform operations
 */
const struct platform_ops *intel_get_windows_platform_ops(void)
{
    return &windows_ndis_platform_ops;
}
/**
 * @brief Initialize Windows platform access through NDIS filter
 */
static int windows_platform_init(device_t *dev)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    
    /* Allocate Windows-specific context */
    win_ctx = (struct windows_hw_context *)malloc(sizeof(struct windows_hw_context));
    if (!win_ctx) {
        return WIN_ERROR_ACCESS;
    }
    
    memset(win_ctx, 0, sizeof(struct windows_hw_context));
    
    /* Try to open the AVB filter device */
    win_ctx->filter_device_handle = CreateFile(
        L"\\\\.\\IntelAvbFilter",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );
    
    if (win_ctx->filter_device_handle == INVALID_HANDLE_VALUE) {
        printf("Windows HW: Failed to open AVB filter device. Error: %lu\n", GetLastError());
        free(win_ctx);
        return WIN_ERROR_DEVICE;
    }
    
    /* Initialize the AVB device through the filter */
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_INIT_DEVICE,
        NULL,
        0,
        NULL,
        0,
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Failed to initialize AVB device. Error: %lu\n", GetLastError());
        CloseHandle(win_ctx->filter_device_handle);
        free(win_ctx);
        return WIN_ERROR_DEVICE;
    }
    
    win_ctx->initialized = TRUE;
    win_ctx->ops = &windows_ndis_platform_ops;
    win_ctx->adapter_selected = 0;
    win_ctx->current_vendor_id = 0;
    win_ctx->current_device_id = 0;
    win_ctx->current_capabilities = 0;
    priv->platform_data = win_ctx;

    /* Automatically select the best available adapter (prefer I226 > I225 > I219 > I210) */
    if (windows_select_best_adapter(dev) == WIN_SUCCESS) {
        printf("Windows HW: Best adapter auto-selected (VID=0x%04x, DID=0x%04x)\n", 
               win_ctx->current_vendor_id, win_ctx->current_device_id);
    } else {
        printf("Windows HW: Warning - No suitable adapter found, manual selection required\n");
    }

    printf("Windows HW: Platform initialized successfully through NDIS filter\n");
    return WIN_SUCCESS;
}

/**
 * @brief Cleanup Windows platform access
 */
static void windows_platform_cleanup(device_t *dev)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    
    if (!dev || !dev->private_data) {
        return;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (win_ctx) {
        if (win_ctx->filter_device_handle && win_ctx->filter_device_handle != INVALID_HANDLE_VALUE) {
            CloseHandle(win_ctx->filter_device_handle);
        }
        
        if (win_ctx->mmio_base) {
            UnmapViewOfFile(win_ctx->mmio_base);
        }
        
        free(win_ctx);
        priv->platform_data = NULL;
    }
    
    printf("Windows HW: Platform cleanup completed\n");
}

/**
 * @brief Read PCI configuration register through NDIS filter
 */
static int windows_pci_read_config(device_t *dev, DWORD offset, DWORD *value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_REGISTER_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data || !value) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    /* Set up request for PCI config read */
    request.offset = offset;
    request.value = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_READ_REGISTER,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: PCI Config Read failed - Offset: 0x%08lx, Error: %lu\n", 
               offset, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: PCI Config Read failed - Offset: 0x%08lx, Status: 0x%lx\n", 
               offset, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    *value = request.value;
    printf("Windows HW: PCI Config Read - Offset: 0x%08lx, Value: 0x%08lx\n", offset, *value);
    return WIN_SUCCESS;
}

/**
 * @brief Write PCI configuration register through NDIS filter
 */
static int windows_pci_write_config(device_t *dev, DWORD offset, DWORD value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_REGISTER_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    /* Set up request for PCI config write */
    request.offset = offset;
    request.value = value;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_WRITE_REGISTER,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: PCI Config Write failed - Offset: 0x%08lx, Value: 0x%08lx, Error: %lu\n", 
               offset, value, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: PCI Config Write failed - Offset: 0x%08lx, Value: 0x%08lx, Status: 0x%lx\n", 
               offset, value, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    printf("Windows HW: PCI Config Write - Offset: 0x%08lx, Value: 0x%08lx\n", offset, value);
    return WIN_SUCCESS;
}

/**
 * @brief Read MMIO register through NDIS filter
 */
static int windows_mmio_read(device_t *dev, uint32_t offset, uint32_t *value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_REGISTER_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data || !value) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    /* Set up request for MMIO read */
    request.offset = offset;
    request.value = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_READ_REGISTER,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: MMIO Read failed - Offset: 0x%08x, Error: %lu\n", 
               offset, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: MMIO Read failed - Offset: 0x%08x, Status: 0x%lx\n", 
               offset, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    *value = request.value;
    printf("Windows HW: MMIO Read - Offset: 0x%08x, Value: 0x%08x\n", offset, *value);
    return WIN_SUCCESS;
}

/**
 * @brief Write MMIO register through NDIS filter
 */
static int windows_mmio_write(device_t *dev, uint32_t offset, uint32_t value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_REGISTER_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    /* Set up request for MMIO write */
    request.offset = offset;
    request.value = value;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_WRITE_REGISTER,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: MMIO Write failed - Offset: 0x%08x, Value: 0x%08x, Error: %lu\n", 
               offset, value, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: MMIO Write failed - Offset: 0x%08x, Value: 0x%08x, Status: 0x%lx\n", 
               offset, value, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    printf("Windows HW: MMIO Write - Offset: 0x%08x, Value: 0x%08x\n", offset, value);
    return WIN_SUCCESS;
}

/**
 * @brief Perform MDIO read operation through NDIS filter
 */
static int windows_mdio_read(device_t *dev, uint16_t phy_addr, uint16_t reg_addr, uint16_t *value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_MDIO_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data || !value) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: MDIO Read - PHY: 0x%04x, Reg: 0x%04x\n", phy_addr, reg_addr);
    
    /* Set up request for MDIO read */
    request.page = phy_addr;
    request.reg = reg_addr;
    request.value = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_MDIO_READ,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: MDIO Read failed - PHY: 0x%04x, Reg: 0x%04x, Error: %lu\n", 
               phy_addr, reg_addr, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: MDIO Read failed - PHY: 0x%04x, Reg: 0x%04x, Status: 0x%lx\n", 
               phy_addr, reg_addr, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    *value = request.value;
    printf("Windows HW: MDIO Read - PHY: 0x%04x, Reg: 0x%04x, Value: 0x%04x\n", 
           phy_addr, reg_addr, *value);
    return WIN_SUCCESS;
}

/**
 * @brief Perform MDIO write operation through NDIS filter
 */
static int windows_mdio_write(device_t *dev, uint16_t phy_addr, uint16_t reg_addr, uint16_t value)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_MDIO_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: MDIO Write - PHY: 0x%04x, Reg: 0x%04x, Value: 0x%04x\n", 
           phy_addr, reg_addr, value);
    
    /* Set up request for MDIO write */
    request.page = phy_addr;
    request.reg = reg_addr;
    request.value = value;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_MDIO_WRITE,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: MDIO Write failed - PHY: 0x%04x, Reg: 0x%04x, Value: 0x%04x, Error: %lu\n", 
               phy_addr, reg_addr, value, GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: MDIO Write failed - PHY: 0x%04x, Reg: 0x%04x, Value: 0x%04x, Status: 0x%lx\n", 
               phy_addr, reg_addr, value, request.status);
        return WIN_ERROR_ACCESS;
    }
    
    printf("Windows HW: MDIO Write completed - PHY: 0x%04x, Reg: 0x%04x, Value: 0x%04x\n", 
           phy_addr, reg_addr, value);
    return WIN_SUCCESS;
}

/**
 * @brief Read IEEE 1588 timestamp through NDIS filter
 */
static int windows_read_timestamp(device_t *dev, uint64_t *timestamp)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_TIMESTAMP_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data || !timestamp) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Reading IEEE 1588 timestamp through filter...\n");
    
    /* Initialize request */
    request.timestamp = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
    IOCTL_AVB_GET_TIMESTAMP,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Timestamp read failed, Error: %lu\n", GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: Timestamp read failed, Status: 0x%lx\n", request.status);
        return WIN_ERROR_ACCESS;
    }
    
    *timestamp = request.timestamp;
    
    printf("Windows HW: Timestamp: 0x%016llx\n", *timestamp);
    return WIN_SUCCESS;
}

/**
 * @brief Enumerate available adapters using filter driver
 */
static int windows_enum_adapters(device_t *dev, int index, uint32_t *count, uint16_t *vendor_id, uint16_t *device_id, uint32_t *capabilities)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_ENUM_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Enumerating adapters (index: %d)...\n", index);
    
    request.index = index;
    request.count = 0;
    request.vendor_id = 0;
    request.device_id = 0;
    request.capabilities = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_ENUM_ADAPTERS,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Adapter enumeration failed, Error: %lu\n", GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: Adapter enumeration failed, Status: 0x%lx\n", request.status);
        return WIN_ERROR_DEVICE;
    }
    
    if (count) *count = request.count;
    if (vendor_id) *vendor_id = request.vendor_id;  
    if (device_id) *device_id = request.device_id;
    if (capabilities) *capabilities = request.capabilities;
    
    printf("Windows HW: Found %lu adapters, VID=0x%04x, DID=0x%04x, Caps=0x%08lx\n", 
           request.count, request.vendor_id, request.device_id, request.capabilities);
    
    return WIN_SUCCESS;
}

/**
 * @brief Open specific adapter using filter driver  
 */
static int windows_open_adapter(device_t *dev, uint16_t vendor_id, uint16_t device_id)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_OPEN_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Opening adapter VID=0x%04x, DID=0x%04x...\n", vendor_id, device_id);
    
    request.vendor_id = vendor_id;
    request.device_id = device_id;
    request.reserved = 0;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_OPEN_ADAPTER,
        &request,
        sizeof(request),
        &request,  
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Adapter open failed, Error: %lu\n", GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: Adapter open failed, Status: 0x%lx\n", request.status);
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Adapter opened successfully\n");
    return WIN_SUCCESS;
}

/**
 * @brief Get device information using filter driver
 */
static int windows_get_device_info(device_t *dev, char *info_buffer, uint32_t *buffer_size)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_DEVICE_INFO_REQUEST request;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data || !info_buffer || !buffer_size) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Getting device information...\n");
    
    memset(&request, 0, sizeof(request));
    request.buffer_size = *buffer_size;
    request.status = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_GET_DEVICE_INFO,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Device info query failed, Error: %lu\n", GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (request.status != 0) {
        printf("Windows HW: Device info query failed, Status: 0x%lx\n", request.status);
        return WIN_ERROR_DEVICE;
    }
    
    // Copy information to user buffer
    size_t copy_size = min(request.buffer_size, *buffer_size - 1);
    memcpy(info_buffer, request.device_info, copy_size);
    info_buffer[copy_size] = '\0';
    *buffer_size = request.buffer_size;
    
    printf("Windows HW: Device info retrieved (%lu bytes)\n", request.buffer_size);
    return WIN_SUCCESS;
}

/**
 * @brief Get adapter priority for selection (higher = better)
 * @param device_id PCI Device ID
 * @return Priority score (higher is better)
 */
static int windows_get_adapter_priority(uint16_t device_id)
{
    switch (device_id) {
        case 0x125B: // I226-LM 
        case 0x125C: // I226-V
            return 100; // Highest - full TSN support + 2.5G
            
        case 0x15F2: // I225-LM
        case 0x15F3: // I225-V  
            return 90;  // High - full TSN support
            
        case 0x15B7: // I219-LM
        case 0x15B8: // I219-V
            return 60;  // Medium - basic PTP + MDIO
            
        case 0x1533: // I210
            return 50;  // Lower - basic PTP only
            
        case 0x153A: // I217-LM
        case 0x153B: // I217-V
            return 40;  // Lowest - basic PTP
            
        default:
            return 10;  // Unknown Intel device
    }
}

/**
 * @brief Automatically select the best available adapter (prefer I226 > I225 > I219 > I210)
 */
static int windows_select_best_adapter(device_t *dev)
{
    struct intel_private *priv;
    struct windows_hw_context *win_ctx;
    AVB_ENUM_REQUEST enumReq;
    DWORD bytesReturned;
    
    if (!dev || !dev->private_data) {
        return WIN_ERROR_ACCESS;
    }
    
    priv = (struct intel_private *)dev->private_data;
    win_ctx = (struct windows_hw_context *)priv->platform_data;
    
    if (!win_ctx || !win_ctx->initialized) {
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Auto-selecting best adapter...\n");
    
    /* Get adapter count */
    memset(&enumReq, 0, sizeof(enumReq));
    enumReq.index = 0;
    
    if (!DeviceIoControl(
        win_ctx->filter_device_handle,
        IOCTL_AVB_ENUM_ADAPTERS,
        &enumReq,
        sizeof(enumReq),
        &enumReq,
        sizeof(enumReq),
        &bytesReturned,
        NULL)) {
        printf("Windows HW: Adapter enumeration failed, Error: %lu\n", GetLastError());
        return WIN_ERROR_ACCESS;
    }
    
    if (enumReq.count == 0) {
        printf("Windows HW: No Intel AVB adapters found\n");
        return WIN_ERROR_DEVICE;
    }
    
    printf("Windows HW: Found %lu Intel adapters, selecting best...\n", (unsigned long)enumReq.count);
    
    /* Find the best adapter */
    int best_priority = -1;
    uint16_t best_vendor_id = 0;
    uint16_t best_device_id = 0;
    uint32_t best_capabilities = 0;
    
    for (uint32_t i = 0; i < enumReq.count; i++) {
        enumReq.index = i;
        
        if (DeviceIoControl(
            win_ctx->filter_device_handle,
            IOCTL_AVB_ENUM_ADAPTERS,
            &enumReq,
            sizeof(enumReq),
            &enumReq,
            sizeof(enumReq),
            &bytesReturned,
            NULL)) {
            
            int priority = windows_get_adapter_priority(enumReq.device_id);
            
            printf("Windows HW: Adapter #%lu: VID=0x%04x, DID=0x%04x (", 
                   (unsigned long)i, enumReq.vendor_id, enumReq.device_id);
                   
            switch (enumReq.device_id) {
                case 0x125B: printf("I226-LM"); break;
                case 0x125C: printf("I226-V"); break;
                case 0x15F2: printf("I225-LM"); break;
                case 0x15F3: printf("I225-V"); break;
                case 0x15B7: printf("I219-LM"); break;
                case 0x15B8: printf("I219-V"); break;
                case 0x1533: printf("I210"); break;
                case 0x153A: printf("I217-LM"); break;
                default: printf("Unknown"); break;
            }
            printf("), Priority=%d, Caps=0x%08lx\n", priority, (unsigned long)enumReq.capabilities);
            
            if (priority > best_priority) {
                best_priority = priority;
                best_vendor_id = enumReq.vendor_id;
                best_device_id = enumReq.device_id;
                best_capabilities = enumReq.capabilities;
            }
        }
    }
    
    if (best_priority > 0) {
        /* Select the best adapter */
        if (windows_open_adapter(dev, best_vendor_id, best_device_id) == WIN_SUCCESS) {
            win_ctx->current_vendor_id = best_vendor_id;
            win_ctx->current_device_id = best_device_id;
            win_ctx->current_capabilities = best_capabilities;
            win_ctx->adapter_selected = 1;
            
            printf("Windows HW: ✅ Selected ");
            switch (best_device_id) {
                case 0x125B: case 0x125C: printf("I226 (Full TSN + 2.5G)"); break;
                case 0x15F2: case 0x15F3: printf("I225 (Full TSN)"); break;
                case 0x15B7: case 0x15B8: printf("I219 (Basic PTP + MDIO)"); break;
                case 0x1533: printf("I210 (Basic PTP)"); break;
                default: printf("Intel adapter"); break;
            }
            printf(" as primary adapter\n");
            
            return WIN_SUCCESS;
        } else {
            printf("Windows HW: Failed to open best adapter\n");
            return WIN_ERROR_DEVICE;
        }
    }
    
    return WIN_ERROR_DEVICE;
}

/**
 * @brief Public wrapper for Windows adapter enumeration
 * @param index Adapter index to query (0..N-1) 
 * @param count Output: total number of adapters found
 * @param vendor_id Output: vendor ID of the adapter
 * @param device_id Output: device ID of the adapter
 * @param capabilities Output: capability flags of the adapter
 * @return 0 on success, negative error code on failure
 */
int intel_windows_enum_adapters(int index, uint32_t *count, uint16_t *vendor_id, uint16_t *device_id, uint32_t *capabilities)
{
    HANDLE filter_handle;
    AVB_ENUM_REQUEST request;
    DWORD bytesReturned;

    if (!count || !vendor_id || !device_id || !capabilities) {
        return -EINVAL;
    }
    
    /* Try to open the filter device directly */
    filter_handle = CreateFile(
        L"\\\\.\\IntelAvbFilter",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );
    
    if (filter_handle == INVALID_HANDLE_VALUE) {
        printf("Windows enumeration: Failed to open AVB filter device. Error: %lu\n", GetLastError());
        return -ENODEV;
    }
    
    /* Prepare enumeration request */
    request.index = index;
    request.count = 0;
    request.vendor_id = 0;
    request.device_id = 0;
    request.capabilities = 0;
    request.status = 0;
    
    /* Execute enumeration IOCTL */
    if (!DeviceIoControl(
        filter_handle,
        IOCTL_AVB_ENUM_ADAPTERS,
        &request,
        sizeof(request),
        &request,
        sizeof(request),
        &bytesReturned,
        NULL)) {
        printf("Windows enumeration: IOCTL failed, Error: %lu\n", GetLastError());
        CloseHandle(filter_handle);
        return -EIO;
    }
    
    if (request.status != 0) {
        printf("Windows enumeration: Request failed, Status: 0x%lx\n", request.status);
        CloseHandle(filter_handle);
        return -EIO;
    }
    
    /* Return results */
    *count = request.count;
    *vendor_id = request.vendor_id;
    *device_id = request.device_id;
    *capabilities = request.capabilities;
    
    CloseHandle(filter_handle);
    
    printf("Windows enumeration: Found %u adapters, current: VID=0x%04x, DID=0x%04x, Caps=0x%08x\n",
           *count, *vendor_id, *device_id, *capabilities);
    
    return 0;
}

/* Note: platform ops getter defined earlier (windows_ndis_platform_ops). */
