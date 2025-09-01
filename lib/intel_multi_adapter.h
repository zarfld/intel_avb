/* intel_multi_adapter.h - Enhanced Multi-Adapter API for Service Separation */
#ifndef _INTEL_MULTI_ADAPTER_H_
#define _INTEL_MULTI_ADAPTER_H_

#include "intel.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Maximum number of parallel adapters supported */
#define INTEL_MAX_ADAPTERS 4

/* Adapter context for service separation */
typedef struct {
    device_t device;                    /* Device context */
    char service_name[64];              /* Service identifier */
    uint16_t vendor_id;                 /* PCI Vendor ID */
    uint16_t device_id;                 /* PCI Device ID */
    uint32_t capabilities;              /* Hardware capabilities */
    int priority;                       /* Selection priority */
    int active;                         /* Adapter is active */
    const struct platform_ops *ops;    /* Platform operations */
    void *service_context;              /* Service-specific context */
} intel_adapter_context_t;

/* Multi-adapter manager */
typedef struct {
    intel_adapter_context_t adapters[INTEL_MAX_ADAPTERS];
    int adapter_count;
    int initialized;
} intel_multi_manager_t;

/* Service role definitions */
typedef enum {
    INTEL_SERVICE_TSN_PRIMARY,      /* Primary TSN operations (I226 preferred) */
    INTEL_SERVICE_TSN_BACKUP,       /* Backup TSN operations */
    INTEL_SERVICE_PTP_MASTER,       /* PTP master clock */
    INTEL_SERVICE_PTP_SLAVE,        /* PTP slave/monitor */
    INTEL_SERVICE_AVB_STREAM,       /* AVB streaming */
    INTEL_SERVICE_MONITORING,       /* System monitoring */
    INTEL_SERVICE_GENERIC          /* Generic usage */
} intel_service_role_t;

/* Service configuration */
typedef struct {
    intel_service_role_t role;
    const char *service_name;
    uint32_t required_capabilities;     /* Required capability flags */
    uint32_t preferred_capabilities;    /* Preferred capability flags */
    uint16_t preferred_device_id;       /* 0 = auto-select */
    int exclusive;                      /* Service needs exclusive access */
} intel_service_config_t;

/**
 * ========================================
 * MULTI-ADAPTER MANAGEMENT API
 * ========================================
 */

/**
 * @brief Initialize multi-adapter manager
 * @return 0 on success, negative on error
 */
int intel_multi_init(void);

/**
 * @brief Cleanup multi-adapter manager
 */
void intel_multi_cleanup(void);

/**
 * @brief Get total number of available adapters
 * @return Number of available Intel adapters
 */
int intel_multi_get_adapter_count(void);

/**
 * @brief Enumerate all available adapters
 * @param adapters Output array of adapter info
 * @param max_adapters Maximum adapters to return
 * @return Number of adapters found
 */
int intel_multi_enum_all_adapters(intel_adapter_context_t *adapters, int max_adapters);

/**
 * ========================================
 * SERVICE-BASED ADAPTER ALLOCATION
 * ========================================
 */

/**
 * @brief Request adapter for specific service
 * @param config Service configuration
 * @param adapter_ctx Output adapter context for service
 * @return 0 on success, negative on error
 */
int intel_multi_request_adapter(const intel_service_config_t *config, 
                               intel_adapter_context_t **adapter_ctx);

/**
 * @brief Release adapter from service
 * @param adapter_ctx Adapter context to release
 * @return 0 on success, negative on error
 */
int intel_multi_release_adapter(intel_adapter_context_t *adapter_ctx);

/**
 * ========================================
 * PARALLEL OPERATIONS API
 * ========================================
 */

/**
 * @brief Read register from specific adapter
 * @param adapter_ctx Target adapter context
 * @param offset Register offset
 * @param value Output value
 * @return 0 on success, negative on error
 */
int intel_multi_read_reg(intel_adapter_context_t *adapter_ctx, uint32_t offset, uint32_t *value);

