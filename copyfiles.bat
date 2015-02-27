@echo off
setlocal

set CONFIGURATION=%1
set PLATFORM=%2

set DEST=obj\%PLATFORM%\%CONFIGURATION%\

if %PLATFORM%==Win32 copy /y dbghelp_x86\*.* %DEST%
if %PLATFORM%==x64   copy /y dbghelp_x64\*.* %DEST%

copy /y "src\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION%\dbghelpw.dll" %DEST%
copy /y "src\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION% - Wow64\dbghelpw.dll" %DEST%\dbghelpw_wow64.dll

copy /y src\crashback\bin\%PLATFORM%\Release\crashreport.exe %DEST%
