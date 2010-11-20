# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------
isEmpty(LIBSBML_DIR) { 
    win32:LIBSBML_DIR = ..\..\libSBML-3.3.2
    unix:LIBSBML_DIR = /usr/local/
    mac:LIBSBML_DIR = /usr/local/
}
isEmpty(SBW_DIR) { 
    win32:SBW_DIR = ..\..\sbw
    unix:SBW_DIR = ../../sbw-2.7.6/
    mac:SBW_DIR = ../../buildall/build/cvs-dl/core/
}

# CellML Stuff:
isEmpty(CELLML_DIR) { 
    win32:CELLML_DIR = ..\..\CellML
    unix:CELLML_DIR = ../../CellML/hg
    mac:CELLML_DIR = ../../CellML
}
isEmpty(CELLML_API):CELLML_API = $${CELLML_DIR}/cellml-api
isEmpty(CELLML_OPENCELL):CELLML_OPENCELL = $${CELLML_DIR}/cellml-opencell
isEmpty(XULRUNNER):XULRUNNER = /home/lpsmith/xulrunner-sdk
isEmpty(CELLML_INCLUDES):CELLML_INCLUDES = -I/usr/local/include \
    -I$${XULRUNNER}/include/ \
    -I$${XULRUNNER}/include/xpcom \
    -I$${XULRUNNER}/include/nspr \
    -I$${XULRUNNER}/include/necko \
    -I$${XULRUNNER}/include/string \
    -I$${XULRUNNER}/include/dom \
    -I$${XULRUNNER}/include/js \
    -I$${XULRUNNER}/include/editor \
    -I$${XULRUNNER}/include/docshell \
    -I$${XULRUNNER}/include/content \
    -I$${XULRUNNER}/include/rdf \
    -I$${CELLML_API} \
    -I$${CELLML_API}/sources \
    -I$${CELLML_API}/interfaces \
    -I$${CELLML_API}/simple_interface_generators/glue/xpcom \
    -I$${CELLML_OPENCELL}/DataCollector \
    -I$${CELLML_OPENCELL}/stubs
isEmpty(CELLML_INSTALLED_LIBRARY):CELLML_INSTALLED_LIBARARY = /usr/local/lib/
isEmpty(CELLML_LIBRARIES):CELLML_LIBRARIES = -L$${XULRUNNER}/lib \
    -l'xpcomglue_s' \
    -l'xpcom' \
    -l'xul' \
    -l'embed_base_s' \
    -l'sqlite3' \
    -l'mozjs' \
    -L$${CELLML_INSTALLED_LIBRARY} \
    -lcellml \
    -lcevas \
    -L$${CELLML_OPENCELL_DIR}/opencellStage/components/ \
    -lDataCollector
mac:DEFINES += DARWIN \
    LINUX
unix:DEFINES += LINUX

# DEFINES += SBW_INTEGRATION
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
    $${CELLML_LIBRARIES} \
    -L$${LIBSBML_DIR}/lib \
    -L$${LIBSBML_DIR} \
    -lsbml

# -lxml2 \
# -lz \
# -lbz2
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\win32\bin"
win32:QMAKE_LFLAGS += /LIBPATH:"..\win32"
win32:RC_FILE = antimonyicon.rc
mac:ICON = antimony.icns
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
    Tutorial.cpp \
    CopyMessageBox.cpp \
    CellMLTab.cpp
HEADERS += AntimonyTab.h \
    SBMLTab.h \
    Translator.h \
    ChangeableTextBox.h \
    TabManager.h \
    QTAntimony.h \
    FileWatcher.h \
    SBWIntegration.h \
    Tutorial.h \
    Settings.h \
    CopyMessageBox.h \
    CellMLTab.h
