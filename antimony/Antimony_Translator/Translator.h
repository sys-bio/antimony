#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QtGui/QMainWindow>
#include <QTextEdit>

class AntimonyTab;
class SBMLTab;
class QApplication;
class TabManager;

class Translator : public QMainWindow
{
    Q_OBJECT

private:
    //The application (can't be the parent)
    QApplication* m_app;
    //Tabs
    TabManager* m_tabmanager;
    AntimonyTab* m_antimony;
    std::vector<SBMLTab*> m_allSBML;
    //Editor actions (are tied to active tab only)
    QAction* m_actionUndo;
    QAction* m_actionRedo;
    QAction* m_actionCut;
    QAction* m_actionCopy;
    QAction* m_actionPaste;
    QAction* m_actionSelectAll;
    QAction* m_actionRevertText;


public:
    Translator(); // Unimplemented--no default constructor.
    Translator(QApplication* app, char* filename=NULL);
    //~Translator();  //Hmm, do we need destructors here?
    void AddSBMLTab(std::string name = "", std::string text = "");

public slots:
    void SetPasteAvailability();

};

#endif // TRANSLATOR_H
