#ifndef QTANTIMONY_H
#define QTANTIMONY_H

#include <QApplication>

#ifdef SBW_INTEGRATION

#include <string>
#include <QEvent>

// we need an event to be sent to the application that a new 
//SBML model should be loaded

class QSBMLEvent : public QEvent
{	
	std::string _sbmlContent;
public: 
	QSBMLEvent(std::string sbmlContent) :  QEvent(QEvent::User)
	{
		_sbmlContent = sbmlContent;
	}

	std::string getSBML() { return _sbmlContent; } 
	
};

#endif

class Translator;
class QTAntimony : public QApplication
{
    Q_OBJECT;
private:
    Translator* m_original;
    bool m_opened;
    QString m_currentdir;

#ifdef SBW_INTEGRATION
protected:
	bool QTAntimony::eventFilter(QObject *obj, QEvent *oEvent);
#endif

public:
    QTAntimony(int& argc, char**& argv);
    void OpenFile(QString filename);
    void OpenFiles(QStringList filenames);
    QString GetCurrentDir();
    void DisplayWindow(Translator* t);

public slots:
    void OpenNewFile();
    void SetCurrentDirectory(QString dir);
    void NewWindow();

};

#endif // QTANTIMONY_H
