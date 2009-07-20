#include <QtGui/QApplication>
#include "Translator.h"
#include "QTAntimony.h"

#ifdef SBW_INTEGRATION

#include "SBW/SBW.h"
#include "QEvent"
#include <string>
using namespace std;
using namespace SystemsBiologyWorkbench;


// QT Antimony SBW Service ... just load an SBML file, send it to the application .. thats it
class SBWAntimony : SystemsBiologyWorkbench::SBWListener
{
public:
	SBWAntimony() {}

	virtual void onShutdown() { exit(0); }

		static void registerMethods(MethodTable<SBWAntimony> &table)
		{
			table.addMethod(
				&SBWAntimony::doAnalysisImpl,"void doAnalysis(string)",0,""
				);
		}
		DataBlockWriter doAnalysisImpl(Module /*from*/, DataBlockReader arguments)
		{
			string sbml; arguments >> sbml;
			qApp->postEvent(qApp, new QSBMLEvent(sbml));
			return DataBlockWriter();
		}
};

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

int main(int argc, char *argv[])
{
    qInstallMsgHandler(myMessageOutput);
    QTAntimony a(argc, argv);
    for (int arg=1; arg<argc; arg++) {
        a.OpenFile(argv[arg]);
    }
    if (argc==1) {
        a.NewWindow();
        /*
        Translator* newwindow = a.GetNewTranslator();
        newwindow->show();
        */
    }

#ifdef SBW_INTEGRATION

	try
	{
		SBW::disconnect();
		ModuleImpl oModule("QTAntimony", "QTAntimony", UniqueModule, "Antimony analyzer");
		SBWAntimony service;
		oModule.addServiceObject("analysis", "QT Antimony", "/Analysis", &service, "Antimony analyzer");
		oModule.enableModuleServices();

		// install an event filter that will display a new window  when SBML is loaded
		a.installEventFilter(&a);
	}
	catch (...)
	{
		// oups
	}

#endif

    return a.exec();
}
