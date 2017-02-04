; Very Sleepy install script, for Inno Setup

#include "src/appinfo.h"
#include "src/version.h"

[Setup]
AppName={#APPNAME}
AppVersion={#VERSION}
VersionInfoVersion={#VERSION_MAJOR}.{#VERSION_MINOR}.{#VERSION_PATCH}.{#VERSION_DIRTY}

; AppId is used to identify the program in the registry.
AppId={#APPNAME}
AppPublisher={#VENDOR}
AppPublisherURL=http://{#VENDOR}/
AppSupportURL={#APPURL}
DefaultDirName={pf}\{#APPNAME}
DefaultGroupName={#APPNAME}
AllowNoIcons=yes
LicenseFile=license.rtf
OutputBaseFilename=setup
SetupIconFile=src\res\sleepy.ico
Compression=lzma
SolidCompression=yes
OutputDir=.
ArchitecturesInstallIn64BitMode=x64
UninstallDisplayIcon={app}\sleepy.exe
DisableWelcomePage=no

#ifdef SIGN
SignTool=sleepy /d "{#APPNAME} v{#VERSION} installer" /du "{#APPURL}"
#endif

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]

; 32-bit version
Source: "obj\Win32\Release\sleepy.exe"                   ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "src\crashback\bin\Win32\Release\crashreport.exe"; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "dbghelp_x86\dbghelpms.dll"                      ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "dbghelp_x86\dbghelpms6.dll"                     ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "dbghelp_x86\symsrv.dll"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "dbghelp_x86\srcsrv.dll"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "dbghelp_x86\symsrv.yes"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "obj\Win32\Release\dbghelpw.dll"                 ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "obj\Win32\Release\dbghelpdr.dll"                ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "obj\Win32\Release\msvcr120.dll"                 ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "obj\Win32\Release\msvcp120.dll"                 ; DestDir: "{app}"   ; Flags: ignoreversion; Check: not Is64BitInstallMode

; 64-bit version
Source: "obj\x64\Release\sleepy.exe"                     ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "src\crashback\bin\x64\Release\crashreport.exe"  ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x64\dbghelpms.dll"                      ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x64\dbghelpms6.dll"                     ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x64\symsrv.dll"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x64\srcsrv.dll"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x64\symsrv.yes"                         ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\x64\Release\dbghelpw.dll"                   ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\x64\Release\dbghelpw_wow64.dll"             ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\x64\Release\dbghelpdr.dll"                  ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\x64\Release\msvcr120.dll"                   ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\x64\Release\msvcp120.dll"                   ; DestDir: "{app}"   ; Flags: ignoreversion; Check:     Is64BitInstallMode

; 32-bit version for 64-bit systems
Source: "obj\Win32\Release\sleepy.exe"                   ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "src\crashback\bin\Win32\Release\crashreport.exe"; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x86\dbghelpms.dll"                      ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x86\dbghelpms6.dll"                     ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x86\symsrv.dll"                         ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x86\srcsrv.dll"                         ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "dbghelp_x86\symsrv.yes"                         ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\Win32\Release\dbghelpw.dll"                 ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\Win32\Release\dbghelpdr.dll"                ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\Win32\Release\msvcr120.dll"                 ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode
Source: "obj\Win32\Release\msvcp120.dll"                 ; DestDir: "{app}\32"; Flags: ignoreversion; Check:     Is64BitInstallMode


; Other bits
Source: "keywords.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "license.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "osfunctions.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "osmodules.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[InstallDelete]
; Delete dbghelp.dll installed by older versions
Type: files; Name: "{app}\dbghelp.dll"
Type: files; Name: "{app}\32\dbghelp.dll"


[Icons]
Name: "{group}\{#APPNAME}"; Filename: "{app}\sleepy.exe"
Name: "{group}\{#APPNAME} (32-bit)"; Filename: "{app}\32\sleepy.exe"; Check: Is64BitInstallMode

[Run]
Filename: "{app}\sleepy.exe"; Description: "{cm:LaunchProgram,{#APPNAME}}"; Flags: nowait postinstall skipifsilent

[Code]
const
  MsiDir = 'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{49CCD620-07C3-48B3-9B53-D1E104DC47D0}';
  MsiUninstall = '/uninstall {49CCD620-07C3-48B3-9B53-D1E104DC47D0} /passive';

var
  MsiExists: Boolean;
  MsiPage: TInputOptionWizardPage;

procedure InitializeWizard();
begin
  MsiExists := False;

  // Prompt to remove version 0.6 if it exists
  if RegKeyExists( HKLM, MsiDir ) then
  begin
    MsiExists := True;

    MsiPage := CreateInputOptionPage(wpWelcome,
      'Previous Version', 'An older version was detected.',
      'Would you like to first remove the older version of {#APPNAME}?',
      True, False);

    MsiPage.Add('Uninstall the older version first.');
    MsiPage.Add('Leave it where it is.');

    MsiPage.Values[0] := True;
  end;
end;

function NextButtonClick(CurPageID: Integer): Boolean;
var
  ResultCode: Integer;

begin
  Result := True;

  // Remove the old version right here, before we prompt to pick a new directory.
  if MsiExists then
  begin
    if (CurPageID = MsiPage.ID) and (MsiPage.Values[0]) then
    begin
      if not Exec('MsiExec.exe', MsiUninstall, '', SW_SHOW, ewWaitUntilTerminated, ResultCode) then
      begin
        MsgBox('The previous version could not be uninstalled. Please uninstall it manually.', mbError, MB_OK);
        Result := False;
      end;
    end;
  end;
end;
