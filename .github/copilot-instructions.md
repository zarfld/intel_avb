# Copilot Instructions for Intel AVB Codebase

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

## Project Overview
This repository provides Intel-specific AVB/TSN register access and hardware abstraction for OpenAvnu, supporting I210/I219/I225/I226 Ethernet controllers. The codebase is structured for direct register access, timestamping, and TSN feature configuration for real-time media streaming.


## Architecture & Key Components
- **lib/**: Core hardware abstraction layer. Contains device-specific implementations (`intel_i210.c`, `intel_i217.c`, `intel_i219.c`, `intel_i225.c`, `intel_i226.c`), common logic (`intel_common.c`), and unified API (`intel.h`).
- **driver/**: Contains test and build scripts, test drivers, and Windows-specific integration code.
- **spec/**: Official Intel datasheets, specification updates, and the authoritative register header submodule.
  - **spec/intel-ethernet-regs/**: Git submodule providing auto-generated register headers (`gen/i210_regs.h`, `gen/i217_regs.h`, etc.) for each adapter. These headers are the single source of truth for all device-specific register maps. Always include and reference these headers in device implementations.

## Developer Workflows
- **Build (Windows):**
  - Use `lib/build_windows.bat` or `lib/Build-IntelHAL.ps1` for building on Windows.
  - For minimal builds, use `lib/test_minimal.bat`.
  - Output binaries are placed in `lib/build/`.
- **Testing:**
  - Run test executables in `lib/build/` (e.g., `test_driver.exe`, `test_hardware.exe`).
  - Test sources are in `lib/` (e.g., `test_driver.c`, `test_hardware.c`).
- **Simulation vs. Real Hardware:**
  - Most device access is currently simulated/stubbed. Real hardware access is required for production.
  - See `TODO.md` for roadmap and missing hardware features.

- **Unified API:** All device operations use the interface in `intel.h`. Example:
  ```c
  int intel_probe(device_t *dev);
  int intel_attach(char *dev_path, device_t *pdev);
  int intel_get_systime(device_t *dev, uint64_t *systime);
  int intel_setup_time_aware_shaper(device_t *dev, struct tsn_tas_config *config);
  int intel_mdio_read(device_t *dev, uint32_t page, uint32_t reg, uint16_t *value);
  int intel_read_reg(device_t *dev, uint32_t offset, uint32_t *value);
  ```

- **Register Map Source of Truth:**
  - Always use the headers from `spec/intel-ethernet-regs/gen/` (e.g., `i210_regs.h`, `i219_regs.h`) for adapter-specific register definitions.
  - Do not duplicate register definitions in device source files. Include the appropriate header for each device:
    ```c
    #include "../spec/intel-ethernet-regs/gen/i210_regs.h" // I210
    #include "../spec/intel-ethernet-regs/gen/i219_regs.h" // I219
    // ...etc
    ```
  - If a register is missing, update the submodule and regenerate headers rather than adding local definitions.
- **Device Support Matrix:** Implementation status varies by device. Reference `README.md` and `spec/README.md` for current support and limitations.
- **Windows Integration:** Windows-specific code is in `intel_windows.c` and related scripts. Device detection and register access may differ from Linux.
- **Specification-Driven Development:** Always consult `spec/` documents for register layouts, bit patterns, and hardware features before implementing or debugging.

## Integration Points
- **OpenAvnu:** This codebase is designed to integrate with OpenAvnu for AVB/TSN features.
- **Windows Device Manager:** Used for device detection (especially I219-LM).

## Critical Notes
- **Simulation/Stub Code:** Many hardware access routines are simulated. See `TODO.md` for required real hardware implementations.
- **API Consistency:** All new features should extend the unified API in `intel.h`.
- **Documentation:** For hardware details, always reference the official Intel specs in `spec/`.

---
_Last updated: August 2025_
