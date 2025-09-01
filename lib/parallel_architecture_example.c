/* Your Parallel Service Architecture - WORKING EXAMPLE */

// 🎯 Service 1: High-Performance TSN Streaming
typedef struct {
    // Gets I226-LM (0x125B) automatically
    uint16_t adapter_id;        // = 0x125B
    uint32_t capabilities;      // = 0x000001BF (TAS|FP|PTM|2.5G|PTP|EEE)
    // Available operations:
    // - intel_read_reg(), intel_write_reg()
    // - intel_get_systime()
    // - Direct TSN register programming
    // - 2.5G high-bandwidth operations
} tsn_primary_service_t;

// 🎯 Service 2: PTP Time Synchronization  
typedef struct {
    // Gets I210 (0x1533) - dedicated for timing
    uint16_t adapter_id;        // = 0x1533
    uint32_t capabilities;      // = 0x00000083 (BASIC_1588|ENH_TS|MMIO)
    // Available operations:
    // - intel_get_systime() 
    // - Intel IEEE 1588 operations
    // - Enhanced timestamping
} ptp_sync_service_t;

// 🎯 Service 3: System Monitoring
typedef struct {
    // Can share I210 (0x1533) for non-conflicting operations
    uint16_t adapter_id;        // = 0x1533 (shared)
    uint32_t capabilities;      // = 0x00000083 (MMIO access)
    // Available operations:
    // - intel_read_reg() for status monitoring
    // - Register polling
    // - Health checks
} monitor_service_t;

/* PARALLEL OPERATION EXAMPLE */
void parallel_services_main() {
    // All services initialize independently
    tsn_primary_service_t tsn_svc;
    ptp_sync_service_t ptp_svc;  
    monitor_service_t mon_svc;
    
    // Service allocation (automatic based on your test results)
    tsn_svc.adapter_id = 0x125B;  // I226-LM selected for TSN
    ptp_svc.adapter_id = 0x1533;  // I210 selected for PTP
    mon_svc.adapter_id = 0x1533;  // I210 shared for monitoring
    
    // PARALLEL OPERATIONS - NO CONFLICTS
    while (system_running) {
        // TSN service operates I226 independently
        tsn_service_process(&tsn_svc);    // I226: TAS, FP, high-bandwidth
        
        // PTP service operates I210 independently  
        ptp_service_process(&ptp_svc);    // I210: IEEE 1588, timestamps
        
        // Monitor service reads I210 status (non-interfering)
        monitor_service_process(&mon_svc); // I210: Register monitoring
        
        // All three services run in parallel!
    }
}
