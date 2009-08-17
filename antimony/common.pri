DEFINES += "NCELLML"
!contains(DEFINES,NSBML){

isEmpty(LIBSBML_DIR) {
win32:LIBSBML_DIR=..\libSBML-3.3.2
unix:LIBSBML_DIR=/usr/local/lib
mac:LIBSBML_DIR=/usr/local/lib
}

message("using libsbml from: $${LIBSBML_DIR}")


CONFIG -= debug
CONFIG += release

win32:INCLUDEPATH += "$${LIBSBML_DIR}\include" "$${LIBSBML_DIR}\include\sbml"

win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\lib" 
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\bin" 
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\win32\bin" 
#For whatever reason this does not work on XP
#win32:LIBS += -L"$${LIBSBML_DIR}\bin" 
#win32:LIBS += -L"$${LIBSBML_DIR}\lib" 

win32:DEFINES +=  LIB_EXPORTS WIN32 _CRT_SECURE_NO_WARNINGS

win32:LIBS +=  -L$${LIBSBML_DIR} -llibsbml

mac:LIBS += -lsbml -L/usr/local/lib  -L$${LIBSBML_DIR}

unix:LIBS += -lsbml -L/usr/local/lib -L$${LIBSBML_DIR}

} else {
message("not using LIBSBML")
}

mac:CONFIG -= app_bundle
mac:CONFIG += x86 ppc


DESTDIR = ../bin/
OBJECTS_DIR = ./tmp/
