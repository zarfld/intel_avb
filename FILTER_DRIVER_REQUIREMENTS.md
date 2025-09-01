# Intel AVB Filter Driver Enhancement Requirements

**Document Version**: 1.0  
**Date**: September 1, 2025  
**Target Audience**: Filter Driver Development Team  
**Status**: **SPECIFICATION** - Required enhancements for complete AVB/TSN support

## 📋 **Executive Summary**

This document specifies required enhancements to `IntelAvbFilter.sys` to support advanced I226/I225 TSN features and AVB/TSN event notification capabilities. The current filter driver provides basic register access - these enhancements enable complete TSN functionality and real-time event handling.

### **Current Filter Driver Status**
- ✅ **Working**: Basic IOCTL communication (`IOCTL_AVB_READ_REGISTER`, `IOCTL_AVB_WRITE_REGISTER`)
- ✅ **Working**: Device enumeration (`IOCTL_AVB_ENUM_ADAPTERS`)
- ✅ **Working**: Credit-based shaper setup (`IOCTL_AVB_SETUP_QAV`)
- ✅ **Working**: Basic PTP timestamping (`IOCTL_AVB_GET_TIMESTAMP`, `IOCTL_AVB_SET_TIMESTAMP`)
- ❌ **Missing**: Advanced TSN features (TAS, Frame Preemption)
- ❌ **Missing**: Enhanced precision timestamping (nanosecond accuracy, stream correlation)
- ❌ **Missing**: Event notification and subscription mechanism

---

## 🎯 **Required IOCTL Enhancements**

### **Priority 1: Time-Aware Shaper (TAS) Support** ⭐ **HIGH PRIORITY**

#### **Use Case**: AVB Audio/Video Streaming with Guaranteed Latency
Real-time audio streaming requires predictable, bounded latency. TAS enables time-based gate control to guarantee bandwidth and latency for critical AVB streams while allowing best-effort traffic in remaining time slots.

#### **Business Requirement**: 
- Professional audio applications require <2ms latency guarantees
- Video streaming needs predictable frame delivery timing
- TSN compliance for industrial and automotive AVB applications

#### **Proposed IOCTL**: `IOCTL_AVB_SETUP_TAS`

```c
#define IOCTL_AVB_SETUP_TAS CTL_CODE(FILE_DEVICE_NETWORK, 0x820, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* TAS Gate Control Entry */
typedef struct {
    uint8_t gate_states;        /* Gate open/close state for each queue (bit mask) */
                               /* Bit 0 = Queue 0, Bit 1 = Queue 1, etc. */
                               /* 1 = Gate Open, 0 = Gate Closed */
    uint32_t time_interval;     /* Time interval in nanoseconds */
} avb_tas_gate_entry_t;

/* TAS Configuration Structure */
typedef struct {
    uint32_t adapter_index;     /* Target adapter index */
    uint64_t base_time;         /* Base time in nanoseconds (PTP time) */
    uint32_t cycle_time;        /* Cycle time in nanoseconds */
    uint32_t cycle_time_extension; /* Cycle time extension in nanoseconds */
    uint8_t gate_list_length;   /* Number of gate control entries (1-64) */
    avb_tas_gate_entry_t gate_list[64]; /* Gate control list */
    
    /* Configuration flags */
    uint8_t config_change;      /* Enable configuration change */
    uint8_t config_change_error; /* Configuration change error (output) */
} avb_tas_config_t;
```

#### **Required Register Programming** (I226 Specific):
```c
/* Internal filter driver implementation would program: */
/* - QBVCTRL (0x3570): Enable/disable TAS, set list length */
/* - QBVBASETIME_L/H (0x3574/0x3578): Base time registers */
/* - QBVCYCLETIME (0x357C): Cycle time */
/* - QBVGATECONTROL[0-63] (0x3580-0x367C): Gate control entries */
```

---

### **Priority 2: Frame Preemption Support** ⭐ **HIGH PRIORITY**

#### **Use Case**: Ultra-Low Latency AVB Applications
Frame preemption allows high-priority AVB frames to interrupt transmission of lower-priority frames, dramatically reducing worst-case latency for critical audio/control streams.

#### **Business Requirement**:
- Professional audio mixing consoles require <1ms control response
- Industrial control systems need deterministic response times
- Gaming audio requires ultra-low latency for competitive applications

#### **Proposed IOCTL**: `IOCTL_AVB_SETUP_FRAME_PREEMPTION`

