---
applyTo: '**'
---

# Intel AVB Library Copilot Instructions

## Component Overview

Intel AVB Library provides the IOCTL interface layer between intel-ethernet-hal and the NDIS kernel driver. This component translates cross-platform HAL requests into Windows-specific device control operations for Intel Ethernet controllers.

**Architecture Position**: Driver Interface Layer (HAL ↔ Kernel Bridge)  
**Primary Responsibility**: IOCTL interface to NDISIntelFilterDriver for hardware register access
**Critical Role**: Bridge between intel-ethernet-hal abstraction and Windows kernel-mode driver

## Working principles
-- ensure you understand the architecture and patterns before coding
-- No Fake, No Stubs, no Simulations, simplified code allowed in productive Code
-- no implementation based assumtions, use specification or analysis results (ask if required)
-- no false advertising, prove and ensure correctness
-- always use real hardware access patterns
-- use Intel hardware specifications for register access
-- code needs to compile before commit, no broken code
-- Always reference the exact Intel datasheet section or spec version when implementing register access.
-- Validate all hardware reads/writes with range checks or masks from the specification.
-- Every function must have a Doxygen comment explaining purpose, parameters, return values, and hardware context.
-- Use portable printf format macros (PRIu64, PRId64, PRIu32) to prevent Windows MSVC assertion dialogs
-- All hardware access MUST go through IOCTL interface to NDIS driver - NEVER direct memory mapping
-- This component bridges intel-ethernet-hal to Windows kernel driver - maintain proper abstraction
-- no duplicate or redundant implementations to avoid inconsistencies and confusion; use centralized, reusable functions instead
-- no ad-hoc file copies (e.g., *_fixed, *_new, *_correct); refactor in place step-by-step to avoid breakage
-- Clean submit rules:
   - each commit compiles and passes checks
   - small, single-purpose, reviewable diffs (no WIP noise)
   - no dead or commented-out code; remove unused files
   - run formatter and static analysis before commit
   - update docs/tests and reference the spec/issue in the message
   - use feature flags or compatibility layers when incremental changes risk breakage
-- Avoid unnecessary duplication. Duplication is acceptable when it improves clarity, isolates modules, or is required for performance.
-- Avoid code that is difficult to understand. Prefer clear naming and structure over excessive comments or unnecessary helper variables.
-- Avoid unnecessary complexity. Keep required abstractions for maintainability, testability, or hardware safety
-- Design modules so that changes in one module do not require changes in unrelated modules. Avoid dependencies that cause single changes to break multiple areas.
-- Design components for reuse where practical, but prioritize correctness and domain fit over forced generalization.
-- Prefer incremental modification of existing code over reimplementation; adapt existing functions instead of creating redundant new ones

## CRITICAL: Architectural Position in Hardware Chain

### Hardware Integration Chain Position (CORRECT INTERFACES)
```
intel-ethernet-hal (Cross-platform API)
    ↓ (intel.h API)
Intel AVB Library ← YOU ARE HERE
    ↓ (avb_ioctl.h IOCTL-interface)
NDISIntelFilterDriver (Kernel Driver)
    ↓ (register access)
Intel NIC Hardware (I210/I219/I225/I226)
```

### IOCTL Interface Responsibilities
- **Device Control Translation**: Convert intel.h API requests to avb_ioctl.h IOCTL operations
- **Register Access Abstraction**: Provide safe, validated access to Intel controller registers
- **Timestamping Operations**: Handle TX/RX timestamp capture through avb_ioctl.h interface  
- **Error Translation**: Convert kernel-mode errors to intel.h API error codes
- **Resource Management**: Manage IOCTL handles and buffer allocation for hardware operations

### Printf Format Compatibility (CRITICAL)
Windows MSVC requires portable format macros to prevent runtime assertion dialogs:

