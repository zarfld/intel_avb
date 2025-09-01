# Intel AVB Specifications and Documentation

This directory contains Intel-specific documentation related to the Intel AVB implementation, including official Intel datasheets, specification updates, and technical documentation for supported Intel Ethernet controllers.

## Documentation Index

### Intel I210 Family
- **332763_I210_SpecUpdate_Rev3.0** - Official Intel I210 specification update (Rev 3.0)
- **333016 - I210_Datasheet_v_3_7** - Complete Intel I210 datasheet (v3.7)
- **335761 - I210_CS_CL_Datasheet_v_1_8** - Intel I210-CS/CL automotive variants datasheet (v1.8)

### Intel I217 Family
- **i217-ethernet-controller-datasheet-2** - Intel I217 Ethernet Controller datasheet (v2.x)

### Intel I219 Family  
- **ethernet-connection-i219-datasheet** - Intel I219 Ethernet Connection datasheet

### Intel I225/I226 Family
- **621661-Intel® Ethernet Controller I225-Public External Specification Update-v1.2** - I225 specification update
- **621753-Intel® Ethernet Controller I225-I226-Product Brief** - I225/I226 product brief

### Intel-Altera Integration
- **2407151103_Intel-Altera-KTI226V-S-RKTU_C26159200** - Intel-Altera KTI226V integration documentation

## Device Support Matrix (September 2025 - VERIFIED)

| Controller | Implementation Status | Documentation | Hardware Access | Test Status |
|------------|----------------------|---------------|-----------------|-------------|
| **I226-LM**| ✅ **Production Ready** | Complete official specs | ✅ **Working via Filter Driver** | ✅ **VERIFIED** |
| **I210**   | ✅ **Production Ready** | Complete official specs | ✅ **Working via Filter Driver** | ✅ **VERIFIED** |  
| **I225**   | ✅ **API Complete** | Complete official specs | ✅ **Filter Driver Ready** | ⚠️ **Untested** |
| **I219-LM**| ✅ **API Complete** | Complete official specs | ✅ **Filter Driver Ready** | ⚠️ **Simulated** |
| **I217**   | ✅ **API Complete** | Complete official specs | ✅ **Filter Driver Ready** | ⚠️ **Simulated** |

### **🎯 VERIFIED WORKING CONFIGURATION**
- **Hardware**: Intel I210 + Intel I226-LM controllers
- **Platform**: Windows 11 with IntelAvbFilter.sys NDIS driver
- **Capabilities**: Multi-adapter parallel operation with service separation
- **Status**: **PRODUCTION READY** for parallel service deployment

### **Priority-Based Adapter Selection**
1. **I226-LM (Priority 100)** - Full TSN + 2.5G + PCIe PTM → Primary TSN service
2. **I225 (Priority 90)** - Full TSN + 2.5G → High-performance alternative  
3. **I219-LM (Priority 60)** - Basic IEEE 1588 + MDIO → Timing services
4. **I210 (Priority 50)** - Basic IEEE 1588 + MMIO → Monitoring/backup

## **Register Definitions Submodule**

### **✅ intel-ethernet-regs Integration**
The `intel-ethernet-regs/` subdirectory contains a Git submodule providing auto-generated register headers:

```bash
# Initialize submodule (already done)
git submodule init
git submodule update

# Available register headers:
spec/intel-ethernet-regs/gen/i210_regs.h  # I210 register definitions
spec/intel-ethernet-regs/gen/i217_regs.h  # I217 register definitions  
spec/intel-ethernet-regs/gen/i219_regs.h  # I219 register definitions
spec/intel-ethernet-regs/gen/i225_regs.h  # I225 register definitions
spec/intel-ethernet-regs/gen/i226_regs.h  # I226 register definitions
```

### **Usage in Device Implementations**
Each device implementation includes its specific register header:
```c
// In intel_i226.c:
#include "../spec/intel-ethernet-regs/gen/i226_regs.h"

// In intel_i210.c:  
#include "../spec/intel-ethernet-regs/gen/i210_regs.h"
```

**Benefits:**
- ✅ **Single Source of Truth**: All register definitions from official Intel YAML specs
- ✅ **Auto-Generated**: Consistent naming and bit field definitions
- ✅ **Traceable**: Each header includes source YAML and commit references
- ✅ **Build Integration**: Successfully integrated with Windows build system
| **I219**   | ⚠️ **Simulation Only** | Complete official specs | TODO: Real MDIO/Register access |
| **I225**   | ⚠️ **Simulation Only** | Complete official specs + updates | TODO: Real TSN/MMIO implementation |
| **I226**   | ⚠️ **Simulation Only** | Complete official specs | TODO: Real TSN/MMIO implementation |

### Implementation Status Legend
- ✅ **Production Ready**: Real hardware access, fully tested
- ⚠️ **Simulation Only**: Architecture complete, but uses fake/stub hardware access
- ⚠️ **Stub Implementation**: Basic structure, missing real hardware interface
- ❌ **Not Implemented**: No implementation exists

## Usage Notes

These specifications are the authoritative source for:
- Register definitions and memory maps
- Hardware capabilities and limitations
- Programming interfaces and sequences
- Timing requirements and electrical specifications
- Compliance and certification information

**Important**: All implementations in `../lib/` should reference these official specifications for accuracy and compliance.

## Document Status

All documents are official Intel publications and should be considered authoritative for implementation decisions. When implementing new features or debugging hardware issues, always consult the relevant specification first.

Last updated: July 2025
