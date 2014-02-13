; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Antimony Python bindings"
#define MyAppVersion "2.5.0"
#define MyAppPublisher "University of Washington, Seattle, WA, USA"
#define MyAppURL "http://antimony.sourceforge.net/"
#define MyAppSetupIconFile "..\install-release\bin\antimony.ico"
#define ThisInstallerPostfix "win32"
 
#define Py "Python"
#define PyVer "2.7"
#define AppDir "antimony"

;Used for downloader
;#include ReadReg(HKEY_LOCAL_MACHINE,'Software\Sherlock Software\InnoTools\Downloader','ScriptPath','');

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{CA28ACCA-CD39-4A1D-A346-BDA989E8494E}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DisableWelcomePage=yes
DefaultDirName={code:SetDefaultAppDirName}

;enable the next line for debug only
;DisableDirPage=yes


;DefaultGroupName=libRoadRunner
DisableProgramGroupPage=yes
;LicenseFile=..\..\LICENSE.txt
;InfoBeforeFile=..\..\NOTICE.txt
DisableReadyPage=yes
;DisableFinishedPage=yes ;Finished page is good feedback
OutputDir=.
OutputBaseFilename={#MyAppName}-{#MyAppVersion}-{#ThisInstallerPostfix}
SetupIconFile={#MyAppSetupIconFile}
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: ..\install-release\bindings\python\{#AppDir}\*; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs
Source: ..\install-release\bindings\python\libantimony.pth; DestDir: {app}\..\; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\LICENSE.TXT"; DestDir: "{app}"; Flags: ignoreversion

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Code]
//////////////////////////////////////////////////////////////////////////////
const
  appDir = '{#AppDir}';
  pyReg = 'SOFTWARE\{#Py}\PythonCore\{#PyVer}\InstallPath';
  pyRegWow6443Node = 'SOFTWARE\Wow6432Node\{#Py}\PythonCore\{#PyVer}\InstallPath';

var
  DefaultAppDirName: String;

//////////////////////////////////////////////////////////////////////////////
function GetPathForPythonSitePackages(): string;
var          
  InstallPath: string;
begin
  
  if RegQueryStringValue(HKEY_LOCAL_MACHINE, pyReg, '', InstallPath) then
    begin
    Log('HKLM pyReg: '+ InstallPath);
    Result := InstallPath + 'Lib\site-packages\';
    end
  else
  if RegQueryStringValue(HKEY_CURRENT_USER, pyReg, '', InstallPath) then
    begin
    Log('HKCU pyReg: '+ InstallPath);
    Result := InstallPath + 'Lib\site-packages\'; 
    end
  else
  if RegQueryStringValue(HKEY_LOCAL_MACHINE, pyRegWow6443Node, '', InstallPath) then
    begin
    Log('HKLM pyRegWow6443Node: '+ InstallPath);
    Result := InstallPath + 'Lib\site-packages\';
    end
  else
    begin
    MsgBox('Our installer did not find your Python installation. You need '
    + 'Python to run {#MyAppName}. In the next step use [Your Python installation'
    + ' location]\Lib\site-packages\{#AppDir} directory.',mbError,MB_OK);
    end
end;

//////////////////////////////////////////////////////////////////////////////
function SetDefaultAppDirName(Value: String): String;
begin
  
  if (GetPathForPythonSitePackages() <> '') then
    begin
    DefaultAppDirName := GetPathForPythonSitePackages() + AppDir;
    Result := DefaultAppDirName;
    end
  else 
    begin
    Result := 'C:\Python27\Lib\site-packages\{#AppDir}';
    end;

end;

