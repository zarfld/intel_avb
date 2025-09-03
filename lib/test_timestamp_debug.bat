@echo off
echo Intel AVB Timestamp Debug Test
echo ==============================

cd /d "%~dp0"

echo Building timestamp debug test...
cl /nologo /W3 /O2 ^
   test_timestamp_debug.c ^
   intel.c intel_common.c intel_i226.c intel_windows.c ^
   /I. /I..\include /I..\spec\intel-ethernet-regs\gen ^
   /Fe:build\test_timestamp_debug.exe ^
   /Fo:build\ ^
   user32.lib kernel32.lib

if errorlevel 1 (
    echo ❌ Build failed!
    pause
    exit /b 1
)

echo ✅ Build successful!
echo.
echo Running timestamp debug test...
echo.

build\test_timestamp_debug.exe

echo.
echo Test complete. Press any key to exit...
pause > nul
