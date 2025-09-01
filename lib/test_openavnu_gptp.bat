@echo off
REM Test OpenAvnu gPTP Integration
REM This requires administrative privileges to access hardware

echo Testing OpenAvnu gPTP Integration...
echo.
echo This test demonstrates how Intel AVB services integrate with
echo OpenAvnu-compatible gPTP timing services for production AVB applications.
echo.

REM Check if we have build output
if not exist "build\test_openavnu_gptp.exe" (
    echo Building test executable...
    call build_windows.bat
    if errorlevel 1 (
        echo Build failed!
        exit /b 1
    )
    echo.
)

REM Run the test
echo Running OpenAvnu gPTP integration test...
echo ==========================================
build\test_openavnu_gptp.exe

if errorlevel 1 (
    echo.
    echo ❌ Test failed - Make sure you're running as Administrator!
    echo    Also verify IntelAvbFilter.sys is installed and running.
) else (
    echo.
    echo ✅ OpenAvnu gPTP integration test completed successfully!
)
