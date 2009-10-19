######################################################################
# Automatically generated by qmake (2.01a) Wed Feb 25 19:03:53 2009
######################################################################

include(common.pri)


TEMPLATE = lib

TARGET = antimony
CONFIG -= qt
unix:CONFIG += staticlib
unix:CONFIG -= dll plugin
mac:CONFIG += staticlib
mac:CONFIG -= dll plugin
DEPENDPATH += . src
INCLUDEPATH += . src

# Input
#YACCSOURCES += src/antimony.ypp

HEADERS += src/antimony_api.h \
           src/dnastrand.h \
           src/event.h \
           src/formula.h \
           src/libutil.h \
           src/module.h \
           src/enums.h \
           src/reactantlist.h \
           src/reaction.h \
           src/registry.h \
           src/sbmlx.h \
           src/stringx.h \
	   src/typex.h \
           src/userfunction.h \
           src/variable.h
SOURCES += src/Antimony.cpp \
           src/antimony_api.cpp \
           src/antimony.tab.cpp \
           src/dnastrand.cpp \
           src/event.cpp \
           src/formula.cpp \
           src/module.cpp \
           src/reactantlist.cpp \
           src/reaction.cpp \
           src/registry.cpp \
           src/sbmlx.cpp \
           src/stringx.cpp \
	   src/typex.cpp \
           src/userfunction.cpp \
           src/variable.cpp