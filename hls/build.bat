@echo off
setlocal enabledelayedexpansion

:: Initialize version file if it does not exist
if not exist version.txt (
    echo 0.0.1 > version.txt
)

:: Read the current version from version.txt
set /p VERSION=<version.txt

:: Parse the version number
for /f "tokens=1,2,3 delims=." %%a in ("%VERSION%") do (
    set MAJOR=%%a
    set MINOR=%%b
    set PATCH=%%c
)

:: Increment the patch version
set /a PATCH+=1

:: Construct the new version
set NEW_VERSION=%MAJOR%.%MINOR%.%PATCH%

:: Save the new version back to version.txt
echo %NEW_VERSION% > version.txt

:: Use the new version in the build process
set "SOURCE_FILES=mlr_calc.c mlr_calc_tb.c"
set "FPGA_OUTPUT_NAME=hls_mlr_"
set "FPGA_FLAGS=-march=MAX10 --clock 50MHz --quartus-compile"
rem set "FPGA_FLAGS=-march=MAX10"

if not "%1"=="" (
  set "TARGET=%1"
) else (
  set "TARGET=emulate_"
)

if "%TARGET%" == "emulate_" (
  set "CMD=i++ -march=x86-64 -o %TARGET%%NEW_VERSION%.exe"
) else if "%TARGET%" == "fpga" (
  set "CMD=i++ %FPGA_FLAGS% -o %FPGA_OUTPUT_NAME%%NEW_VERSION%.exe"
)

set "CMD=%CMD:""="%"

echo %CMD% %SOURCE_FILES%
echo:
%CMD% %SOURCE_FILES%

endlocal
