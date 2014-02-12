#define AppDir "antimony"
#define Py "Python"
#define PyVer "2.7"

[Setup]
AppId={{9F5DF3DE-FBE7-4AC4-9AFD-357A1C256847}
DefaultGroupName=Antimony
UsePreviousGroup=true
AppName=QTAntimony
AppVerName=QTAntimony 2.5.0
DefaultDirName={pf}\Antimony
UsePreviousAppDir=false
[Icons]
Name: {group}\{cm:UninstallProgram, QTAntimony}; Filename: {uninstallexe}
Name: {group}\QTAntimony; Filename: {app}\QTAntimony.exe; WorkingDir: {userdocs}
Name: {group}\README; Filename: {app}\README.txt
[Run]
Filename: {app}\README.txt; Description: View the README file; Flags: postinstall shellexec skipifsilent
Filename: {app}\QTAntimony.exe; WorkingDir: {userdocs}; Flags: postinstall unchecked
[Dirs]
Name: {app}\biomodels
[Files]
Source: ..\install-release\bindings\*; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs
Source: ..\install-release\bin\QTAntimony.exe; DestDir: {app}
Source: ..\install-release\bin\QtCore4.dll; DestDir: {app}
Source: ..\install-release\bin\QtGui4.dll; DestDir: {app}
Source: ..\install-release\bin\README.txt; DestDir: {app}
Source: ..\install-release\bin\annotools.dll; DestDir: {app}
Source: ..\install-release\bin\antimony.ico; DestDir: {app}
Source: ..\install-release\bin\antimony2cellml.exe; DestDir: {app}
Source: ..\install-release\bin\antimony2sbml.exe; DestDir: {app}
Source: ..\install-release\bin\celeds.dll; DestDir: {app}
Source: ..\install-release\bin\cellml.dll; DestDir: {app}
Source: ..\install-release\bin\cellml2antimony.exe; DestDir: {app}
Source: ..\install-release\bin\cevas.dll; DestDir: {app}
Source: ..\install-release\bin\cuses.dll; DestDir: {app}
Source: ..\install-release\bin\libantimony.dll; DestDir: {app}
Source: ..\install-release\bin\libantimony.lib; DestDir: {app}
Source: ..\install-release\bin\libsbml.dll; DestDir: {app}
Source: ..\install-release\bin\libxml2.dll; DestDir: {app}
Source: ..\install-release\bin\malaes.dll; DestDir: {app}
Source: ..\install-release\bin\msvcp100.dll; DestDir: {app}
Source: ..\install-release\bin\msvcr100.dll; DestDir: {app}
Source: ..\install-release\bin\rehashantimony.exe; DestDir: {app}
Source: ..\install-release\bin\sbml2antimony.exe; DestDir: {app}
Source: ..\install-release\bin\sbtranslate.exe; DestDir: {app}
Source: ..\install-release\bin\telicems.dll; DestDir: {app}
Source: ..\install-release\bin\testantimony.exe; DestDir: {app}
Source: ..\doc\examples\ex_antimony_output.txt; DestDir: {app}
Source: ..\doc\examples\ex_sbml_input.xml; DestDir: {app}
Source: ..\doc\examples\ex_sbml_output___main_sbml.xml; DestDir: {app}
Source: ..\doc\examples\ex_sbml_output_bistable_sbml.xml; DestDir: {app}
Source: ..\doc\examples\ex_sbml_output_combined_model_sbml.xml; DestDir: {app}
Source: ..\doc\examples\ex_sbml_output_ffn_sbml.xml; DestDir: {app}
Source: ..\doc\examples\ex_sbml_output_ringoscil_sbml.xml; DestDir: {app}
Source: ..\doc\examples\ex_antimony_input.txt; DestDir: {app}
Source: ..\doc\examples\biomodels\BIOMD0000000001.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000002.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000003.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000004.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000005.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000006.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000007.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000008.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000009.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000010.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000011.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000012.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000013.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000014.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000015.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000016.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000017.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000018.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000019.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000020.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000021.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000022.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000023.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000024.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000025.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000026.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000027.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000028.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000029.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000030.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000031.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000032.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000033.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000034.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000035.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000036.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000037.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000038.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000039.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000040.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000041.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000042.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000043.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000044.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000045.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000046.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000047.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000048.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000049.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000050.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000051.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000052.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000053.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000054.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000055.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000056.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000057.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000058.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000059.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000060.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000061.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000062.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000063.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000064.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000065.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000066.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000067.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000068.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000069.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000070.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000071.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000072.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000073.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000074.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000075.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000076.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000077.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000078.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000079.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000080.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000081.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000082.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000083.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000084.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000085.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000086.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000087.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000088.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000089.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000090.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000091.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000092.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000093.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000094.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000095.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000096.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000097.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000098.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000099.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000100.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000101.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000102.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000103.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000104.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000105.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000106.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000107.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000108.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000109.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000110.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000111.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000112.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000113.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000114.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000115.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000116.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000117.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000118.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000119.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000120.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000121.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000122.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000123.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000124.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000125.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000126.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000127.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000128.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000129.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000130.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000131.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000132.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000133.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000134.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000135.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000136.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000137.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000138.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000139.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000140.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000141.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000142.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000143.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000144.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000145.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000146.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000147.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000148.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000149.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000150.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000151.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000152.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000153.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000154.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000155.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000156.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000157.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000158.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000159.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000160.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000161.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000162.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000163.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000164.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000165.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000166.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000167.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000168.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000169.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000170.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000171.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000172.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000173.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000174.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000175.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000176.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000177.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000178.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000179.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000180.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000181.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000182.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000183.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000184.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000185.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000186.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000187.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000188.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000189.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000190.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000191.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000192.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000193.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000194.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000195.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000196.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000197.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000198.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000199.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000200.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000201.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000202.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000203.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000204.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000205.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000206.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000207.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000208.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000209.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000210.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000211.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000212.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000213.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000214.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000215.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000216.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000217.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000218.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000219.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000220.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000221.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000222.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000223.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000224.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000225.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000226.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000227.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000228.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000229.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000230.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000231.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000232.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000233.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000234.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000235.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000236.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000237.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000238.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000239.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000240.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000241.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000242.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000243.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000244.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000245.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000246.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000247.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000248.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000249.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000250.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000251.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000252.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000253.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000254.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000255.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000256.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000257.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000258.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000259.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000260.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000261.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000262.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000263.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000264.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000265.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000266.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000267.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000268.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000269.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000270.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000271.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000272.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000273.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000274.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000275.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000276.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000277.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000278.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000279.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000280.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000281.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000282.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000283.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000284.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000285.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000286.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000287.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000288.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000289.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000290.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000291.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000292.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000293.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000294.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000295.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000296.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000297.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000298.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000299.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000300.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000301.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000302.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000303.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000304.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000305.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000306.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000307.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000308.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000309.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000310.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000311.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000312.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000313.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000314.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000315.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000316.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000317.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000318.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000319.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000320.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000321.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000322.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000323.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000324.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000325.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000326.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000327.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000328.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000329.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000330.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000331.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000332.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000333.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000334.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000335.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000336.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000337.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000338.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000339.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000340.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000341.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000342.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000343.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000344.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000345.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000346.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000347.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000348.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000349.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000350.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000351.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000352.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000353.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000354.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000355.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000356.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000357.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000358.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000359.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000360.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000361.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000362.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000363.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000364.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000365.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000366.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000367.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000368.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000369.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000370.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000371.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000372.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000373.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000374.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000375.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000376.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000377.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000378.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000379.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000380.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000381.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000382.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000383.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000384.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000385.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000386.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000387.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000388.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000389.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000390.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000391.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000392.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000393.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000394.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000395.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000396.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000397.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000398.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000399.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000400.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000401.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000402.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000403.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000404.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000405.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000406.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000407.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000408.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000409.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000410.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000411.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000412.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000413.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000414.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000415.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000416.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000417.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000418.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000419.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000420.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000421.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000422.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000423.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000424.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000425.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000426.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000427.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000428.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000429.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000430.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000431.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000432.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000433.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000434.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000435.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000436.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000437.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000438.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000439.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000440.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000441.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000442.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000443.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000444.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000445.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000446.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000447.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000448.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000449.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000450.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000451.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000452.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000453.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000454.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000455.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000456.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000457.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000458.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000459.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000460.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000461.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000462.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000463.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000464.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000465.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000466.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000467.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000468.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000469.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000470.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000471.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000472.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000473.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000474.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000475.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000476.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000477.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000478.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000479.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000480.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000481.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000482.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000483.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000484.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000485.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000486.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000487.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000488.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000489.txt; DestDir: {app}\biomodels\
Source: ..\doc\examples\biomodels\BIOMD0000000490.txt; DestDir: {app}\biomodels\

[Code]
//////////////////////////////////////////////////////////////////////////////
const
  appDir = '{#AppDir}';
  pyReg = 'SOFTWARE\{#Py}\PythonCore\{#PyVer}\InstallPath';
  pyRegWow6443Node = 'SOFTWARE\Wow6432Node\{#Py}\PythonCore\{#PyVer}\InstallPath';

var
  //installPython: Boolean;
  DefaultAppDirName: String;


//////////////////////////////////////////////////////////////////////////////
procedure ExitProcess(exitCode:integer);
  external 'ExitProcess@kernel32.dll stdcall';

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
    MsgBox('Could not find Python',mbError,MB_OK);
    //ExitProcess(1);
    end
end;

//////////////////////////////////////////////////////////////////////////////
function IsPythonInstalled(): Boolean;
var          
  InstallPath: string; //not really used here
begin
  
  if RegQueryStringValue(HKEY_LOCAL_MACHINE, pyReg, '', InstallPath) then
    begin
    Result := True;
    end
  else
  if RegQueryStringValue(HKEY_CURRENT_USER, pyReg, '', InstallPath) then
    begin
    Result := True;
    end
  else
  if RegQueryStringValue(HKEY_LOCAL_MACHINE, pyRegWow6443Node, '', InstallPath) then
    begin
    Result := True;
    end
  else
    begin
    Result := False;
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

//////////////////////////////////////////////////////////////////////////////
function IsInstalled(name: String): Boolean;
//function IsInstalled(name: string; version: string): boolean;  //ver not neeeded
var          
  InstallPath: string;
  //reg : string;
begin
  //reg := 'Software\' + name + '\' + version
  // + '\InstallPath'
  // Log('reg Python: ' + reg)
  
  //if Numpy/ matplotlib installed - direct check for file
  InstallPath := GetPathForPythonSitePackages() + name + '/__init__.py'
  Log('install dir: ' + InstallPath)
  if FileExists(InstallPath) then
  //if RegQueryStringValue(HKEY_CURRENT_USER, reg, 'InstallPath', InstallPath) then
   //numpy doesnt have a reg entry! (also gets its install path, not used here)
    begin 
    Result := True;
    end
  else 
    begin
    Result := False;
    end;
end;

//////////////////////////////////////////////////////////////////////////////
procedure RunMsiInstaller(execName: string);
var
  ResultCode: Integer;
  ExecPath: String;
  ExecCommand: String;
begin
  ExecPath := ExpandConstant('{tmp}\') + execName;
  ExecCommand := '/i ' + ExecPath + ''; //+ ' /qb'; //qb does it silently
 
  //Check that the msi installer file is present
  if FileExists(ExecPath) then
    begin
    Log('ExecPath exists : ' + ExecPath);
    end 
  else 
    begin
    Log('ExecPath doe not exist : ' + ExecPath);
    MsgBox('Could not find ' + execName + ' installer',mbError,MB_OK);
    ExitProcess(1);
    //something went wrong: hell or high water python installer must be there
    end;
  
  //execute msi installer, otherwie error and exit
  if not ShellExec('', 'msiexec.exe', ExecCommand, '', SW_SHOWNORMAL, 
                   ewWaitUntilTerminated, ResultCode) then
      //msi exec not working
      MsgBox('Msi installer failed to run!' + #13#10 + ExecCommand + ' ' +  
             SysErrorMessage(ResultCode), mbError, MB_OK);
end;

procedure RunOtherInstaller(execName: string);
var
  ResultCode: Integer;
begin
  if not Exec(ExpandConstant('{tmp}\' + execName), '', '', SW_SHOWNORMAL,
    ewWaitUntilTerminated, ResultCode)
  then
    MsgBox('Other installer failed to run!' + #13#10 + execName +
      SysErrorMessage(ResultCode), mbError, MB_OK);
end; 
