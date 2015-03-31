set WXWIN=C:\Prj\3rdParty\wxWidgets\2.9.5\

if exist "%VS120COMNTOOLS%vsvars32.bat" (
call "%VS120COMNTOOLS%vsvars32.bat"
) else if exist "%VS110COMNTOOLS%vsvars32.bat" (
call "%VS110COMNTOOLS%vsvars32.bat"
) else if exist "%VS100COMNTOOLS%vsvars32.bat" (
call "%VS100COMNTOOLS%vsvars32.bat"
)

del %~dp0*.sdf
@rem rmdir /s /q %~dp0x64
start devenv.com %~dp0sleepy-v12.sln
