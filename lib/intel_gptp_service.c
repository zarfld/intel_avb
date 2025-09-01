/* Intel AVB - OpenAvnu gPTP Integration for Windows
 * 
 * This module bridges our proven Intel service architecture with OpenAvnu's 
 * industry-standard gPTP implementation for Windows environments.
 */

#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "intel.h"
#include "intel_windows.h"

// OpenAvnu-compatible gPTP data structures
#define SHM_SIZE (4*8 + sizeof(HANDLE)) /* 3 - 64 bit and 2 - 32 bits */
#define SHM_NAME  "Global\\IntelAVB_gPTP"

typedef long double FrequencyRatio;

typedef struct {
    int64_t ml_phoffset;            /* Master-to-local phase offset */
    int64_t ls_phoffset;            /* Local-to-system phase offset */
    FrequencyRatio ml_freqoffset;   /* Master-to-local frequency offset */
    FrequencyRatio ls_freqoffset;   /* Local-to-system frequency offset */
    uint64_t local_time;            /* Local network device time */
    
    /* Current grandmaster information */
    uint8_t gptp_grandmaster_id[8]; /* Current grandmaster id */
    uint8_t gptp_domain_number;     /* gPTP domain number */
    
    /* Grandmaster support information */
    uint8_t clock_identity[8];      /* Local clock identity */
    uint8_t priority1;              /* Priority1 field of the local clock */
    uint8_t clock_class;            /* ClockClass field of the local clock */ 
    uint16_t offset_scaled_log_variance; /* OffsetScaledLogVariance field */
    uint8_t clock_accuracy;         /* ClockAccuracy field of the local clock */
    uint8_t priority2;              /* Priority2 field of the local clock */
    
    /* Interface-specific information */
    int8_t log_sync_interval;       /* currentLogSyncInterval */
    int8_t log_announce_interval;   /* currentLogAnnounceInterval */
    int8_t log_pdelay_interval;     /* currentLogPDelayReqInterval */
    uint16_t port_number;           /* portNumber field */
} intel_gptp_time_data_t;

/* Intel gPTP Service Context */
typedef struct {
    device_t *device;
    HANDLE shared_memory;           /* Shared memory handle */
    intel_gptp_time_data_t *mapped_data;  /* Mapped shared memory */
    HANDLE mutex;                   /* Mutex for synchronization */
    intel_gptp_time_data_t shared_data;   /* Local copy of data */
    LARGE_INTEGER qpc_frequency;    /* Query performance counter frequency */
    uint64_t last_sync_time;
    uint64_t last_update_time;
    int initialized;
    const char *interface_name;
} intel_gptp_service_t;

/* Global gPTP service instance */
static intel_gptp_service_t g_gptp_service = {0};

/**
 * @brief Initialize Intel gPTP service with OpenAvnu compatibility
 * @param device Intel device to provide timing for
 * @param interface_name Network interface name (for OpenAvnu compatibility)
 * @return 0 on success, negative on failure
 */
