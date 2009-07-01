# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------
LIBSBML_DIR = ..\..\libSBML-3.3.2
message("using libsbml from: $${LIBSBML_DIR}")
CONFIG -= debug
CONFIG += release
INCLUDEPATH += "$${LIBSBML_DIR}\include" \
    "$${LIBSBML_DIR}\include/sbml"
LIBS += -llibsbml \
    -lantimony
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\lib"
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
    FileWatcher.cpp
HEADERS += AntimonyTab.h \
    SBMLTab.h \
    Translator.h \
    ChangeableTextBox.h \
    TabManager.h \
    QTAntimony.h \
    FileWatcher.h
INCLUDEPATH += ..\src \
    LIBS \
    += \
    -L..\win32\ \
    -lantimony \
    -L..\..\libsbml-3.3.2\win32\bin \
    -llibsbml
