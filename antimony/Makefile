#If not using libSBML:
#sbmlflag = -DNSBML
#libsbml = 

#otherwise
sbml_location = /usr/local/lib/
sbml_includes = /usr/local/include/
libsbml = -L$(sbml_location) -lsbml
sbmlflag = 

#For a debug version:
CPPFLAGS = -Wall -ggdb $(sbmlflag) -I$(sbml_includes)
#For a non-debug version:
#CPPFLAGS = -Wall -DNDEBUG $(sbmlflag)

#Library flags
LIBRARYFLAGS = $(libsbml) -Llib -lantimony

src_dir = src/
lib_dir = lib/
doc_dir = doc/

YPPFILES = $(src_dir)antimony.ypp

CPPFILES = $(src_dir)antimony_api.cpp \
	$(src_dir)Antimony.cpp \
	$(src_dir)antimony.tab.cpp \
	$(src_dir)dnastrand.cpp \
	$(src_dir)event.cpp \
	$(src_dir)formula.cpp \
	$(src_dir)module.cpp \
	$(src_dir)reactantlist.cpp \
	$(src_dir)reaction.cpp \
	$(src_dir)registry.cpp \
	$(src_dir)sbmlx.cpp \
	$(src_dir)stringx.cpp \
	$(src_dir)testantimony.cpp \
	$(src_dir)typex.cpp \
	$(src_dir)userfunction.cpp \
	$(src_dir)variable.cpp

HFILES = $(src_dir)antimony_api.h \
	$(src_dir)dnastrand.h \
	$(src_dir)enums.h \
	$(src_dir)event.h \
	$(src_dir)formula.h \
	$(src_dir)libutil.h \
	$(src_dir)module.h \
	$(src_dir)reactantlist.h \
	$(src_dir)reaction.h \
	$(src_dir)registry.h \
	$(src_dir)sbmlx.h \
	$(src_dir)stringx.h \
	$(src_dir)typex.h \
	$(src_dir)userfunction.h \
	$(src_dir)variable.h

LIBOFILES = $(src_dir)antimony_api.o \
	$(src_dir)antimony.tab.o \
	$(src_dir)dnastrand.o \
	$(src_dir)event.o \
	$(src_dir)formula.o \
	$(src_dir)module.o \
	$(src_dir)reactantlist.o \
	$(src_dir)reaction.o \
	$(src_dir)registry.o \
	$(src_dir)sbmlx.o \
	$(src_dir)stringx.o \
	$(src_dir)typex.o \
	$(src_dir)userfunction.o \
	$(src_dir)variable.o

QMAKEFILES = antimony.pro \
	antimony2sbml.pro \
	sbml2antimony.pro \
	testantimony.pro

DOCFILES = $(doc_dir)antimony__api_8h.html \
	$(doc_dir)antimony__api_8h-source.html \
	$(doc_dir)antimony-installation.html \
	$(doc_dir)antimony-license.html \
	$(doc_dir)antimony-technical-spec.html \
	$(doc_dir)antimony-why.html \
	$(doc_dir)doxygen.css \
	$(doc_dir)doxygen.png \
	$(doc_dir)enums_8h.html \
	$(doc_dir)enums_8h-source.html \
	$(doc_dir)files.html \
	$(doc_dir)ftv2blank.png \
	$(doc_dir)ftv2doc.png \
	$(doc_dir)ftv2folderclosed.png \
	$(doc_dir)ftv2folderopen.png \
	$(doc_dir)ftv2lastnode.png \
	$(doc_dir)ftv2link.png \
	$(doc_dir)ftv2mlastnode.png \
	$(doc_dir)ftv2mnode.png \
	$(doc_dir)ftv2node.png \
	$(doc_dir)ftv2plastnode.png \
	$(doc_dir)ftv2pnode.png \
	$(doc_dir)ftv2vertline.png \
	$(doc_dir)globals_enum.html \
	$(doc_dir)globals_func.html \
	$(doc_dir)globals.html \
	$(doc_dir)group__input.html \
	$(doc_dir)group__output.html \
	$(doc_dir)index.html \
	$(doc_dir)main.html \
	$(doc_dir)olddocumentation.txt \
	$(doc_dir)pages.html \
	$(doc_dir)tab_b.gif \
	$(doc_dir)tab_l.gif \
	$(doc_dir)tab_r.gif \
	$(doc_dir)tabs.css \
	$(doc_dir)tree.html \
	$(doc_dir)Tutorial.pdf \

DOCSRCFILES = \
	$(doc_dir)antimony-installation.txt \
	$(doc_dir)antimony-license.txt \
	$(doc_dir)antimony-mainpage.txt \
	$(doc_dir)antimony-technical-spec.txt \
	$(doc_dir)antimony-why.txt \
	$(doc_dir)doxygen.antimony.cfg \
	$(doc_dir)technical_spec.html \
	$(src_dir)antimony_api.h \
	$(src_dir)enums.h \
	LICENSE.txt \
	README.txt


