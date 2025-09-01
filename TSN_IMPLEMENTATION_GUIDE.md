# Intel AVB - TSN Implementation Guide

**Document Version**: 1.0  
**Date**: September 1, 2025  
**Target Audience**: AVB Stack Development Team, Filter Driver Developers, Hardware Engineers  
**Document Type**: **Framework Reference Implementation Guide**

## 📋 **Executive Summary**

This guide provides comprehensive TSN (Time-Sensitive Networking) implementation **framework and reference patterns** for Intel Ethernet Controllers (I210, I217, I219, I225, I226). The guide enables production AVB stack development by providing complete hardware programming sequences, register access patterns, and validation procedures.

### **Key Framework Achievements**
- **✅ Hardware Access Framework**: Multi-adapter reference implementation with documented patterns
- **✅ Service Framework Patterns**: Intelligent adapter allocation demonstration patterns (reference implementation)
- **✅ Complete Register Definitions**: Auto-generated headers from official Intel specifications
- **✅ Windows Integration Framework**: IOCTL interface patterns and communication framework

**⚠️ Important**: This repository provides **reference implementation and framework patterns** - not production services. Production AVB stack implementation should use these patterns in separate repository.

---

## 🏗️ **Architecture Overview**

### **Hardware Foundation**
```
Intel Ethernet Controllers Supported:
├── I226-LM (Premium TSN) - Priority: 100
│   ├── Full TSN Feature Set
│   ├── Time-Aware Shaper (TAS)
│   ├── Frame Preemption (FP)
│   └── Precision Time Protocol (PTP)
├── I225 (Advanced TSN) - Priority: 90
│   ├── Enhanced TSN Features
│   └── High-Performance Timestamping
├── I219-LM (Standard TSN) - Priority: 60
│   ├── Basic TSN Support
│   └── Standard PTP Features
└── I210 (Legacy AVB) - Priority: 50
    ├── IEEE 802.1AS Support
    └── Basic AVB Features
```

### **Service Architecture Pattern**
```
AVB Stack Services:
├── Audio Service → I226 (TSN optimization)
├── gPTP Service → I210 (efficient dedicated timing)
├── Network Monitor → Available adapter
└── Management → Shared access patterns
```

---

## 🎯 **TSN Feature Implementation Matrix**

| Feature | I226-LM | I225 | I219-LM | I210 | Implementation Status |
|---------|---------|------|---------|------|--------------------|
| **Time-Aware Shaper (TAS)** | ✅ Full | ✅ Full | ⚠️ Limited | ❌ None | Register headers ✅, IOCTL needed |
| **Frame Preemption (FP)** | ✅ Full | ✅ Full | ❌ None | ❌ None | Register headers ✅, IOCTL needed |
| **Credit-Based Shaper (CBS)** | ✅ Full | ✅ Full | ✅ Basic | ✅ Basic | **Working** ✅ |
| **PTP Hardware Timestamping** | ✅ Full | ✅ Full | ✅ Full | ✅ Full | Register headers ✅, IOCTL partial |
| **Queue Priority Mapping** | ✅ 8 Queues | ✅ 8 Queues | ✅ 4 Queues | ✅ 4 Queues | **Working** ✅ |

---

## 📖 **Register Programming Sequences**

### **1. Time-Aware Shaper (TAS) Configuration**

**Target Controllers**: I226, I225  
**Register Header**: `spec/intel-ethernet-regs/gen/i226_regs.h`

#### **I226 TAS Programming Sequence**

