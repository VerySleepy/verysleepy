; Very Sleepy install script, for Inno Setup

[Setup]
AppName=Very Sleepy
AppVersion=0.82

; AppId is used to identify the program in the registry.
AppId=Very Sleepy
AppPublisher=codersnotes.com
AppPublisherURL=http://www.codersnotes.com
AppSupportURL=http://www.codersnotes.com
AppUpdatesURL=http://www.codersnotes.com
DefaultDirName={pf}\Very Sleepy
DefaultGroupName=Very Sleepy
AllowNoIcons=yes
LicenseFile=license.rtf
OutputBaseFilename=setup
SetupIconFile=src\sleepy.ico
Compression=lzma
SolidCompression=yes
OutputDir=.
ArchitecturesInstallIn64BitMode=x64


[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
; 32-bit version
Source: "S:\Projects\sleepy\obj\Win32\Release\sleepy.exe"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\src\crashback\bin\Win32\Release\crashreport.exe"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x86\dbghelp.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x86\dbghelpw.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x86\symsrv.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x86\srcsrv.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x86\symsrv.yes"; DestDir: "{app}"; Flags: ignoreversion; Check: not Is64BitInstallMode

; 64-bit version
Source: "S:\Projects\sleepy\obj\x64\Release\sleepy.exe"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\src\crashback\bin\x64\Release\crashreport.exe"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\dbghelp.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\dbghelpw.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\dbghelpw_wow64.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\symsrv.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\srcsrv.dll"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode
Source: "S:\Projects\sleepy\dbghelp_x64\symsrv.yes"; DestDir: "{app}"; Flags: ignoreversion; Check: Is64BitInstallMode

; Other bits
Source: "S:\Projects\sleepy\keywords.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "S:\Projects\sleepy\license.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "S:\Projects\sleepy\osfunctions.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "S:\Projects\sleepy\osmodules.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Very Sleepy"; Filename: "{app}\sleepy.exe"

[Run]
Filename: "{app}\sleepy.exe"; Description: "{cm:LaunchProgram,Very Sleepy}"; Flags: nowait postinstall skipifsilent

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
      'Would you like to first remove the older version of Very Sleepy?',
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

