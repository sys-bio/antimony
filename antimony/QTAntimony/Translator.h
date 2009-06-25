#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QtGui/QMainWindow>
#include <QTextEdit>

class AntimonyTab;
class SBMLTab;
class QApplication;
class TabManager;
class QTAntimony;
class FileWatcher;

class Translator : public QMainWindow
{
    Q_OBJECT

private:
    //Tabs
    TabManager* m_tabmanager;
    AntimonyTab* m_antimony;
    FileWatcher* m_filewatcher;
    std::vector<SBMLTab*> m_allSBML;
    //Editor actions (are tied to active tab only)
    QAction* m_actionUndo;
    QAction* m_actionRedo;
    QAction* m_actionCut;
    QAction* m_actionCopy;
    QAction* m_actionPaste;
    QAction* m_actionSelectAll;
    QAction* m_actionRevertToTranslated;
    QAction* m_actionRevertToOriginal;


public:
    Translator(); // Unimplemented--no default constructor.
    Translator(QTAntimony* app, QString filename="");
    //~Translator();  //Hmm, do we need destructors here?
    void AddSBMLTab(QString name = "", QString text = "", bool translated=true);
    bool IsBlank();
    virtual void closeEvent(QCloseEvent* event);

public slots:
    void SetPasteAvailability();
    void ResetWindowNameWith(const QString& filename);
};

#endif // TRANSLATOR_H
