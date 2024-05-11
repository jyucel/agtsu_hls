@echo off
setlocal enabledelayedexpansion

:: Set initial variables
set "SOURCE_FILES=mlr_calc.c mlr_calc_tb.c"
set "EMULATE_OUTPUT_NAME=emulate"
set "FPGA_OUTPUT_NAME=hls_mlr"
set "FPGA_FLAGS=-march=MAX10 --clock 50MHz --quartus-compile"

:: Initialize version numbers
set MAJOR=0
set MINOR=0
set PATCH=0
set FOUND_VERSION=0

:: Check for existing executable files and find the latest version
for /f "tokens=2,3,4 delims=_." %%a in ('dir /b /a-d %EMULATE_OUTPUT_NAME%_*.exe 2^>nul') do (
    set FOUND_VERSION=1
    set TEMP_MAJOR=%%a
    set TEMP_MINOR=%%b
    set TEMP_PATCH=%%c
    if !TEMP_MAJOR! gtr %MAJOR% (
        set MAJOR=!TEMP_MAJOR!
        set MINOR=!TEMP_MINOR!
        set PATCH=!TEMP_PATCH!
    ) else if !TEMP_MAJOR! equ %MAJOR% (
        if !TEMP_MINOR! gtr %MINOR% (
            set MINOR=!TEMP_MINOR!
            set PATCH=!TEMP_PATCH!
        ) else if !TEMP_MINOR! equ %MINOR% (
            if !TEMP_PATCH! gtr %PATCH% (
                set PATCH=!TEMP_PATCH!
            )
        )
    )
)

:: Display the latest found version before incrementing
if %FOUND_VERSION%==1 (
    echo Latest found version: %MAJOR%.%MINOR%.%PATCH%
) else (
    echo No existing version found. Starting from 0.0.0.
)

:: Increment the patch version
set /a PATCH+=1

:: Construct the new version
set NEW_VERSION=%MAJOR%.%MINOR%.%PATCH%

:: Display the new version to be used
echo New version to be used: %NEW_VERSION%

:: Determine the target
if not "%1"=="" (
    set "TARGET=%1"
) else (
    set "TARGET=emulate"
)

:: Construct the command based on the target
if "%TARGET%" == "emulate" (
    set "CMD=i++ -march=x86-64 -o %EMULATE_OUTPUT_NAME%_%NEW_VERSION%.exe"
) else if "%TARGET%" == "fpga" (
    set "CMD=i++ %FPGA_FLAGS% -o %FPGA_OUTPUT_NAME%_%NEW_VERSION%.exe"
)

:: Display the command
echo %CMD% %SOURCE_FILES%
echo:

:: Execute the command
%CMD% %SOURCE_FILES%

endlocal
