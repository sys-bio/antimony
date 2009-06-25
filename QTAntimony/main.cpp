#include <QtGui/QApplication>
#include "Translator.h"
#include "QTAntimony.h"

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
    return a.exec();
}
