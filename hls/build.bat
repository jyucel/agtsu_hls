@echo off
setlocal enabledelayedexpansion

:: Set initial variables
set "SOURCE_FILES=mlr_calc.c mlr_calc_tb.c"
set "FPGA_OUTPUT_NAME=hls_mlr_"
set "FPGA_FLAGS=-march=MAX10 --clock 50MHz --quartus-compile"
rem set "FPGA_FLAGS=-march=MAX10"

:: Initialize version numbers
set MAJOR=0
set MINOR=0
set PATCH=0

:: Check for existing executable files and find the latest version
for /f "tokens=1,2,3 delims=_.exe" %%a in ('dir /b /o-n hls_mlr_*.exe') do (
    set "MAJOR=%%b"
    set "MINOR=%%c"
    set "PATCH=%%d"
    goto :found_version
)
:found_version

:: Increment the patch version
set /a PATCH+=1

:: Construct the new version
set NEW_VERSION=%MAJOR%.%MINOR%.%PATCH%

:: Determine the target
if not "%1"=="" (
  set "TARGET=%1"
) else (
  set "TARGET=emulate_"
)

:: Construct the command based on the target
if "%TARGET%" == "emulate_" (
  set "CMD=i++ -march=x86-64 -o %TARGET%%NEW_VERSION%.exe"
) else if "%TARGET%" == "fpga" (
  set "CMD=i++ %FPGA_FLAGS% -o %FPGA_OUTPUT_NAME%%NEW_VERSION%.exe"
)

:: Remove extra quotes from the command
set "CMD=%CMD:""=%"

:: Display and execute the command
echo %CMD% %SOURCE_FILES%
echo:
%CMD% %SOURCE_FILES%

endlocal
