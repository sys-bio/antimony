# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------
TARGET = QTAntimony
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    AntimonyTab.cpp \
    SBMLTab.cpp \
    Translator.cpp \
    ChangeableTextBox.cpp \
    TabManager.cpp \
    QTAntimony.cpp \
    FileWatcher.cpp
HEADERS += mainwindow.h \
    AntimonyTab.h \
    SBMLTab.h \
    Translator.h \
    ChangeableTextBox.h \
    TabManager.h \
    QTAntimony.h \
    FileWatcher.h
INCLUDEPATH += /home/lpsmith/antimony/src/
LIBS += -L/home/lpsmith/antimony/lib/ \
    -lantimony \
    -L/usr/local/lib \
    -lsbml
