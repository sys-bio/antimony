# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------
isEmpty(LIBSBML_DIR) { 
    win32:LIBSBML_DIR = ..\..\libSBML-3.3.2
    unix:LIBSBML_DIR = /usr/local/lib
    mac:LIBSBML_DIR = /usr/local/lib
}
isEmpty(SBW_DIR) { 
    win32:SBW_DIR = ..\..\sbw
    unix:SBW_DIR = ../../SBW-2.7.6/
    mac:SBW_DIR = ../../buildall/build/cvs-dl/core/
}
mac:DEFINES += DARWIN \
    LINUX
unix:DEFINES += LINUX
DEFINES += SBW_INTEGRATION
LIBS += -L$${SBW_DIR}/lib \
    -lSBW-static
INCLUDEPATH += $${SBW_DIR}/include
message("using libsbml from: $${LIBSBML_DIR}")
CONFIG -= debug
CONFIG += release
INCLUDEPATH += "$${LIBSBML_DIR}/include" \
    "$${LIBSBML_DIR}/include/sbml" \
    "../src"
LIBS += -L../lib/ \
    -lantimony \
    -L$${LIBSBML_DIR} \
    -lsbml \
# -lxml2 \
# -lz \
# -lbz2


win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\win32\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"..\win32"
TARGET = QTAntimony
TEMPLATE = app
SOURCES += main.cpp \
    AntimonyTab.cpp \
    SBMLTab.cpp \
    Translator.cpp \
    ChangeableTextBox.cpp \
    TabManager.cpp \
    QTAntimony.cpp \
    FileWatcher.cpp \
    SBWIntegration.cpp \
    Tutorial.cpp
HEADERS += AntimonyTab.h \
    SBMLTab.h \
    Translator.h \
    ChangeableTextBox.h \
    TabManager.h \
    QTAntimony.h \
    FileWatcher.h \
    SBWIntegration.h \
    Tutorial.h
