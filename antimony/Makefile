#version number
version = 2.0

#mingw:
#mingw = i586-mingw32msvc
#CXX = $(mingw)-c++
#AR = $(mingw)-ar
#sbml_location = /usr/$(mingw)
#mingw_include = -I/usr/$(mingw)/include

#if no mingw:
mingw_include =


#If not using libSBML:
#sbmlflag = -DNSBML
#sbml_includes = 
#libsbml = 

#otherwise
sbml_location = /usr/local
sbml_includes = -I$(sbml_location)/include
libsbml = -L$(sbml_location)/lib -lsbml
sbmlflag = 


#If not using libCellML:
#cellmlflag = -DNCELLML
#cellml_includes =
#libcellml =

#otherwise
CELLML_API_DIR = /home/lpsmith/CellML/hg/cellml-api
cellml_location = /usr/local/lib/
cellml_includes = -I/usr/local/include/ \
  -I/usr/local/lib/ \
  -I$(CELLML_API_DIR) \
  -I$(CELLML_API_DIR)/sources/ \
  -I$(CELLML_API_DIR)/sources/cellml/ \
  -I$(CELLML_API_DIR)/TeLICeMS/sources/ \
  -I$(CELLML_API_DIR)/CUSES/sources/ \
  -I$(CELLML_API_DIR)/CeVAS/sources/ \
  -I$(CELLML_API_DIR)/interfaces/ 

libcellml = -L$(cellml_location) -L$(CELLML_API_DIR)/.libs -lcellml -lcevas -lcuses -ltelicems


generalcflags = -Wall -DVERSION_STRING="\"v$(version)\"" $(sbmlflag) $(mingw_include) $(sbml_includes) $(cellml_includes)
#For a debug version:
CPPFLAGS = -ggdb $(generalcflags)
#For profiling:
#CPPFLAGS = -O3 -pg $(generalcflags)
#for nondebug version
#CPPFLAGS = -O3 -DNDEBUG $(generalcflags)

#Library flags
LIBRARYFLAGS =  -Llib -lantimony $(libsbml) $(libcellml) 

src_dir = src/
lib_dir = lib/
bin_dir = bin/
doc_dir = doc/
ex_dir  = doc/examples/
qt_dir  = QTAntimony_src/

YPPFILES = $(src_dir)antimony.ypp

CPPFILES = $(src_dir)antimony_api.cpp \
	$(src_dir)Antimony.cpp \
	$(src_dir)antimony.tab.cpp \
	$(src_dir)cellmlx.cpp \
	$(src_dir)dnastrand.cpp \
	$(src_dir)event.cpp \
	$(src_dir)formula.cpp \
	$(src_dir)module.cpp \
	$(src_dir)module-sbml.cpp \
	$(src_dir)module-cellml.cpp \
	$(src_dir)reactantlist.cpp \
	$(src_dir)reaction.cpp \
	$(src_dir)registry.cpp \
	$(src_dir)sbmlx.cpp \
	$(src_dir)stringx.cpp \
	$(src_dir)testantimony.cpp \
	$(src_dir)rehashantimony.cpp \
	$(src_dir)sbtranslate.cpp \
	$(src_dir)typex.cpp \
	$(src_dir)userfunction.cpp \
	$(src_dir)variable.cpp \
	$(src_dir)antimony2sbml.cpp \
	$(src_dir)antimony2cellml.cpp \
	$(src_dir)sbml2antimony.cpp \
	$(src_dir)cellml2antimony.cpp \
	$(src_dir)testantimony.cpp \

HFILES = $(src_dir)antimony_api.h \
	$(src_dir)dnastrand.h \
	$(src_dir)cellmlx.h \
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
	$(src_dir)cellmlx.o \
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
	$(src_dir)variable.o \

