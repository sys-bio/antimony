#ifndef QTANTIMONY_H
#define QTANTIMONY_H

#include <QApplication>

#ifdef SBW_INTEGRATION

#include "SBW/SBW.h"
#include "SBW/SBWC.h"
#include <QEvent>
#include <string>
using namespace std;
using namespace SystemsBiologyWorkbench;


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


// QT Antimony SBW Service ... just load an SBML file, send it to the application .. thats it
class SBWAntimony : SystemsBiologyWorkbench::SBWListener
{
public:
	SBWAntimony() {}
	
	virtual void onShutdown() { exit(0); }
	
	static void registerMethods(MethodTable<SBWAntimony> &table)
	{
		table.addMethod(
						&SBWAntimony::doAnalysisImpl,"void doAnalysis(string)",0,""
						);
	}
	
	DataBlockWriter doAnalysisImpl(Module /*from*/, DataBlockReader arguments)
	{
		string sbml; arguments >> sbml;
		qApp->postEvent(qApp, new QSBMLEvent(sbml));
		return DataBlockWriter();
	}
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