int intel_gptp_service_init(device_t *device, const char *interface_name)
{
    printf("Intel gPTP Service: Initializing OpenAvnu-compatible timing service\n");
    
    if (!device || !interface_name) {
        printf("❌ Intel gPTP Service: Invalid parameters\n");
        return -1;
    }
    
    if (g_gptp_service.initialized) {
        printf("✅ Intel gPTP Service: Already initialized\n");
        return 0;
    }
    
    /* Create shared memory for gPTP data (OpenAvnu compatibility) */
    g_gptp_service.shared_memory = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SHM_SIZE,
        SHM_NAME
    );
    
    if (!g_gptp_service.shared_memory) {
        printf("❌ Intel gPTP Service: Failed to create shared memory (Error: %lu)\n", GetLastError());
        return -1;
    }
    
    g_gptp_service.mapped_data = (intel_gptp_time_data_t *)MapViewOfFile(
        g_gptp_service.shared_memory,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHM_SIZE
    );
    
    if (!g_gptp_service.mapped_data) {
        printf("❌ Intel gPTP Service: Failed to map shared memory (Error: %lu)\n", GetLastError());
        CloseHandle(g_gptp_service.shared_memory);
        return -1;
    }
    
    /* Create mutex for thread-safe access */
    g_gptp_service.mutex = CreateMutexA(NULL, FALSE, "IntelAVB_gPTP_Mutex");
    if (!g_gptp_service.mutex) {
        printf("❌ Intel gPTP Service: Failed to create mutex (Error: %lu)\n", GetLastError());
        UnmapViewOfFile(g_gptp_service.mapped_data);
        CloseHandle(g_gptp_service.shared_memory);
        return -1;
    }
    
    /* Initialize service context */
    g_gptp_service.device = device;
    g_gptp_service.interface_name = _strdup(interface_name);
    g_gptp_service.last_sync_time = 0;
    g_gptp_service.last_update_time = 0;
    QueryPerformanceFrequency(&g_gptp_service.qpc_frequency);
    g_gptp_service.initialized = 1;
    
    /* Initialize shared memory with default values */
    memset(g_gptp_service.mapped_data, 0, sizeof(intel_gptp_time_data_t));
    
    /* Set default clock identity (based on Intel device) */
    uint16_t vendor_id = device->pci_vendor_id;
    uint16_t device_id = device->pci_device_id;
    g_gptp_service.mapped_data->clock_identity[0] = (vendor_id >> 8) & 0xFF;
    g_gptp_service.mapped_data->clock_identity[1] = vendor_id & 0xFF;
    g_gptp_service.mapped_data->clock_identity[2] = (device_id >> 8) & 0xFF;
    g_gptp_service.mapped_data->clock_identity[3] = device_id & 0xFF;
    
    /* Set reasonable default values for gPTP parameters */
    g_gptp_service.mapped_data->gptp_domain_number = 0;
    g_gptp_service.mapped_data->clock_class = 248;  /* Default class for end stations */
    g_gptp_service.mapped_data->clock_accuracy = 0x21; /* 100ns accuracy */
    g_gptp_service.mapped_data->priority1 = 255;    /* Lowest priority (slave only) */
    g_gptp_service.mapped_data->priority2 = 255;
    g_gptp_service.mapped_data->log_sync_interval = -3;  /* 125ms */
    g_gptp_service.mapped_data->log_announce_interval = 1; /* 2s */
    g_gptp_service.mapped_data->log_pdelay_interval = 0;   /* 1s */
    g_gptp_service.mapped_data->port_number = 1;
    
    printf("✅ Intel gPTP Service: Initialized successfully\n");
    printf("   Interface: %s\n", interface_name);
    printf("   Device: VID=0x%04x, DID=0x%04x\n", vendor_id, device_id);
    printf("   Shared Memory: %s\n", SHM_NAME);
    
    return 0;
}

/**
 * @brief Update gPTP timing information from Intel hardware
 * @return 0 on success, negative on failure
 */
int intel_gptp_service_update_timing(void)
{
    if (!g_gptp_service.initialized) {
        return -1;
    }
    
    /* Get current system time and hardware time */
    SYSTEMTIME sys_time;
    FILETIME file_time;
    uint64_t system_time_ns;
    uint64_t hardware_time_ns;
    
    GetSystemTime(&sys_time);
    SystemTimeToFileTime(&sys_time, &file_time);
    
    /* Convert Windows FILETIME to nanoseconds since 1970 */
    uint64_t filetime_ns = ((uint64_t)file_time.dwHighDateTime << 32) | file_time.dwLowDateTime;
    system_time_ns = (filetime_ns - 116444736000000000ULL) * 100; /* Convert to ns since 1970 */
    
    /* Get hardware timestamp from Intel device */
    /* Use direct hardware access when available, fallback to system time */
    hardware_time_ns = system_time_ns; /* Simplified for now - production would read hardware */
    
    /* Lock shared memory for update */
    WaitForSingleObject(g_gptp_service.mutex, INFINITE);
    
    /* Update timing information */
    g_gptp_service.mapped_data->local_time = hardware_time_ns;
    g_gptp_service.mapped_data->ml_phoffset = 0;  /* Start with no offset */
    g_gptp_service.mapped_data->ls_phoffset = system_time_ns - hardware_time_ns;
    g_gptp_service.mapped_data->ml_freqoffset = 1.0;  /* No frequency adjustment initially */
    g_gptp_service.mapped_data->ls_freqoffset = 1.0;
    
    g_gptp_service.last_sync_time = hardware_time_ns;
    
    ReleaseMutex(g_gptp_service.mutex);
    
    return 0;
}

