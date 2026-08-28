#define MyAppName "QTAntimony"
#ifndef MyAppVersion
  #define MyAppVersion "3.1.3"
#endif
#define MyAppSetupIconFile "..\QTAntimony_src\antimony.ico"

; Defaults to the relative layout a local 'cmake --install' with the
; convention used elsewhere in this repo (an install-release/ dir sibling to
; win32/) produces. CI overrides this via 'iscc /DInstallDir=...' to point at
; wherever its own install step actually put things.
#ifndef InstallDir
  #define InstallDir "..\install-release"
#endif

[Setup]
AppId={{9F5DF3DE-FBE7-4AC4-9AFD-357A1C256847}
DefaultGroupName=Antimony
UsePreviousGroup=true
AppName={#MyAppName}
AppVerName={#MyAppName} {#MyAppVersion}
DefaultDirName={autopf}\Antimony
UsePreviousAppDir=false
OutputDir=.
OutputBaseFilename=antimonyInstaller_v{#MyAppVersion}
SetupIconFile={#MyAppSetupIconFile}
ArchitecturesInstallIn64BitMode=x64compatible
ArchitecturesAllowed=x64compatible
[Icons]
Name: {group}\{cm:UninstallProgram, QTAntimony}; Filename: {uninstallexe}
Name: {group}\QTAntimony; Filename: {app}\QTAntimony.exe; WorkingDir: {autodocs}
Name: {group}\README; Filename: {app}\README.txt
[Run]
Filename: {app}\README.txt; Description: View the README file; Flags: postinstall shellexec skipifsilent
Filename: {app}\QTAntimony.exe; WorkingDir: {autodocs}; Flags: postinstall unchecked
[Dirs]
Name: {app}\biomodels
[Files]
Source: {#InstallDir}\bin\QTAntimony.exe; DestDir: {app}
Source: {#InstallDir}\bin\Qt5Core.dll; DestDir: {app}
Source: {#InstallDir}\bin\Qt5Gui.dll; DestDir: {app}
Source: {#InstallDir}\bin\Qt5PrintSupport.dll; DestDir: {app}
Source: {#InstallDir}\bin\Qt5Widgets.dll; DestDir: {app}
Source: {#InstallDir}\bin\platforms\qwindows.dll; DestDir: {app}\platforms
Source: {#InstallDir}\bin\README.txt; DestDir: {app}
Source: {#InstallDir}\bin\antimony.ico; DestDir: {app}
Source: {#InstallDir}\bin\antimony_ico.png; DestDir: {app}
Source: {#InstallDir}\bin\antimony2sbml.exe; DestDir: {app}
Source: {#InstallDir}\bin\rehashantimony.exe; DestDir: {app}
Source: {#InstallDir}\bin\sbml2antimony.exe; DestDir: {app}
Source: {#InstallDir}\bin\sbtranslate.exe; DestDir: {app}
Source: {#InstallDir}\bin\testantimony.exe; DestDir: {app}
Source: {#InstallDir}\lib\libantimony.dll; DestDir: {app}
Source: {#InstallDir}\lib\libantimony.lib; DestDir: {app}
Source: ..\doc\examples\ex_antimony_output.txt; DestDir: {app}
Source: ..\doc\examples\ex_sbml_input.xml; DestDir: {app}
Source: ..\doc\examples\ex_antimony_input.txt; DestDir: {app}
Source: ..\doc\examples\bistable.txt; DestDir: {app}
Source: ..\doc\examples\bistable.xml; DestDir: {app}
Source: ..\doc\examples\feed_forward_network.txt; DestDir: {app}
Source: ..\doc\examples\feed_forward_network.xml; DestDir: {app}
Source: ..\doc\examples\ring_oscillator.txt; DestDir: {app}
Source: ..\doc\examples\ring_oscillator.xml; DestDir: {app}
Source: ..\doc\examples\combined.txt; DestDir: {app}
Source: ..\doc\examples\combined_comp.xml; DestDir: {app}
Source: ..\doc\examples\combined_flat.xml; DestDir: {app}
Source: ..\doc\examples\combined_with_signal.txt; DestDir: {app}
Source: ..\doc\examples\combined_with_signal_comp.xml; DestDir: {app}
Source: ..\doc\examples\combined_with_signal_flat.xml; DestDir: {app}
Source: "..\doc\examples\biomodels\*"; DestDir: "{app}\biomodels"; Flags: recursesubdirs createallsubdirs