#Executables:
all : bin/testantimony bin/antimony2sbml bin/sbml2antimony
	@echo ""
	@echo "Libary created:"
	@echo "  lib/libantimony.a:  The libAntimony static library"
	@echo ""
	@echo "Executables created:  "
	@echo "  bin/testantimony:   Prints information about your antimony file(s)"
	@echo "  bin/antimony2sbml:  Converts all modules in an antimony file to SBML files"
	@echo "  bin/sbml2antimony:  Converts an SBML file into an antimony file."
	@echo ""
	@echo "For more information, see the documentation in the doc/ directory."
	@echo ""

bin/testantimony : $(lib_dir)libantimony.a $(src_dir)testantimony.o
	$(CXX) -o bin/testantimony $(src_dir)testantimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

bin/antimony2sbml : $(lib_dir)libantimony.a $(src_dir)antimony2sbml.o
	$(CXX) -o bin/antimony2sbml $(src_dir)antimony2sbml.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

bin/sbml2antimony : $(lib_dir)libantimony.a $(src_dir)sbml2antimony.o
	$(CXX) -o bin/sbml2antimony  $(src_dir)sbml2antimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

#The distribution zip file.
antimony.tar.gz : $(YPPFILES) $(CPPFILES) $(HFILES) $(QMAKEFILES) $(DOCFILES) $(DOCSRCFILES) Makefile
	tar -cvf antimony.tar $(YPPFILES) $(CPPFILES) $(HFILES) $(QMAKEFILES) $(DOCFILES) $(DOCSRCFILES) Makefile
	gzip -f antimony.tar

#The documentation.  doxygen.css is a proxy for the general dependencies
$(doc_dir)index.html : $(DOCSRCFILES)
	cd doc/; doxygen doxygen.antimony.cfg;

#The library
$(lib_dir)libantimony.a : $(LIBOFILES)
	$(AR) -rcs $(lib_dir)libantimony.a $(LIBOFILES)


#The .o files
$(src_dir)antimony2sbml.o : $(src_dir)antimony2sbml.cpp

$(src_dir)sbml2antimony.o : $(src_dir)sbml2antimony.cpp

$(src_dir)testantimony.o : $(src_dir)testantimony.cpp $(src_dir)antimony_api.h $(src_dir)registry.h $(src_dir)stringx.h

$(src_dir)antimony.tab.o : $(src_dir)antimony.tab.cpp

$(src_dir)antimony_api.o : $(src_dir)antimony_api.cpp $(src_dir)antimony_api.h $(src_dir)formula.h $(src_dir)libutil.h $(src_dir)module.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)sbmlx.h $(src_dir)stringx.h $(src_dir)typex.h

$(src_dir)dnastrand.o : $(src_dir)dnastrand.cpp $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h $(src_dir)typex.h

$(src_dir)event.o : $(src_dir)event.cpp $(src_dir)event.h $(src_dir)formula.h $(src_dir)registry.h $(src_dir)stringx.h $(src_dir)variable.h

$(src_dir)formula.o : $(src_dir)formula.cpp $(src_dir)formula.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)module.o : $(src_dir)module.cpp $(src_dir)module.h $(src_dir)variable.h $(src_dir)enums.h $(src_dir)reaction.h $(src_dir)sbmlx.h $(src_dir)stringx.h $(src_dir)typex.h

$(src_dir)typex.o : $(src_dir)typex.cpp $(src_dir)enums.h $(src_dir)typex.h

$(src_dir)reactantlist.o : $(src_dir)reactantlist.cpp $(src_dir)reactantlist.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)reaction.o : $(src_dir)reaction.cpp $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)registry.h $(src_dir)enums.h $(src_dir)stringx.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)typex.h

$(src_dir)registry.o : $(src_dir)registry.cpp $(src_dir)registry.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)stringx.h $(src_dir)formula.h $(src_dir)variable.h

$(src_dir)stringx.o : $(src_dir)stringx.cpp $(src_dir)stringx.h

$(src_dir)sbmlx.o : $(src_dir)sbmlx.cpp $(src_dir)sbmlx.h

$(src_dir)userfunction.o : $(src_dir)userfunction.cpp $(src_dir)module.h $(src_dir)formula.h

$(src_dir)variable.o : $(src_dir)variable.cpp $(src_dir)variable.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)event.h $(src_dir)formula.h $(src_dir)reaction.h $(src_dir)typex.h

#The bison-generated .cpp file
$(src_dir)antimony.tab.cpp : $(src_dir)antimony.ypp $(src_dir)registry.h $(src_dir)module.h
	bison --verbose -o$(src_dir)antimony.tab.cpp $(src_dir)antimony.ypp



clean :
	rm src/*.o lib/libantimony.a testantimony sbml2antimony antimony2sbml
