#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>

class AntimonyTab;
class SBMLTab;
class TabManager;
class QTAntimony;
class FileWatcher;
class FindDialog;
class FindReplaceDialog;
class GoToLineDialog;

class Translator : public QMainWindow
{
    Q_OBJECT

private:
    QTAntimony* m_app;
    //Tabs
    TabManager* m_tabmanager;
    AntimonyTab* m_antimony;
    FileWatcher* m_filewatcher;
    //Editor actions (are tied to active tab only)
    QAction* m_actionUndo;
    QAction* m_actionRedo;
    QAction* m_actionCut;
    QAction* m_actionCopy;
    QAction* m_actionPaste;
    QAction* m_actionSelectAll;
    QAction* m_actionRevertToTranslated;
    QAction* m_actionRevertToOriginal;
    QAction* m_actionSetSBMLLevelAndVersion;
    //Find/Replace actions and dialogues
    QAction* m_actionFind;
    QAction* m_actionFindReplace;
    QAction* m_actionGoToLine;
    FindDialog* m_findDialog;
    FindReplaceDialog* m_findReplaceDialog;
    GoToLineDialog* m_goToLineDialog;
    //Global actions for defaults
    QAction* m_actionDimensionless;
    QAction* m_actionAddDefaults;

#ifdef SBW_INTEGRATION
    void addSBWMenu();
#endif
	
public:
    Translator(); // Unimplemented--no default constructor.
    Translator(QTAntimony* app, QString filename="");
    //~Translator();  //Hmm, do we need destructors here?
    void AddSBMLTab(QString name = "", QString text = "", bool translated=true, int level=3, int version=1);
    void AddCellMLTab(QString name = "", QString text = "", bool translated=true);
    void SetSBMLTab(QString model);
    bool IsBlank();
    virtual void closeEvent(QCloseEvent* event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
	
public slots:
    void SetPasteAvailability();
    void DisplayAbout();
    void DisplayTutorial();
};

#endif // TRANSLATOR_H