```c
/* Step 1: Disable TAS during configuration */
#include "../spec/intel-ethernet-regs/gen/i226_regs.h"

int intel_i226_configure_tas(device_t *dev, struct tsn_tas_config *config) {
    uint32_t reg_val;
    
    /* 1. Disable TAS (I226_QBVCTRL register) */
    intel_read_reg(dev, I226_QBVCTRL, &reg_val);
    reg_val &= ~I226_QBVCTRL_ENABLE;
    intel_write_reg(dev, I226_QBVCTRL, reg_val);
    
    /* 2. Configure Base Time (I226_QBVTXCTLQ) */
    intel_write_reg(dev, I226_QBVTXCTL_BASETIME_L, 
                    (uint32_t)(config->base_time & 0xFFFFFFFF));
    intel_write_reg(dev, I226_QBVTXCTL_BASETIME_H, 
                    (uint32_t)(config->base_time >> 32));
    
    /* 3. Configure Cycle Time */
    intel_write_reg(dev, I226_QBVTXCTL_CYCLETIME, config->cycle_time);
    
    /* 4. Configure Gate Control List */
    for (int i = 0; i < config->list_length; i++) {
        uint32_t gate_control = 0;
        gate_control |= (config->gate_list[i].gate_states & 0xFF);
        gate_control |= ((config->gate_list[i].time_interval & 0xFFFFFF) << 8);
        
        intel_write_reg(dev, I226_QBVTXCTL_GATE_ENTRY(i), gate_control);
    }
    
    /* 5. Set List Length */
    intel_read_reg(dev, I226_QBVCTRL, &reg_val);
    reg_val &= ~I226_QBVCTRL_LIST_LENGTH_MASK;
    reg_val |= ((config->list_length - 1) << I226_QBVCTRL_LIST_LENGTH_SHIFT);
    intel_write_reg(dev, I226_QBVCTRL, reg_val);
    
    /* 6. Enable TAS */
    reg_val |= I226_QBVCTRL_ENABLE;
    intel_write_reg(dev, I226_QBVCTRL, reg_val);
    
    return 0;
}
```

#### **Required IOCTL Enhancement**
```c
/* Filter Driver Implementation Needed */
#define IOCTL_AVB_SETUP_TAS CTL_CODE(FILE_DEVICE_NETWORK, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct {
    uint64_t base_time;        /* Base time in nanoseconds */
    uint32_t cycle_time;       /* Cycle time in nanoseconds */
    uint32_t list_length;      /* Number of gate control entries */
    struct {
        uint8_t gate_states;   /* Gate states for queues (bit mask) */
        uint32_t time_interval; /* Time interval in nanoseconds */
    } gate_list[MAX_TAS_ENTRIES];
} tas_config_t;
```

### **2. Frame Preemption (FP) Configuration**

**Target Controllers**: I226, I225  
**Register Header**: `spec/intel-ethernet-regs/gen/i226_regs.h`

#### **I226 Frame Preemption Setup**

```c
int intel_i226_configure_frame_preemption(device_t *dev, uint8_t preemptible_queues) {
    uint32_t reg_val;
    
    /* 1. Configure Preemption Control (I226_FPQCTRL) */
    intel_read_reg(dev, I226_FPQCTRL, &reg_val);
    
    /* Set preemptible queue mask */
    reg_val &= ~I226_FPQCTRL_PREEMPTIBLE_MASK;
    reg_val |= (preemptible_queues << I226_FPQCTRL_PREEMPTIBLE_SHIFT);
    
    /* Enable frame preemption */
    reg_val |= I226_FPQCTRL_ENABLE;
    
    intel_write_reg(dev, I226_FPQCTRL, reg_val);
    
    /* 2. Configure minimum fragment size */
    intel_read_reg(dev, I226_FPFRAGSIZE, &reg_val);
    reg_val &= ~I226_FPFRAGSIZE_MASK;
    reg_val |= (64 << I226_FPFRAGSIZE_SHIFT); /* 64-byte minimum */
    intel_write_reg(dev, I226_FPFRAGSIZE, reg_val);
    
    return 0;
}
```

### **3. Credit-Based Shaper (CBS) Configuration** ✅ **WORKING**

**Target Controllers**: All (I226, I225, I219, I210)  
**Status**: Already implemented and tested

```c
/* From lib/intel_common.c - Already Working */
int intel_setup_credit_based_shaper(device_t *dev, uint32_t queue, struct cbs_params *params) {
    switch (dev->device_id) {
        case INTEL_I226_LM:
            return intel_i226_setup_cbs(dev, queue, params);
        case INTEL_I225_V:
            return intel_i225_setup_cbs(dev, queue, params);
        case INTEL_I219_LM:
            return intel_i219_setup_cbs(dev, queue, params);
        case INTEL_I210_COPPER:
            return intel_i210_setup_cbs(dev, queue, params);
        default:
            return -1;
    }
}
```

### **4. PTP Hardware Timestamping** ⚠️ **PARTIAL**

**Target Controllers**: All  
**Current Status**: Basic IOCTLs working, enhanced timestamping needed

