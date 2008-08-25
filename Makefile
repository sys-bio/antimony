CPPFLAGS = -Wall -ggdb 
LIBRARYFLAGS = -L/usr/local/lib -lsbml

antimony : antimony.tab.o antimony_api.o formula.o module.o rd_type.o reactantlist.o reaction.o registry.o stringx.o variable.o Antimony.o
	g++ -o antimony -lm $(CPPFLAGS) $(LIBRARYFLAGS) antimony.tab.o antimony_api.o formula.o module.o rd_type.o reactantlist.o reaction.o registry.o stringx.o variable.o Antimony.o

antimony.tar.gz : antimony.ypp antimony.tab.cpp antimony_api.cpp antimony_api.h formula.cpp formula.h libutil.h module.cpp module.h rd_type.cpp rd_type.h reactantlist.cpp reactantlist.h reaction.cpp reaction.h registry.cpp registry.h stringx.cpp stringx.h variable.cpp variable.h Antimony.cpp Makefile documentation.txt 
	tar -cvf antimony.tar antimony.ypp antimony.tab.cpp antimony_api.cpp antimony_api.h formula.cpp formula.h libutil.h module.cpp module.h rd_type.cpp rd_type.h reactantlist.cpp reactantlist.h reaction.cpp reaction.h registry.cpp registry.h stringx.cpp stringx.h variable.cpp variable.h Antimony.cpp Makefile documentation.txt
	gzip -f antimony.tar

Antimony.o : Antimony.cpp
	g++ -c $(CPPFLAGS) Antimony.cpp

antimony.tab.o : antimony.tab.cpp
	g++ -c $(CPPFLAGS) antimony.tab.cpp

antimony_api.o : antimony_api.cpp antimony_api.h libutil.h registry.h stringx.h
	g++ -c $(CPPFLAGS) antimony_api.cpp

formula.o : formula.cpp formula.h module.h registry.h variable.h reaction.h
	g++ -c $(CPPFLAGS) formula.cpp

module.o : module.cpp module.h variable.h reaction.h
	g++ -c $(CPPFLAGS) module.cpp

rd_type.o : rd_type.cpp rd_type.h
	g++ -c $(CPPFLAGS) rd_type.cpp

reactantlist.o : reactantlist.cpp reactantlist.h registry.h module.h variable.h reaction.h
	g++ -c $(CPPFLAGS) reactantlist.cpp

reaction.o : reaction.cpp reaction.h registry.h rd_type.h stringx.h module.h variable.h
	g++ -c $(CPPFLAGS) reaction.cpp

registry.o : registry.cpp registry.h module.h reaction.h reactantlist.h formula.h variable.h
	g++ -c $(CPPFLAGS) registry.cpp

stringx.o : stringx.cpp stringx.h
	g++ -c $(CPPFLAGS) stringx.cpp

variable.o : variable.cpp variable.h module.h registry.h formula.h reaction.h
	g++ -c $(CPPFLAGS) variable.cpp


antimony.tab.cpp : antimony.ypp antimony_api.h registry.h rd_type.h module.h variable.h reaction.h
	bison --verbose antimony.ypp
