#include <QtGui/QApplication>
#include "Translator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Translator w(&a);
    w.show();
    return a.exec();
}