```c
/* Enhanced PTP Timestamping - Requires IOCTL Implementation */
int intel_get_hardware_timestamp(device_t *dev, uint32_t *timestamp_ns) {
    uint32_t systiml, systimh;
    
    /* Read system time registers */
    intel_read_reg(dev, SYSTIML, &systiml);
    intel_read_reg(dev, SYSTIMH, &systimh);
    
    /* Combine into 64-bit timestamp */
    uint64_t timestamp = ((uint64_t)systimh << 32) | systiml;
    *timestamp_ns = (uint32_t)(timestamp / 1000000); /* Convert to milliseconds */
    
    return 0;
}
```

---

## 🔧 **Hardware Validation Procedures**

### **Test Framework Integration**

All TSN features can be validated using the proven test framework:

```bash
# Build complete test suite
cd lib
.\build_windows.bat

# Run hardware validation
.\build\test_hardware.exe

# Validate multi-adapter TSN setup
.\build\test_multi_adapter.exe

# Test service allocation with TSN features
.\build\test_service_direct.exe
```

### **Expected Test Results**

```
Intel I226 TSN Validation:
✅ TAS Configuration: QBVCTRL register accessible
✅ Frame Preemption: FPQCTRL register accessible  
✅ CBS Working: Credit-based shaper functional
✅ PTP Timestamps: Hardware timestamping operational
✅ Queue Priority: 8-queue traffic management working

Intel I210 AVB Validation:
✅ CBS Working: Basic credit-based shaper functional
✅ PTP Basic: Hardware timestamping operational
✅ Queue Priority: 4-queue traffic management working
⚠️ TAS/FP: Not supported (hardware limitation)
```

---

## 🚨 **Filter Driver Enhancement Requirements** (External Dependency)

**Current Status**: Basic IOCTLs working ✅, Advanced TSN IOCTLs need implementation ⚠️  
**Required for Full TSN**: Complete implementation of TSN-specific IOCTLs in filter driver

**📋 COMPREHENSIVE SPECIFICATION AVAILABLE**: See **[FILTER_DRIVER_REQUIREMENTS.md](FILTER_DRIVER_REQUIREMENTS.md)** for complete technical specification including:
- Detailed IOCTL definitions with data structures
- Use cases and business requirements  
- Register programming sequences
- Event notification system design
- Test cases and validation requirements
- Implementation timeline and priorities

### **Missing IOCTL Implementations** (External Dependency)

For complete TSN functionality, the following IOCTLs need implementation in `IntelAvbFilter.sys`:

#### **Priority 1: Advanced TSN Features**

#### **1. Time-Aware Shaper IOCTL** ⭐ **HIGH PRIORITY**
```c
#define IOCTL_AVB_SETUP_TAS CTL_CODE(FILE_DEVICE_NETWORK, 0x820, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* Use Case: AVB audio/video streaming with guaranteed <2ms latency */
/* Requirement: Professional audio applications and TSN compliance */
typedef struct {
    uint32_t adapter_index;
    uint64_t base_time;             /* Base time in nanoseconds (PTP time) */
    uint32_t cycle_time;            /* Cycle time in nanoseconds */
    uint8_t gate_list_length;       /* Number of gate control entries */
    avb_tas_gate_entry_t gate_list[64]; /* Gate control list */
} avb_tas_config_t;
```

#### **2. Frame Preemption IOCTL** ⭐ **HIGH PRIORITY**
```c
#define IOCTL_AVB_SETUP_FRAME_PREEMPTION CTL_CODE(FILE_DEVICE_NETWORK, 0x821, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* Use Case: Ultra-low latency applications requiring <1ms response */
/* Requirement: Professional audio mixing and industrial control */
typedef struct {
    uint32_t adapter_index;
    uint8_t preemptible_queues;     /* Bit mask of preemptible queues */
    uint16_t minimum_fragment_size; /* Minimum fragment size (64-512 bytes) */
    uint8_t verify_disable_time;   /* Verification disable time */
} avb_frame_preemption_config_t;
```

#### **3. Enhanced Timestamp IOCTL** ⭐ **MEDIUM PRIORITY**
```c
#define IOCTL_AVB_ENHANCED_TIMESTAMP CTL_CODE(FILE_DEVICE_NETWORK, 0x822, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* Use Case: Precision gPTP synchronization and stream alignment */
/* Requirement: Multi-device audio synchronization and timing validation */
typedef struct {
    uint32_t adapter_index;
    uint32_t timestamp_type;        /* Type of timestamp to retrieve */
    uint64_t timestamp_ns;          /* Timestamp in nanoseconds (output) */
    uint8_t timestamp_valid;        /* Timestamp validity flag (output) */
} avb_enhanced_timestamp_t;
```