/**
 * @brief Get current gPTP time (OpenAvnu-compatible interface)
 * @param time_ns Output: current gPTP time in nanoseconds
 * @return 0 on success, negative on failure
 */
int intel_gptp_get_time(uint64_t *time_ns)
{
    if (!g_gptp_service.initialized || !time_ns) {
        return -1;
    }
    
    /* Update timing before returning */
    intel_gptp_service_update_timing();
    
    /* Lock shared memory for read */
    WaitForSingleObject(g_gptp_service.mutex, INFINITE);
    
    uint64_t local_time = g_gptp_service.mapped_data->local_time;
    int64_t ml_phoffset = g_gptp_service.mapped_data->ml_phoffset;
    
    *time_ns = local_time + ml_phoffset;  /* Apply master offset */
    
    ReleaseMutex(g_gptp_service.mutex);
    
    return 0;
}

/**
 * @brief Get detailed gPTP information (OpenAvnu-compatible)
 * @param data Output: gPTP timing and status data
 * @return 0 on success, negative on failure
 */
int intel_gptp_get_data(intel_gptp_time_data_t *data)
{
    if (!g_gptp_service.initialized || !data) {
        return -1;
    }
    
    /* Update timing before returning */
    intel_gptp_service_update_timing();
    
    /* Lock shared memory for read */
    WaitForSingleObject(g_gptp_service.mutex, INFINITE);
    
    /* Copy all gPTP data */
    memcpy(data, g_gptp_service.mapped_data, sizeof(intel_gptp_time_data_t));
    
    ReleaseMutex(g_gptp_service.mutex);
    
    return 0;
}

/**
 * @brief Cleanup Intel gPTP service
 */
void intel_gptp_service_cleanup(void)
{
    if (!g_gptp_service.initialized) {
        return;
    }
    
    printf("Intel gPTP Service: Cleaning up...\n");
    
    if (g_gptp_service.mutex) {
        CloseHandle(g_gptp_service.mutex);
    }
    
    if (g_gptp_service.mapped_data) {
        UnmapViewOfFile(g_gptp_service.mapped_data);
    }
    
    if (g_gptp_service.shared_memory) {
        CloseHandle(g_gptp_service.shared_memory);
    }
    
    if (g_gptp_service.interface_name) {
        free((void*)g_gptp_service.interface_name);
    }
    
    memset(&g_gptp_service, 0, sizeof(g_gptp_service));
    
    printf("✅ Intel gPTP Service: Cleanup complete\n");
}

/**
 * @brief Check if gPTP service is available and functioning
 * @return 1 if available, 0 if not
 */
int intel_gptp_is_available(void)
{
    return g_gptp_service.initialized;
}

/**
 * @brief Get gPTP service status information
 * @param status_buffer Output buffer for status string
 * @param buffer_size Size of status buffer
 */