```c
#define IOCTL_AVB_SETUP_FRAME_PREEMPTION CTL_CODE(FILE_DEVICE_NETWORK, 0x821, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct {
    uint32_t adapter_index;         /* Target adapter index */
    uint8_t preemptible_queues;     /* Bit mask of preemptible queues */
                                   /* Bit 0 = Queue 0 preemptible, etc. */
    uint16_t minimum_fragment_size; /* Minimum fragment size (64-512 bytes) */
    uint8_t enable_verify_disable;  /* Enable/disable frame preemption verify */
    uint8_t verify_disable_time;    /* Verify disable time (1-128 ms) */
    uint8_t additional_fragment_size; /* Additional fragment size (0-3) */
    
    /* Status outputs */
    uint8_t verification_status;    /* Verification status (output) */
    uint8_t preemption_active;      /* Preemption currently active (output) */
} avb_frame_preemption_config_t;
```

#### **Required Register Programming** (I226 Specific):
```c
/* Internal filter driver implementation would program: */
/* - FPQCTRL (0x3590): Frame preemption control */
/* - FPFRAGSIZE (0x3594): Fragment size configuration */
/* - FPVERIFY (0x3598): Verification configuration */
```

---

### **Priority 3: Enhanced Hardware Timestamping** ⭐ **MEDIUM PRIORITY**
*(Note: Basic PTP timestamping already working via `IOCTL_AVB_GET_TIMESTAMP`/`IOCTL_AVB_SET_TIMESTAMP`)*

#### **Use Case**: Precision gPTP Synchronization and AVB Stream Alignment
Enhanced timestamping provides **nanosecond-precision timestamps** for gPTP synchronization and AVB stream sample alignment across multiple devices, **beyond the basic PTP functionality currently available**.

#### **Business Requirement**:
- Multi-room audio systems require sample-accurate synchronization
- Professional recording requires precise timestamp correlation  
- Industrial automation needs deterministic timing validation
- Current basic PTP: ✅ Working but limited precision
- **Enhancement needed**: Nanosecond precision, stream packet correlation, multiple timestamp types

#### **Proposed IOCTL**: `IOCTL_AVB_ENHANCED_TIMESTAMP`

```c
#define IOCTL_AVB_ENHANCED_TIMESTAMP CTL_CODE(FILE_DEVICE_NETWORK, 0x822, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef enum {
    AVB_TIMESTAMP_TX_SYNC = 0,      /* PTP Sync message timestamp */
    AVB_TIMESTAMP_TX_DELAY_REQ,     /* PTP Delay Request timestamp */
    AVB_TIMESTAMP_RX_SYNC,          /* PTP Sync message receive timestamp */
    AVB_TIMESTAMP_RX_DELAY_REQ,     /* PTP Delay Request receive timestamp */
    AVB_TIMESTAMP_SYSTEM_TIME,      /* Current system time */
    AVB_TIMESTAMP_AVB_STREAM        /* AVB stream packet timestamp */
} avb_timestamp_type_t;

typedef struct {
    uint32_t adapter_index;         /* Target adapter index */
    avb_timestamp_type_t type;      /* Timestamp type to retrieve */
    uint16_t queue_index;           /* Queue index (for stream timestamps) */
    
    /* Timestamp outputs */
    uint64_t timestamp_ns;          /* Timestamp in nanoseconds */
    uint32_t sequence_id;           /* Sequence ID for correlation */
    uint8_t timestamp_valid;        /* Timestamp validity flag */
} avb_enhanced_timestamp_t;
```

---

## 🔔 **Event Notification System** ⭐ **HIGH PRIORITY**

### **Use Case**: Real-Time AVB/TSN Event Handling
AVB applications need immediate notification of network events (stream connect/disconnect, timing changes, errors) to maintain audio continuity and user experience.

#### **Business Requirements**:
- Audio applications must detect stream disconnections within 10ms
- Network topology changes require immediate adaptation
- gPTP timing changes need real-time service notification
- TSN configuration errors require immediate alert and recovery

### **Proposed Event Subscription IOCTL**: `IOCTL_AVB_SUBSCRIBE_EVENTS`

```c
#define IOCTL_AVB_SUBSCRIBE_EVENTS CTL_CODE(FILE_DEVICE_NETWORK, 0x830, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef enum {
    AVB_EVENT_STREAM_CONNECT       = 0x0001,  /* AVB stream connection established */
    AVB_EVENT_STREAM_DISCONNECT    = 0x0002,  /* AVB stream disconnected */
    AVB_EVENT_GPTP_SYNC_CHANGE     = 0x0004,  /* gPTP synchronization status change */
    AVB_EVENT_GPTP_MASTER_CHANGE   = 0x0008,  /* gPTP grandmaster change */
    AVB_EVENT_TAS_CONFIG_ERROR     = 0x0010,  /* TAS configuration error */
    AVB_EVENT_PREEMPTION_STATUS    = 0x0020,  /* Frame preemption status change */
    AVB_EVENT_LINK_STATUS_CHANGE   = 0x0040,  /* Physical link status change */
    AVB_EVENT_TIMESTAMP_ERROR      = 0x0080,  /* Hardware timestamp error */
    AVB_EVENT_QUEUE_OVERFLOW       = 0x0100,  /* Queue overflow/underflow */
    AVB_EVENT_BANDWIDTH_VIOLATION  = 0x0200,  /* Bandwidth allocation violation */
    AVB_EVENT_ALL                  = 0xFFFF   /* Subscribe to all events */
} avb_event_type_t;

typedef struct {
    uint32_t adapter_index;         /* Target adapter index */
    uint32_t event_mask;            /* Bit mask of events to subscribe to */
    HANDLE event_handle;            /* Windows event handle for notification */
    uint32_t process_id;            /* Subscribing process ID */
    uint8_t enable_subscription;    /* Enable/disable subscription */
} avb_event_subscription_t;
```

