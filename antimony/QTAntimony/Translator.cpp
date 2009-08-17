#ifdef SBW_INTEGRATION
#include "SBW/DataBlockReader.h"
#include "SBW/DataBlockWriter.h"
#include "SBW/SBW.h"
#include "SBW/SBWC.h"
#include "SBW/SBWApplicationException.h"
#include "SBW/SBWLowLevel.h"
#include <string>
#include <vector>
using namespace SystemsBiologyWorkbench;
#undef SetCurrentDirectory

#endif


#include "Translator.h"
#include "Tutorial.h"
#include "TabManager.h"
#include "AntimonyTab.h"
#include "ChangeableTextBox.h"
#include "SBMLTab.h"
#include "FileWatcher.h"
#include "QTAntimony.h"

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
#include <QCloseEvent>
#include <QMessageBox>

using namespace std;
Translator::Translator(QTAntimony* app, QString filename)
        : QMainWindow(NULL),
        m_app(app),
        m_antimony(),
        m_filewatcher(new FileWatcher),
        m_allSBML()
{
    //Actions
    QAction* actionNew = new QAction(tr("&New"), this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setEnabled(true);
    QAction* actionOpen = new QAction(tr("&Open"), this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setEnabled(true);
    QAction* actionSaveCurrentTab = new QAction(tr("&Save Current Tab"), this);
    actionSaveCurrentTab->setShortcut(QKeySequence::Save);
    actionSaveCurrentTab->setEnabled(true);
    QAction* actionSaveAs = new QAction(tr("Save Current &Tab As..."), this);
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    actionSaveAs->setEnabled(true);
    QAction* actionSaveAntimony = new QAction(tr("Save &Antimony"), this);
    actionSaveAntimony->setShortcut(QKeySequence(tr("Alt+a")));
    actionSaveAntimony->setEnabled(true);
    QAction* actionSaveSBML = new QAction(tr("Save All S&BML"), this);
    actionSaveSBML->setShortcut(QKeySequence(tr("Alt+s")));
    actionSaveSBML->setEnabled(true);
    QAction* actionPrint = new QAction(tr("&Print current tab"), this);
    actionPrint->setShortcut(QKeySequence::Print);
    actionPrint->setEnabled(true);
    QAction* actionClose = new QAction(tr("&Close"), this);
    actionClose->setShortcut(QKeySequence::Close);
    actionClose->setEnabled(true);
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
    QAction* actionTranslateCurrent = new QAction(tr("&Translate Tab"), this);
    actionTranslateCurrent->setShortcut(tr("Ctrl+t"));
    actionTranslateCurrent->setEnabled(true);
    QAction* actionTranslateAntimony = new QAction(tr("Translate &Antimony to SBML"), this);
    actionTranslateAntimony->setShortcut(tr("Alt+t"));
    actionTranslateAntimony->setEnabled(true);
    QAction* actionTranslateSBML = new QAction(tr("Translate &SBML to Antimony"), this);
    actionTranslateSBML->setShortcut(tr("Ctrl+Alt+t"));
    actionTranslateSBML->setEnabled(true);
    m_actionRevertToTranslated = new QAction(tr("Re&vert to Translated"), this);
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
    actionShowTutorial->setEnabled(true);
    QAction* actionAbout = new QAction(tr("&About"), this);
    actionAbout->setEnabled(true);

    //The tabs
    setWindowTitle("QTAntimony");
    m_tabmanager = new TabManager(this);
    m_antimony = new AntimonyTab;
    m_tabmanager->addTab(m_antimony, m_antimony->GetTabName());
    connect(m_antimony, SIGNAL(TabNameIsNow(QString,ChangeableTextBox*)), m_tabmanager, SLOT(TabNameIs(QString,ChangeableTextBox*)));
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
                m_antimony->SetSavedFilename(filename);
                m_antimony->SetOriginal();
                for (size_t mod=1; mod<getNumModules(); mod++) {
                    char* modname = getNthModuleName(mod);
                    AddSBMLTab(modname, getSBMLString(modname), true);
                }
                char* mod0name = getNthModuleName(0);
                if (getNumSymbolsOfType(mod0name, allSymbols) != 0 || getNumModules()==1) {
                    AddSBMLTab(mod0name, getSBMLString(mod0name), true);
                }            }
            else if (SBMLHandle != -1) {
                //Originally SBML
                char* modname = getNthModuleName(getNumModules()-1);
                AddSBMLTab(modname, filetext, false);
                m_tabmanager->textbox(1)->SetOriginal();
                m_tabmanager->textbox(1)->SetSavedFilename(filename);
                m_antimony->SetTranslatedText(getAntimonyString());
            }
            else {
                //Not a valid file of either format, but maybe we can tell if it's XML or not.
                QRegExp lessthanstart("^\\s*<");
                if (filetext.contains(lessthanstart)) {
                    //It's SBML.  Probably.
                    AddSBMLTab("", filetext, false);
                    m_tabmanager->textbox(1)->SetFailedTranslation();
                    m_antimony->SetFailedTranslation();
                    m_tabmanager->textbox(1)->SetSavedFilename(filename);
                }
                else{
                    AddSBMLTab();
                    m_antimony->setText(filetext);
                    m_antimony->SetSavedFilename(filename);
                    m_tabmanager->textbox(1)->SetFailedTranslation();
                    m_antimony->SetFailedTranslation();
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
    connect(actionNew, SIGNAL(triggered()), QApplication::instance(), SLOT(NewWindow()));
    connect(actionOpen, SIGNAL(triggered()), QApplication::instance(), SLOT(OpenNewFile()));
    connect(actionSaveCurrentTab, SIGNAL(triggered()), m_tabmanager, SLOT(SaveCurrent()));
    connect(actionSaveAntimony, SIGNAL(triggered()), m_tabmanager, SLOT(SaveAntimony()));
    connect(actionSaveSBML, SIGNAL(triggered()), m_tabmanager, SLOT(SaveAllSBML()));
    connect(actionSaveAs, SIGNAL(triggered()), m_tabmanager, SLOT(SaveCurrentAs()));
    connect(actionQuit,SIGNAL(triggered()), QApplication::instance(), SLOT(closeAllWindows()));
    connect(actionPrint, SIGNAL(triggered()), m_tabmanager, SLOT(print()));
    connect(actionClose, SIGNAL(triggered()), this, SLOT(close()));
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
    connect(actionTranslateCurrent, SIGNAL(triggered()), m_tabmanager, SLOT(TranslateCurrent()));
    connect(actionTranslateAntimony, SIGNAL(triggered()), m_tabmanager, SLOT(TranslateAntimony()));
    connect(actionTranslateSBML, SIGNAL(triggered()), m_tabmanager, SLOT(TranslateSBML()));
    connect(m_actionRevertToTranslated, SIGNAL(triggered()), m_tabmanager, SLOT(revertToTranslated()));
    connect(m_antimony, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(m_actionRevertToOriginal, SIGNAL(triggered()), m_tabmanager, SLOT(revertToOriginal()));
    connect(m_antimony, SIGNAL(OriginalAvailable(bool)), m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation()), m_antimony, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation()), m_antimony, SLOT(SetFailedTranslation()));
    connect(m_antimony, SIGNAL(StartWatching(QString)), m_filewatcher, SLOT(StartWatching(QString)));
    connect(m_antimony, SIGNAL(StopWatching(QString)), m_filewatcher, SLOT(StopWatching(QString)));
    connect(m_filewatcher, SIGNAL(fileChanged(QString)), m_antimony, SLOT(FileChanged(QString)));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(DisplayAbout()));
    connect(actionShowTutorial, SIGNAL(triggered()), this, SLOT(DisplayTutorial()));

    //The File menu
    QMenu* filemenu = menuBar()->addMenu(tr("&File"));
    filemenu->addAction(actionNew);
    filemenu->addAction(actionOpen);
    filemenu->addAction(actionSaveCurrentTab);
    filemenu->addAction(actionSaveAs);
    filemenu->addAction(actionSaveAntimony);
    filemenu->addAction(actionSaveSBML);
    filemenu->addSeparator();
    filemenu->addAction(actionPrint);
    filemenu->addSeparator();
    filemenu->addAction(actionClose);
    filemenu->addAction(actionQuit);

    //The Edit Menu
    QMenu* editmenu = menuBar()->addMenu(tr("&Edit"));
    editmenu->addAction(m_actionUndo);
    editmenu->addAction(m_actionRedo);
    editmenu->addSeparator();
    editmenu->addAction(m_actionCut);
    editmenu->addAction(m_actionCopy);
    editmenu->addAction(m_actionPaste);
    editmenu->addAction(m_actionSelectAll);
    editmenu->addSeparator();
    editmenu->addAction(actionTranslateCurrent);
    editmenu->addAction(actionTranslateAntimony);
    editmenu->addAction(actionTranslateSBML);
    editmenu->addAction(m_actionRevertToTranslated);
    editmenu->addAction(m_actionRevertToOriginal);
    editmenu->addSeparator();
    editmenu->addAction(actionFind);
    menuBar()->addMenu(editmenu);

#ifdef 	SBW_INTEGRATION
    addSBWMenu();
#endif
	
    //The Help Menu
    QMenu* helpmenu = menuBar()->addMenu(tr("&Help"));
    helpmenu->addAction(actionShowTutorial);
    helpmenu->addAction(actionAbout);
    //QKeySequence::
    //setMenuBar(menubar);

    setCentralWidget(m_tabmanager);
    m_tabmanager->textbox(0)->setFocus();

}

#ifdef SBW_INTEGRATION

vector< DataBlockReader > Translator::findServices(string  var0,bool  var1)
{
	try
	{
		DataBlockWriter oArguments;
		oArguments.add(var0);
		oArguments.add(var1);
		
		if (!SBWGetConnectionStatus())
		SBW::connect();
		Module oModule = SBW::getModuleInstance("BROKER");
		Service oService = oModule.findServiceByName("BROKER");
		vector< DataBlockReader > result;
		oService.getMethod("{}[] findServices(string, boolean)").call(oArguments) >> result;
		return result;
	}
	catch(SBWException *e)
	{
		throw e;
	}
}


void Translator::addSBWMenu() {
    vector<DataBlockReader> oModules = findServices("Analysis",true);
    if (oModules.size()==0) return;
    QMenu *oMenu = menuBar()->addMenu(tr("&SBW"));

    // as exercise to the reader, this list should now be sorted :) based on DisplayName
	
    for (unsigned int i = 0; i < oModules.size(); i++)
    {
        string sModuleName; string sServiceName; string sMenuName;
        DataBlockReader oTemp = oModules[i];
        oTemp >> sModuleName >> sServiceName >> sMenuName;
        QAction *oAction = new QAction(QString(sMenuName.c_str()), this);
        QStringList oList; oList.push_back(sModuleName.c_str()); oList.push_back(sServiceName.c_str());
        oAction->setData( QVariant( oList) );
        connect(oAction, SIGNAL(triggered()), m_tabmanager, SLOT(startSBWAnalyzer()));
        oMenu->addAction(oAction);
    }
}

#endif


void Translator::AddSBMLTab(QString name, QString text, bool translated)
{
    SBMLTab* sbml = new SBMLTab();
    sbml->SetModelName(name);
    sbml->setPlainText(text);
    if (translated) {
        sbml->SetTranslated();
    }
    else {
        sbml->SetOriginal();
    }
    m_tabmanager->addTab(sbml, sbml->GetTabName());
    m_allSBML.push_back(sbml);
    connect(sbml, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(OriginalAvailable(bool)),   m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation()), sbml, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation()), sbml, SLOT(SetFailedTranslation()));
    connect(sbml, SIGNAL(StartWatching(QString)), m_filewatcher, SLOT(StartWatching(QString)));
    connect(sbml, SIGNAL(StopWatching(QString)), m_filewatcher, SLOT(StopWatching(QString)));
    connect(m_filewatcher, SIGNAL(fileChanged(QString)), sbml, SLOT(FileChanged(QString)));
    connect(sbml, SIGNAL(TabNameIsNow(QString,ChangeableTextBox*)), m_tabmanager, SLOT(TabNameIs(QString,ChangeableTextBox*)));
}

void Translator::SetSBMLTab(QString model)
{
    assert(m_tabmanager->count()==2);
    assert(m_tabmanager->textbox(0)->toPlainText() == "");
    assert(m_tabmanager->textbox(1)->toPlainText() == "");
    m_tabmanager->textbox(1)->setPlainText(model);
    m_tabmanager->Translate(1);
    m_tabmanager->setCurrentIndex(1);
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
    if (m_tabmanager->CanIClose()) {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void Translator::DisplayAbout()
{
    QMessageBox msgBox;
    msgBox.setText("QTAntimony v0.6:");
    msgBox.setInformativeText("Based on libAntimony v1.2 and libSBML v3.4.1");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();

}

void Translator::DisplayTutorial()
{
    QMainWindow* newwin = new QMainWindow;
    Tutorial* tutorial = new Tutorial(this);
    newwin->setCentralWidget(tutorial);
    newwin->setWindowTitle("Antimony Tutorial");

    m_app->DisplayWindow(newwin);
    //tutorial.set
}
