!contains(DEFINES,NSBML){

isEmpty(LIBSBML_DIR) {
win32:LIBSBML_DIR=C:\Users\fbergmann\Documents\Visual Studio Codename Orcas\Projects\libsbml
unix:LIBSBML_DIR=/usr/local/lib
mac:LIBSBML_DIR=/usr/local/lib
}


message("using libsbml from: $${LIBSBML_DIR}")

win32:INCLUDEPATH += "$${LIBSBML_DIR}\include" "$${LIBSBML_DIR}\include/sbml"
win32:LIBS +=  -llibsbml3 -L"$${LIBSBML_DIR}\win32\bin" -L"$${LIBSBML_DIR}\win32\lib"
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
