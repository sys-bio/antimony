# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------

include(../common.pri)

contains(DEFINES,NSBML){
	error("Cannot compile sbml2antimony without LIBSBML, but NSBML is defined")
}


isEmpty(SBW_DIR) { 
    win32:SBW_DIR = ..\..\sbw
    unix:SBW_DIR = ../../SBW-2.7.6/
    mac:SBW_DIR = ../../buildall/build/cvs-dl/core/
}
mac:DEFINES  += DARWIN LINUX
unix:DEFINES += LINUX

DEFINES      += SBW_INTEGRATION
LIBS += -L$${SBW_DIR}/lib \
    -lSBW
INCLUDEPATH += $${SBW_DIR}/include


INCLUDEPATH += "$${LIBSBML_DIR}/include" "$${LIBSBML_DIR}/include/sbml"  "../src"
LIBS += -L../lib/      -lantimony 


win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\win32\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"..\win32"
win32:RC_FILE = ../QTAntimony/antimonyicon.rc

mac:ICON=antimony.icns

TARGET = QTAntimony

TEMPLATE = app

SOURCES += ../QTAntimony/main.cpp \
    ../QTAntimony/AntimonyTab.cpp \
    ../QTAntimony/SBMLTab.cpp \
    ../QTAntimony/Translator.cpp \
    ../QTAntimony/ChangeableTextBox.cpp \
    ../QTAntimony/TabManager.cpp \
    ../QTAntimony/QTAntimony.cpp \
    ../QTAntimony/FileWatcher.cpp \
    ../QTAntimony/SBWIntegration.cpp \
    ../QTAntimony/CopyMessageBox.cpp\
    ../QTAntimony/Tutorial.cpp
HEADERS += ../QTAntimony/AntimonyTab.h \
    ../QTAntimony/SBMLTab.h \
    ../QTAntimony/Translator.h \
    ../QTAntimony/ChangeableTextBox.h \
    ../QTAntimony/TabManager.h \
    ../QTAntimony/QTAntimony.h \
    ../QTAntimony/FileWatcher.h \
    ../QTAntimony/SBWIntegration.h \
    ../QTAntimony/Tutorial.h
