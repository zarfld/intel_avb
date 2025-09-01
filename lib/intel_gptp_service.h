/* Intel AVB - OpenAvnu gPTP Integration Header
 * 
 * Windows-specific implementation of OpenAvnu-compatible gPTP timing services
 * using Intel hardware timestamping capabilities.
 */

#ifndef INTEL_GPTP_SERVICE_H
#define INTEL_GPTP_SERVICE_H

#include <stdint.h>
#include "intel.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef long double FrequencyRatio;

/* Intel gPTP Time Data Structure (OpenAvnu compatible) */
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

/* gPTP Service Functions */

/**
 * @brief Initialize Intel gPTP service with OpenAvnu compatibility
 * @param device Intel device to provide timing for
 * @param interface_name Network interface name (for OpenAvnu compatibility)
 * @return 0 on success, negative on failure
 */
int intel_gptp_service_init(device_t *device, const char *interface_name);

/**
 * @brief Update gPTP timing information from Intel hardware
 * @return 0 on success, negative on failure
 */
int intel_gptp_service_update_timing(void);

/**
 * @brief Get current gPTP time (OpenAvnu-compatible interface)
 * @param time_ns Output: current gPTP time in nanoseconds
 * @return 0 on success, negative on failure
 */
int intel_gptp_get_time(uint64_t *time_ns);

/**
 * @brief Get detailed gPTP information (OpenAvnu-compatible)
 * @param data Output: gPTP timing and status data
 * @return 0 on success, negative on failure
 */
int intel_gptp_get_data(intel_gptp_time_data_t *data);

/**
 * @brief Cleanup Intel gPTP service
 */
void intel_gptp_service_cleanup(void);

/**
 * @brief Check if gPTP service is available and functioning
 * @return 1 if available, 0 if not
 */
int intel_gptp_is_available(void);

/**
 * @brief Get gPTP service status information
 * @param status_buffer Output buffer for status string
 * @param buffer_size Size of status buffer
 */
void intel_gptp_get_status(char *status_buffer, size_t buffer_size);

/* OpenAvnu Compatibility Functions */

/**
 * @brief OpenAvnu-compatible gPTP initialization (Linux shared memory style)
 * @param shm_fd Shared memory file descriptor (Windows: unused, can be NULL)
 * @param shm_map Shared memory mapping (Windows: unused, can be NULL) 
 * @return 0 on success, negative on failure
 */
int gptpinit(int *shm_fd, char **shm_map);

/**
 * @brief OpenAvnu-compatible gPTP data retrieval
 * @param shm_mmap Shared memory mapping (Windows: unused)
 * @param td Output: gPTP time data
 * @return 0 on success, negative on failure
 */
int gptpgetdata(char *shm_mmap, intel_gptp_time_data_t *td);

/**
 * @brief OpenAvnu-compatible gPTP scaling/frequency information
 * @param shm_mmap Shared memory mapping (Windows: unused)
 * @param td Output: gPTP scaling data
 * @return 0 on success, negative on failure
 */
int gptpscaling(char *shm_mmap, intel_gptp_time_data_t *td);

/**
 * @brief OpenAvnu-compatible gPTP cleanup
 * @param shm_fd Shared memory file descriptor (Windows: unused)
 * @param shm_map Shared memory mapping (Windows: unused)
 * @return 0 on success, negative on failure
 */
int gptpdeinit(int *shm_fd, char **shm_map);

#ifdef __cplusplus
}
#endif

#endif /* INTEL_GPTP_SERVICE_H */
