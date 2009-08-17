#ifndef TUTORIAL_H
#define TUTORIAL_H

#include<QTextBrowser>

class QFile;

class Tutorial: public QTextBrowser
{
    public:
    Tutorial(QWidget* parent = 0);
};

#endif // TUTORIAL_H
