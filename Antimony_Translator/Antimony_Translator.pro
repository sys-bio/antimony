# -------------------------------------------------
# Project created by QtCreator 2009-06-01T16:21:30
# -------------------------------------------------
TARGET = Antimony_Translator
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    AntimonyTab.cpp \
    SBMLTab.cpp \
    Translator.cpp \
    ChangeableTextBox.cpp \
    TabManager.cpp
HEADERS += mainwindow.h \
    AntimonyTab.h \
    SBMLTab.h \
    Translator.h \
    ChangeableTextBox.h \
    TabManager.h
INCLUDEPATH += /home/lpsmith/antimony/src/
LIBS += -L/home/lpsmith/antimony/lib/ -lantimony -L/usr/local/lib -lsbml
