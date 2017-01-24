@echo off

rem This batch file copies additional DLLs to the obj\ directory,
rem so that you can run a functional Very Sleepy right from Visual Studio.
rem It is automatically called as a PostBuildEvent from sleepy.vcxproj.

if not defined DRMINGW set DRMINGW=..\drmingw

set CONFIGURATION=%1
set PLATFORM=%2

set DEST=obj\%PLATFORM%\%CONFIGURATION%\

if %PLATFORM%==Win32 set DBGHELPERS=dbghelp_x86
if %PLATFORM%==x64   set DBGHELPERS=dbghelp_x64
copy /y %DBGHELPERS%\*.* %DEST%

if not exist %DBGHELPERS%\dbghelpw.dll copy /y "thirdparty\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION%\dbghelpw.dll" %DEST%
if %PLATFORM%==x64 if not exist %DBGHELPERS%\dbghelpw_wow64.dll copy /y "thirdparty\dbghelpw\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION% - Wow64\dbghelpw.dll" %DEST%\dbghelpw_wow64.dll

if %PLATFORM%==Win32 set PLATFORM_BITS=32
if %PLATFORM%==x64   set PLATFORM_BITS=64

if not exist %DBGHELPERS%\dbghelpdr.dll copy %DRMINGW%\build\%PLATFORM_BITS%\bin\mgwhelp.dll %DEST%\dbghelpdr.dll

copy /y src\crashback\bin\%PLATFORM%\%CONFIGURATION%\crashreport.exe %DEST%
