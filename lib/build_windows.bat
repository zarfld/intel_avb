@echo off
REM Intel AVB HAL Library Windows Build Script
REM
REM This script sets up the Visual Studio environment and builds the Intel HAL library

echo Building Intel AVB HAL Library for Windows...

REM Ensure we run from this script's directory for relative paths
pushd %~dp0

REM Setup Visual Studio 2022 environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

REM Create output directory
if not exist "build" mkdir build

REM Compile source files
echo Compiling source files...
set INC=/I. /I..\include
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel.c /Fo:build\intel.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_common.c /Fo:build\intel_common.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_i210.c /Fo:build\intel_i210.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_i217.c /Fo:build\intel_i217.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_i219.c /Fo:build\intel_i219.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_i225.c /Fo:build\intel_i225.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_multi_adapter.c /Fo:build\intel_multi_adapter.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_windows.c /Fo:build\intel_windows.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_realmode.c /Fo:build\test_realmode.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_driver_verification.c /Fo:build\test_driver_verification.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_filter_driver.c /Fo:build\test_filter_driver.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_multi_adapter.c /Fo:build\test_multi_adapter.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_i226_priority.c /Fo:build\test_i226_priority.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_tsn_support.c /Fo:build\test_tsn_support.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% demo_parallel_services.c /Fo:build\demo_parallel_services.obj

REM Create static library
echo Creating static library...
lib /OUT:build\intel_avb.lib build\intel.obj build\intel_common.obj build\intel_i210.obj build\intel_i217.obj build\intel_i219.obj build\intel_i225.obj build\intel_multi_adapter.obj build\intel_windows.obj

REM Create DLL
echo Creating dynamic library...
link /DLL /OUT:build\intel_avb.dll build\intel.obj build\intel_common.obj build\intel_i210.obj build\intel_i217.obj build\intel_i219.obj build\intel_i225.obj build\intel_multi_adapter.obj build\intel_windows.obj

REM Compile test program
echo Compiling test program...
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% test_intel.c /Fo:build\test_intel.obj
cl /c /O2 /W3 /D_CRT_SECURE_NO_WARNINGS %INC% intel_common.c /Fo:build\test_intel_common.obj
link /OUT:build\test_intel.exe build\test_intel.obj build\test_intel_common.obj build\intel_avb.lib build\intel_windows.obj
link /OUT:build\test_realmode.exe build\test_realmode.obj
link /OUT:build\test_driver_verification.exe build\test_driver_verification.obj advapi32.lib
link /OUT:build\test_filter_driver.exe build\test_filter_driver.obj
link /OUT:build\test_multi_adapter.exe build\test_multi_adapter.obj
link /OUT:build\test_i226_priority.exe build\test_i226_priority.obj
link /OUT:build\test_tsn_support.exe build\test_tsn_support.obj
link /OUT:build\demo_parallel_services.exe build\demo_parallel_services.obj

echo Build complete!
echo.
echo Output files:
echo   build\intel_avb.lib   - Static library
echo   build\intel_avb.dll   - Dynamic library  
echo   build\test_intel.exe      - Simulated API test
echo   build\test_realmode.exe   - Real IOCTL interface test
echo   build\test_i226_priority.exe - I226 preference test
echo   build\test_multi_adapter.exe - Multi-adapter test
echo   build\test_tsn_support.exe - TSN IOCTL support test
echo   build\demo_parallel_services.exe - Parallel services demonstration
echo   build\test_filter_driver.exe - Filter driver test
echo.
popd
