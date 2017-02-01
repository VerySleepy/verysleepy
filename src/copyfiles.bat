@echo off

rem This batch file copies additional DLLs to the obj\ directory,
rem so that you can run a functional Very Sleepy right from Visual Studio.
rem It is automatically called as a PostBuildEvent from sleepy.vcxproj.

set CONFIGURATION=%1
set PLATFORM=%2

set DEST=obj\%PLATFORM%\%CONFIGURATION%\

if %PLATFORM%==Win32 set PLATFORM_X=x86
if %PLATFORM%==x64   set PLATFORM_X=x64

set DBGHELPERS=dbghelp_%PLATFORM_X%
copy /y %DBGHELPERS%\*.* %DEST%
if errorlevel 1 exit /b 1

                   if not exist %DBGHELPERS%\dbghelpw.dll       copy /y "thirdparty\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION%\dbghelpw.dll"         %DEST%
if errorlevel 1 exit /b 1
if %PLATFORM%==x64 if not exist %DBGHELPERS%\dbghelpw_wow64.dll copy /y "thirdparty\wine\dlls\dbghelp\vs\bin\%PLATFORM%\%CONFIGURATION% - Wow64\dbghelpw.dll" %DEST%\dbghelpw_wow64.dll
if errorlevel 1 exit /b 1

if %PLATFORM%==Win32 set PLATFORM_BITS=32
if %PLATFORM%==x64   set PLATFORM_BITS=64

if not exist %DBGHELPERS%\dbghelpdr.dll copy thirdparty\drmingw_build_%PLATFORM_BITS%\bin\mgwhelp.dll %DEST%\dbghelpdr.dll
if errorlevel 1 exit /b 1

if not defined VCINSTALLDIR if defined VS120COMNTOOLS set VCINSTALLDIR=%VS120COMNTOOLS%\..\..\VC
for %%D in (msvcr120.dll msvcp120.dll) do copy "%VCINSTALLDIR%\redist\%PLATFORM_X%\Microsoft.VC120.CRT\%%D" %DEST%\%%D
if errorlevel 1 echo copyfiles.bat: Warning: couldn't copy the C/C++ runtime DLLs

copy /y src\crashback\bin\%PLATFORM%\%CONFIGURATION%\crashreport.exe %DEST%
if errorlevel 1 exit /b 1
