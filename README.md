# Intel AVB Register Abstraction Layer

This directory provides Intel-specific AVB/TSN register access and hardware abstraction for OpenAvnu, supporting I210/I219/I225/I226 Ethernet controllers. It implements direct register access, timestamping, and TSN feature configuration for real-time media streaming.

## Supported Devices & Status (July 2025)

| Device      | Features                                  | Implementation Status      | Hardware Access Status        |
|-------------|-------------------------------------------|---------------------------|-------------------------------|
| **I225/I226** | TSN (Qbv, Qbu, PTM), gPTP, 2.5G, MMIO   | ⚠️ **Architecture Complete** | **Simulated** - needs real MMIO |
| **I219**    | MDIO, basic IEEE 1588 timestamping        | ⚠️ **Architecture Complete** | **Simulated** - needs real MDIO |
| **I210**    | MMIO, basic IEEE 1588 timestamping        | ⚠️ **Stub Implementation**   | **TODO** - needs MMIO mapping |

### Status Legend
- ✅ **Production Ready**: Real hardware access implemented and tested
- ⚠️ **Architecture Complete**: Full API design, but simulated hardware access
- ⚠️ **Stub Implementation**: Basic structure, missing hardware interface
- ❌ **Not Implemented**: No implementation exists

**IMPORTANT**: Current implementation uses extensive simulation and stub code. Real hardware access is required for production use.

📋 **See [TODO.md](TODO.md) for detailed implementation roadmap and required work.**

## Recent Changes

- Refactored register abstraction for all supported Intel NICs.
- Improved TSN configuration API (Qbv, Qbu, PTM).
- Enhanced Windows compatibility (MMIO, timestamping).
- **Added comprehensive specification library in `spec/` directory**
- ⚠️ **CRITICAL**: Identified extensive simulation/stub code requiring real hardware implementation
- **Created detailed TODO.md with implementation roadmap**

## Public API (`intel.h`)

Unified interface for device management, time sync, TSN, MDIO, and register access.  
See [intel.h](intel.h) for full details.

```c
int intel_probe(device_t *dev);
int intel_attach(char *dev_path, device_t *pdev);
int intel_detach(device_t *dev);
int intel_get_systime(device_t *dev, uint64_t *systime);
int intel_set_systime(device_t *dev, uint64_t systime);
int intel_adjust_systime(device_t *dev, int32_t ppb);
int intel_setup_time_aware_shaper(device_t *dev, struct tsn_tas_config *config);
int intel_setup_frame_preemption(device_t *dev, struct tsn_fp_config *config);
int intel_setup_ptm(device_t *dev, struct ptm_config *config);
int intel_mdio_read(device_t *dev, uint32_t page, uint32_t reg, uint16_t *value);
int intel_mdio_write(device_t *dev, uint32_t page, uint32_t reg, uint16_t value);
int intel_read_reg(device_t *dev, uint32_t offset, uint32_t *value);
int intel_write_reg(device_t *dev, uint32_t offset, uint32_t value);
```

## Current Implementation Status

⚠️ **CRITICAL**: The current implementation contains extensive simulation and stub code that must be replaced with real hardware access before production use.

### What Works (Simulated)
- **Device Detection**: Windows Device Manager integration for I219-LM
- **API Architecture**: Complete, well-designed public interface  
- **Register Patterns**: Correct register layouts and bit patterns
- **Error Handling**: Comprehensive error checking and validation

### What Needs Real Implementation
- **PCI Configuration Access**: Currently returns hardcoded values (`0xF0000000`, `0x12345678`)
- **MMIO Operations**: All memory-mapped I/O is simulated with fake responses
- **MDIO/PHY Access**: Ethernet PHY communication is completely faked
- **IEEE 1588 Timestamping**: Timestamp registers return simulated values
- **TSN Features**: Time-aware shaping and frame preemption are stubbed

### Testing Status
- ✅ **Architecture Validation**: API design verified through simulation
- ⚠️ **Device Detection**: Real I219-LM hardware identified successfully
- ❌ **Hardware Register Access**: No real hardware operations implemented
- ❌ **Production Testing**: Cannot be production-tested without real hardware access

## Build Instructions

**Linux/Unix**
```bash
cd lib/intel_avb/lib
make all
```

**Windows**
```bash
make windows
```

**Install**
```bash
make install PREFIX=/usr/local
```

## Integration with OpenAvnu

Add to `lib/common/avb.h`:
```c
#ifndef AVB_FEATURE_INTEL
#define AVB_FEATURE_INTEL 1
#include "avb_intel.h"
#endif
```

### AVB Intel Header (`lib/common/avb_intel.h`)
```c
#ifndef __AVB_INTEL_H__
#define __AVB_INTEL_H__

#include <intel.h>

#define INTEL_BIND_NAMESZ 24

int pci_connect_intel(device_t * intel_dev);

#endif
```

## Device Capabilities & Architecture

Each device reports its capabilities through capability flags:

```c
#define INTEL_CAP_BASIC_1588    (1 << 0)  /* Basic IEEE 1588 */
#define INTEL_CAP_ENHANCED_TS   (1 << 1)  /* Enhanced timestamping */
#define INTEL_CAP_TSN_TAS       (1 << 2)  /* Time Aware Shaper */
#define INTEL_CAP_TSN_FP        (1 << 3)  /* Frame Preemption */
#define INTEL_CAP_PCIe_PTM      (1 << 4)  /* PCIe PTM */
#define INTEL_CAP_2_5G          (1 << 5)  /* 2.5 Gbps support */
#define INTEL_CAP_MDIO          (1 << 6)  /* MDIO access */
#define INTEL_CAP_MMIO          (1 << 7)  /* Memory-mapped I/O */
```

**Internal Architecture:**
- Modular design: device-specific implementations with a common interface
- Function pointers: runtime dispatch to device-specific handlers
- Capability-based: features enabled based on device capabilities
- Extensible: easy to add new devices or features

## Official Documentation

Complete Intel hardware specifications are available in the `spec/` directory:
- **I210 Family**: Complete datasheets, specification updates, automotive variants
- **I217 Family**: Controller datasheets and programming guides  
- **I219 Family**: Ethernet connection specifications
- **I225/I226 Family**: Latest specification updates and product briefs
- **Integration Guides**: Intel-Altera and multi-vendor compatibility

See [`spec/README.md`](spec/README.md) for a complete documentation index.

## License

BSD 3-Clause License - Copyright (c) 2025

---

**Documentation lifecycle:**  
This README reflects the current implementation and hardware validation status as of July 2025. For ongoing changes, see `docs/TODO.md`. Completed features are tracked in `docs/completed/`.  
Hardware validation is required for all production claims.