### **Proposed Event Data Retrieval IOCTL**: `IOCTL_AVB_GET_EVENT_DATA`

```c
#define IOCTL_AVB_GET_EVENT_DATA CTL_CODE(FILE_DEVICE_NETWORK, 0x831, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct {
    uint64_t timestamp_ns;          /* Event timestamp */
    uint32_t event_type;            /* Type of event that occurred */
    uint32_t adapter_index;         /* Adapter that generated the event */
    uint32_t data_length;           /* Length of event-specific data */
    uint8_t event_data[256];        /* Event-specific data payload */
} avb_event_data_t;

typedef struct {
    uint32_t adapter_index;         /* Target adapter index */
    uint32_t max_events;            /* Maximum events to retrieve */
    uint32_t events_returned;       /* Number of events returned (output) */
    avb_event_data_t events[16];    /* Event data array */
} avb_event_retrieval_t;
```

### **Event-Specific Data Structures**:

```c
/* Stream Connection Event Data */
typedef struct {
    uint64_t stream_id;             /* AVB stream ID */
    uint8_t destination_mac[6];     /* Destination MAC address */
    uint16_t vlan_id;               /* VLAN ID */
    uint8_t stream_format;          /* Stream format (AAF, CRF, etc.) */
    uint32_t samples_per_frame;     /* Audio samples per frame */
    uint32_t sample_rate;           /* Audio sample rate */
} avb_stream_event_data_t;

/* gPTP Synchronization Event Data */
typedef struct {
    uint8_t grandmaster_id[8];      /* Current grandmaster clock ID */
    int64_t offset_from_master;     /* Offset from master in nanoseconds */
    int8_t log_sync_interval;       /* Current sync interval */
    uint8_t sync_state;             /* Synchronization state */
} avb_gptp_event_data_t;

/* TAS Configuration Error Event Data */
typedef struct {
    uint32_t error_code;            /* TAS error code */
    uint8_t gate_list_index;        /* Index of problematic gate entry */
    uint64_t config_change_time;    /* Time when error occurred */
} avb_tas_error_event_data_t;
```

---

## 🔧 **Implementation Architecture**

### **Filter Driver Internal Architecture**

```c
/* Suggested filter driver internal structure */
typedef struct {
    /* Event Management */
    KEVENT event_notification[MAX_SUBSCRIBERS];
    LIST_ENTRY event_queue[MAX_ADAPTERS];
    KSPIN_LOCK event_lock;
    
    /* TAS State Management */
    avb_tas_config_t tas_config[MAX_ADAPTERS];
    KTIMER tas_timer[MAX_ADAPTERS];
    
    /* Frame Preemption State */
    avb_frame_preemption_config_t fp_config[MAX_ADAPTERS];
    
    /* Timestamp Management */
    LARGE_INTEGER timestamp_frequency;
    KEVENT timestamp_event[MAX_ADAPTERS];
    
    /* Event Subscriptions */
    avb_event_subscription_t subscriptions[MAX_SUBSCRIBERS];
    uint32_t subscription_count;
    
} intel_avb_filter_context_t;
```

### **Register Programming Patterns**

Each IOCTL implementation should follow these patterns:

1. **Validate Input Parameters**
   - Check adapter index bounds
   - Validate configuration values against hardware limits
   - Verify proper alignment and data structure integrity

2. **Hardware Register Access**
   - Use existing register read/write infrastructure
   - Program registers in correct sequence (disable → configure → enable)
   - Verify configuration was applied successfully

3. **State Management**
   - Update internal driver state
   - Enable/configure hardware interrupts if needed
   - Set up timers or DPCs for periodic operations

4. **Event Generation**
   - Generate appropriate events for configuration changes
   - Update event subscribers with status changes
   - Maintain event history for debugging

---

## 📊 **Testing and Validation Requirements**

### **TAS Validation Test Cases**

