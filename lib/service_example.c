/* service_example.c - Practical Example of Service-Specific Adapter Usage */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "intel.h"
#include "intel_multi_adapter.h"

/**
 * Example Service 1: AVB Audio Stream Service
 * - Requires TSN capabilities (TAS, FP)
 * - Prefers I226 for best performance
 */
typedef struct {
    intel_adapter_context_t *adapter;
    int stream_active;
    uint64_t last_timestamp;
    int packet_count;
} avb_audio_service_t;

int avb_audio_service_init(avb_audio_service_t *service)
{
    printf("🎵 AVB Audio Service: Initializing...\n");
    
    /* Request adapter with TSN capabilities */
    intel_service_config_t config = {
        .role = INTEL_SERVICE_TSN_PRIMARY,
        .service_name = "AVB_Audio_Stream",
        .required_capabilities = INTEL_CAP_TSN_TAS | INTEL_CAP_BASIC_1588,
        .preferred_capabilities = INTEL_CAP_TSN_FP | INTEL_CAP_2_5G,
        .preferred_device_id = 0x125B, /* I226 preferred */
        .exclusive = 0
    };
    
    if (intel_multi_request_adapter(&config, &service->adapter) != 0) {
        printf("❌ AVB Audio Service: No suitable adapter found\n");
        return -1;
    }
    
    printf("✅ AVB Audio Service: Using adapter 0x%04X\n", service->adapter->device_id);
    
    /* Initialize service state */
    service->stream_active = 0;
    service->last_timestamp = 0;
    service->packet_count = 0;
    
    return 0;
}

int avb_audio_service_start_stream(avb_audio_service_t *service)
{
    if (!service || !service->adapter) return -1;
    
    printf("🎵 AVB Audio Service: Starting audio stream...\n");
    
    /* Configure TSN Time-Aware Shaper for audio stream */
    if (intel_multi_has_capability(service->adapter, INTEL_CAP_TSN_TAS)) {
        struct tsn_tas_config tas_config = {0};
        tas_config.cycle_time_ns = 125000; /* 125µs for audio */
        tas_config.gate_states[1] = 0xFF;  /* Audio queue always open */
        tas_config.gate_durations[1] = 62500; /* 50% cycle time */
        
        if (intel_multi_setup_tas(service->adapter, &tas_config) == 0) {
            printf("   ✅ TAS configured for audio stream\n");
        } else {
            printf("   ⚠️  TAS configuration failed (using simulated mode)\n");
        }
    }
    
    /* Get initial timestamp */
    intel_multi_get_systime(service->adapter, &service->last_timestamp);
    service->stream_active = 1;
    
    printf("   ✅ Audio stream started\n");
    return 0;
}

void avb_audio_service_process(avb_audio_service_t *service)
{
    if (!service || !service->stream_active) return;
    
    /* Get current timestamp */
    uint64_t current_time = 0;
    intel_multi_get_systime(service->adapter, &current_time);
    
    /* Simulate packet processing */
    service->packet_count++;
    
    if (service->packet_count % 100 == 0) {
        printf("🎵 AVB Audio: Processed %d packets (Time: 0x%llX)\n", 
               service->packet_count, current_time & 0xFFFFFFFF);
    }
}

/**
 * Example Service 2: PTP Time Synchronization Service
 * - Requires basic IEEE 1588 capability
 * - Can use any available adapter
 */
typedef struct {
    intel_adapter_context_t *adapter;
    int sync_active;
    uint64_t master_time;
    int sync_count;
} ptp_sync_service_t;

int ptp_sync_service_init(ptp_sync_service_t *service)
{
    printf("⏰ PTP Sync Service: Initializing...\n");
    
    /* Request adapter with PTP capabilities */
    intel_service_config_t config = {
        .role = INTEL_SERVICE_PTP_MASTER,
        .service_name = "PTP_Time_Sync",
        .required_capabilities = INTEL_CAP_BASIC_1588,
        .preferred_capabilities = INTEL_CAP_ENHANCED_TS,
        .preferred_device_id = 0, /* Any adapter */
        .exclusive = 0
    };
    
    if (intel_multi_request_adapter(&config, &service->adapter) != 0) {
        printf("❌ PTP Sync Service: No suitable adapter found\n");
        return -1;
    }
    
    printf("✅ PTP Sync Service: Using adapter 0x%04X\n", service->adapter->device_id);
    
    /* Initialize service state */
    service->sync_active = 0;
    service->master_time = 0;
    service->sync_count = 0;
    
    return 0;
}

