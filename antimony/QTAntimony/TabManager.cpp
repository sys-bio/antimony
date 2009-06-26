#include "TabManager.h"
#include "Translator.h"
#include "ChangeableTextBox.h"
#include "SBMLTab.h"
#include "AntimonyTab.h"
#include "antimony_api.h"
#include <QMessageBox>
#include <vector>

using namespace std;

TabManager::TabManager(QWidget* parent)
        : QTabWidget(parent),
        m_oldtab(-1)
{
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(SwitchTabs(int)));
}

int TabManager::addTab(ChangeableTextBox* page, const QString& label)
{
    return QTabWidget::addTab(page, label);
}

int TabManager::addTab(ChangeableTextBox* page, const QIcon& icon, const QString& label)
{
    return QTabWidget::addTab(page, icon, label);
}

ChangeableTextBox* TabManager::textbox(int tabnum)
{
    return static_cast<ChangeableTextBox*>(widget(tabnum));
}

//We provide the functions and pass them to the underlying active editor tab
void TabManager::undo()
{
    GetActiveEditor()->undo();
}
void TabManager::redo()
{
    GetActiveEditor()->redo();
}
void TabManager::cut()
{
    GetActiveEditor()->cut();
}
void TabManager::copy()
{
    GetActiveEditor()->copy();
}
void TabManager::paste()
{
    GetActiveEditor()->paste();
}
void TabManager::selectAll()
{
    GetActiveEditor()->selectAll();
}
void TabManager::revertToTranslated()
{
    GetActiveEditor()->RevertToTranslated();
}
void TabManager::revertToOriginal()
{
    GetActiveEditor()->RevertToOriginal();
}

ChangeableTextBox* TabManager::GetActiveEditor()
{
    return textbox(currentIndex());
}

void TabManager::SwitchTabs(int tab)
{
    ChangeableTextBox* oldtab = textbox(m_oldtab);
    /*
    if (oldtab != NULL) {
        if (oldtab->IsOriginal()) {
            SetOthersTranslated(m_oldtab);
        }
        else if (oldtab->IsTranslated()) {
            SetOthersOriginal(m_oldtab);
        }
        else if (!oldtab->IsMixed()) {
            Translate(m_oldtab);
        }
    }
    */
    if ((oldtab != NULL) &&
        !oldtab->IsOriginal() &&
        !oldtab->IsTranslated() &&
        !oldtab->IsMixed()) {
        Translate(m_oldtab);
    }
    if (tab >= count()) {
        tab = count()-1;
        setCurrentIndex(tab);
        textbox(tab)->setFocus();
    }
    ChangeableTextBox* newtab = textbox(tab);
    newtab->NewlyActive();
    m_oldtab = tab;
}

void TabManager::TranslateCurrent()
{
    Translate(currentIndex());
}

void TabManager::TranslateAntimony()
{
    Translate(0);
}

void TabManager::TranslateSBML()
{
    for (int sbml=1; sbml<count(); sbml++) {
        Translate(sbml);
    }
}

void TabManager::Translate(int tab)
{
    if (tab==-1) return;
    ChangeableTextBox* oldtab = textbox(tab);
    if (oldtab == NULL) return;
    setUpdatesEnabled(false);
    QString tabtext = oldtab->toPlainText();
    oldtab->SetOriginal();
    tabtext.replace(QChar::ParagraphSeparator, "\n");
    if (tab==0) {
        TranslateAntimony(tabtext);
    }
    else {
        TranslateSBML(tab, tabtext);
    }
    clearPreviousLoads();
    freeAll();
    setUpdatesEnabled(true);
}

void TabManager::SetOthersOriginal(int oldtab)
{
    if (oldtab==0) {
        for (int sbml=1; sbml<count(); sbml++) {
            textbox(sbml)->RevertToOriginal();
        }
    }
    else {
        textbox(0)->RevertToOriginal();
    }
}

void TabManager::SetOthersTranslated(int oldtab)
{
    if (oldtab==0) {
        for (int sbml=1; sbml<count(); sbml++) {
            textbox(sbml)->RevertToTranslated();
        }
    }
    else {
        textbox(0)->RevertToTranslated();
    }
}

