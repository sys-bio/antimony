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
#include "Settings.h"
#include "AntimonyTab.h"
#include "ChangeableTextBox.h"
//#include "resource.h"
#include "SBMLTab.h"
#include "CellMLTab.h"
#include "FileWatcher.h"
#include "QTAntimony.h"
#include "CopyMessageBox.h"
#include "finddialog.h"
#include "findreplacedialog.h"
#include "GoToLineDialog.h"

#include "antimony_api.h"
#include <sbml/SBMLTypes.h>

#include <cassert>
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

using namespace std;
Translator::Translator(QTAntimony* app, QString filename)
        : QMainWindow(NULL),
        m_app(app),
        m_antimony(),
        m_filewatcher(new FileWatcher)
{
    setAcceptDrops(true);
    QAction* actionFlattenSBML = new QAction(tr("&Flatten SBML tab(s)"), this);
    //Set the window icon (for windows)
    QIcon anticon("antimony.ico");
    setWindowIcon(anticon);
    //We need to know if we should display SBML tabs, CellML tabs, or both:
    QSettings qset(ORG, APP);
    qset.sync();
    bool displaysbml = true;
    displaysbml = (qset.value("displaysbml", displaysbml).toBool());
    bool displaycellml = false;
    displaycellml = (qset.value("displaycellml", displaycellml).toBool());
#ifdef NCELLML
    displaysbml = true;
    displaycellml = false;
#endif

    bool flattensbml = false;
    flattensbml = qset.value("flattensbml", flattensbml).toBool();

    bool isDimensionless = false;
    isDimensionless = qset.value("isDimensionless", isDimensionless).toBool();

    bool addDefaults = false;
    addDefaults = qset.value("addDefaults", addDefaults).toBool();

    m_tabmanager = new TabManager(this, actionFlattenSBML, flattensbml);
    m_antimony = new AntimonyTab;
    m_findDialog = new FindDialog(this);
    m_findDialog->setModal(false);
    m_findDialog->setPlainTextEdit(m_antimony);

    m_findReplaceDialog = new FindReplaceDialog(this);
    m_findReplaceDialog->setModal(false);
    m_findReplaceDialog->setPlainTextEdit(m_antimony);

    m_goToLineDialog = new GoToLineDialog(this);
    m_goToLineDialog->setPlainTextEdit(m_antimony);

    //Actions
    //File
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
    QAction* actionQuit = new QAction(tr("E&xit"), this);
    actionQuit->setShortcut(QKeySequence(tr("Ctrl+q")));

    //Edit
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

    //Translation
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

    //Translation nuance
    m_actionSetSBMLLevelAndVersion = new QAction(tr("Set SBML &Level and Version"), this);
    m_actionSetSBMLLevelAndVersion->setEnabled(true);
    actionFlattenSBML->setCheckable(true);
    actionFlattenSBML->setChecked(flattensbml);
    actionFlattenSBML->setShortcut(QKeySequence(tr("F4")));
    m_actionDimensionless = new QAction(tr("Unqualified &numbers are dimensionless"), this);
    m_actionDimensionless->setCheckable(true);
    m_actionDimensionless->setChecked(isDimensionless);
    m_actionAddDefaults = new QAction(tr("Add missing &defaults"), this);
    m_actionAddDefaults->setCheckable(true);
    m_actionAddDefaults->setChecked(addDefaults);

    //Find/Replace/Go-to
    m_actionFind = new QAction(tr("&Find"), this);
    m_actionFind->setShortcut(QKeySequence::Find);
    m_actionFind->setEnabled(true);
    m_actionFindReplace = new QAction(tr("&Replace"), this);
    m_actionFindReplace->setShortcut(QKeySequence::Replace);
    m_actionFindReplace->setEnabled(true);
    m_actionGoToLine = new QAction(tr("&Go to line"), this);
    m_actionGoToLine->setShortcut(tr("Ctrl+g"));
    m_actionGoToLine->setEnabled(true);

    //View
//LS DEBUG CELLML
#ifndef NCELLML
    //If we're able to see CellML, set what the user sees.
    QAction* sbmlTabs = new QAction(tr("&SBML tab(s)"), this);
    sbmlTabs->setCheckable(true);
    sbmlTabs->setChecked(displaysbml);
    QAction* cellmlTabs= new QAction(tr("&CellML tab"), this);
    cellmlTabs->setCheckable(true);
    cellmlTabs->setChecked(displaycellml);
#endif
    QAction* setAntimonyFont = new QAction(tr("Set &Antimony Font"), this);
    setAntimonyFont->setEnabled(true);
    QAction* setXMLFont = new QAction(tr("Set &XML Font"), this);
    setXMLFont->setEnabled(true);
    QAction* zoomIn = new QAction(tr("Zoom &in"), this);
    zoomIn->setShortcut(QKeySequence::ZoomIn);
    zoomIn->setEnabled(true);
    QAction* zoomOut = new QAction(tr("Zoom &out"), this);
    zoomOut->setShortcut(QKeySequence::ZoomOut);
    zoomOut->setEnabled(true);
    QAction* addCellMLTab = new QAction(tr("Add CellML &Tab"), this);
    QAction* setCellMLFont = new QAction(tr("Set &CellML Font"), this);

    //Help
    QAction* actionShowTutorial = new QAction(tr("Show &Tutorial"), this);
    actionShowTutorial->setEnabled(true);
    QAction* actionAbout = new QAction(tr("&About"), this);
    actionAbout->setEnabled(true);

    //The tabs
    setWindowTitle("QTAntimony");
    ChangeableTextBox* active = m_antimony;
    m_tabmanager->addTab(m_antimony, m_antimony->GetTabName());
    connect(m_antimony, SIGNAL(TabNameIsNow(QString,ChangeableTextBox*)), m_tabmanager, SLOT(TabNameIs(QString,ChangeableTextBox*)));
    connect(m_antimony, SIGNAL(IsActive(QPlainTextEdit*)), m_findDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(m_antimony, SIGNAL(IsActive(QPlainTextEdit*)), m_findReplaceDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(m_antimony, SIGNAL(IsActive(QPlainTextEdit*)), m_goToLineDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    if (filename != "") {
        QFile file(filename);
        QString filetext = "";
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //error
            if (displaycellml) {
                AddCellMLTab();
            }
            if (displaysbml) {
                AddSBMLTab();
            }
        }
        else {
            QTextStream in(&file);
            filetext = in.readAll();
            m_filewatcher->addPath(filename);
            if (loadAntimonyFile(filename.toUtf8().data()) != -1) {
                //Originally Antimony
                m_antimony->setPlainText(filetext);
                m_antimony->SetSavedFilename(filename);
                m_antimony->SetOriginal();
#ifndef NCELLML
                if (displaycellml) {
                    char* modname = getMainModuleName();
                    AddCellMLTab(modname, getCellMLString(modname), true);
                }
#endif //NCELLML
                if (displaysbml) {
                    for (size_t mod=1; mod<getNumModules(); mod++) {
                        char* modname = getNthModuleName(mod);
#ifdef USE_COMP
                        if (flattensbml) {
                          AddSBMLTab(modname, getSBMLString(modname), true);
                        }
                        else {
                          AddSBMLTab(modname, getCompSBMLString(modname), true);
                        }
#else
                        AddSBMLTab(modname, getSBMLString(modname), true);
#endif
                    }
                    char* mod0name = getNthModuleName(0);
                    if (getNumSymbolsOfType(mod0name, allSymbols) != 0 || getNumModules()==1) {
#ifdef USE_COMP
                        if (flattensbml) {
                          AddSBMLTab(mod0name, getSBMLString(mod0name), true);
                        }
                        else {
                          AddSBMLTab(mod0name, getCompSBMLString(mod0name), true);
                        }
#else
                        AddSBMLTab(mod0name, getSBMLString(mod0name), true);
#endif
                    }
                }
            }
            else if (loadSBMLFile(filename.toUtf8().data()) != -1) {
                //Originally SBML
#ifndef NCELLML
                m_tabmanager->sbmlTabs(true);
                sbmlTabs->setChecked(true);
#endif
                char* modname = getNthModuleName(getNumModules()-1);
                SBMLDocument* document = readSBML(filename.toUtf8().data());
                int level = document->getLevel();
                int version = document->getVersion();
                AddSBMLTab(modname, filetext, false, level, version);
                m_tabmanager->firstsbmltextbox()->SetOriginal();
                m_tabmanager->firstsbmltextbox()->SetSavedFilename(filename);
                m_antimony->SetTranslatedText(getAntimonyString(NULL));
                if (displaycellml) {
                    AddCellMLTab();
                    m_tabmanager->TranslateSBML();
                }
            }
#ifndef NCELLML
            else if (loadCellMLFile(filename.toUtf8().data()) != -1) {
                //Originally CellML
                m_tabmanager->cellmlTabs(true);
                cellmlTabs->setChecked(true);
                char* modname = getMainModuleName();
                ChangeableTextBox* cellml = m_tabmanager->cellmltextbox();
                cellml->SetModelName(modname);
                cellml->setPlainText(filetext);
                cellml->SetOriginal();
                cellml->SetSavedFilename(filename);
                m_antimony->SetTranslatedText(getAntimonyString(NULL));
                displaycellml = true;
                if (displaysbml) {
                  //AddSBMLTab();
                  //We have to re-load the model so that we can create and populate the correct number of SBML tabs.
                  m_tabmanager->TranslateCellML();
                }
            }
#endif
            else {
                //Not a valid file of any format, but maybe we can tell if it's XML or not.
                QRegExp lessthanstart("^\\s*<");
                if (filetext.contains(lessthanstart)) {
                    bool iscellml = false;
                    QRegExp cellmlorg("www.cellml.org");
                    if (filetext.contains(cellmlorg)) {
                      iscellml = true;
                      AddCellMLTab("", filetext, false);
                      m_tabmanager->cellmltextbox()->SetSavedFilename(filename);
                      m_tabmanager->cellmltextbox()->SetFailedTranslation();
                      active = m_tabmanager->cellmltextbox();
                    }
                    else {
                      //It's SBML.  Probably.  Re-read it as SBML to find the error:
                      loadSBMLFile(filename.toUtf8().data());
                      AddSBMLTab("", filetext, false);
                      m_tabmanager->firstsbmltextbox()->SetSavedFilename(filename);
                      m_tabmanager->firstsbmltextbox()->SetFailedTranslation();
                      active = m_tabmanager->firstsbmltextbox();
                    }
                    QString error = getLastError();
                    //m_tabmanager->textbox(1)->DisplayError(error);
                    QRegExp oneline("([^\n]{50}\\S*)\\s");
                    error.replace(oneline, "\\1\n");
                    error = "// " + error;
                    QRegExp returns("\n");
                    error.replace(returns, "\n//  ");
                    error = "// (Switch to the SBML tab to get the original faulty model.  Hit 'undo' if necessary.)\n" + error;
                    m_antimony->ReplaceTextWith(error);
                    m_antimony->SetFailedTranslation();
                }
                else{
                    AddSBMLTab();
                    m_antimony->setPlainText(filetext);
                    m_antimony->SetSavedFilename(filename);
                    m_tabmanager->textbox(1)->SetFailedTranslation();
                    m_antimony->SetFailedTranslation();
                }
            }
            clearPreviousLoads();
#ifndef WIN32
            freeAll();
#endif
        }
    }
    else {
        AddSBMLTab();
    }
    active->SetActive();

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
    connect(m_actionSetSBMLLevelAndVersion, SIGNAL(triggered()), m_tabmanager, SLOT(SetAllSBMLLevelsAndVersions()));
    connect(actionFlattenSBML, SIGNAL(toggled(bool)), m_tabmanager, SLOT(SetFlatten(bool)));
    connect(m_actionAddDefaults, SIGNAL(toggled(bool)), m_tabmanager, SLOT(SetAddDefaults(bool)));
    connect(m_actionDimensionless, SIGNAL(toggled(bool)), m_tabmanager, SLOT(SetDimensionless(bool)));
    connect(m_actionRevertToTranslated, SIGNAL(triggered()), m_tabmanager, SLOT(revertToTranslated()));
    connect(m_antimony, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(m_actionRevertToOriginal, SIGNAL(triggered()), m_tabmanager, SLOT(revertToOriginal()));
    connect(zoomIn, SIGNAL(triggered()), m_tabmanager, SLOT(zoomIn()));
    connect(zoomOut, SIGNAL(triggered()), m_tabmanager, SLOT(zoomOut()));
    connect(setAntimonyFont, SIGNAL(triggered()), m_tabmanager, SLOT(setAntimonyFont()));
    connect(setXMLFont, SIGNAL(triggered()), m_tabmanager, SLOT(setXMLFont()));
    connect(m_actionFind, SIGNAL(triggered()), m_findDialog, SLOT(show()));
    connect(m_actionFindReplace, SIGNAL(triggered()), m_findReplaceDialog, SLOT(show()));
    connect(m_actionGoToLine, SIGNAL(triggered()), m_goToLineDialog, SLOT(show()));
#ifndef NCELLML
    connect(sbmlTabs, SIGNAL(toggled(bool)), m_tabmanager, SLOT(sbmlTabs(bool)));
    connect(cellmlTabs, SIGNAL(toggled(bool)), m_tabmanager, SLOT(cellmlTabs(bool)));
#endif
    connect(m_antimony, SIGNAL(OriginalAvailable(bool)), m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation()), m_antimony, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation()), m_antimony, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedCellMLTranslation()), m_antimony, SLOT(SetFailedTranslation()));
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
    editmenu->addAction(m_actionFind);
    editmenu->addAction(m_actionFindReplace);
    editmenu->addAction(m_actionGoToLine);
    editmenu->addSeparator();
    editmenu->addAction(actionTranslateCurrent);
    editmenu->addAction(actionTranslateAntimony);
    editmenu->addAction(actionTranslateSBML);
    editmenu->addAction(m_actionRevertToTranslated);
    editmenu->addAction(m_actionRevertToOriginal);
    editmenu->addSeparator();
    editmenu->addAction(m_actionSetSBMLLevelAndVersion);
#ifdef USE_COMP
    editmenu->addAction(actionFlattenSBML);
#endif
    editmenu->addAction(m_actionDimensionless);
    editmenu->addAction(m_actionAddDefaults);

    //The View Menu
    QMenu* viewmenu = menuBar()->addMenu(tr("&View"));
    viewmenu->addAction(zoomIn);
    viewmenu->addAction(zoomOut);
    viewmenu->addAction(setAntimonyFont);
    viewmenu->addAction(setXMLFont);
#ifndef NCELLML
    viewmenu->addAction(sbmlTabs);
    viewmenu->addAction(cellmlTabs);
#endif

#ifdef 	SBW_INTEGRATION
    if (m_app->GetUseSBW()) {
        addSBWMenu();
    }
#endif
	
    //The Help Menu
    QMenu* helpmenu = menuBar()->addMenu(tr("&Help"));
    helpmenu->addAction(actionShowTutorial);
    helpmenu->addAction(actionAbout);

    //alt-right(?)
    QAction* nextTab = new QAction(tr("&New"), this);
    nextTab->setShortcut(QKeySequence::NextChild);
    nextTab->setShortcut(QKeySequence(tr("Alt+right")));
    nextTab->setEnabled(true);
    connect(nextTab, SIGNAL(triggered()), m_tabmanager, SLOT(nextTab()));


    m_tabmanager->sbmlTabs(displaysbml);
    m_tabmanager->cellmlTabs(displaycellml);
    m_tabmanager->SetFlatten(flattensbml);
    m_tabmanager->SetAddDefaults(addDefaults);
    setBareNumbersAreDimensionless(isDimensionless);

    //And finally...
    setCentralWidget(m_tabmanager);
    m_tabmanager->textbox(0)->setFocus();

}