QTANTIMONYFILES = $(qt_dir)AntimonyTab.cpp \
	$(qt_dir)AntimonyTab.h \
	$(qt_dir)ChangeableTextBox.cpp \
	$(qt_dir)ChangeableTextBox.h \
	$(qt_dir)CopyMessageBox.cpp \
	$(qt_dir)CopyMessageBox.h \
	$(qt_dir)CellMLTab.cpp \
	$(qt_dir)CellMLTab.h \
	$(qt_dir)FileWatcher.cpp \
	$(qt_dir)FileWatcher.h \
	$(qt_dir)main.cpp \
	$(qt_dir)QTAntimony.cpp \
	$(qt_dir)QTAntimony.h \
	$(qt_dir)QTAntimony.pro \
	$(qt_dir)SBMLTab.cpp \
	$(qt_dir)SBMLTab.h \
	$(qt_dir)SBWIntegration.cpp \
	$(qt_dir)SBWIntegration.h \
	$(qt_dir)Settings.h \
	$(qt_dir)TabManager.cpp \
	$(qt_dir)TabManager.h \
	$(qt_dir)Translator.cpp \
	$(qt_dir)Translator.h \
	$(qt_dir)Tutorial.cpp \
	$(qt_dir)Tutorial.h \
	$(qt_dir)Tutorial.html \
	$(qt_dir)Tutorial.xxd \
	$(qt_dir)antimony.icns \
	$(qt_dir)antimony.ico \
	$(qt_dir)antimony.jpg \
	$(qt_dir)antimony.qrc \
	$(qt_dir)antimony_ico.pdn \
	$(qt_dir)antimonyicon.rc \
	$(qt_dir)README.txt \


DOCFILES = $(doc_dir)antimony__api_8h.html \
	$(doc_dir)antimony__api_8h-source.html \
	$(doc_dir)antimony-biomodels.html \
	$(doc_dir)antimony-cellml.html \
	$(doc_dir)antimony-examples.html \
	$(doc_dir)antimony-installation.html \
	$(doc_dir)antimony-license.html \
	$(doc_dir)antimony-qt.html \
	$(doc_dir)antimony-technical-spec.html \
	$(doc_dir)antimony-why.html \
	$(doc_dir)cellmllist_ant.html \
	$(doc_dir)cellmllist_sbml.html \
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
	$(doc_dir)index.html \
	$(doc_dir)main.html \
	$(doc_dir)tab_b.gif \
	$(doc_dir)tab_l.gif \
	$(doc_dir)tab_r.gif \
	$(doc_dir)tabs.css \
	$(doc_dir)tree.html \
	$(doc_dir)Tutorial.pdf \
	$(doc_dir)Screenshot-linux.png \
	$(doc_dir)Screenshot-macosx.png \
	$(doc_dir)Screenshot-windows.png \
	$(ex_dir).htaccess \
	$(ex_dir)ex_antimony_input.txt \
	$(ex_dir)ex_antimony_output.txt \
	$(ex_dir)ex_sbml_input.xml \
	$(ex_dir)ex_sbml_output_bistable_sbml.xml \
	$(ex_dir)ex_sbml_output_combined_model_sbml.xml \
	$(ex_dir)ex_sbml_output_ffn_sbml.xml \
	$(ex_dir)ex_sbml_output___main_sbml.xml \
	$(ex_dir)ex_sbml_output_ringoscil_sbml.xml \
	$(ex_dir)biomodels/BIOMD0000000001.txt \
	$(ex_dir)biomodels/BIOMD0000000???.txt \
	$(ex_dir)cellml_files.zip

DOCSRCFILES = \
	$(doc_dir)antimony-biomodels.txt \
	$(doc_dir)antimony-cellml.txt \
	$(doc_dir)antimony-examples.txt \
	$(doc_dir)antimony-installation.txt \
	$(doc_dir)antimony-license.txt \
	$(doc_dir)antimony-mainpage.txt \
	$(doc_dir)antimony-qt.txt \
	$(doc_dir)antimony-technical-spec.txt \
	$(doc_dir)antimony-why.txt \
	$(doc_dir)cellml2html.pl \
	$(doc_dir)doxygen.antimony.cfg \
	$(doc_dir)technical_spec.html \
	$(doc_dir)Screenshot-linux.png \
	$(doc_dir)Screenshot-macosx.png \
	$(doc_dir)Screenshot-windows.png \
	$(src_dir)antimony_api.h \
	$(src_dir)enums.h \
	LICENSE.txt \
	README.txt