void TabManager::TranslateAntimony(const QString& text)
{
    long handle = loadString(text.toAscii().data());
    if (handle == -1) {
        //error condition
        char* error = getLastError();
        emit FailedAntimonyTranslation();
        textbox(0)->DisplayError(error);
        return;
    }
    long nummods = getNumModules();
    long visibletabs = nummods;
    for (long mod=0; mod<nummods; mod++) {
        int tabnum = mod;
        char* modname = getNthModuleName(mod);
        //The '__main' module will always be model 0.  I want this to be the *last* tab for this translator, so since the Antimony tab is tab 0, model 0 (if it has any variables) goes to the end.
        if (mod==0) {
            tabnum = nummods;
            long numvars = getNumSymbolsOfType(modname, allSymbols);
            if (numvars == 0) {
                visibletabs--;
            }
            Translator* translator = static_cast<Translator*>(parent());
            while (visibletabs >= count()) {
                translator->AddSBMLTab();
            }
            if (visibletabs < nummods) continue;
        }
        ChangeableTextBox* tab_s = textbox(tabnum);
        tab_s->SetTranslatedText(QString(getSBMLString(modname)));
        tab_s->SetModelName(QString(modname));
        setTabText(tabnum, tab_s->GetTabName());
    }
    while (visibletabs+1 < count() && count()>2) {
        removeTab(count()-1);
    }
    clearPreviousLoads();
    freeAll();
    /*
    for (int cleart = visibletabs+1; cleart < count(); cleart++) {
        ChangeableTextBox* tab_s = textbox(cleart);
        tab_s->SetLastText(QString(""));
        setTabText(cleart, QString("<defunct>"));
    }
    */
}

void TabManager::TranslateSBML(int tab, const QString& text)
{
    ChangeableTextBox* tab_s = textbox(tab);
    QString oldmodelname = tab_s->GetModelName();
    int handle = loadSBMLString(text.toAscii().data());
    if (handle == -1) {
        char* error = getLastError();
        emit FailedSBMLTranslation();
        tab_s->DisplayError(error);
        //do something about the error
        return;
    }
    long modelnum = 0;
    if (getNumModules() == 2) {
        modelnum = 1;
    }
    QString modelname = getNthModuleName(modelnum);
    tab_s->SetModelName(modelname);
    setTabText(tab, tab_s->GetTabName());

    char* antimonytext = getAntimonyString();
    AntimonyTab* anttab = static_cast<AntimonyTab*>(textbox(0));
    anttab->ReplaceModelWithString(oldmodelname, QString(antimonytext));
    //Now set the antimony tab type appropriately.
    bool someSBMLtranslated = false;
    for (int sbml=1; sbml<count(); sbml++) {
        if (!textbox(sbml)->IsOriginal()) {
            someSBMLtranslated = true;
        }
    }
    if (someSBMLtranslated) {
        anttab->SetMixed();
    }
    else {
        anttab->SetTranslated();
    }
    clearPreviousLoads();
    freeAll();
}

void TabManager::TabNameIs(const QString& tabname, ChangeableTextBox* tab)
{
    for (int tnum=0; tnum<count(); tnum++) {
        if (textbox(tnum) == tab) {
            if (tabText(tnum) != tabname) {
                setTabText(tnum, tabname);
                return;
            }
        }
    }
}

void TabManager::SaveCurrent()
{
    GetActiveEditor()->SaveTab();
}

void TabManager::SaveCurrentAs()
{
    GetActiveEditor()->SaveTabAs();
}

void TabManager::SaveAntimony()
{
    textbox(0)->SaveTab();
}

void TabManager::SaveAllSBML()
{
    for (int tab=1; tab<count(); tab++) {
        textbox(tab)->SaveTab();
    }
}

bool TabManager::CanIClose()
{
    QString message = "The ";
    vector<int> unsaved;
    for (int tab=0; tab<count(); tab++) {
        if (!textbox(tab)->IsSaved()) {
            if (tab==0) {
                message += "Antimony tab";
                unsaved.push_back(tab);
            }
            else {
                if (unsaved.size()==0) {
                    message += "SBML model(s) ";
                }
                else if (unsaved.size()==1 && unsaved[0]==0) {
                    message += " and the SBML model(s) ";
                }
                else {
                    message += ", ";
                }
                message += "'" + textbox(tab)->GetModelName() + "'";
                unsaved.push_back(tab);
            }
        }
    }
    if (unsaved.size()==0) return true;
    if (unsaved.size()==1) {
        message += " has";
    }
    else {
        message += " have";
    }
    message += " not been saved.  Save before closing?";
    QMessageBox msgBox;
    msgBox.setText("Some tabs have not been saved.");
    msgBox.setInformativeText(message);
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Discard);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch(ret)  {
    case QMessageBox::Cancel:
        return false;
    case QMessageBox::Discard:
        return true;
    case QMessageBox::Save:
    default:
        break;
    }
    for (size_t unum=0; unum<unsaved.size(); unum++) {
        textbox(unsaved[unum])->SaveTab();
    }
    bool someunsaved = false;
    for (int tab=0; tab<count(); tab++) {
        if (!textbox(tab)->IsSaved()) {
            someunsaved=true;
        }
    }
    if (someunsaved) {
        QMessageBox msgBox2;
        msgBox2.setText("Some tabs are still unsaved.");
        msgBox2.setInformativeText("Close window anyway?");
        msgBox2.setStandardButtons(QMessageBox::Cancel | QMessageBox::Discard);
        msgBox2.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox2.exec();
        switch(ret) {
        case QMessageBox::Discard:
            return true;
        case QMessageBox::Cancel:
        default:
            return false;
        }
    }
    return true;
}