```c
/* Test Case 1: Basic TAS Configuration */
avb_tas_config_t basic_tas = {
    .adapter_index = 0,
    .base_time = 0,                     /* Start immediately */
    .cycle_time = 1000000,              /* 1ms cycle */
    .gate_list_length = 2,
    .gate_list = {
        {.gate_states = 0x01, .time_interval = 500000},  /* Queue 0 open for 500µs */
        {.gate_states = 0x00, .time_interval = 500000}   /* All queues closed for 500µs */
    }
};

/* Test Case 2: Multi-Queue TAS with Audio Priority */
avb_tas_config_t audio_tas = {
    .adapter_index = 0,
    .base_time = 0,
    .cycle_time = 125000,               /* 125µs cycle (8kHz audio) */
    .gate_list_length = 4,
    .gate_list = {
        {.gate_states = 0x80, .time_interval = 31250},   /* Queue 7 (audio) - 25% */
        {.gate_states = 0x40, .time_interval = 31250},   /* Queue 6 (video) - 25% */
        {.gate_states = 0x3F, .time_interval = 31250},   /* Queues 0-5 (data) - 25% */
        {.gate_states = 0x00, .time_interval = 31250}    /* Guard band - 25% */
    }
};
```

### **Event Notification Test Cases**

```c
/* Test Case 1: Stream Connection Detection */
/* 1. Subscribe to AVB_EVENT_STREAM_CONNECT */
/* 2. Generate test AVB stream packet */
/* 3. Verify event notification within 10ms */
/* 4. Validate event data contains correct stream info */

/* Test Case 2: gPTP Synchronization Change */
/* 1. Subscribe to AVB_EVENT_GPTP_SYNC_CHANGE */
/* 2. Simulate grandmaster change */
/* 3. Verify event notification */
/* 4. Validate timing offset information */
```

---

## 🚨 **Migration and Compatibility**

### **Backward Compatibility Requirements**

1. **Existing IOCTL Support**: All current IOCTLs must continue working unchanged
2. **Graceful Degradation**: New features should fail gracefully on older hardware
3. **Version Detection**: Provide mechanism to detect filter driver capabilities

### **Suggested Capability Detection IOCTL**

```c
#define IOCTL_AVB_GET_CAPABILITIES CTL_CODE(FILE_DEVICE_NETWORK, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct {
    uint32_t driver_version;            /* Filter driver version */
    uint32_t supported_features;        /* Bit mask of supported features */
    uint32_t max_tas_entries;           /* Maximum TAS gate entries */
    uint32_t max_event_subscribers;     /* Maximum event subscribers */
    uint8_t supported_adapters[16];     /* Supported adapter device IDs */
} avb_driver_capabilities_t;

#define AVB_FEATURE_TAS                 0x0001
#define AVB_FEATURE_FRAME_PREEMPTION    0x0002
#define AVB_FEATURE_ENHANCED_TIMESTAMPS 0x0004
#define AVB_FEATURE_EVENT_NOTIFICATION  0x0008
#define AVB_FEATURE_MULTI_QUEUE         0x0010
```

---

## 🎯 **Implementation Priority and Timeline**

### **Phase 1** (Critical for AVB functionality):
1. `IOCTL_AVB_SETUP_TAS` - Enables guaranteed latency for audio/video
2. `IOCTL_AVB_SUBSCRIBE_EVENTS` + `IOCTL_AVB_GET_EVENT_DATA` - Enables real-time event handling

### **Phase 2** (Enhanced performance):
1. `IOCTL_AVB_SETUP_FRAME_PREEMPTION` - Ultra-low latency applications
2. `IOCTL_AVB_ENHANCED_TIMESTAMP` - Precision timing applications

### **Phase 3** (Management and diagnostics):
1. `IOCTL_AVB_GET_CAPABILITIES` - Feature detection and compatibility
2. Additional diagnostic and management IOCTLs

---

## 📋 **Summary for Filter Driver Team**

### **Required Deliverables**:

1. **Enhanced IntelAvbFilter.sys** with new IOCTL support
2. **Updated IOCTL interface headers** with new definitions
3. **Test utilities** for validating new functionality
4. **Documentation** of register programming sequences implemented
5. **Performance validation** showing TSN timing guarantees

### **Success Criteria**:

- [ ] TAS configuration achieves <2ms guaranteed latency for audio streams
- [ ] Frame preemption reduces worst-case latency to <1ms
- [ ] Event notification latency <10ms for all event types
- [ ] All existing functionality remains unchanged
- [ ] New IOCTLs pass comprehensive validation test suite

### **Integration with AVB Stack**:

The enhanced filter driver will enable the AVB framework in this repository to provide complete TSN functionality, supporting professional audio applications, industrial automation, and automotive AVB use cases.

---

**Document Prepared By**: Intel AVB Framework Development Team  
**Target Implementation**: Enhanced IntelAvbFilter.sys  
**Business Justification**: Complete AVB/TSN support for professional audio and industrial applications

This specification provides everything needed for the filter driver team to implement complete I226/I225 TSN support with real-time event handling capabilities.