#Pointer:
all : \
	Makefile
	@echo "Antimony now uses CMake as its build system.  To use, create a build directory\nand change into it:"
	@echo ""
	@echo "mkdir build/; cd build"
	@echo ""
	@echo "Then run cmake (cmake-gui or ccmake) from that directory, with '..' as\nthe argument:"
	@echo ""
	@echo "cmake-gui .."
	@echo ""
	@echo "This will create a makefile for whatever system you told it to."
	@echo ""
	@echo "This makefile still exists for the purpose of creating source and"
	@echo "documentation distributions.  'make srcdist' and 'make docs' can be"
	@echo "used for these tasks (until they too are moved to cmake)."
	@echo ""
	@echo "For more information, see the documentation in the doc/ directory,"
	@echo "doc/antimony-installation.html in particular."
	@echo ""

$(bin_dir)testantimony : $(lib_dir)libantimony.a $(src_dir)testantimony.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)testantimony $(src_dir)testantimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)antimony2sbml : $(lib_dir)libantimony.a $(src_dir)antimony2sbml.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)antimony2sbml $(src_dir)antimony2sbml.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)antimony2cellml : $(lib_dir)libantimony.a $(src_dir)antimony2cellml.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)antimony2cellml $(src_dir)antimony2cellml.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)sbml2antimony : $(lib_dir)libantimony.a $(src_dir)sbml2antimony.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)sbml2antimony  $(src_dir)sbml2antimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)cellml2antimony : $(lib_dir)libantimony.a $(src_dir)cellml2antimony.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)cellml2antimony  $(src_dir)cellml2antimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)sbtranslate : $(lib_dir)libantimony.a $(src_dir)sbtranslate.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)sbtranslate  $(src_dir)sbtranslate.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)

$(bin_dir)rehashantimony : $(lib_dir)libantimony.a $(src_dir)rehashantimony.o
	mkdir -p $(bin_dir)
	$(CXX) -o $(bin_dir)rehashantimony $(src_dir)rehashantimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS)


#The distribution zip file.
srcdist : $(YPPFILES) $(CPPFILES) $(HFILES) $(DOCFILES) $(DOCSRCFILES) $(QTANTIMONYFILES) Makefile CMakeLists.txt $(ex_dir)cellml_files.zip
	tar --transform 's,^,antimony/,' -cvf antimony_src_v$(version).tar $(YPPFILES) $(CPPFILES) $(HFILES) $(QMAKEFILES) $(DOCFILES) $(DOCSRCFILES) $(QTANTIMONYFILES) $(ex_dir)cellml_files.zip Makefile CMakeLists.txt
	gzip antimony_src_v$(version).tar

#The documentation.
$(ex_dir)cellml_files.zip:
	cd $(ex_dir); zip cellml_files.zip cellml/*/*; cd ../..;

docs : $(doc_dir)index.html $(doc_dir)cellmllist_ant.html $(doc_dir)cellmllist_sbml.html
	zip Antimony_documentation_v$(version).zip $(DOCFILES)

dist : srcdist docs

$(doc_dir)index.html : $(DOCSRCFILES)
	cd doc/; doxygen doxygen.antimony.cfg; cd ..;

$(doc_dir)cellmllist_ant.html : $(DOCSRCFILES)
	cd doc/; cellml2html.pl examples/cellml/*/*.txt > cellmllist_ant.html; cd ..;

