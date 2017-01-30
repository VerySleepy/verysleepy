@echo off
setlocal enabledelayedexpansion

rem Build Dr. MinGW

echo build.cmd: Building Dr. MinGW
call thirdparty\drmingw_build_mingw.cmd
if errorlevel 1 exit /b 1

rem Find MSBuild

if not defined MSBUILD for %%a in (msbuild.exe) do if not [%%~$PATH:a] == [] set MSBUILD=%%~$PATH:a
if not defined MSBUILD if exist "%ProgramFiles(x86)%\MSBuild\14.0\Bin\MSBuild.exe" set MSBUILD=%ProgramFiles(x86)%\MSBuild\14.0\Bin\MSBuild.exe
if not defined MSBUILD if exist "%ProgramFiles(x86)%\MSBuild\12.0\Bin\MSBuild.exe" set MSBUILD=%ProgramFiles(x86)%\MSBuild\12.0\Bin\MSBuild.exe
if not defined MSBUILD if exist %WinDir%\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe set MSBUILD=%WinDir%\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe
if not defined MSBUILD echo build.cmd: Can't find msbuild! & exit /b 1
echo build.cmd: Found msbuild at: %MSBUILD%

rem Build Very Sleepy

if not defined CONFIGURATION set CONFIGURATION=Release

for %%p in (Win32 x64) do (
	set PLATFORM=%%p

	echo build.cmd: Building !CONFIGURATION! ^| !PLATFORM!

	"%MSBUILD%" /p:Configuration="!CONFIGURATION! - Wow64" /p:Platform=!PLATFORM! sleepy.sln
	if errorlevel 1 exit /b 1

	"%MSBUILD%" /p:Configuration=!CONFIGURATION! /p:Platform=!PLATFORM! sleepy.sln
	if errorlevel 1 exit /b 1
)

echo build.cmd: Done!
