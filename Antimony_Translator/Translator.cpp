#include "Translator.h"
#include "TabManager.h"
#include "AntimonyTab.h"
#include "SBMLTab.h"
#include <QTabWidget>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGridLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QClipboard>

using namespace std;
Translator::Translator(QApplication* app, char* filename)
        : QMainWindow(NULL),
        m_app(app),
        m_antimony(),
        m_allSBML()
{
    //Actions
    QAction* actionNew = new QAction(tr("&New"), this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setEnabled(false);
    QAction* actionOpen = new QAction(tr("&Open"), this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setEnabled(false);
    QAction* actionSaveAntimony = new QAction(tr("Save &Antimony"), this);
    actionSaveAntimony->setShortcut(QKeySequence::Save);
    actionSaveAntimony->setEnabled(false);
    QAction* actionSaveSBML = new QAction(tr("Save &SBML"), this);
    actionSaveSBML->setShortcut(QKeySequence(tr("Alt+s")));
    actionSaveSBML->setEnabled(false);
    QAction* actionQuit = new QAction(tr("&Quit"), this);
    actionQuit->setShortcut(QKeySequence(tr("Ctrl+q")));
    m_actionUndo = new QAction(tr("&Undo"), this);
    m_actionUndo->setShortcut(QKeySequence::Undo);
    m_actionUndo->setEnabled(false);
    m_actionRedo = new QAction(tr("&Redo"), this);
    m_actionRedo->setShortcut(QKeySequence::Redo);
    m_actionRedo->setEnabled(false);
    m_actionCut = new QAction(tr("Cu&t"), this);
    m_actionCut->setShortcut(QKeySequence::Cut);
    m_actionCut->setEnabled(false);
    m_actionCopy = new QAction(tr("&Copy"), this);
    m_actionCopy->setShortcut(QKeySequence::Copy);
    m_actionCopy->setEnabled(false);
    m_actionPaste = new QAction(tr("&Paste"), this);
    m_actionPaste->setShortcut(QKeySequence::Paste);
    SetPasteAvailability();
    m_actionSelectAll = new QAction(tr("Select &All"), this);
    m_actionSelectAll->setShortcut(QKeySequence::SelectAll);
    m_actionRevertText = new QAction(tr("Rever&t"), this);
    m_actionRevertText->setShortcut(tr("Ctrl+R"));
    m_actionRevertText->setToolTip(tr("Revert this tab to the last auto-translated version."));
    m_actionRevertText->setEnabled(false);
    QAction* actionFind = new QAction(tr("&Find"), this);
    actionFind->setShortcut(QKeySequence::Find);
    actionFind->setEnabled(false);
    QAction* actionShowTutorial = new QAction(tr("Show &Tutorial"), this);
    actionShowTutorial->setEnabled(false);
    QAction* actionAbout = new QAction(tr("&About"), this);
    actionAbout->setEnabled(false);

    //The tabs
    setWindowTitle("Antimony/SBML translator");
    m_tabmanager = new TabManager(this);
    m_antimony = new AntimonyTab;
    m_tabmanager->addTab(m_antimony, "Antimony");
    AddSBMLTab("");
    m_antimony->SetActive();

    //Connections
    connect(actionQuit,SIGNAL(triggered()), m_app, SLOT(quit()));
    connect(m_actionUndo, SIGNAL(triggered()), m_tabmanager, SLOT(undo()));
    connect(m_antimony, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(m_actionRedo, SIGNAL(triggered()), m_tabmanager, SLOT(redo()));
    connect(m_antimony, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(m_actionCut, SIGNAL(triggered()), m_tabmanager, SLOT(cut()));
    connect(m_antimony, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(m_actionCopy, SIGNAL(triggered()), m_tabmanager, SLOT(copy()));
    connect(m_antimony, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(m_actionPaste, SIGNAL(triggered()), m_tabmanager, SLOT(paste()));
    connect(m_app->clipboard(), SIGNAL(dataChanged()), this, SLOT(SetPasteAvailability()));
    connect(m_actionSelectAll, SIGNAL(triggered()), m_tabmanager, SLOT(selectAll()));
    connect(m_actionRevertText, SIGNAL(triggered()), m_tabmanager, SLOT(revertText()));
    connect(m_antimony, SIGNAL(LastTextAvailable(bool)), m_actionRevertText, SLOT(setEnabled(bool)));

    //The File menu
    QMenu* filemenu = menuBar()->addMenu(tr("&File"));
    filemenu->addAction(actionNew);
    filemenu->addAction(actionOpen);
    filemenu->addAction(actionSaveAntimony);
    filemenu->addAction(actionSaveSBML);
    filemenu->addAction(actionQuit);

    //The Edit Menu
    QMenu* editmenu = menuBar()->addMenu(tr("&Edit"));
    editmenu->addAction(m_actionUndo);
    editmenu->addAction(m_actionRedo);
    editmenu->addSeparator();
    editmenu->addAction(m_actionCut);
    editmenu->addAction(m_actionCopy);
    editmenu->addAction(m_actionPaste);
    editmenu->addSeparator();
    editmenu->addAction(m_actionSelectAll);
    editmenu->addAction(m_actionRevertText);
    editmenu->addSeparator();
    editmenu->addAction(actionFind);
    menuBar()->addMenu(editmenu);

    //The Help Menu
    QMenu* helpmenu = menuBar()->addMenu(tr("&Help"));
    helpmenu->addAction(actionShowTutorial);
    helpmenu->addAction(actionAbout);
    //QKeySequence::
    //setMenuBar(menubar);

    //General look
    QRect rect = QApplication::desktop()->availableGeometry(this);
    setGeometry(200, 200, 600, 600);

    setCentralWidget(m_tabmanager);
    m_tabmanager->textbox(0)->setFocus();

}

void Translator::AddSBMLTab(string name, string text)
{
    SBMLTab* sbml = new SBMLTab();
    string tabname = "SBML";
    if (name != "") {
        tabname += " - " + name;
    }
    m_tabmanager->addTab(sbml, tabname.c_str());
    m_allSBML.push_back(sbml);
    sbml->setPlainText(text.c_str());
    sbml->SetTextUnchanged();
    connect(sbml, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(LastTextAvailable(bool)),   m_actionRevertText, SLOT(setEnabled(bool)));
}

void Translator::SetPasteAvailability()
{
    if (m_app->clipboard()->text()=="") {
        m_actionPaste->setEnabled(false);
    }
    else {
        m_actionPaste->setEnabled(true);
    }
}