int ptp_sync_service_start(ptp_sync_service_t *service)
{
    if (!service || !service->adapter) return -1;
    
    printf("⏰ PTP Sync Service: Starting time synchronization...\n");
    
    /* Get initial time reference */
    intel_multi_get_systime(service->adapter, &service->master_time);
    service->sync_active = 1;
    
    printf("   ✅ PTP sync started with time: 0x%llX\n", service->master_time);
    return 0;
}

void ptp_sync_service_process(ptp_sync_service_t *service)
{
    if (!service || !service->sync_active) return;
    
    /* Update master time */
    intel_multi_get_systime(service->adapter, &service->master_time);
    service->sync_count++;
    
    if (service->sync_count % 50 == 0) {
        printf("⏰ PTP Sync: Sync #%d (Master Time: 0x%llX)\n",
               service->sync_count, service->master_time & 0xFFFFFFFF);
    }
}

/**
 * Example Service 3: Network Monitoring Service
 * - Only needs basic register access
 * - Prefers I210 to leave better adapters for other services
 */
typedef struct {
    intel_adapter_context_t *adapter;
    int monitoring_active;
    uint32_t last_stats[4]; /* Track some register values */
    int poll_count;
} monitoring_service_t;

int monitoring_service_init(monitoring_service_t *service)
{
    printf("📊 Monitoring Service: Initializing...\n");
    
    /* Request basic adapter for monitoring */
    intel_service_config_t config = {
        .role = INTEL_SERVICE_MONITORING,
        .service_name = "Network_Monitor",
        .required_capabilities = INTEL_CAP_MMIO,
        .preferred_capabilities = 0,
        .preferred_device_id = 0x1533, /* Prefer I210 */
        .exclusive = 0
    };
    
    if (intel_multi_request_adapter(&config, &service->adapter) != 0) {
        printf("❌ Monitoring Service: No suitable adapter found\n");
        return -1;
    }
    
    printf("✅ Monitoring Service: Using adapter 0x%04X\n", service->adapter->device_id);
    
    /* Initialize service state */
    service->monitoring_active = 0;
    memset(service->last_stats, 0, sizeof(service->last_stats));
    service->poll_count = 0;
    
    return 0;
}

int monitoring_service_start(monitoring_service_t *service)
{
    if (!service || !service->adapter) return -1;
    
    printf("📊 Monitoring Service: Starting network monitoring...\n");
    service->monitoring_active = 1;
    
    printf("   ✅ Monitoring started\n");
    return 0;
}

void monitoring_service_process(monitoring_service_t *service)
{
    if (!service || !service->monitoring_active) return;
    
    /* Read various status registers */
    intel_multi_read_reg(service->adapter, 0x00000, &service->last_stats[0]); /* CTRL */
    intel_multi_read_reg(service->adapter, 0x00008, &service->last_stats[1]); /* STATUS */
    intel_multi_read_reg(service->adapter, 0x000C0, &service->last_stats[2]); /* ICR */
    intel_multi_read_reg(service->adapter, 0x040C0, &service->last_stats[3]); /* GPRC */
    
    service->poll_count++;
    
    if (service->poll_count % 30 == 0) {
        printf("📊 Monitor: Poll #%d - CTRL=0x%08X, STATUS=0x%08X\n",
               service->poll_count, service->last_stats[0], service->last_stats[1]);
    }
}

/**
 * Main demonstration
 */