/**
 * @brief Write register to specific adapter
 * @param adapter_ctx Target adapter context
 * @param offset Register offset
 * @param value Value to write
 * @return 0 on success, negative on error
 */
int intel_multi_write_reg(intel_adapter_context_t *adapter_ctx, uint32_t offset, uint32_t value);

/**
 * @brief Get system time from specific adapter
 * @param adapter_ctx Target adapter context
 * @param systime Output system time
 * @return 0 on success, negative on error
 */
int intel_multi_get_systime(intel_adapter_context_t *adapter_ctx, uint64_t *systime);

/**
 * @brief MDIO read from specific adapter
 * @param adapter_ctx Target adapter context
 * @param page MDIO page
 * @param reg Register address
 * @param value Output value
 * @return 0 on success, negative on error
 */
int intel_multi_mdio_read(intel_adapter_context_t *adapter_ctx, uint32_t page, uint32_t reg, uint16_t *value);

/**
 * ========================================
 * TSN OPERATIONS FOR SPECIFIC ADAPTERS
 * ========================================
 */

/**
 * @brief Setup Time-Aware Shaper on specific adapter
 * @param adapter_ctx Target adapter context
 * @param config TAS configuration
 * @return 0 on success, negative on error
 */
int intel_multi_setup_tas(intel_adapter_context_t *adapter_ctx, struct tsn_tas_config *config);

/**
 * @brief Setup Frame Preemption on specific adapter
 * @param adapter_ctx Target adapter context
 * @param config Frame preemption configuration
 * @return 0 on success, negative on error
 */
int intel_multi_setup_fp(intel_adapter_context_t *adapter_ctx, struct tsn_fp_config *config);

/**
 * ========================================
 * UTILITY FUNCTIONS
 * ========================================
 */

/**
 * @brief Get adapter information string
 * @param adapter_ctx Adapter context
 * @param info_buffer Output buffer
 * @param buffer_size Buffer size
 * @return 0 on success, negative on error
 */
int intel_multi_get_adapter_info(intel_adapter_context_t *adapter_ctx, char *info_buffer, size_t buffer_size);

/**
 * @brief Check if adapter has specific capability
 * @param adapter_ctx Adapter context
 * @param capability Capability flag to check
 * @return 1 if supported, 0 if not
 */
int intel_multi_has_capability(intel_adapter_context_t *adapter_ctx, uint32_t capability);

/**
 * @brief Get adapter priority score (higher = better)
 * @param device_id PCI Device ID
 * @return Priority score
 */
int intel_multi_get_priority_score(uint16_t device_id);

/**
 * ========================================
 * CONVENIENCE MACROS FOR SERVICES
 * ========================================
 */

/* Quick service configuration macros */
#define INTEL_SERVICE_CONFIG_TSN_PRIMARY() { \
    .role = INTEL_SERVICE_TSN_PRIMARY, \
    .service_name = "TSN_Primary", \
    .required_capabilities = INTEL_CAP_TSN_TAS | INTEL_CAP_TSN_FP, \
    .preferred_capabilities = INTEL_CAP_2_5G | INTEL_CAP_PCIe_PTM, \
    .preferred_device_id = 0x125B, \
    .exclusive = 0 \
}

#define INTEL_SERVICE_CONFIG_PTP_MASTER() { \
    .role = INTEL_SERVICE_PTP_MASTER, \
    .service_name = "PTP_Master", \
    .required_capabilities = INTEL_CAP_BASIC_1588, \
    .preferred_capabilities = INTEL_CAP_ENHANCED_TS, \
    .preferred_device_id = 0, \
    .exclusive = 0 \
}

#define INTEL_SERVICE_CONFIG_MONITORING() { \
    .role = INTEL_SERVICE_MONITORING, \
    .service_name = "Monitoring", \
    .required_capabilities = INTEL_CAP_MMIO, \
    .preferred_capabilities = 0, \
    .preferred_device_id = 0x1533, \
    .exclusive = 0 \
}

#ifdef __cplusplus
}
#endif

#endif /* _INTEL_MULTI_ADAPTER_H_ */
