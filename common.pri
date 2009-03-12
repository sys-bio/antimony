!contains(DEFINES,NSBML){

isEmpty(LIBSBML_DIR) {
win32:LIBSBML_DIR=c:\Program Files\SBML\libSBML-3.3.1-expat\win32
unix:LIBSBML_DIR=/usr/local/lib
mac:LIBSBML_DIR=/usr/local/lib
}


message("using libsbml from: $${LIBSBML_DIR}")

win32:INCLUDEPATH += "$${LIBSBML_DIR}\include" "$${LIBSBML_DIR}\include/sbml"
win32:LIBS +=  -llibsbml 

win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\lib" 
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\bin" 
#For whatever reason this does not work on XP
#win32:LIBS += -L"$${LIBSBML_DIR}\bin" 
#win32:LIBS += -L"$${LIBSBML_DIR}\lib" 

win32:DEFINES +=  LIB_EXPORTS WIN32 _CRT_SECURE_NO_WARNINGS

mac:LIBS += -lsbml -L/usr/local/lib  -L$${LIBSBML_DIR}

unix:LIBS += -lsbml -L/usr/local/lib -L$${LIBSBML_DIR}

} else {
message("not using LIBSBML")
}

mac:CONFIG -= app_bundle
mac:CONFIG += x86 ppc


DESTDIR = ../bin/
OBJECTS_DIR = ./tmp/