$(doc_dir)cellmllist_sbml.html : $(DOCSRCFILES)
	cd doc/; cellml2html.pl examples/cellml/*/*.xml > cellmllist_sbml.html; cd ..;

$(ex_dir)/biomodels/BIOMD0000000001.txt : $(bin_dir)sbml2antimony
	cd $(ex_dir)/biomodels/; ../../($bin_dir)/sbml2antimony ~/biomodels/curated/BIOMD0000000???.xml

#The library
$(lib_dir)libantimony.a : $(LIBOFILES)
	mkdir -p $(lib_dir)
	$(AR) -rcs $(lib_dir)libantimony.a $(LIBOFILES)


#The .o files
$(src_dir)antimony2sbml.o : $(src_dir)antimony2sbml.cpp

$(src_dir)antimony2cellml.o : $(src_dir)antimony2cellml.cpp

$(src_dir)sbml2antimony.o : $(src_dir)sbml2antimony.cpp

$(src_dir)cellml2antimony.o : $(src_dir)cellml2antimony.cpp

$(src_dir)testantimony.o : $(src_dir)testantimony.cpp $(src_dir)antimony_api.h $(src_dir)registry.h $(src_dir)stringx.h $(src_dir)variable.h

$(src_dir)antimony.tab.o : $(src_dir)antimony.tab.cpp

$(src_dir)antimony_api.o : $(src_dir)antimony_api.cpp $(src_dir)antimony_api.h $(src_dir)cellmlx.h $(src_dir)formula.h $(src_dir)libutil.h $(src_dir)module.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)sbmlx.h $(src_dir)stringx.h $(src_dir)typex.h

$(src_dir)cellmlx.o : $(src_dir)cellmlx.cpp $(src_dir)cellmlx.h

$(src_dir)dnastrand.o : $(src_dir)dnastrand.cpp $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h $(src_dir)typex.h

$(src_dir)event.o : $(src_dir)event.cpp $(src_dir)event.h $(src_dir)formula.h $(src_dir)registry.h $(src_dir)stringx.h $(src_dir)sbmlx.h $(src_dir)variable.h

$(src_dir)formula.o : $(src_dir)formula.cpp $(src_dir)formula.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)module.o : $(src_dir)module.cpp $(src_dir)module-sbml.cpp $(src_dir)module-cellml.cpp $(src_dir)cellmlx.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)enums.h $(src_dir)reaction.h $(src_dir)sbmlx.h $(src_dir)stringx.h $(src_dir)typex.h $(src_dir)formula.h

$(src_dir)typex.o : $(src_dir)typex.cpp $(src_dir)enums.h $(src_dir)typex.h

$(src_dir)reactantlist.o : $(src_dir)reactantlist.cpp $(src_dir)reactantlist.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)reaction.o : $(src_dir)reaction.cpp $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)registry.h $(src_dir)enums.h $(src_dir)stringx.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)typex.h $(src_dir)formula.h

$(src_dir)registry.o : $(src_dir)registry.cpp $(src_dir)registry.h $(src_dir)cellmlx.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)stringx.h $(src_dir)sbmlx.h $(src_dir)formula.h $(src_dir)variable.h

$(src_dir)stringx.o : $(src_dir)stringx.cpp $(src_dir)stringx.h

$(src_dir)sbmlx.o : $(src_dir)sbmlx.cpp $(src_dir)sbmlx.h

$(src_dir)userfunction.o : $(src_dir)userfunction.cpp $(src_dir)module.h $(src_dir)sbmlx.h $(src_dir)formula.h

$(src_dir)variable.o : $(src_dir)variable.cpp $(src_dir)variable.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)enums.h $(src_dir)registry.h $(src_dir)event.h $(src_dir)formula.h $(src_dir)reaction.h $(src_dir)sbmlx.h $(src_dir)typex.h

#The bison-generated .cpp file
$(src_dir)antimony.tab.cpp : $(src_dir)antimony.ypp $(src_dir)registry.h $(src_dir)module.h
	bison --verbose -o$(src_dir)antimony.tab.cpp $(src_dir)antimony.ypp

clean :
	rm -f src/*.o $(lib_dir)libantimony.a $(bin_dir)testantimony $(bin_dir)sbml2antimony $(bin_dir)cellml2antimony $(bin_dir)antimony2sbml $(bin_dir)antimony2cellml antimony_src*.tar.gz Antimony_documentation*.zip