#### **Priority 2: Event Notification System** ⭐ **HIGH PRIORITY**

#### **4. Event Subscription IOCTL**
```c
#define IOCTL_AVB_SUBSCRIBE_EVENTS CTL_CODE(FILE_DEVICE_NETWORK, 0x830, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* Use Case: Real-time notification of AVB/TSN network events */
/* Requirement: <10ms event notification for stream changes, timing updates */
typedef struct {
    uint32_t adapter_index;
    uint32_t event_mask;            /* Bit mask of events to subscribe to */
    HANDLE event_handle;            /* Windows event handle for notification */
    uint8_t enable_subscription;    /* Enable/disable subscription */
} avb_event_subscription_t;

/* Event Types */
#define AVB_EVENT_STREAM_CONNECT    0x0001  /* AVB stream connection */
#define AVB_EVENT_STREAM_DISCONNECT 0x0002  /* AVB stream disconnection */
#define AVB_EVENT_GPTP_SYNC_CHANGE  0x0004  /* gPTP synchronization change */
#define AVB_EVENT_TAS_CONFIG_ERROR  0x0010  /* TAS configuration error */
#define AVB_EVENT_LINK_STATUS_CHANGE 0x0040 /* Physical link status change */
```

#### **5. Event Data Retrieval IOCTL**
```c
#define IOCTL_AVB_GET_EVENT_DATA CTL_CODE(FILE_DEVICE_NETWORK, 0x831, METHOD_BUFFERED, FILE_ANY_ACCESS)

/* Use Case: Retrieve detailed event information for service response */
typedef struct {
    uint32_t adapter_index;
    uint32_t max_events;            /* Maximum events to retrieve */
    uint32_t events_returned;       /* Number of events returned (output) */
    avb_event_data_t events[16];    /* Event data array */
} avb_event_retrieval_t;
```

#### **3. Enhanced Timestamp IOCTL**
```c
#define IOCTL_AVB_GET_TIMESTAMP CTL_CODE(FILE_DEVICE_NETWORK, 0x812, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct {
    uint64_t system_time_ns;       /* Current system time */
    uint64_t hardware_time_ns;     /* Hardware timestamp */
    uint32_t timestamp_accuracy;   /* Timestamp accuracy indicator */
} ioctl_timestamp_t;
```

### **Implementation Priority**
1. **HIGH**: `IOCTL_AVB_SETUP_TAS` - Enables time-aware scheduling
2. **HIGH**: `IOCTL_AVB_GET_TIMESTAMP` - Enhanced precision timing  
3. **MEDIUM**: `IOCTL_AVB_SETUP_FP` - Frame preemption for low latency

---

## 📊 **Register Header Reference**

### **Complete Register Map Access**

All register definitions are available from the auto-generated headers:

```c
/* Device-Specific Headers (Auto-Generated) */
#include "../spec/intel-ethernet-regs/gen/i210_regs.h"    /* I210 registers */
#include "../spec/intel-ethernet-regs/gen/i217_regs.h"    /* I217 registers */
#include "../spec/intel-ethernet-regs/gen/i219_regs.h"    /* I219 registers */
#include "../spec/intel-ethernet-regs/gen/i225_regs.h"    /* I225 registers */
#include "../spec/intel-ethernet-regs/gen/i226_regs.h"    /* I226 registers */
```

### **Key Register Categories**

| Category | I226 Registers | I225 Registers | I219 Registers | I210 Registers |
|----------|----------------|----------------|----------------|----------------|
| **TAS Control** | `I226_QBVCTRL` | `I225_QBVCTRL` | N/A | N/A |
| **Frame Preemption** | `I226_FPQCTRL` | `I225_FPQCTRL` | N/A | N/A |
| **CBS Control** | `I226_TQAVCTRL` | `I225_TQAVCTRL` | `I219_TQAVCTRL` | `I210_TQAVCTRL` |
| **PTP Timestamps** | `I226_SYSTIML/H` | `I225_SYSTIML/H` | `I219_SYSTIML/H` | `I210_SYSTIML/H` |
| **Queue Management** | `I226_TXDCTL` | `I225_TXDCTL` | `I219_TXDCTL` | `I210_TXDCTL` |

---

