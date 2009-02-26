isEmpty(LIBSBML_DIR) {
win32:LIBSBML_DIR=C:\Users\fbergmann\Documents\Visual Studio Codename Orcas\Projects\libsbml
unix:LIBSBML_DIR=/usr/local/lib
mac:LIBSBML_DIR=/usr/local/lib
}

message("using libsbml from: $${LIBSBML_DIR}")

win32:INCLUDEPATH += "$${LIBSBML_DIR}\include" "$${LIBSBML_DIR}\include/sbml"
win32:LIBS +=  -llibsbml3 
win32:QMAKE_LFLAGS += /LIBPATH:"$${LIBSBML_DIR}\win32\bin"
win32:DEFINES +=  LIB_EXPORTS WIN32

mac:LIBS += -lsbml -L/usr/local/lib  -L$${LIBSBML_DIR}

unix:LIBS += -lsbml -L/usr/local/lib -L$${LIBSBML_DIR}

mac:CONFIG -= app_bundle
mac:CONFIG += x86 ppc


DESTDIR = ./bin/
OBJECTS_DIR = ./tmp/
