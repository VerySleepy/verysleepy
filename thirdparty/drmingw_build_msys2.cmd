@echo off
setlocal enabledelayedexpansion

rem This batch file attempts to build Dr. MinGW using MSys2
rem (https://msys2.github.io/) in a way that's compatible with Very
rem Sleepy's project file.

rem Note that this method is not recommended - currently, MSys2 only
rem packages MinGW with POSIX threads, whereas Dr. MinGW is
rem recommended to be built with Win32 threads. Using POSIX threads
rem will result in lower performance and a dependency to
rem libwinpthread-1.dll (which can manifest in an error message such
rem as "Could not load dbghelpdr.dll: %1 is not a valid Win32
rem application" in Very Sleepy).

rem You can run:
rem $ pacman -S --needed mingw-w64-{i686,x86_64}-{gcc,make}
rem in the MSys2 shell to install the necessary MSys2 packages.

rem Find MSys2.

if not defined MSYS2 for %%a in (mingw32-make.exe) do (
	set MSYS2_EXE=%%~$PATH:a
	if not [!MSYS2_EXE!] == [] for %%b in ("!MSYS2_EXE!") do (
		set MSYS2_BIN=%%~dpb
		for %%c in ("!MSYS2_BIN:~0,-1!") do (
			set MSYS2_MGW=%%~dpc
			for %%d in ("!MSYS2_MGW:~0,-1!") do set MSYS2=%%~dpd
		)
	)
)

if not defined MSYS2 if exist "!SystemDrive!\msys64" set MSYS2="!SystemDrive!\msys64"

if not defined MSYS2 echo drmingw_build: Can't find MSys2 installation - please add it to PATH or specify the path to it in the MSYS2 environment variable. & exit /b 1

echo drmingw_build: Found MSys2 at !MSYS2!

rem Find CMake.

if not defined CMAKE for %%a in (cmake.exe) do (
	set CMAKE_EXE=%%~$PATH:a
	if not [!CMAKE_EXE!] == [] for %%b in ("!CMAKE_EXE!") do (
		set CMAKE_BIN=%%~dpb
		for %%c in ("!CMAKE_BIN:~0,-1!") do set CMAKE=%%~dpc
	)
)

if not defined CMAKE if exist "!ProgramFiles!\CMake" set CMAKE=!ProgramFiles!\CMake

if not defined CMAKE if exist "!ProgramFiles(x86)!\CMake" set CMAKE=!ProgramFiles(x86)!\CMake

if not defined CMAKE if exist "!SystemDrive!\CMake" set CMAKE=!SystemDrive!\CMake

if not defined CMAKE echo drmingw_build: Can't find CMake installation - please add it to PATH or specify the path to it in the CMAKE environment variable. & exit /b 1

echo drmingw_build: Found CMake at !CMAKE!

rem Build!

for %%t in (32 64) do (
	set TARGET=%%t
	echo drmingw_build: Building for mingw!TARGET!

	cd "%~dp0"
	if not exist drmingw_build_!TARGET! mkdir drmingw_build_!TARGET!
	cd drmingw_build_!TARGET!

	rem Clear and rebuild PATH to ensure that nothing may contaminate it.
	set PATH=!MSYS2!\mingw!TARGET!\bin;!CMAKE!\bin;!WinDir!\System32
	set MAKE=
	set CC=

	if not exist Makefile cmake -G "MinGW Makefiles" ..\drmingw
	if errorlevel 1 exit /b 1

	cmake --build . --target mgwhelp
	if errorlevel 1 exit /b 1
)
if errorlevel 1 exit /b 1

echo drmingw_build: Done!
