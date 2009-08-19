#include <QtGui/QApplication>
#include "Translator.h"
#include "QTAntimony.h"
#include "SBWIntegration.h"

#ifdef SBW_INTEGRATION
#include "SBW/ModuleImpl.h"
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
	
//#ifdef SBW_INTEGRATION
    bool sbwon = true;
    try {
	SBWAntimony *service = new SBWAntimony();
	
	static const std::string Name("QTAntimony");
	static const std::string ServiceName("QTAntimony");
	static const std::string DisplayName("QTAntimony 1.0");
	static const std::string HelpString("Antimony analyzer");
	static const std::string CategoryName("/Analysis");
		
	ModuleImpl oModule(Name, DisplayName, UniqueModule, HelpString);
	oModule.addServiceObject(ServiceName, DisplayName, CategoryName, service, HelpString);

	// register if neccessary
        for (int arg=1; arg<argc; arg++) {
            std::string sArg(argv[arg]);
                if (sArg == "-sbwregister" || sArg == "--sbwregister")
                {
                    oModule.run(argc, argv);
                    return 0;
		}
        }
	// otherwise enable SBW service
	oModule.enableModuleServices();
    }
    catch (...) {
        sbwon = false;
    }
	
//#endif
	
    qInstallMsgHandler(myMessageOutput);
    QTAntimony a(argc, argv);

#ifdef SBW_INTEGRATION

    // install an event filter that will display a new window when SBML is loaded
    if (sbwon) {
        a.installEventFilter(&a);
    }
    else {
        a.SetUseSBW(false);
    }
#endif

    for (int arg=1; arg<argc; arg++) {
        a.OpenFile(argv[arg]);
    }
    if (argc==1) {
        a.NewWindow();
    }

    return a.exec();
}
