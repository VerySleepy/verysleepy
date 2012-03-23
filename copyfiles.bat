@echo off
setlocal
set PLATFORM=%1
set DEST=%2

copy /y dbghelp_%PLATFORM%\*.* %DEST%

if %PLATFORM%==x86 copy /y src\crashback\bin\Win32\Release\crashreport.exe %DEST%
if %PLATFORM%==x64 copy /y src\crashback\bin\x64\Release\crashreport.exe %DEST%
