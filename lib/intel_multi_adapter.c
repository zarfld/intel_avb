/* intel_multi_adapter.c - Enhanced Multi-Adapter Implementation for Service Separation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intel.h"
#include "intel_multi_adapter.h"
#include "intel_private.h"
#include "intel_windows.h"  /* For platform operations */

/* Global multi-adapter manager */
static intel_multi_manager_t g_multi_manager = {0};

/**
 * @brief Initialize multi-adapter manager
 */
int intel_multi_init(void)
{
    printf("Intel Multi-Adapter: Initializing...\n");
    
    if (g_multi_manager.initialized) {
        printf("Intel Multi-Adapter: Already initialized\n");
        return 0;
    }
    
    memset(&g_multi_manager, 0, sizeof(g_multi_manager));
    
    /* Initialize platform operations */
    const struct platform_ops *ops = intel_get_windows_platform_ops();
    if (!ops) {
        printf("Intel Multi-Adapter: Failed to get platform operations\n");
        return -1;
    }
    
    /* Discover all available adapters */
    device_t temp_dev = {0};
    
    /* Initialize temporary device for enumeration */
    if (intel_common_init(&temp_dev) != 0) {
        printf("Intel Multi-Adapter: Failed to initialize temp device\n");
        return -1;
    }
    
    if (ops->init(&temp_dev) != 0) {
        printf("Intel Multi-Adapter: Failed to initialize platform\n");
        intel_common_cleanup(&temp_dev);
        return -1;
    }
    
    /* Enumerate all adapters */
    uint32_t adapter_count = 0;
    for (int i = 0; i < INTEL_MAX_ADAPTERS; i++) {
        uint16_t vendor_id = 0, device_id = 0;
        uint32_t capabilities = 0;
        
        if (intel_enum_adapters(&temp_dev, i, &adapter_count, &vendor_id, &device_id, &capabilities) == 0) {
            if (i < (int)adapter_count) {
                intel_adapter_context_t *ctx = &g_multi_manager.adapters[g_multi_manager.adapter_count];
                
                /* Initialize adapter context */
                memset(ctx, 0, sizeof(*ctx));
                ctx->vendor_id = vendor_id;
                ctx->device_id = device_id;
                ctx->capabilities = capabilities;
                ctx->priority = intel_multi_get_priority_score(device_id);
                ctx->ops = ops;
                ctx->active = 0;
                
                /* Initialize device structure */
                if (intel_common_init(&ctx->device) == 0) {
                    ctx->device.pci_vendor_id = vendor_id;
                    ctx->device.pci_device_id = device_id;
                    ctx->device.capabilities = capabilities;
                    
                    snprintf(ctx->service_name, sizeof(ctx->service_name), "Unassigned_%d", g_multi_manager.adapter_count);
                    
                    printf("Intel Multi-Adapter: Found adapter #%d - VID=0x%04x, DID=0x%04x, Priority=%d\n",
                           g_multi_manager.adapter_count, vendor_id, device_id, ctx->priority);
                    
                    g_multi_manager.adapter_count++;
                } else {
                    printf("Intel Multi-Adapter: Failed to initialize adapter #%d\n", g_multi_manager.adapter_count);
                }
            }
        }
        
        if (i >= (int)adapter_count - 1) break;
    }
    
    /* Cleanup temporary device */
    ops->cleanup(&temp_dev);
    intel_common_cleanup(&temp_dev);
    
    if (g_multi_manager.adapter_count == 0) {
        printf("Intel Multi-Adapter: No adapters found\n");
        return -1;
    }
    
    g_multi_manager.initialized = 1;
    printf("Intel Multi-Adapter: Initialized with %d adapters\n", g_multi_manager.adapter_count);
    
    return 0;
}

/**
 * @brief Cleanup multi-adapter manager
 */
void intel_multi_cleanup(void)
{
    printf("Intel Multi-Adapter: Cleaning up...\n");
    
    if (!g_multi_manager.initialized) {
        return;
    }
    
    /* Cleanup all active adapters */
    for (int i = 0; i < g_multi_manager.adapter_count; i++) {
        intel_adapter_context_t *ctx = &g_multi_manager.adapters[i];
        if (ctx->active && ctx->ops && ctx->ops->cleanup) {
            ctx->ops->cleanup(&ctx->device);
        }
        intel_common_cleanup(&ctx->device);
    }
    
    memset(&g_multi_manager, 0, sizeof(g_multi_manager));
    printf("Intel Multi-Adapter: Cleanup complete\n");
}

/**
 * @brief Get total number of available adapters
 */
int intel_multi_get_adapter_count(void)
{
    if (!g_multi_manager.initialized) {
        return -1;
    }
    return g_multi_manager.adapter_count;
}

/**
 * @brief Enumerate all available adapters
 */
