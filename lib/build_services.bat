@echo off
REM Build service example applications

echo Building Intel AVB Service Examples...

REM Set up Visual Studio environment
call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
if ERRORLEVEL 1 (
    call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
    if ERRORLEVEL 1 (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul 2>&1
        if ERRORLEVEL 1 (
            echo ERROR: Could not find Visual Studio environment
            exit /b 1
        )
    )
)

REM Create build directory if needed
if not exist "build" mkdir build

echo Compiling service applications...

REM Service Example Application
cl /nologo /Fe:build\service_example.exe service_example.c build\intel_avb.lib ws2_32.lib advapi32.lib

REM Service Separation Test
cl /nologo /Fe:build\test_service_separation.exe test_service_separation.c build\intel_avb.lib ws2_32.lib advapi32.lib

REM TSN Simple Test  
cl /nologo /Fe:build\test_tsn_simple.exe test_tsn_simple.c build\intel_avb.lib ws2_32.lib advapi32.lib

if ERRORLEVEL 1 (
    echo ERROR: Compilation failed
    exit /b 1
)

echo ✅ Service applications compiled successfully
echo.
echo Available service applications:
echo   .\build\service_example.exe         - Multi-service demonstration
echo   .\build\test_service_separation.exe - Service isolation testing
echo   .\build\test_tsn_simple.exe         - Simple TSN operations
echo.
echo Run any of these to see advanced multi-adapter usage!
