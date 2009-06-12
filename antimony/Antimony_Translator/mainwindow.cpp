#include "mainwindow.h"
#include <QTextEdit>
#include <QSplitter>
#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    editor1 = new MyEditor;
    editor2 = new QTextEdit;
    QSplitter * splitter = new QSplitter(this);
    splitter->addWidget(editor1);
    splitter->addWidget(editor2);
    splitter->children();
    setCentralWidget(splitter);

     QRect rect = QApplication::desktop()->availableGeometry(this);
     setGeometry(rect.center().x()  - width()/2, rect.center().y()  - height()/2, width(), height());
     //move(rect.center());

     connect(editor1,SIGNAL(manyChangesMade()),this,SLOT(textChangedInEditor1()));
}

 void MainWindow::textChangedInEditor1()
 {
     editor2->setPlainText(editor1->toPlainText());
 }

MyEditor::MyEditor() : counter(0)
{
}

void MyEditor::keyPressEvent(QKeyEvent * e)
{
    ++counter;
    if (counter > 10)
    {
        emit manyChangesMade();
        counter = 0;
    }
    QTextEdit::keyPressEvent(e);
}


MainWindow::~MainWindow()
{

}
