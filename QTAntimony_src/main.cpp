#include <cstdio>
#include <QApplication>
#include <QString>
#include <QRegExp>
#include "Translator.h"
#include "QTAntimony.h"
#include "SBWIntegration.h"

#include <cstdio>

#ifdef SBW_INTEGRATION
#include "SBW/SBWC.h"
#endif

void myMessageOutput(QtMsgType type, const char *msg)
{
	switch (type) {
	 case QtDebugMsg:
#ifndef NDEBUG
		 fprintf(stderr, "Debug: %s\n", msg);
#endif
		 break;
	 case QtWarningMsg:
#ifndef NDEBUG
		 fprintf(stderr, "Warning: %s\n", msg);
#endif
		 break;
	 case QtCriticalMsg:
		 fprintf(stderr, "Critical error from QT: %s\n", msg);
		 break;
	 case QtFatalMsg:
		 fprintf(stderr, "Fatal error from QT: %s\n", msg);
		 abort();
	}
}

#ifdef SBW_INTEGRATION

void doAnalysis(SBWInteger /*from*/, SBWDataBlockReader *args, SBWDataBlockWriter * /*result*/, void * /*userData*/)
{
	char *sbml; 
	SBWRead(args, "string", &sbml);
	QSBMLEvent sbmlEvent(sbml);
	qApp->postEvent(qApp, &sbmlEvent);
	SBWFree(sbml);
}

#endif 

int main(int argc, char *argv[])
{

#ifdef SBW_INTEGRATION
  bool sbwon = true;

	static const char* Name("QTAntimony");
	static const char* ServiceName("QTAntimony");
	static const char* DisplayName("QTAntimony 1.0");
	static const char* HelpString("Antimony analyzer");
	static const char* CategoryName("/Analysis");

	SBWCreateModuleImpl( Name, DisplayName, SBW_UniqueModule, HelpString);

	SBWModuleImplAddService( ServiceName, DisplayName, CategoryName, HelpString);

	SBWModuleImplSetHandler( ServiceName, doAnalysis, 0, "void doAnalysis(string)", 1, HelpString);
	
	int sbwModuleIndex = -1;
	try 
	{
		// register if neccessary
		for (int arg=1; arg<argc; arg++) 
		{
			std::string sArg(argv[arg]);
			if (sArg == "-sbwregister" || sArg == "--sbwregister")
			{
				SBWModuleImplRun(argc, argv, 1);
				return 0;
			}
			else if (sArg == "-sbwregister" || sArg == "--sbwregister")
				sbwModuleIndex = arg;
		}
		// otherwise enable SBW service
		SBWModuleImplEnableServices();
	}
	catch (...) 
	{
		sbwon = false;
	}

#endif

	qInstallMsgHandler(myMessageOutput);
	QTAntimony a(argc, argv);
  //QString sheet = a.styleSheet();
  //sheet.append("QMessageBox { messagebox-text-interaction-flags: 1 }");
  //a.setStyleSheet(sheet);

#ifdef SBW_INTEGRATION
	// install an event filter that will display a new window when SBML is loaded
	if (sbwon) {
		a.installEventFilter(&a);
	}
	else {
		a.SetUseSBW(false);
	}
	for (int arg=1; arg<argc; arg++) {
		if (sbwModuleIndex != arg) a.OpenFile(argv[arg]);
	}
#else
        a.SetUseSBW(false);
#endif
  if (argc==1) {
		a.NewWindow();
	}

	return a.exec();
}
