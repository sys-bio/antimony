#ifndef QTANTIMONY_H
#define QTANTIMONY_H

#include <QApplication>
#include <QMainWindow>

#define ORG "SBWTeam"
#define APP "QTAntimony"

class Translator;
class QTAntimony : public QApplication
{
    Q_OBJECT;
	
	
private:
    Translator* m_original;
    bool m_opened;
    bool m_usesbw;
    QString m_currentdir;

    QWidget* m_basewindow;

protected:
#ifdef SBW_INTEGRATION
        bool eventFilter(QObject *obj, QEvent *oEvent);
#endif

public:
    QTAntimony(int& argc, char**& argv);
    void OpenFile(QString filename);
    void OpenFiles(QStringList filenames);
    QString GetCurrentDir();
    void DisplayWindow(QMainWindow* t);
    bool GetUseSBW() {return m_usesbw;}
    void SetUseSBW(bool on);

public slots:
    void OpenNewFile();
    void SaveCurrentDirectory(QString dir);
    Translator* NewWindow();

};

#endif // QTANTIMONY_H
