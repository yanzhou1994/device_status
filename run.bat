@echo off
rem Build and run the device_status simulator.
rem Usage: run.bat [generator]
setlocal
cd /d "%~dp0"

set "GEN=%~1"
if "%GEN%"=="" set "GEN=Visual Studio 18 2026"

if not exist "build\CMakeCache.txt" (
  echo [1/2] Configuring ...
  cmake -S sim -B build -G "%GEN%" || goto :error
)

echo [2/2] Building ...
cmake --build build --config Debug --parallel || goto :error

echo Starting simulator ...
"build\bin\lvgl_simulator.exe"
exit /b 0

:error
echo Build failed.
exit /b 1
