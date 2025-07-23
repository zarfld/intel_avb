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

/* IOCTL definitions for communication with NDIS filter driver */
#define _NDIS_CONTROL_CODE(request,method) \
            CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, request, method, FILE_ANY_ACCESS)

#define IOCTL_AVB_INIT_DEVICE           _NDIS_CONTROL_CODE(20, METHOD_BUFFERED)
#define IOCTL_AVB_READ_REGISTER         _NDIS_CONTROL_CODE(22, METHOD_BUFFERED)
#define IOCTL_AVB_WRITE_REGISTER        _NDIS_CONTROL_CODE(23, METHOD_BUFFERED)
#define IOCTL_AVB_GET_TIMESTAMP         _NDIS_CONTROL_CODE(24, METHOD_BUFFERED)
#define IOCTL_AVB_MDIO_READ             _NDIS_CONTROL_CODE(29, METHOD_BUFFERED)
#define IOCTL_AVB_MDIO_WRITE            _NDIS_CONTROL_CODE(30, METHOD_BUFFERED)

/* IOCTL data structures */
typedef struct _AVB_REGISTER_REQUEST {
    UINT32 offset;
    UINT32 value;
    ULONG status;
} AVB_REGISTER_REQUEST, *PAVB_REGISTER_REQUEST;

typedef struct _AVB_TIMESTAMP_REQUEST {
    UINT64 timestamp;
    int clock_id;
    ULONG status;
} AVB_TIMESTAMP_REQUEST, *PAVB_TIMESTAMP_REQUEST;

typedef struct _AVB_MDIO_REQUEST {
    UINT32 page;
    UINT32 reg;
    UINT16 value;
    ULONG status;
} AVB_MDIO_REQUEST, *PAVB_MDIO_REQUEST;

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
    priv->platform_data = win_ctx;
    
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
 * @brief Write MMIO register (simulation for I219 MDIO access)
 */
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
               (reg_addr << 16) | /* Register address */
               (2 << 0);          /* Turnaround bits */
    
    /* Write MDIO command */
    if (windows_mmio_write(dev, 0x0020, mdio_cmd) != WIN_SUCCESS) {
        return WIN_ERROR_ACCESS;
    }
    
    /* Wait for completion (simulated) */
    do {
        Sleep(1);
        if (windows_mmio_read(dev, 0x0020, &mdio_data) != WIN_SUCCESS) {
            return WIN_ERROR_ACCESS;
        }
        timeout--;
    } while ((mdio_data & 0x80000000) && timeout > 0);
    
    if (timeout <= 0) {
        printf("Windows HW: MDIO Write timeout\n");
        return WIN_ERROR_ACCESS;
    }
    
    printf("Windows HW: MDIO Write completed\n");
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
        IOCTL_AVB_READ_TIMESTAMP,
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

/* Windows platform operations structure */
static const struct platform_ops windows_platform_ops = {
    .init = windows_hw_init,
    .cleanup = windows_hw_cleanup,
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
    return &windows_platform_ops;
}
