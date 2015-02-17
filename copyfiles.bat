@echo off
setlocal
set PLATFORM=%1
set DEST=%2

copy /y dbghelp_%PLATFORM%\*.* %DEST%

if %PLATFORM%==x86 set PLATFORM=Win32

copy /y "src\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\Release\dbghelpw.dll" %DEST%
copy /y "src\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\Release - Wow64\dbghelpw.dll" %DEST%\dbghelpw_wow64.dll

copy /y src\crashback\bin\%PLATFORM%\Release\crashreport.exe %DEST%