```c
// ✅ CORRECT: Portable format macros for IOCTL operations
#include <inttypes.h>
printf("IOCTL register read: offset 0x%" PRIX32 ", value 0x%" PRIX32 "\n", 
       reg_offset, reg_value);
printf("Timestamp captured: %" PRIu64 " ns\n", timestamp);
printf("Device handle: 0x%" PRIXPTR "\n", (uintptr_t)device_handle);

// ❌ WRONG: Platform-specific format specifiers (causes Windows assertions)
printf("IOCTL register read: offset 0x%x, value 0x%x\n", reg_offset, reg_value);
printf("Timestamp captured: %lu ns\n", timestamp);      // Wrong for uint64_t
printf("Device handle: 0x%p\n", device_handle);         // Use PRIXPTR instead
```

## Project Overview
This repository provides the Windows IOCTL interface layer for Intel AVB/TSN hardware access within the OpenAvnu architecture. It bridges intel-ethernet-hal cross-platform API to Windows NDIS kernel driver, supporting I210/I219/I225/I226 Ethernet controllers through proper kernel-mode device control operations.

## CRITICAL: IOCTL Interface Architecture

### Windows Hardware Access Pattern
```c
// ✅ CORRECT: Proper IOCTL interface implementation
typedef struct {
    uint32_t register_offset;    // Intel register address
    uint32_t access_type;        // READ/WRITE operation
    uint32_t value;              // Register value
    uint32_t device_id;          // Target Intel adapter
} avb_ioctl_request_t;

intel_avb_result_t intel_avb_read_register(HANDLE device_handle, 
                                          uint32_t offset, 
                                          uint32_t *value) {
    avb_ioctl_request_t request = {
        .register_offset = offset,
        .access_type = AVB_IOCTL_READ_REG,
        .device_id = current_device_id
    };
    
    DWORD bytes_returned;
    BOOL result = DeviceIoControl(
        device_handle,
        IOCTL_AVB_READ_REGISTER,
        &request, sizeof(request),
        &request, sizeof(request),
        &bytes_returned, NULL
    );
    
    if (!result) {
        DWORD error = GetLastError();
        printf("Register read IOCTL failed: offset 0x%" PRIX32 ", error %" PRIu32 "\n", 
               offset, error);
        return INTEL_AVB_ERROR_IOCTL;
    }
    
    *value = request.value;
    printf("Register read: offset 0x%" PRIX32 " = 0x%" PRIX32 "\n", offset, *value);
    return INTEL_AVB_SUCCESS;
}

// ❌ WRONG: Direct memory mapping (bypasses kernel driver)
// void* mmio_base = MapPhysicalMemory(pci_bar_address);  // ARCHITECTURAL VIOLATION
// uint32_t value = *(uint32_t*)(mmio_base + offset);     // NEVER DO THIS
```

### Timestamping IOCTL Operations  
```c
// ✅ CORRECT: Timestamping through kernel driver
intel_avb_result_t intel_avb_get_tx_timestamp(HANDLE device_handle, 
                                              intel_avb_timestamp_t *timestamp) {
    avb_timestamp_request_t request = {
        .timestamp_type = AVB_TIMESTAMP_TX,
        .sequence_id = current_sequence_id,
        .device_id = current_device_id
    };
    
    DWORD bytes_returned;
    BOOL result = DeviceIoControl(
        device_handle,
        IOCTL_AVB_GET_TIMESTAMP,
        &request, sizeof(request),
        timestamp, sizeof(*timestamp),
        &bytes_returned, NULL
    );
    
    if (!result) {
        DWORD error = GetLastError();
        printf("TX timestamp IOCTL failed: error %" PRIu32 "\n", error);
        return INTEL_AVB_ERROR_TIMESTAMP;
    }
    
    printf("TX timestamp: %" PRIu64 " ns (sequence %" PRIu32 ")\n", 
           timestamp->nanoseconds, request.sequence_id);
    return INTEL_AVB_SUCCESS;
}
```


## Architecture & Key Components

