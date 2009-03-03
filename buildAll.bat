
qmake CONFIG-=debug CONFIG+=release CONFIG+=dll antimony.pro && nmake 
REM clean && nmake
qmake -t vclib antimony.pro
qmake CONFIG-=debug CONFIG+=release antimony2sbml.pro && nmake 
qmake -t vcapp antimony2sbml.pro
qmake CONFIG-=debug CONFIG+=release sbml2antimony.pro && nmake 
qmake -t vcapp sbml2antimony.pro
qmake CONFIG-=debug CONFIG+=release testantimony.pro && nmake 
qmake -t vcapp testantimony.pro