## 🎯 **AVB Stack Integration Points**

### **Service Architecture Bridge**

The proven service architecture provides perfect integration points for separate AVB stack:

```c
/* Service Allocation Pattern for AVB Stack */
typedef struct {
    device_t *audio_service_adapter;      /* I226 - TSN optimized */
    device_t *timing_service_adapter;     /* I210 - gPTP dedicated */
    device_t *management_adapter;         /* Available - monitoring */
} avb_service_allocation_t;

/* Integration Function */
int avb_stack_initialize_services(avb_service_allocation_t *services) {
    /* Use proven intel_allocate_service_adapter() pattern */
    services->audio_service_adapter = intel_allocate_service_adapter(SERVICE_AUDIO);
    services->timing_service_adapter = intel_allocate_service_adapter(SERVICE_TIMING);
    services->management_adapter = intel_allocate_service_adapter(SERVICE_MANAGEMENT);
    
    return (services->audio_service_adapter && services->timing_service_adapter) ? 0 : -1;
}
```

### **Hardware Access Integration**

```c
/* Direct Hardware Access for AVB Stack */
static inline int avb_stack_read_register(device_t *dev, uint32_t offset, uint32_t *value) {
    return intel_read_reg(dev, offset, value);  /* Uses proven IOCTL path */
}

static inline int avb_stack_write_register(device_t *dev, uint32_t offset, uint32_t value) {
    return intel_write_reg(dev, offset, value); /* Uses proven IOCTL path */
}
```

---

## 🔄 **Development Workflow**

### **For AVB Stack Development Team**

1. **Use This Repository As Reference**
   ```bash
   git clone <intel-avb-repo>
   cd intel_avb
   
   # Build reference implementation
   cd lib
   .\build_windows.bat
   
   # Test hardware access patterns
   .\build\test_hardware.exe
   ```

2. **Copy Service Architecture Patterns**
   - Use `lib/intel_common.c` service allocation patterns
   - Copy `lib/intel_windows.c` IOCTL communication code
   - Reference `include/avb_ioctl.h` for IOCTL definitions

3. **Integrate Register Headers**
   ```bash
   git submodule add https://github.com/intel-ethernet-regs intel-regs
   # Use auto-generated headers for register access
   ```

### **For Filter Driver Enhancement**

1. **Priority IOCTL Implementations**
   - Implement `IOCTL_AVB_SETUP_TAS` first (highest value)
   - Add `IOCTL_AVB_GET_TIMESTAMP` for precision timing
   - Implement `IOCTL_AVB_SETUP_FP` for frame preemption

2. **Validation Integration**
   - Use existing test framework for validation
   - Reference working CBS implementation patterns
   - Test with proven multi-adapter scenarios

---

## 📋 **Appendix: Complete Feature Matrix**

### **Implementation Readiness Status**

| Component | Status | Notes |
|-----------|---------|-------|
| **Hardware Access Layer** | ✅ **Complete** | Multi-adapter IOCTL working |
| **Service Architecture** | ✅ **Complete** | Production allocation system |
| **Register Definitions** | ✅ **Complete** | Auto-generated from Intel specs |
| **CBS Implementation** | ✅ **Complete** | Working on all adapters |
| **Basic PTP** | ✅ **Complete** | Hardware timestamping functional |
| **TAS Implementation** | 🔶 **Ready** | Register headers available, IOCTL needed |
| **Frame Preemption** | 🔶 **Ready** | Register headers available, IOCTL needed |
| **Enhanced Timestamping** | 🔶 **Ready** | Basic working, precision IOCTL needed |

### **Validation Test Coverage**

- ✅ **Hardware Detection**: All adapters (I210, I217, I219, I225, I226)
- ✅ **Multi-Adapter Access**: Parallel operation confirmed
- ✅ **Service Allocation**: Intelligent adapter assignment working
- ✅ **Register Access**: MMIO operations through IOCTL functional
- ✅ **CBS Configuration**: Credit-based shaper on all devices
- ⚠️ **TAS Validation**: Register access confirmed, full config pending IOCTL
- ⚠️ **FP Validation**: Register access confirmed, full config pending IOCTL

---

**Document Prepared By**: Intel AVB Development Team  
**Last Updated**: September 1, 2025  
**Next Review**: Upon filter driver IOCTL completion

This guide provides complete foundation for separate AVB stack development with comprehensive hardware programming sequences and proven integration patterns.