### IOCTL Interface Components
- **lib/**: Core IOCTL interface layer. Contains device-specific IOCTL handlers (`intel_i210.c`, `intel_i217.c`, `intel_i219.c`, `intel_i225.c`, `intel_i226.c`), common IOCTL logic (`intel_common.c`), and unified API (`intel.h`).
- **include/**: Public API headers for intel-ethernet-hal integration (`avb_ioctl.h`, `intel_avb_api.h`)
- **spec/**: Official Intel datasheets, specification updates, and the authoritative register header submodule.
  - **spec/intel-ethernet-regs/**: Git submodule providing auto-generated register headers (`gen/i210_regs.h`, `gen/i217_regs.h`, etc.) for each adapter. These headers are the single source of truth for all device-specific register maps. Always include and reference these headers in device implementations.

### Intel Ethernet HAL Integration via intel.h API
```c
// ✅ CORRECT: How intel-ethernet-hal should use this library via intel.h API
#include "intel.h"

intel_hal_result_t intel_hal_read_register(intel_hal_device_t *device, 
                                          uint32_t offset, 
                                          uint32_t *value) {
    // Translate HAL request to intel.h API operation
    int result = intel_read_reg(device->intel_device, offset, value);
    
    // Translate intel.h result to HAL result
    switch (result) {
        case 0:  // Success
            return INTEL_HAL_SUCCESS;
        case -1: // IOCTL error
            return INTEL_HAL_ERROR_HARDWARE;
        case -2: // Timeout
            return INTEL_HAL_ERROR_TIMEOUT;
        default:
            return INTEL_HAL_ERROR_UNKNOWN;
    }
}
```

### NDIS Driver Communication
```c
// ✅ CORRECT: Proper NDIS filter driver communication
typedef struct {
    HANDLE driver_handle;        // Handle to NDIS filter driver
    uint32_t device_instance;    // Intel adapter instance ID
    OVERLAPPED async_operation;  // For asynchronous IOCTL operations
} intel_avb_device_context_t;

intel_avb_result_t intel_avb_open_device(const char *device_path, 
                                         intel_avb_device_context_t **context) {
    HANDLE driver_handle = CreateFile(
        device_path,
        GENERIC_READ | GENERIC_WRITE,
        0,                          // No sharing
        NULL,                       // Default security
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
        NULL
    );
    
    if (driver_handle == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        printf("Failed to open NDIS driver: %" PRIu32 "\n", error);
        return INTEL_AVB_ERROR_DEVICE_OPEN;
    }
    
    *context = malloc(sizeof(intel_avb_device_context_t));
    (*context)->driver_handle = driver_handle;
    (*context)->device_instance = extract_device_instance(device_path);
    
    printf("Opened NDIS driver: handle 0x%" PRIXPTR ", instance %" PRIu32 "\n",
           (uintptr_t)driver_handle, (*context)->device_instance);
    
    return INTEL_AVB_SUCCESS;
}
```

## Developer Workflows

### IOCTL Development and Testing
- **Build (Windows):**
  - Use `lib/build_windows.bat` or `lib/Build-IntelHAL.ps1` for building IOCTL interface layer
  - For minimal builds, use `lib/test_minimal.bat`
  - Output binaries are placed in `lib/build/`
  - Link with kernel32.lib for DeviceIoControl functions
- **IOCTL Testing:**
  - Run test executables in `lib/build/` (e.g., `test_ioctl.exe`, `test_hardware.exe`)
  - Test NDIS driver communication with `test_driver.exe`  
  - Validate register access patterns with `test_register_access.exe`
  - Test sources are in `lib/` (e.g., `test_ioctl.c`, `test_hardware.c`)

### IOCTL Code Generation and Validation
- **Generating register headers (Python):**
  - Python is available via the Windows launcher. Verified: `py -3 --version` → Python 3.13.5
  - From `spec/intel-ethernet-regs/`, regenerate headers for IOCTL validation:
    - `py -3 tools\reggen.py devices\i210.yaml gen`
    - `py -3 tools\reggen.py devices\i217.yaml gen`
    - `py -3 tools\reggen.py devices\i219.yaml gen`
    - `py -3 tools\reggen.py devices\i225.yaml gen`
    - `py -3 tools\reggen.py devices\i226.yaml gen`
  - Output goes to `spec/intel-ethernet-regs/gen/` (e.g., `gen\i217_regs.h`)
  - Use these headers to validate IOCTL register offset parameters

### IOCTL vs. Direct Hardware Access
- **CRITICAL**: All device access MUST go through IOCTL interface to NDIS driver
- **NEVER use direct memory mapping** - this bypasses Windows security and driver model
- **Real hardware access**: All IOCTL operations communicate with actual Intel hardware through kernel driver

### IOCTL API Implementation Pattern
All device operations use the IOCTL interface pattern in `intel.h`. Example:
```c
// ✅ CORRECT: IOCTL-based device operations
int intel_probe_ioctl(device_t *dev);
int intel_attach_ioctl(char *dev_path, device_t *pdev);
int intel_get_systime_ioctl(device_t *dev, uint64_t *systime);
int intel_setup_time_aware_shaper_ioctl(device_t *dev, struct tsn_tas_config *config);
int intel_read_reg_ioctl(device_t *dev, uint32_t offset, uint32_t *value);
int intel_write_reg_ioctl(device_t *dev, uint32_t offset, uint32_t value);

// ❌ WRONG: Direct hardware access functions (architectural violation)
// int intel_read_reg_direct(device_t *dev, uint32_t offset, uint32_t *value);
// uint32_t* intel_map_registers(device_t *dev);  // NEVER implement these
```

### Register Map Source of Truth for IOCTL Operations
- Always use the headers from `spec/intel-ethernet-regs/gen/` (e.g., `i210_regs.h`, `i219_regs.h`) for adapter-specific register definitions in IOCTL requests
- Do not duplicate register definitions in device source files. Include the appropriate header for each device:
  ```c
  #include "../spec/intel-ethernet-regs/gen/i210_regs.h" // I210 IOCTL operations
  #include "../spec/intel-ethernet-regs/gen/i219_regs.h" // I219 IOCTL operations
  // ...etc
  ```
- If a register is missing, update the submodule and regenerate headers rather than adding local definitions
- Use register definitions to validate IOCTL offset parameters before kernel driver communication

### IOCTL Error Handling and Validation
```c
// ✅ CORRECT: Comprehensive IOCTL error handling
intel_avb_result_t intel_avb_validate_and_read_register(HANDLE device_handle,
                                                       uint32_t offset,
                                                       uint32_t *value) {
    // Validate register offset against device specification
    if (!is_valid_register_offset(offset)) {
        printf("Invalid register offset: 0x%" PRIX32 "\n", offset);
        return INTEL_AVB_ERROR_INVALID_PARAM;
    }
    
    avb_ioctl_request_t request = {
        .register_offset = offset,
        .access_type = AVB_IOCTL_READ_REG,
        .device_id = current_device_id
    };
    
    DWORD bytes_returned = 0;
    BOOL result = DeviceIoControl(
        device_handle,
        IOCTL_AVB_READ_REGISTER,
        &request, sizeof(request),
        &request, sizeof(request),
        &bytes_returned, NULL
    );
    
    if (!result) {
        DWORD error = GetLastError();
        printf("IOCTL failed: offset 0x%" PRIX32 ", error %" PRIu32 "\n", offset, error);
        
        // Translate Windows error to intel_avb error
        switch (error) {
            case ERROR_DEVICE_NOT_CONNECTED:
                return INTEL_AVB_ERROR_DEVICE_DISCONNECTED;
            case ERROR_TIMEOUT:
                return INTEL_AVB_ERROR_TIMEOUT;
            case ERROR_ACCESS_DENIED:
                return INTEL_AVB_ERROR_ACCESS_DENIED;
            default:
                return INTEL_AVB_ERROR_IOCTL;
        }
    }
    
    if (bytes_returned != sizeof(request)) {
        printf("IOCTL returned unexpected size: %" PRIu32 " (expected %" PRIu32 ")\n",
               bytes_returned, (uint32_t)sizeof(request));
        return INTEL_AVB_ERROR_INVALID_RESPONSE;
    }
    
    *value = request.value;
    printf("Register read successful: 0x%" PRIX32 " = 0x%" PRIX32 "\n", offset, *value);
    return INTEL_AVB_SUCCESS;
}
```
- **Device Support Matrix:** Implementation status varies by device. Reference `README.md` and `spec/README.md` for current IOCTL support and limitations.
- **Windows NDIS Integration:** Windows-specific IOCTL code is in `intel_windows.c` and related scripts. Device detection and register access through NDIS filter driver interface.
- **Specification-Driven Development:** Always consult `spec/` documents for register layouts, bit patterns, and hardware features before implementing IOCTL operations or debugging.

## Integration Points

### OpenAvnu Architecture Integration
- **intel-ethernet-hal**: Primary consumer of this IOCTL interface layer
- **gPTP Service**: Indirect consumer through intel-ethernet-hal for timestamping operations
- **AVDECC Controllers**: Uses IOCTL interface for device capability discovery
- **Windows NDIS Driver Stack**: Direct integration with NDISIntelFilterDriver

### NDIS Filter Driver Communication
```c
// ✅ CORRECT: Proper NDIS filter driver integration
#define IOCTL_AVB_READ_REGISTER     CTL_CODE(FILE_DEVICE_NETWORK, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVB_WRITE_REGISTER    CTL_CODE(FILE_DEVICE_NETWORK, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVB_GET_TIMESTAMP     CTL_CODE(FILE_DEVICE_NETWORK, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AVB_ENABLE_TIMESTAMPING CTL_CODE(FILE_DEVICE_NETWORK, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Device path format for NDIS filter driver
#define INTEL_AVB_DEVICE_PATH       "\\\\.\\IntelAvbFilter%d"
#define INTEL_AVB_DEVICE_NAME       "IntelAvbFilter"
```

## CRITICAL: Common Implementation Mistakes

### ❌ WRONG: Direct Hardware Access (Architectural Violation)
```c
// NEVER access hardware directly - bypasses Windows driver model
void* mmio_base = MapPhysicalMemory(pci_bar_address);
uint32_t value = *(uint32_t*)(mmio_base + register_offset);  // ARCHITECTURAL VIOLATION
WriteRegister(mmio_base + offset, value);                    // BYPASSES SECURITY
```

### ✅ CORRECT: IOCTL-Based Hardware Access
```c
// Always use IOCTL interface for hardware access
intel_avb_result_t intel_avb_write_register(HANDLE device_handle,
                                           uint32_t offset,
                                           uint32_t value) {
    avb_ioctl_request_t request = {
        .register_offset = offset,
        .access_type = AVB_IOCTL_WRITE_REG,
        .value = value,
        .device_id = current_device_id
    };
    
    DWORD bytes_returned;
    BOOL result = DeviceIoControl(
        device_handle,
        IOCTL_AVB_WRITE_REGISTER,
        &request, sizeof(request),
        NULL, 0,
        &bytes_returned, NULL
    );
    
    if (!result) {
        DWORD error = GetLastError();
        printf("Register write IOCTL failed: offset 0x%" PRIX32 ", value 0x%" PRIX32 ", error %" PRIu32 "\n",
               offset, value, error);
        return INTEL_AVB_ERROR_IOCTL;
    }
    
    printf("Register write successful: 0x%" PRIX32 " = 0x%" PRIX32 "\n", offset, value);
    return INTEL_AVB_SUCCESS;
}
```

### ❌ WRONG: Platform-Specific Printf Formats  
```c
// Causes Windows MSVC assertion dialogs
printf("IOCTL handle: %p\n", device_handle);           // Use PRIXPTR instead
printf("Register offset: %x\n", offset);               // Use PRIX32 instead  
printf("Timestamp: %lu ns\n", timestamp);              // Use PRIu64 instead
printf("Error code: %d\n", GetLastError());            // Use PRIu32 instead
```

### ✅ CORRECT: Portable Printf Formats
```c
#include <inttypes.h>
printf("IOCTL handle: 0x%" PRIXPTR "\n", (uintptr_t)device_handle);
printf("Register offset: 0x%" PRIX32 "\n", offset);
printf("Timestamp: %" PRIu64 " ns\n", timestamp);
printf("Error code: %" PRIu32 "\n", (uint32_t)GetLastError());
```

## Performance and Resource Management

### IOCTL Operation Optimization
- **Batch Operations**: Group multiple register access operations into single IOCTL calls when possible
- **Asynchronous Operations**: Use overlapped I/O for non-blocking IOCTL operations
- **Handle Management**: Efficiently manage NDIS driver handles to minimize resource usage
- **Error Recovery**: Implement robust error recovery for IOCTL timeouts and device disconnections

### Memory Management for IOCTL Buffers
```c
// ✅ CORRECT: Efficient IOCTL buffer management
typedef struct {
    avb_ioctl_request_t* request_buffer;
    size_t buffer_size;
    OVERLAPPED overlapped;
} intel_avb_ioctl_context_t;

intel_avb_result_t intel_avb_allocate_ioctl_context(intel_avb_ioctl_context_t **context) {
    *context = malloc(sizeof(intel_avb_ioctl_context_t));
    if (*context == NULL) {
        printf("Failed to allocate IOCTL context\n");
        return INTEL_AVB_ERROR_MEMORY;
    }
    
    (*context)->buffer_size = sizeof(avb_ioctl_request_t) * AVB_MAX_BATCH_SIZE;
    (*context)->request_buffer = malloc((*context)->buffer_size);
    if ((*context)->request_buffer == NULL) {
        free(*context);
        printf("Failed to allocate IOCTL buffer: %" PRIu32 " bytes\n", 
               (uint32_t)(*context)->buffer_size);
        return INTEL_AVB_ERROR_MEMORY;
    }
    
    memset(&(*context)->overlapped, 0, sizeof(OVERLAPPED));
    printf("Allocated IOCTL context: buffer size %" PRIu32 " bytes\n",
           (uint32_t)(*context)->buffer_size);
    
    return INTEL_AVB_SUCCESS;
}
```

## Critical Notes and Development Guidelines

### IOCTL Interface Requirements  
- **CRITICAL**: All hardware access MUST go through IOCTL interface to NDIS driver - this is NOT optional
- **Security Compliance**: IOCTL interface maintains Windows security model and driver isolation
- **API Consistency**: All new features should extend the unified IOCTL API in `intel.h`
- **Thread Safety**: IOCTL operations must be thread-safe for concurrent intel-ethernet-hal access

### Documentation and Specification Compliance
- **Hardware References**: For hardware details, always reference the official Intel specs in `spec/`
- **IOCTL Documentation**: Document all IOCTL codes, buffer formats, and error conditions
- **Error Code Mapping**: Maintain clear mapping between Windows errors and intel_avb error codes
- **Performance Metrics**: Document IOCTL latency and throughput characteristics

---
**Architecture Note**: This Intel AVB Library is the IOCTL interface layer in the OpenAvnu hardware chain. It bridges intel-ethernet-hal to Windows NDIS kernel driver. ALL hardware access must go through this IOCTL interface - never implement direct memory mapping or register access.

**Printf Format Reminder**: Always use portable format macros (PRIu64, PRId64, PRIX32, PRIXPTR) to prevent Windows MSVC runtime assertion dialogs. This is critical for IOCTL error reporting and debugging.

**IOCTL Security**: This component maintains Windows driver security model. Never bypass IOCTL interface with direct hardware access - this violates Windows security architecture and will not work in production environments.
