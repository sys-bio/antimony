#include "Translator.h"
#include "TabManager.h"
#include "AntimonyTab.h"
#include "ChangeableTextBox.h"
#include "SBMLTab.h"
#include "antimony_api.h"
#include <QTabWidget>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGridLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QClipboard>
#include <QFile>
#include <QTextStream>
#include <QFileSystemWatcher>

using namespace std;
Translator::Translator(QTAntimony* app, QString filename)
        : QMainWindow(NULL),
        m_antimony(),
        m_filewatcher(new QFileSystemWatcher),
        m_allSBML()
{
    //Actions
    QAction* actionNew = new QAction(tr("&New"), this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setEnabled(false);
    QAction* actionOpen = new QAction(tr("&Open"), this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setEnabled(true);
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
    m_actionRevertToTranslated = new QAction(tr("Revert to &Translated"), this);
    m_actionRevertToTranslated->setShortcut(tr("Ctrl+R"));
    m_actionRevertToTranslated->setToolTip(tr("Revert this tab to the last auto-translated version."));
    m_actionRevertToTranslated->setEnabled(false);
    m_actionRevertToOriginal = new QAction(tr("Revert to last &Original"), this);
    m_actionRevertToOriginal->setShortcut(tr("Ctrl+L"));
    m_actionRevertToOriginal->setToolTip(tr("Revert this tab to the last original version."));
    m_actionRevertToOriginal->setEnabled(false);
    QAction* actionFind = new QAction(tr("&Find"), this);
    actionFind->setShortcut(QKeySequence::Find);
    actionFind->setEnabled(false);
    QAction* actionShowTutorial = new QAction(tr("Show &Tutorial"), this);
    actionShowTutorial->setEnabled(false);
    QAction* actionAbout = new QAction(tr("&About"), this);
    actionAbout->setEnabled(false);

    //The tabs
    setWindowTitle("QTAntimony");
    m_tabmanager = new TabManager(this);
    m_antimony = new AntimonyTab;
    m_tabmanager->addTab(m_antimony, m_antimony->GetTabName());
    if (filename != "") {
        QFile file(filename);
        QString filetext = "";
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //error
            AddSBMLTab();
       }
        else {
            QTextStream in(&file);
            filetext = in.readAll();
            m_filewatcher->addPath(filename);
            long SBMLHandle = loadSBMLFile(filename.toAscii().data());
            long AntimonyHandle = loadFile(filename.toAscii().data());
            if (SBMLHandle == -1 && AntimonyHandle != -1) {
                //Originally Antimony
                m_antimony->setText(filetext);
                m_antimony->SetOriginal();
                for (size_t mod=1; mod<getNumModules(); mod++) {
                    char* modname = getNthModuleName(mod);
                    AddSBMLTab(modname, getSBMLString(modname), true);
                }
            }
            else if (SBMLHandle != -1) {
                //Originally SBML
                char* modname = getNthModuleName(getNumModules()-1);
                AddSBMLTab(modname, filetext, false);
                m_tabmanager->textbox(1)->SetOriginal();
                m_antimony->SetTranslatedText(getAntimonyString());
            }
            else {
                //Not a valid file of either format, but maybe we can tell if it's XML or not.
                QRegExp lessthanstart("^\\s*<");
                if (filetext.contains(lessthanstart)) {
                    //It's SBML.  Probably.
                    AddSBMLTab("", filetext, false);
                    m_tabmanager->textbox(1)->SetOriginal();
                    m_antimony->SetFailedTranslation();
                }
                else{
                    AddSBMLTab();
                    m_tabmanager->textbox(1)->SetFailedTranslation();
                    m_antimony->setText(filetext);
                }
            }
            clearPreviousLoads();
            freeAll();
        }
    }
    else {
        AddSBMLTab();
    }
    m_antimony->SetActive();

    //Connections
    connect(actionOpen, SIGNAL(triggered()), QApplication::instance(), SLOT(OpenNewFile()));
    connect(actionQuit,SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
    connect(m_actionUndo, SIGNAL(triggered()), m_tabmanager, SLOT(undo()));
    connect(m_antimony, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(m_actionRedo, SIGNAL(triggered()), m_tabmanager, SLOT(redo()));
    connect(m_antimony, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(m_actionCut, SIGNAL(triggered()), m_tabmanager, SLOT(cut()));
    connect(m_antimony, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(m_actionCopy, SIGNAL(triggered()), m_tabmanager, SLOT(copy()));
    connect(m_antimony, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(m_actionPaste, SIGNAL(triggered()), m_tabmanager, SLOT(paste()));
    connect(QApplication::clipboard(), SIGNAL(dataChanged()), this, SLOT(SetPasteAvailability()));
    connect(m_actionSelectAll, SIGNAL(triggered()), m_tabmanager, SLOT(selectAll()));
    connect(m_actionRevertToTranslated, SIGNAL(triggered()), m_tabmanager, SLOT(revertToTranslated()));
    connect(m_antimony, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(m_actionRevertToOriginal, SIGNAL(triggered()), m_tabmanager, SLOT(revertToOriginal()));
    connect(m_antimony, SIGNAL(OriginalAvailable(bool)), m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation(QString)), m_antimony, SLOT(SetFailedTranslation()));

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
    editmenu->addAction(m_actionRevertToTranslated);
    editmenu->addAction(m_actionRevertToOriginal);
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

void Translator::AddSBMLTab(QString name, QString text, bool translated)
{
    SBMLTab* sbml = new SBMLTab();
    sbml->SetModelName(name);
    m_tabmanager->addTab(sbml, sbml->GetTabName());
    m_allSBML.push_back(sbml);
    sbml->setPlainText(text);
    if (translated) {
        sbml->SetTranslated();
    }
    else {
        sbml->SetOriginal();
    }
    connect(sbml, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(OriginalAvailable(bool)),   m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation(QString)), sbml, SLOT(SetFailedTranslation()));
}

bool Translator::IsBlank()
{
    if (m_tabmanager->count() != 2) return false;
    if (m_tabmanager->textbox(0)->toPlainText() != "") return false;
    if (m_tabmanager->textbox(1)->toPlainText() != "") return false;
    return true;
}

void Translator::SetPasteAvailability()
{
    if (QApplication::clipboard()->text()=="") {
        m_actionPaste->setEnabled(false);
    }
    else {
        m_actionPaste->setEnabled(true);
    }
}

void Translator::closeEvent(QCloseEvent* event)
{
    emit isClosing();
    QMainWindow::closeEvent(event);
}
