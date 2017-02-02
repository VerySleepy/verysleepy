@echo off
setlocal enabledelayedexpansion

rem Get options from the command line

for %%a in (%*) do set %%a

rem Build Dr. MinGW

echo build.cmd: Building Dr. MinGW
call thirdparty\drmingw_build_mingw.cmd
if errorlevel 1 exit /b 1

rem Set up wxWidgets ignores, so that git describe
rem does not think we're building with a dirty tree

if exist .git\modules\thirdparty\wxWidgets\info\exclude if not exist .git\modules\thirdparty\wxWidgets\info\exclude_sleepy (
	echo build.cmd: Configuring .git\modules\thirdparty\wxWidgets\info\exclude

	echo /build/msw/vc_mswu/>>     .git\modules\thirdparty\wxWidgets\info\exclude
	echo /build/msw/vc_x64_mswu/>> .git\modules\thirdparty\wxWidgets\info\exclude
	echo /include/wx/msw/setup.h>> .git\modules\thirdparty\wxWidgets\info\exclude
	echo /lib/vc_lib/>>            .git\modules\thirdparty\wxWidgets\info\exclude
	echo /lib/vc_x64_lib/>>        .git\modules\thirdparty\wxWidgets\info\exclude

	echo. > .git\modules\thirdparty\wxWidgets\info\exclude_sleepy
)

rem Find MSBuild

if not defined MSBUILD for %%a in (msbuild.exe) do if not [%%~$PATH:a] == [] set MSBUILD=%%~$PATH:a
if not defined MSBUILD if exist "%ProgramFiles(x86)%\MSBuild\14.0\Bin\MSBuild.exe" set MSBUILD=%ProgramFiles(x86)%\MSBuild\14.0\Bin\MSBuild.exe
if not defined MSBUILD if exist "%ProgramFiles(x86)%\MSBuild\12.0\Bin\MSBuild.exe" set MSBUILD=%ProgramFiles(x86)%\MSBuild\12.0\Bin\MSBuild.exe
if not defined MSBUILD if exist %WinDir%\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe set MSBUILD=%WinDir%\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe
if not defined MSBUILD echo build.cmd: Can't find msbuild! & exit /b 1
echo build.cmd: Found msbuild at: %MSBUILD%

rem Find SignTool

if defined SIGN (
	if not defined SIGNTOOL for %%a in (signtool.exe) do if not [%%~$PATH:a] == [] set SIGNTOOL=%%~$PATH:a
	if not defined SIGNTOOL if defined MSSdk if exist "!MSSdk!\Bin\signtool.exe" set SIGNTOOL=!MSSdk!\Bin\signtool.exe
	if not defined SIGNTOOL if exist "!ProgramFiles(x86)!\Windows Kits\10\bin\x64\signtool.exe" set "SIGNTOOL=!ProgramFiles(x86)!\Windows Kits\10\bin\x64\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles(x86)!\Windows Kits\8.1\bin\x64\signtool.exe" set "SIGNTOOL=!ProgramFiles(x86)!\Windows Kits\8.1\bin\x64\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles(x86)!\Windows Kits\8.1\bin\x86\signtool.exe" set "SIGNTOOL=!ProgramFiles(x86)!\Windows Kits\8.1\bin\x86\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles(x86)!\Windows Kits\8.0\bin\x64\signtool.exe" set "SIGNTOOL=!ProgramFiles(x86)!\Windows Kits\8.0\bin\x64\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles(x86)!\Windows Kits\8.0\bin\x64\signtool.exe" set "SIGNTOOL=!ProgramFiles(x86)!\Windows Kits\8.0\bin\x64\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles!\Microsoft SDKs\Windows\v7.1\Bin\signtool.exe" set "SIGNTOOL=!ProgramFiles!\Microsoft SDKs\Windows\v7.1\Bin\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles!\Microsoft SDKs\Windows\v7.0\Bin\signtool.exe" set "SIGNTOOL=!ProgramFiles!\Microsoft SDKs\Windows\v7.0\Bin\signtool.exe"
	if not defined SIGNTOOL if exist "!ProgramFiles!\Microsoft SDKs\Windows\v6.0A\Bin\signtool.exe" set "SIGNTOOL=!ProgramFiles!\Microsoft SDKs\Windows\v6.0A\Bin\signtool.exe"
	if not defined SIGNTOOL echo build.cmd: Can't find SignTool! & exit /b 1
	echo build.cmd: Found SignTool at: !SIGNTOOL!
)

rem Use the latest working toolset with Windows XP compatibility
rem (v120_xp at the time of writing).