int intel_multi_enum_all_adapters(intel_adapter_context_t *adapters, int max_adapters)
{
    if (!g_multi_manager.initialized || !adapters || max_adapters <= 0) {
        return -1;
    }
    
    int count = (g_multi_manager.adapter_count < max_adapters) ? g_multi_manager.adapter_count : max_adapters;
    memcpy(adapters, g_multi_manager.adapters, count * sizeof(intel_adapter_context_t));
    
    return count;
}

/**
 * @brief Get adapter priority score (higher = better)
 */
int intel_multi_get_priority_score(uint16_t device_id)
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
 * @brief Check adapter compatibility with service requirements
 */
static int adapter_matches_service(intel_adapter_context_t *adapter, const intel_service_config_t *config)
{
    /* Check required capabilities */
    if ((adapter->capabilities & config->required_capabilities) != config->required_capabilities) {
        return 0;
    }
    
    /* Check preferred device ID */
    if (config->preferred_device_id != 0 && adapter->device_id != config->preferred_device_id) {
        return 0;
    }
    
    /* Check if adapter is already in exclusive use */
    if (config->exclusive && adapter->active) {
        return 0;
    }
    
    return 1;
}

/**
 * @brief Calculate adapter score for service (higher = better match)
 */
static int calculate_service_score(intel_adapter_context_t *adapter, const intel_service_config_t *config)
{
    int score = adapter->priority;
    
    /* Bonus for preferred capabilities */
    if ((adapter->capabilities & config->preferred_capabilities) == config->preferred_capabilities) {
        score += 20;
    }
    
    /* Bonus for exact device ID match */
    if (config->preferred_device_id != 0 && adapter->device_id == config->preferred_device_id) {
        score += 50;
    }
    
    /* Penalty if adapter is already active (sharing) */
    if (adapter->active && !config->exclusive) {
        score -= 10;
    }
    
    return score;
}

/**
 * @brief Request adapter for specific service
 */
int intel_multi_request_adapter(const intel_service_config_t *config, intel_adapter_context_t **adapter_ctx)
{
    if (!g_multi_manager.initialized || !config || !adapter_ctx) {
        return -1;
    }
    
    printf("Intel Multi-Adapter: Requesting adapter for service '%s'\n", config->service_name);
    
    intel_adapter_context_t *best_adapter = NULL;
    int best_score = -1;
    
    /* Find best matching adapter */
    for (int i = 0; i < g_multi_manager.adapter_count; i++) {
        intel_adapter_context_t *adapter = &g_multi_manager.adapters[i];
        
        if (!adapter_matches_service(adapter, config)) {
            continue;
        }
        
        int score = calculate_service_score(adapter, config);
        if (score > best_score) {
            best_score = score;
            best_adapter = adapter;
        }
    }
    
    if (!best_adapter) {
        printf("Intel Multi-Adapter: No suitable adapter found for service '%s'\n", config->service_name);
        return -1;
    }
    
    /* Initialize adapter if not already active */
    if (!best_adapter->active) {
        if (best_adapter->ops->init(&best_adapter->device) != 0) {
            printf("Intel Multi-Adapter: Failed to initialize adapter for service '%s'\n", config->service_name);
            return -1;
        }
        best_adapter->active = 1;
    }
    
    /* Update service information */
    strncpy(best_adapter->service_name, config->service_name, sizeof(best_adapter->service_name) - 1);
    best_adapter->service_name[sizeof(best_adapter->service_name) - 1] = '\0';
    
    *adapter_ctx = best_adapter;
    
    printf("Intel Multi-Adapter: Assigned adapter VID=0x%04x, DID=0x%04x (Priority=%d) to service '%s'\n",
           best_adapter->vendor_id, best_adapter->device_id, best_adapter->priority, config->service_name);
    
    return 0;
}

/**
 * @brief Release adapter from service
 */
int intel_multi_release_adapter(intel_adapter_context_t *adapter_ctx)
{
    if (!g_multi_manager.initialized || !adapter_ctx) {
        return -1;
    }
    
    printf("Intel Multi-Adapter: Releasing adapter from service '%s'\n", adapter_ctx->service_name);
    
    /* Reset service information but keep adapter active for potential reuse */
    snprintf(adapter_ctx->service_name, sizeof(adapter_ctx->service_name), "Released");
    adapter_ctx->service_context = NULL;
    
    return 0;
}

/**
 * ========================================
 * PARALLEL OPERATIONS IMPLEMENTATION
 * ========================================
 */

/**
 * @brief Read register from specific adapter
 */