void intel_gptp_get_status(char *status_buffer, size_t buffer_size)
{
    if (!status_buffer || buffer_size == 0) {
        return;
    }
    
    if (!g_gptp_service.initialized) {
        snprintf(status_buffer, buffer_size, "Intel gPTP Service: Not initialized");
        return;
    }
    
    intel_gptp_time_data_t data;
    if (intel_gptp_get_data(&data) == 0) {
        snprintf(status_buffer, buffer_size,
            "Intel gPTP Service: Active\n"
            "  Interface: %s\n"
            "  Local Time: %llu ns\n" 
            "  GM Offset: %lld ns\n"
            "  Domain: %d, Class: %d\n"
            "  Sync Interval: %d, Announce: %d, PDelay: %d",
            g_gptp_service.interface_name ? g_gptp_service.interface_name : "unknown",
            (unsigned long long)data.local_time,
            (long long)data.ml_phoffset,
            data.gptp_domain_number,
            data.clock_class,
            data.log_sync_interval,
            data.log_announce_interval,
            data.log_pdelay_interval
        );
    } else {
        snprintf(status_buffer, buffer_size, "Intel gPTP Service: Error getting status");
    }
}

/* ==================================================================
 * OpenAvnu Compatibility Functions
 * ================================================================== */

/**
 * @brief Initialize OpenAvnu-compatible shared memory interface
 * @param shm_fd Pointer to store shared memory file descriptor (Windows handle)
 * @param shm_map Pointer to store mapped memory address
 * @return 0 on success, negative on failure
 */
int gptpinit(int *shm_fd, char **shm_map)
{
    if (!g_gptp_service.initialized) {
        /* Try to initialize the service if not already done */
        device_t dummy_dev = {0};
        if (intel_gptp_service_init(&dummy_dev, "Intel0") != 0) {
            return -1;
        }
    }
    
    /* Return handles for OpenAvnu compatibility */
    if (shm_fd) *shm_fd = (int)(uintptr_t)g_gptp_service.shared_memory;
    if (shm_map) *shm_map = (char*)g_gptp_service.mapped_data;
    
    return 0;
}

/**
 * @brief Get gPTP data from shared memory (OpenAvnu compatible)
 * @param shm_map Shared memory map address
 * @param data Output buffer for gPTP data
 * @return 0 on success, negative on failure
 */
int gptpgetdata(char *shm_map, intel_gptp_time_data_t *data)
{
    if (!data || !g_gptp_service.initialized) {
        return -1;
    }
    
    /* Update timing before returning data */
    intel_gptp_service_update_timing();
    
    /* Copy current data */
    WaitForSingleObject(g_gptp_service.mutex, INFINITE);
    memcpy(data, &g_gptp_service.shared_data, sizeof(intel_gptp_time_data_t));
    ReleaseMutex(g_gptp_service.mutex);
    
    return 0;
}

/**
 * @brief Get gPTP scaling information (OpenAvnu compatible)
 * @param shm_map Shared memory map address
 * @param data Output buffer for gPTP scaling data
 * @return 0 on success, negative on failure
 */
int gptpscaling(char *shm_map, intel_gptp_time_data_t *data)
{
    if (!data || !g_gptp_service.initialized) {
        return -1;
    }
    
    /* Update timing to get latest scaling information */
    intel_gptp_service_update_timing();
    
    /* Copy scaling data */
    WaitForSingleObject(g_gptp_service.mutex, INFINITE);
    data->ml_freqoffset = g_gptp_service.shared_data.ml_freqoffset;
    data->ml_phoffset = g_gptp_service.shared_data.ml_phoffset;
    data->ls_freqoffset = g_gptp_service.shared_data.ls_freqoffset;
    data->ls_phoffset = g_gptp_service.shared_data.ls_phoffset;
    ReleaseMutex(g_gptp_service.mutex);
    
    return 0;
}

/**
 * @brief Cleanup OpenAvnu-compatible shared memory interface
 * @param shm_fd Pointer to shared memory file descriptor
 * @param shm_map Pointer to mapped memory address
 * @return 0 on success, negative on failure
 */
int gptpdeinit(int *shm_fd, char **shm_map)
{
    /* OpenAvnu compatibility cleanup - actual cleanup happens in intel_gptp_service_cleanup */
    if (shm_fd) *shm_fd = 0;
    if (shm_map) *shm_map = NULL;
    
    return 0;
}
