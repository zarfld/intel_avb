@echo off
echo Intel AVB TSN Hardware Validation Test
echo ======================================

cd /d "%~dp0"

echo Building TSN hardware validation test...
cl /nologo /W3 /O2 ^
   test_tsn_hardware_validation.c ^
   intel.c intel_common.c intel_i226.c intel_windows.c ^
   /I. /I..\include /I..\spec\intel-ethernet-regs\gen ^
   /Fe:build\test_tsn_hardware_validation.exe ^
   /Fo:build\ ^
   user32.lib kernel32.lib

if errorlevel 1 (
    echo ❌ Build failed!
    pause
    exit /b 1
)

echo ✅ Build successful!
echo.
echo Running TSN hardware validation test...
echo.

build\test_tsn_hardware_validation.exe

echo.
echo Test complete. Press any key to exit...
pause > nul
