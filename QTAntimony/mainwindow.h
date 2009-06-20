#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTextEdit>

class MyEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
public slots:
    void textChangedInEditor1();

private:
    MyEditor* editor1;
    QTextEdit* editor2;
};

class MyEditor: public QTextEdit
{
    Q_OBJECT

    public:
        MyEditor();

    signals:
        void manyChangesMade();

    protected:
        virtual void keyPressEvent(QKeyEvent * e);

    private:
        int counter;

};

#endif // MAINWINDOW_H
