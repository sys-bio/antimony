CPPFLAGS = -Wall -ggdb
LIBRARYFLAGS = -L/usr/local/lib -Llib -lsbml
src_dir = src/
lib_dir = lib/
YPPFILES = $(src_dir)antimony.ypp

CPPFILES = $(src_dir)antimony_api.cpp \
	$(src_dir)Antimony.cpp \
	$(src_dir)antimony.tab.cpp \
	$(src_dir)dnastrand.cpp \
	$(src_dir)event.cpp \
	$(src_dir)formula.cpp \
	$(src_dir)module.cpp \
	$(src_dir)rd_type.cpp \
	$(src_dir)reactantlist.cpp \
	$(src_dir)reaction.cpp \
	$(src_dir)registry.cpp \
	$(src_dir)sbmlx.cpp \
	$(src_dir)stringx.cpp \
	$(src_dir)testantimony.cpp \
	$(src_dir)userfunction.cpp \
	$(src_dir)variable.cpp

HFILES = $(src_dir)antimony_api.h \
	$(src_dir)dnastrand.h \
	$(src_dir)event.h \
	$(src_dir)formula.h \
	$(src_dir)libutil.h \
	$(src_dir)module.h \
	$(src_dir)rd_type.h \
	$(src_dir)reactantlist.h \
	$(src_dir)reaction.h \
	$(src_dir)registry.h \
	$(src_dir)sbmlx.h \
	$(src_dir)stringx.h \
	$(src_dir)userfunction.h \
	$(src_dir)variable.h

LIBOFILES = $(src_dir)antimony_api.o \
	$(src_dir)antimony.tab.o \
	$(src_dir)dnastrand.o \
	$(src_dir)event.o \
	$(src_dir)formula.o \
	$(src_dir)module.o \
	$(src_dir)rd_type.o \
	$(src_dir)reactantlist.o \
	$(src_dir)reaction.o \
	$(src_dir)registry.o \
	$(src_dir)sbmlx.o \
	$(src_dir)stringx.o \
	$(src_dir)userfunction.o \
	$(src_dir)variable.o

DOCFILES = $(doc_dir)Tutorial.odt \
	$(doc_dir)Tutorial.pdf \
	$(doc_dir)technical_spec.html

#Executables:
testantimony : $(lib_dir)libantimony.a $(src_dir)testantimony.o
	g++ -o testantimony $(src_dir)testantimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS) -lantimony

antimony2sbml : $(lib_dir)libantimony.a $(src_dir)antimony2sbml.o
	g++ -o antimony2sbml $(src_dir)antimony2sbml.o -lm $(CPPFLAGS) $(LIBRARYFLAGS) -lantimony

sbml2antimony : $(lib_dir)libantimony.a $(src_dir)sbml2antimony.o
	g++ -o sbml2antimony  $(src_dir)sbml2antimony.o -lm $(CPPFLAGS) $(LIBRARYFLAGS) -lantimony

all : testantimony antimony2sbml sbml2antimony

#The distribution zip file.
antimony.tar.gz : $(YPPFILES) $(CPPFILES) $(HFILES) $(DOCFILES) Makefile 
	tar -cvf antimony.tar $(YPPFILES) $(CPPFILES) $(HFILES) $(DOCFILES) Makefile
	gzip -f antimony.tar

#The library
$(lib_dir)libantimony.a : $(LIBOFILES)
	ar -rcs $(lib_dir)libantimony.a $(LIBOFILES)


#The .o files
$(src_dir)antimony2sbml.o : $(src_dir)antimony2sbml.cpp

$(src_dir)sbml2antimony.o : $(src_dir)sbml2antimony.cpp

$(src_dir)testantimony.o : $(src_dir)testantimony.cpp $(src_dir)antimony_api.h $(src_dir)registry.h $(src_dir)stringx.h

$(src_dir)antimony.tab.o : $(src_dir)antimony.tab.cpp

$(src_dir)antimony_api.o : $(src_dir)antimony_api.cpp $(src_dir)antimony_api.h $(src_dir)formula.h $(src_dir)libutil.h $(src_dir)module.h $(src_dir)rd_type.h $(src_dir)registry.h $(src_dir)sbmlx.h $(src_dir)stringx.h

$(src_dir)dnastrand.o : $(src_dir)dnastrand.cpp $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h

$(src_dir)event.o : $(src_dir)event.cpp $(src_dir)event.h $(src_dir)formula.h $(src_dir)registry.h $(src_dir)stringx.h $(src_dir)variable.h

$(src_dir)formula.o : $(src_dir)formula.cpp $(src_dir)formula.h $(src_dir)module.h $(src_dir)registry.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)module.o : $(src_dir)module.cpp $(src_dir)module.h $(src_dir)variable.h $(src_dir)rd_type.h $(src_dir)reaction.h $(src_dir)sbmlx.h $(src_dir)stringx.h

$(src_dir)rd_type.o : $(src_dir)rd_type.cpp $(src_dir)rd_type.h

$(src_dir)reactantlist.o : $(src_dir)reactantlist.cpp $(src_dir)reactantlist.h $(src_dir)rd_type.h $(src_dir)registry.h $(src_dir)module.h $(src_dir)variable.h $(src_dir)reaction.h

$(src_dir)reaction.o : $(src_dir)reaction.cpp $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)registry.h $(src_dir)rd_type.h $(src_dir)stringx.h $(src_dir)module.h $(src_dir)variable.h

$(src_dir)registry.o : $(src_dir)registry.cpp $(src_dir)registry.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)reaction.h $(src_dir)reactantlist.h $(src_dir)stringx.h $(src_dir)formula.h $(src_dir)variable.h

$(src_dir)stringx.o : $(src_dir)stringx.cpp $(src_dir)stringx.h

$(src_dir)sbmlx.o : $(src_dir)sbmlx.cpp $(src_dir)sbmlx.h

$(src_dir)userfunction.o : $(src_dir)userfunction.cpp $(src_dir)module.h $(src_dir)formula.h

$(src_dir)variable.o : $(src_dir)variable.cpp $(src_dir)variable.h $(src_dir)dnastrand.h $(src_dir)module.h $(src_dir)rd_type.h $(src_dir)registry.h $(src_dir)event.h $(src_dir)formula.h $(src_dir)reaction.h

$(src_dir)antimony.tab.cpp : $(src_dir)antimony.ypp $(src_dir)registry.h $(src_dir)module.h
	bison --verbose -o$(src_dir)antimony.tab.cpp $(src_dir)antimony.ypp



clean :
	rm src/*.o lib/libantimony.a testantimony sbml2antimony antimony2sbml