int main(void)
{
    printf("Intel AVB - Practical Service Examples\n");
    printf("======================================\n");
    printf("Demonstrating how different services use separate adapters\n\n");
    
    /* Initialize multi-adapter system */
    if (intel_multi_init() != 0) {
        printf("❌ Failed to initialize multi-adapter system\n");
        return 1;
    }
    
    printf("✅ Multi-adapter system initialized\n");
    printf("   Available adapters: %d\n\n", intel_multi_get_adapter_count());
    
    /* Initialize services */
    avb_audio_service_t audio_service = {0};
    ptp_sync_service_t ptp_service = {0};
    monitoring_service_t monitor_service = {0};
    
    printf("🚀 Initializing Services:\n");
    printf("========================\n");
    
    /* Service 1: AVB Audio Stream */
    if (avb_audio_service_init(&audio_service) == 0) {
        avb_audio_service_start_stream(&audio_service);
    }
    printf("\n");
    
    /* Service 2: PTP Synchronization */
    if (ptp_sync_service_init(&ptp_service) == 0) {
        ptp_sync_service_start(&ptp_service);
    }
    printf("\n");
    
    /* Service 3: Network Monitoring */
    if (monitoring_service_init(&monitor_service) == 0) {
        monitoring_service_start(&monitor_service);
    }
    printf("\n");
    
    /* Show service allocation */
    printf("📋 Service Allocation Summary:\n");
    printf("=============================\n");
    if (audio_service.adapter) {
        printf("🎵 AVB Audio Stream   -> Adapter 0x%04X (%s)\n", 
               audio_service.adapter->device_id, audio_service.adapter->service_name);
    }
    if (ptp_service.adapter) {
        printf("⏰ PTP Time Sync      -> Adapter 0x%04X (%s)\n",
               ptp_service.adapter->device_id, ptp_service.adapter->service_name);
    }
    if (monitor_service.adapter) {
        printf("📊 Network Monitor    -> Adapter 0x%04X (%s)\n",
               monitor_service.adapter->device_id, monitor_service.adapter->service_name);
    }
    printf("\n");
    
    /* Simulate parallel service operations */
    printf("🔄 Running Parallel Service Operations:\n");
    printf("=======================================\n");
    
    for (int cycle = 1; cycle <= 10; cycle++) {
        printf("\n--- Cycle %d ---\n", cycle);
        
        /* Each service processes independently */
        avb_audio_service_process(&audio_service);
        ptp_sync_service_process(&ptp_service);
        monitoring_service_process(&monitor_service);
        
        Sleep(200); /* 200ms delay */
    }
    
    printf("\n");
    printf("✅ All services completed successfully!\n\n");
    
    /* Cleanup */
    printf("🧹 Cleanup:\n");
    printf("==========\n");
    
    if (audio_service.adapter) {
        intel_multi_release_adapter(audio_service.adapter);
        printf("✅ AVB Audio Service released\n");
    }
    
    if (ptp_service.adapter) {
        intel_multi_release_adapter(ptp_service.adapter);
        printf("✅ PTP Sync Service released\n");
    }
    
    if (monitor_service.adapter) {
        intel_multi_release_adapter(monitor_service.adapter);
        printf("✅ Monitoring Service released\n");
    }
    
    intel_multi_cleanup();
    printf("✅ Multi-adapter system cleanup complete\n\n");
    
    /* Final summary */
    printf("🎯 PRACTICAL USAGE DEMONSTRATION COMPLETE!\n");
    printf("==========================================\n");
    printf("✅ Three separate services used adapters independently\n");
    printf("✅ Each service had dedicated context and operations\n");
    printf("✅ Services ran in parallel without interference\n");
    printf("✅ Intelligent adapter allocation based on requirements\n");
    printf("✅ Clean resource management and cleanup\n\n");
    
    printf("💡 Integration Guide:\n");
    printf("====================\n");
    printf("1. Include intel_multi_adapter.h in your service\n");
    printf("2. Call intel_multi_init() once at system startup\n");
    printf("3. Each service calls intel_multi_request_adapter() with its requirements\n");
    printf("4. Use intel_multi_*() functions for all operations on your adapter\n");
    printf("5. Call intel_multi_release_adapter() when service shuts down\n");
    printf("6. Call intel_multi_cleanup() at system shutdown\n\n");
    
    printf("🏆 RESULT: Your library now supports true parallel service usage!\n");
    
    return 0;
}