#ifdef SBW_INTEGRATION


void Translator::addSBWMenu() 
{
	
	if (!SBWGetConnectionStatus()) SBWConnect();
	int numServices;
	SBWServiceDescriptor* descriptors = SBWFindServices("/Analysis", &numServices, true);

	if ( descriptors == NULL || numServices < 1) return;

	QMenu *oMenu = menuBar()->addMenu(tr("&SBW"));

	for (int i = 0; i < numServices; i++)
	{
		
		QAction *oAction = new QAction(QString(descriptors[i].serviceDisplayName), this);
		QStringList oList; oList.push_back(descriptors[i].module.name); oList.push_back(descriptors[i].serviceName);
        oAction->setData( QVariant( oList) );
        connect(oAction, SIGNAL(triggered()), m_tabmanager, SLOT(startSBWAnalyzer()));
        oMenu->addAction(oAction);
	}

	SBWFree(descriptors);
}

#endif


void Translator::AddSBMLTab(QString name, QString text, bool translated, int level, int version)
{
    SBMLTab* sbml = new SBMLTab();
    sbml->SetModelName(name);
    sbml->setPlainText(text);
    sbml->StoreLevelAndVersion(level, version);
    if (translated) {
        sbml->SetTranslated();
    }
    else {
        sbml->SetOriginal();
    }
    m_tabmanager->addTab(sbml, sbml->GetTabName());
    connect(sbml, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(sbml, SIGNAL(OriginalAvailable(bool)),   m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation()), sbml, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation()), sbml, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedCellMLTranslation()), sbml, SLOT(SetFailedTranslation()));
    connect(sbml, SIGNAL(StartWatching(QString)), m_filewatcher, SLOT(StartWatching(QString)));
    connect(sbml, SIGNAL(StopWatching(QString)), m_filewatcher, SLOT(StopWatching(QString)));
    connect(m_filewatcher, SIGNAL(fileChanged(QString)), sbml, SLOT(FileChanged(QString)));
    connect(sbml, SIGNAL(TabNameIsNow(QString,ChangeableTextBox*)), m_tabmanager, SLOT(TabNameIs(QString,ChangeableTextBox*)));
    connect(sbml, SIGNAL(IsActive(QPlainTextEdit*)), m_findDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(sbml, SIGNAL(IsActive(QPlainTextEdit*)), m_findReplaceDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(sbml, SIGNAL(IsActive(QPlainTextEdit*)), m_goToLineDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
}

void Translator::AddCellMLTab(QString name, QString text, bool translated)
{
    CellMLTab* cellml = new CellMLTab();
    cellml->SetModelName(name);
    cellml->setPlainText(text);
    if (translated) {
        cellml->SetTranslated();
    }
    else {
        cellml->SetOriginal();
    }
    m_tabmanager->insertTab(1, cellml, cellml->GetTabName());
    connect(cellml, SIGNAL(ActiveUndoAvailable(bool)), m_actionUndo, SLOT(setEnabled(bool)));
    connect(cellml, SIGNAL(ActiveRedoAvailable(bool)), m_actionRedo, SLOT(setEnabled(bool)));
    connect(cellml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCut, SLOT(setEnabled(bool)));
    connect(cellml, SIGNAL(ActiveCopyAvailable(bool)), m_actionCopy, SLOT(setEnabled(bool)));
    connect(cellml, SIGNAL(TranslatedAvailable(bool)), m_actionRevertToTranslated, SLOT(setEnabled(bool)));
    connect(cellml, SIGNAL(OriginalAvailable(bool)),   m_actionRevertToOriginal, SLOT(setEnabled(bool)));
    connect(m_tabmanager, SIGNAL(FailedAntimonyTranslation()), cellml, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedSBMLTranslation()), cellml, SLOT(SetFailedTranslation()));
    connect(m_tabmanager, SIGNAL(FailedCellMLTranslation()), cellml, SLOT(SetFailedTranslation()));
    connect(cellml, SIGNAL(StartWatching(QString)), m_filewatcher, SLOT(StartWatching(QString)));
    connect(cellml, SIGNAL(StopWatching(QString)), m_filewatcher, SLOT(StopWatching(QString)));
    connect(m_filewatcher, SIGNAL(fileChanged(QString)), cellml, SLOT(FileChanged(QString)));
    connect(cellml, SIGNAL(TabNameIsNow(QString,ChangeableTextBox*)), m_tabmanager, SLOT(TabNameIs(QString,ChangeableTextBox*)));
    connect(cellml, SIGNAL(IsActive(QPlainTextEdit*)), m_findDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(cellml, SIGNAL(IsActive(QPlainTextEdit*)), m_findReplaceDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
    connect(cellml, SIGNAL(IsActive(QPlainTextEdit*)), m_goToLineDialog, SLOT(setPlainTextEdit(QPlainTextEdit*)));
}

void Translator::SetSBMLTab(QString model)
{
    assert(m_tabmanager->count()==2);
    assert(m_tabmanager->textbox(0)->toPlainText() == "");
    assert(m_tabmanager->textbox(1)->toPlainText() == "");
    m_tabmanager->firstsbmltextbox()->setPlainText(model);
    m_tabmanager->TranslateSBML();
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
        QSettings qset(ORG, APP);
        qset.sync();
        qset.setValue("geometry", saveGeometry());
        qset.setValue("isDimensionless", m_actionDimensionless->isChecked());
        qset.setValue("addDefaults", m_actionAddDefaults->isChecked());
        m_tabmanager->SaveFonts();
        m_tabmanager->SaveTabDisplay();
    }
    else {
        event->ignore();
    }
}

void Translator::DisplayAbout()
{
  QMessageBox msgBox;
  msgBox.setText("QTAntimony " LIBANTIMONY_VERSION_STRING);
  msgBox.setInformativeText("Based on libAntimony " LIBANTIMONY_VERSION_STRING " and libSBML v" LIBSBML_DOTTED_VERSION);
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

void Translator::dragEnterEvent(QDragEnterEvent *event)
{
  const QMimeData* qmd = event->mimeData();
  QString text = event->mimeData()->text();
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void Translator::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
 
    // check for a file or a list of files
    if (mimeData->hasUrls())
    {
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();
 
        // extract the local paths of the files
        for (int i = 0; i < urlList.size() && i < 32; ++i)
        {
            pathList.append(urlList.at(i).toLocalFile());
        }
 
        // call a function to open the files
        m_app->OpenFiles(pathList);
    }
    event->acceptProposedAction();
}