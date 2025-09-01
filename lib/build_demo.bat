@echo off
REM Quick build for missing demo_parallel_services.exe

echo Building demo_parallel_services.exe...

REM Initialize Visual Studio environment
call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
if ERRORLEVEL 1 (
    call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
    if ERRORLEVEL 1 (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
        if ERRORLEVEL 1 (
            echo ERROR: Could not find Visual Studio environment
            echo Please ensure Visual Studio 2019 or 2022 is installed with C++ build tools
            exit /b 1
        )
    )
)

REM Create build directory if needed
if not exist "build" mkdir build

REM Compile the demo
cl /nologo /Fe:build\demo_parallel_services.exe demo_parallel_services.c ws2_32.lib advapi32.lib

if ERRORLEVEL 1 (
    echo ERROR: Compilation failed
    exit /b 1
)

echo ✅ demo_parallel_services.exe compiled successfully
echo.
echo You can now run:
echo   .\build\demo_parallel_services.exe
echo   or
echo   .\run_tests.ps1
