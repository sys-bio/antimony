#ifndef QTANTIMONY_H
#define QTANTIMONY_H

#include <QApplication>

class Translator;
class QTAntimony : public QApplication
{
    Q_OBJECT;
	
	
private:
    Translator* m_original;
    bool m_opened;
    QString m_currentdir;

protected:
#ifdef SBW_INTEGRATION
        bool eventFilter(QObject *obj, QEvent *oEvent);
#endif

public:
    QTAntimony(int& argc, char**& argv);
    void OpenFile(QString filename);
    void OpenFiles(QStringList filenames);
    QString GetCurrentDir();
    void DisplayWindow(Translator* t);

public slots:
    void OpenNewFile();
    void SaveCurrentDirectory(QString dir);
    Translator* NewWindow();

};

#endif // QTANTIMONY_H
