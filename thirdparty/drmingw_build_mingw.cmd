@echo off
setlocal enabledelayedexpansion

rem This batch file attempts to build Dr. MinGW in a way
rem that's compatible with Very Sleepy's project file.

rem Find 7-Zip.

if not defined 7ZIP for %%a in (7z.exe) do if not [%%~$PATH:a] == [] set 7ZIP="%%~$PATH:a"
if not defined 7ZIP if exist "!ProgramFiles!\7-Zip\7z.exe" set 7ZIP="!ProgramFiles!\7-Zip\7z.exe"
if not defined 7ZIP if exist "!ProgramFiles(x86)!\7-Zip\7z.exe" set 7ZIP="!ProgramFiles(x86)!\7-Zip\7z.exe"
if not defined 7ZIP if exist "!SystemDrive!\7-Zip\7z.exe" set 7ZIP="!SystemDrive!\7-Zip\7z.exe"
if not defined 7ZIP echo drmingw_build: Can't find 7-Zip installation - please add it to PATH or specify the full path to 7z.exe in the 7ZIP environment variable. & exit /b 1
echo drmingw_build: Found 7-Zip at !7ZIP!

rem Download MinGW.

set MINGW32_FN=i686-6.3.0-release-win32-dwarf-rt_v5-rev1.7z
set MINGW64_FN=x86_64-6.3.0-release-win32-seh-rt_v5-rev1.7z

set MINGW32_URL=https://sourceforge.net/projects/mingw-w64/files/Toolchains%%20targetting%%20Win32/Personal%%20Builds/mingw-builds/6.3.0/threads-win32/dwarf/%MINGW32_FN%/download
set MINGW64_URL=https://sourceforge.net/projects/mingw-w64/files/Toolchains%%20targetting%%20Win64/Personal%%20Builds/mingw-builds/6.3.0/threads-win32/seh/%MINGW64_FN%/download

for %%t in (32 64) do (
	set FN=!MINGW%%t_FN!
	set URL=!MINGW%%t_URL!

	if not exist "%~dp0\mingw\!FN!" (
		echo Downloading !FN!...
		set DEST=%~dp0/mingw/!FN!
		call :download
		if errorlevel 1 exit /b 1
	)
	if not exist "%~dp0\mingw\mingw%%t" !7ZIP! x -o"%~dp0\mingw" %~dp0/mingw/!FN!
)

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
	set PATH=%~dp0\mingw\mingw!TARGET!\bin;!CMAKE!\bin;!WinDir!\System32
	set MAKE=
	set CC=

	if not exist Makefile cmake -G "MinGW Makefiles" ..\drmingw
	if errorlevel 1 exit /b 1

	cmake --build . --target mgwhelp
	if errorlevel 1 exit /b 1
)
if errorlevel 1 exit /b 1

echo drmingw_build: Done!
goto :eof

:download

rem Download !URL! to !DEST!.
rem Note: Positional parameters don't work here, as the percent signs in URLs are eagerly interpreted despite quoting.

for %%a in (powershell.exe) do if not [%%~$PATH:a] == [] powershell -Command "(New-Object Net.WebClient).DownloadFile('!URL!', '!DEST!')" & goto :eof
for %%a in (curl.exe) do if not [%%~$PATH:a] == [] curl "!URL!" -O "!DEST!" --location & goto :eof
for %%a in (wget.exe) do if not [%%~$PATH:a] == [] wget "!URL!" -o "!DEST!" --max-redirect=5 & goto :eof
for %%a in (bitsadmin.exe) do if not [%%~$PATH:a] == [] start /wait "MinGW download" bitsadmin /transfer "MinGW" "!URL!" "!DEST!" & goto :eof
echo No download utilities available - please download file at !URL! and save to !DEST! manually
exit /b 1