rem Note: Building dbghelpw on x64 with v140_xp fails with strange
rem include errors, such as "fatal error C1083: Cannot open
rem include file: 'fcntl.h': No such file or directory"

rem Note: MSBuild on AppVeyor has some strange problems when
rem building against the v100 toolset:
rem http://help.appveyor.com/discussions/problems/6000-link-fatal-error-lnk1158-cannot-run-cvtresexe

if not defined TOOLSET set TOOLSET=v120_xp

rem Build Very Sleepy

if not defined CONFIGURATION set CONFIGURATION=Release

for %%p in (Win32 x64) do (
	set PLATFORM=%%p

	echo build.cmd: Building !CONFIGURATION! ^| !PLATFORM!

	rem Build for the Wow64 configuration first.
	rem This configuration is only used for the Wine dbghelp implemenation
	rem to support debugging 32-bit programs from a 64-bit host program.

	"%MSBUILD%" /p:Configuration="!CONFIGURATION! - Wow64" /p:Platform=!PLATFORM! /p:PlatformToolset=!TOOLSET! sleepy.sln
	if errorlevel 1 exit /b 1

	rem Now build the non-Wow64 configuration.

	"%MSBUILD%" /p:Configuration=!CONFIGURATION! /p:Platform=!PLATFORM! /p:PlatformToolset=!TOOLSET! sleepy.sln
	if errorlevel 1 exit /b 1

	rem Extract app information (needed by signing).
	rem Do this here as version.h is generated as part of the build.

	for /f "tokens=1,2*" %%a in (src\appinfo.h) do if [%%a] == [#define] if [%%b] == [APPNAME] set APPNAME=%%~c
	for /f "tokens=1,2*" %%a in (src\appinfo.h) do if [%%a] == [#define] if [%%b] == [APPURL]  set APPURL=%%~c
	for /f "tokens=1,2*" %%a in (src\version.h) do if [%%a] == [#define] if [%%b] == [VERSION] set VERSION=%%~c

	rem Sign, if signing is requested.

	if defined SIGN "!SIGNTOOL!" sign /n "!SIGN!" /a /d "!APPNAME! v!VERSION!"                /du "!APPURL!" /t http://time.certum.pl/ "obj\!PLATFORM!\!CONFIGURATION!\sleepy.exe"
	if errorlevel 1 exit /b 1
	if defined SIGN "!SIGNTOOL!" sign /n "!SIGN!" /a /d "!APPNAME! v!VERSION! crash reporter" /du "!APPURL!" /t http://time.certum.pl/ "obj\!PLATFORM!\!CONFIGURATION!\crashreport.exe"
	if errorlevel 1 exit /b 1
)

if not %CONFIGURATION% == Release goto :eof

rem Find InnoSetup

if not defined INNOSETUP for %%a in (ISCC.exe) do if not [%%~$PATH:a] == [] set INNOSETUP="%%~$PATH:a"
if not defined INNOSETUP if exist "%ProgramFiles%\Inno Setup 5\ISCC.exe" set INNOSETUP="%ProgramFiles%\Inno Setup 5\ISCC.exe"
if not defined INNOSETUP if exist "%ProgramFiles(x86)%\Inno Setup 5\ISCC.exe" set INNOSETUP="%ProgramFiles(x86)%\Inno Setup 5\ISCC.exe"
if not defined INNOSETUP if exist "%ProgramW6432%\Inno Setup 5\ISCC.exe" set INNOSETUP="%ProgramW6432%\Inno Setup 5\ISCC.exe"
if not defined INNOSETUP if exist "%SystemDrive%\Inno Setup 5\ISCC.exe" set INNOSETUP="%SystemDrive%\Inno Setup 5\ISCC.exe"
if not defined INNOSETUP echo build.cmd: Can't find InnoSetup! & exit /b 1
echo build.cmd: Found InnoSetup at: %INNOSETUP%

rem Build installer

if exist setup.exe del setup.exe
if exist setup.exe exit /b 1

if     defined SIGN %INNOSETUP% /dSIGN "/Ssleepy=$q%SIGNTOOL%$q sign /n $q%SIGN%$q /a $p /t http://time.certum.pl/ $f" installer.iss
if not defined SIGN %INNOSETUP%                                                                                        installer.iss
if errorlevel 1 exit /b 1
if not exist setup.exe exit /b 1

rem Package AppVeyor symbol archive artifact

if defined APPVEYOR !7ZIP! a symbols.7z "obj\*\Release\sleepy.pdb" "thirdparty\wine\dlls\dbghelp\vs\bin\*\*\dbghelpw.pdb"

echo build.cmd: Done!