int intel_multi_read_reg(intel_adapter_context_t *adapter_ctx, uint32_t offset, uint32_t *value)
{
    if (!adapter_ctx || !adapter_ctx->active || !adapter_ctx->ops || !value) {
        return -1;
    }
    
    if (adapter_ctx->ops->mmio_read) {
        return adapter_ctx->ops->mmio_read(&adapter_ctx->device, offset, value);
    }
    
    return -1;
}

/**
 * @brief Write register to specific adapter
 */
int intel_multi_write_reg(intel_adapter_context_t *adapter_ctx, uint32_t offset, uint32_t value)
{
    if (!adapter_ctx || !adapter_ctx->active || !adapter_ctx->ops) {
        return -1;
    }
    
    if (adapter_ctx->ops->mmio_write) {
        return adapter_ctx->ops->mmio_write(&adapter_ctx->device, offset, value);
    }
    
    return -1;
}

/**
 * @brief Get system time from specific adapter
 */
int intel_multi_get_systime(intel_adapter_context_t *adapter_ctx, uint64_t *systime)
{
    if (!adapter_ctx || !adapter_ctx->active || !adapter_ctx->ops || !systime) {
        return -1;
    }
    
    if (adapter_ctx->ops->read_timestamp) {
        return adapter_ctx->ops->read_timestamp(&adapter_ctx->device, systime);
    }
    
    return -1;
}

/**
 * @brief MDIO read from specific adapter
 */
int intel_multi_mdio_read(intel_adapter_context_t *adapter_ctx, uint32_t page, uint32_t reg, uint16_t *value)
{
    if (!adapter_ctx || !adapter_ctx->active || !adapter_ctx->ops || !value) {
        return -1;
    }
    
    if (adapter_ctx->ops->mdio_read) {
        return adapter_ctx->ops->mdio_read(&adapter_ctx->device, (uint16_t)page, (uint16_t)reg, value);
    }
    
    return -1;
}

/**
 * @brief Setup Time-Aware Shaper on specific adapter
 */
int intel_multi_setup_tas(intel_adapter_context_t *adapter_ctx, struct tsn_tas_config *config)
{
    if (!adapter_ctx || !adapter_ctx->active || !config) {
        return -1;
    }
    
    /* Check if adapter supports TAS */
    if (!(adapter_ctx->capabilities & INTEL_CAP_TSN_TAS)) {
        printf("Intel Multi-Adapter: Adapter does not support TAS\n");
        return -1;
    }
    
    /* Use the main API which will delegate to the right device implementation */
    return intel_setup_time_aware_shaper(&adapter_ctx->device, config);
}

/**
 * @brief Setup Frame Preemption on specific adapter
 */
int intel_multi_setup_fp(intel_adapter_context_t *adapter_ctx, struct tsn_fp_config *config)
{
    if (!adapter_ctx || !adapter_ctx->active || !config) {
        return -1;
    }
    
    /* Check if adapter supports Frame Preemption */
    if (!(adapter_ctx->capabilities & INTEL_CAP_TSN_FP)) {
        printf("Intel Multi-Adapter: Adapter does not support Frame Preemption\n");
        return -1;
    }
    
    /* Use the main API which will delegate to the right device implementation */
    return intel_setup_frame_preemption(&adapter_ctx->device, config);
}

/**
 * @brief Get adapter information string
 */
int intel_multi_get_adapter_info(intel_adapter_context_t *adapter_ctx, char *info_buffer, size_t buffer_size)
{
    if (!adapter_ctx || !info_buffer || buffer_size == 0) {
        return -1;
    }
    
    const char *device_name = "Unknown";
    
    switch (adapter_ctx->device_id) {
        case 0x125B: device_name = "Intel I226-LM (Full TSN + 2.5G)"; break;
        case 0x125C: device_name = "Intel I226-V (Full TSN + 2.5G)"; break;
        case 0x15F2: device_name = "Intel I225-LM (Full TSN)"; break;
        case 0x15F3: device_name = "Intel I225-V (Full TSN)"; break;
        case 0x15B7: device_name = "Intel I219-LM (Basic PTP + MDIO)"; break;
        case 0x15B8: device_name = "Intel I219-V (Basic PTP + MDIO)"; break;
        case 0x1533: device_name = "Intel I210 (Basic PTP)"; break;
        case 0x153A: device_name = "Intel I217-LM (Basic PTP)"; break;
    }
    
    snprintf(info_buffer, buffer_size, "%s - Service: %s, Priority: %d, Active: %s",
             device_name, adapter_ctx->service_name, adapter_ctx->priority,
             adapter_ctx->active ? "Yes" : "No");
    
    return 0;
}

/**
 * @brief Check if adapter has specific capability
 */
int intel_multi_has_capability(intel_adapter_context_t *adapter_ctx, uint32_t capability)
{
    if (!adapter_ctx) {
        return 0;
    }
    
    return (adapter_ctx->capabilities & capability) == capability ? 1 : 0;
}
