# Intel AVB Implementation TODO

This document outlines the critical work required to transform the current simulation-based implementation into a production-ready hardware abstraction layer.

## CRITICAL PRIORITY: Replace Simulation Code with Real Hardware Access

### 🚨 HIGH PRIORITY: Windows Hardware Backend (`lib/intel_windows.c`)

**Current Status**: Extensive simulation with hardcoded return values  
**Required**: Complete rewrite to use real hardware access

#### Issues Found:
```c
// CURRENT (SIMULATED):
*value = 0xF0000000; /* Simulated MMIO base */
*value = 0x12345678; /* Simulated */
*value = 0x00000001; /* Simulated device ready */
```

#### Required Implementation:
1. **PCI Configuration Space Access**
   - Replace simulation with real PCI config reads
   - Use Windows Device Manager APIs or WinIo library
   - Implement proper BAR (Base Address Register) mapping

2. **MMIO (Memory-Mapped I/O) Implementation**
   - Map actual PCI BAR0 to virtual memory space
   - Replace all simulated register reads with real MMIO access
   - Implement memory mapping using Windows APIs

### ✅ COMPLETED: Hardware Access Driver Integration

**Status**: COMPLETED using NDIS Filter Driver approach
- ✅ Integrated with IntelAvbFilter.sys (NDIS 6.30 lightweight filter)
- ✅ IOCTL-based communication for hardware access
- ✅ Real PCI configuration, MMIO, and MDIO operations
- ✅ IEEE 1588 timestamping through hardware

#### Files Modified:
- ✅ `lib/intel_windows.c` - Complete rewrite with NDIS filter integration
- ✅ `lib/intel_windows.h` - Real hardware access structures via IOCTLs

### ✅ COMPLETED: Device-Specific Real Hardware Implementation

#### I219 Implementation (`lib/intel_i219.c`)
**Status**: COMPLETED
- ✅ MMIO access through Windows platform layer (NDIS filter)
- ✅ Hardware access via IOCTLs - no direct mapping needed
- ✅ Real hardware operations through NDIS OID requests

#### I225/I226 Implementation (`lib/intel_i225.c`)
**Status**: COMPLETED
- ✅ MMIO access through Windows platform layer (NDIS filter)
- ✅ Hardware access via IOCTLs - no direct mapping needed

#### I210 Implementation (`lib/intel_i210.c`)  
**Status**: COMPLETED
- ✅ MMIO access through Windows platform layer (NDIS filter)
- ✅ Hardware access via IOCTLs - no direct mapping needed

### 🚀 HIGH PRIORITY: Advanced TSN Features (Remaining Work)

#### I225/I226 TSN Features (`lib/intel_i225.c`)
**Current Issues**:
```c
/* TODO: Map MMIO region for register access */
/* TODO: Unmap MMIO region */
```

**Remaining Work**:
1. Implement TSN register access (Time-Aware Shaper, Frame Preemption)
2. Real PCIe PTM (Precision Time Measurement) implementation
3. 2.5G specific register configurations
4. Advanced TSN features beyond basic hardware access

### ✅ COMPLETED: Integration and Hardware Access

#### Real Hardware Detection (`lib/intel_real_hw.c`)
**Status**: INTEGRATED with NDIS Filter
- ✅ Hardware detection through NDIS filter device enumeration
- ✅ Removed dependency on simulation backend
- ✅ Integrated Windows device enumeration with hardware access

#### Hardware Access Abstraction
**Status**: COMPLETED
- ✅ Created unified hardware access interface through platform operations
- ✅ Abstracted hardware access through NDIS filter driver
- ✅ Implemented proper privilege escalation via kernel-mode NDIS filter
- ✅ Implemented comprehensive error handling for hardware failures

### 🧪 TESTING REQUIREMENTS

#### Unit Testing
**Required**:
1. Test with real Intel hardware (I210, I219, I225, I226)
2. Validate register read/write operations through NDIS filter
3. Test IOCTL communication between library and filter driver
4. Verify IEEE 1588 timestamping accuracy

#### Integration Testing
**Required**:
1. Test with OpenAvnu gPTP daemon
2. Validate TSN feature integration (I225/I226)
3. Test MDIO operations with real PHY
4. Performance benchmarking

#### Hardware-in-the-Loop Testing
**Required**:
1. Real network synchronization testing
2. Timestamp accuracy validation
3. TSN traffic shaping verification
4. Multi-adapter testing

### 📋 IMPLEMENTATION PHASES

#### Phase 1: Basic Hardware Access (2-4 weeks)
- [ ] Choose hardware access method (WinIo vs DirectIO vs custom driver)
- [ ] Implement basic PCI configuration space access
- [ ] Replace simulated PCI reads with real hardware
- [ ] Test on I219 hardware first (most common)

#### Phase 2: MMIO Implementation (3-6 weeks)  
- [ ] Implement memory mapping for all device families
- [ ] Replace all simulated MMIO reads/writes
- [ ] Add proper error handling for hardware failures
- [ ] Test register access patterns

#### Phase 3: Feature-Specific Implementation (4-8 weeks)
- [ ] Real MDIO/PHY access for I219
- [ ] IEEE 1588 timestamping for all devices
- [ ] TSN features for I225/I226 (Qbv, Qbu, PTM)
- [ ] Device-specific optimizations

#### Phase 4: Production Validation (2-4 weeks)
- [ ] Hardware-in-the-loop testing
- [ ] Performance optimization
- [ ] Documentation and examples
- [ ] Multi-platform testing

### 🚧 BLOCKERS AND DEPENDENCIES

#### Administrative Requirements
- **Administrator Privileges**: Hardware access requires elevated permissions
- **Driver Installation**: May require WinIo or similar driver
- **Hardware Availability**: Need real Intel NICs for testing

#### Technical Dependencies
- **Windows SDK**: For device management APIs
- **Hardware Access Library**: WinIo, DirectIO, or custom solution
- **Test Hardware**: I210, I219, I225, I226 adapters

### 📚 REFERENCE DOCUMENTATION

Use the specifications in `spec/` directory for:
- **Register Definitions**: Exact register layouts and bit patterns
- **Programming Sequences**: Proper initialization and configuration flows
- **Hardware Capabilities**: Feature availability per device family
- **Timing Requirements**: Critical timing constraints for operations

### ⚠️ COMPLIANCE REQUIREMENTS

According to OpenAvnu coding instructions:
- **No Mocking**: Real hardware testing required for production claims
- **Documentation Lifecycle**: Update status when features are completed  
- **Hardware Validation**: All features must be tested on actual hardware
- **No Simulation in Production**: Remove all stub/fake implementations

### 🎯 SUCCESS CRITERIA

Implementation is complete when:
- [ ] All simulation code removed from codebase
- [ ] Real hardware register access working on all device families
- [ ] Hardware-in-the-loop tests passing
- [ ] Integration with OpenAvnu daemons successful
- [ ] Performance meets or exceeds simulation benchmarks
- [ ] Documentation updated to reflect real implementation status

---

**Last Updated**: July 2025  
**Next Review**: Upon completion of Phase 1
