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

3. **Hardware Access Driver Integration**
   - Choose hardware access method:
     - Option A: WinIo library (easiest, requires driver installation)
     - Option B: DirectIO library
     - Option C: Custom kernel driver
     - Option D: Windows Device Management APIs

#### Files to Modify:
- `lib/intel_windows.c` - Complete rewrite of hardware access functions
- `lib/intel_windows.h` - Add real hardware access structures

### 🚨 HIGH PRIORITY: Device-Specific Real Hardware Implementation

#### I219 Implementation (`lib/intel_i219.c`)
**Current Issues**:
```c
/* TODO: Map MMIO region and detect PHY address */
/* TODO: Unmap MMIO region */
```

**Required Work**:
1. Implement real MMIO region mapping
2. Detect actual PHY address through hardware
3. Replace stub MDIO operations with real hardware access
4. Implement real IEEE 1588 timestamping register access

#### I225/I226 Implementation (`lib/intel_i225.c`)
**Current Issues**:
```c
/* TODO: Map MMIO region for register access */
/* TODO: Unmap MMIO region */
```

**Required Work**:
1. Implement TSN register access (Time-Aware Shaper, Frame Preemption)
2. Real PCIe PTM (Precision Time Measurement) implementation
3. 2.5G specific register configurations
4. Real MMIO mapping for I225/I226 specific registers

#### I210 Implementation (`lib/intel_i210.c`)
**Current Issues**:
```c
/* TODO: Map MMIO region for register access */
/* TODO: Unmap MMIO region */
```

**Required Work**:
1. Implement basic MMIO access for I210 family
2. Real IEEE 1588 timestamping implementation
3. Basic PCI configuration access

### 🔧 MEDIUM PRIORITY: Integration and Testing

#### Real Hardware Detection (`lib/intel_real_hw.c`)
**Current Status**: Exists but not integrated  
**Required Work**:
1. Connect real device detection with register access
2. Remove dependency on simulation backend
3. Integrate Windows device enumeration with hardware access

#### Hardware Access Abstraction
**Required Work**:
1. Create unified hardware access interface
2. Abstract PCI access across different Windows versions
3. Handle privilege escalation for hardware access
4. Implement proper error handling for hardware failures

### 🧪 TESTING REQUIREMENTS

#### Unit Testing
**Required**:
1. Test with real Intel hardware (I210, I219, I225, I226)
2. Validate register read/write operations
3. Test MMIO mapping and unmapping
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
