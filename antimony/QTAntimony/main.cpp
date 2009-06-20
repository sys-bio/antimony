#include <QtGui/QApplication>
#include "Translator.h"
#include "QTAntimony.h"

int main(int argc, char *argv[])
{
    QTAntimony a(argc, argv);
    for (int arg=1; arg<argc; arg++) {
        a.OpenFile(argv[arg]);
    }
    if (argc==1) {
        Translator* newwindow = a.GetNewTranslator();
        newwindow->show();
    }
    return a.exec();
}
