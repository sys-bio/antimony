#include "TabManager.h"
#include "Translator.h"
#include "ChangeableTextBox.h"
#include "CopyMessageBox.h"
#include "SBMLTab.h"
#include "AntimonyTab.h"
#include "antimony_api.h"
#include "Settings.h"
#include <QPrintDialog>
#include <QAction>
#include <QFontDialog>
#include <QInputDialog>
#include <vector>
#include <cassert>


#ifdef SBW_INTEGRATION
#include "SBW/SBWC.h"
#endif

using namespace std;

TabManager::TabManager(QWidget* parent, QAction* flatten)
        : QTabWidget(parent),
        m_oldtab(-1),
        m_anttab(0),
        m_sbmltab(1),
        m_cellmltab(-1),
        m_flatten(false),
        m_actionFlatten(flatten)
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

ChangeableTextBox* TabManager::firstsbmltextbox()
{
  if (m_sbmltab < 0) return NULL;
  return static_cast<ChangeableTextBox*>(widget(m_sbmltab));
}

ChangeableTextBox* TabManager::cellmltextbox()
{
  if (m_cellmltab < 0) return NULL;
  return static_cast<ChangeableTextBox*>(widget(m_cellmltab));
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
void TabManager::print()
{
    QPrintDialog qpd(GetActiveEditor());
    if (qpd.exec() == QDialog::Accepted) {
        GetActiveEditor()->print(qpd.printer());
    }
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

void TabManager::addCellMLTab()
{

}

void TabManager::setAntimonyFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, textbox(m_anttab)->font(), this);
    if (ok) {
        // the user clicked OK and font is set to the font the user selected
        textbox(m_anttab)->setFont(font);
    }
}

void TabManager::setXMLFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, textbox(1)->font(), this);
    if (ok) {
        // the user clicked OK and font is set to the font the user selected
        for (int tab=1; tab<count(); tab++) {
            textbox(tab)->setFont(font);
        }
    }
}

void TabManager::zoomIn()
{
    int index = currentIndex();
    if (index==0) {
        textbox(index)->zoomIn();
    }
    else {
        for (int ind=1; ind<count(); ind++) {
            textbox(ind)->zoomIn();
        }
    }
}

void TabManager::zoomOut()
{
    int index = currentIndex();
    if (index==0) {
        textbox(index)->zoomOut();
    }
    else {
        for (int ind=1; ind<count(); ind++) {
            textbox(ind)->zoomOut();
        }
    }
}

void TabManager::sbmlTabs(bool checked)
{
  if (checked && m_sbmltab != -1) return; //Just making sure.
  if (!checked && m_sbmltab == -1) return; //Just making sure.
    if (checked) {
        assert(m_sbmltab == -1);
        //Add an SBML Tab (TranslateAntimony will add any necessary extras)
        if (m_cellmltab == -1) m_sbmltab = 1;
        else m_sbmltab = 2;
        Translator* translator = static_cast<Translator*>(parent());
        translator->AddSBMLTab();
        TranslateAntimony();
    }
    else {
        assert(m_sbmltab > 0);
        while (m_sbmltab < count()) {
            removeTab(m_sbmltab);
        }
        m_sbmltab = -1;
    }
}

void TabManager::cellmlTabs(bool checked)
{
  if (checked && m_cellmltab != -1) return; //reconfirm
  if (!checked && m_cellmltab == -1) return; //reconfirm
  if (checked) {
        assert(m_cellmltab == -1);
        //Add a CellML Tab
        m_cellmltab = 1;
        if (m_sbmltab==1) {
            m_sbmltab = 2;
        }
        Translator* translator = static_cast<Translator*>(parent());
        translator->AddCellMLTab();
        TranslateAntimony();
    }
    else {
        //Remove the CellML Tab
        assert(m_cellmltab == 1);
        removeTab(1);
        m_cellmltab = -1;
    }
}

ChangeableTextBox* TabManager::GetActiveEditor()
{
    return textbox(currentIndex());
}

void TabManager::SwitchTabs(int tab)
{
    ChangeableTextBox* oldtab = textbox(m_oldtab);
    ChangeableTextBox* newtab = textbox(tab);
    if ((oldtab != NULL) &&
        !oldtab->IsOriginal() &&
        !oldtab->IsTranslated() &&
        !oldtab->IsMixed()) {
        Translate(m_oldtab);
    }
    else if ((oldtab != NULL) &&
             !oldtab->IsFailed()) {
        newtab->SetTextChanged();
    }
    if (tab >= count()) {
        tab = count()-1;
        setCurrentIndex(tab);
        textbox(tab)->setFocus();
    }
    newtab->NewlyActive();
    m_oldtab = tab;
}

void TabManager::nextTab()
{
    int tab = currentIndex()+1;
    if (tab>count()) tab=0;
    setCurrentIndex(tab);
}


void TabManager::TranslateCurrent()
{
    Translate(currentIndex());
}

void TabManager::TranslateAntimony()
{
    Translate(m_anttab);
}

void TabManager::TranslateSBML()
{
    if (m_sbmltab == -1) return;
    for (int sbml=m_sbmltab; sbml<count(); sbml++) {
        Translate(sbml);
    }
}

void TabManager::TranslateCellML()
{
    Translate(m_cellmltab);
}

void TabManager::Translate(int tab)
{
    if (tab==-1) return;
    ChangeableTextBox* oldtab = textbox(tab);
    if (oldtab == NULL) return;
    setUpdatesEnabled(false);
    QString tabtext = oldtab->toPlainText();
    oldtab->SetOriginal();
    if (tab==m_anttab) {
        TranslateAntimony(tabtext);
    }
    else if (tab==m_cellmltab) {
        TranslateCellML(tabtext);
    }
    else {
        TranslateSBML(tab, tabtext);
    }
    clearPreviousLoads();
#ifndef WIN32
    freeAll();
#endif
    setUpdatesEnabled(true);
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

void TabManager::TranslateAntimony(QString& text)
{
    //Since this is an editor, they may have copied and pasted special characters into it, which need to be changed.
    text.replace(QChar(8230), "...");
    for (int i=0; i<text.size(); i++) {
        if (text[i].category()==QChar::Punctuation_Dash) {
            text[i] = '-';
        }
        else if (text[i]==QChar(8216) ||
                 text[i]==QChar(8217) ||
                 text[i]==QChar(8219)) {
            text[i] = '\'';
        }
        else if (text[i].category()==QChar::Punctuation_FinalQuote ||
                 text[i].category()==QChar::Punctuation_InitialQuote) {
            text[i] = '"';
        }
    }
    if (text.size()==0 || text[text.size()-1] != '\n') {
        text.append('\n');
    }
    //If we have changed the above, replace the text with the 'correct' version.
    if (text != textbox(m_anttab)->toPlainText()) {
        textbox(m_anttab)->ReplaceTextWith(text);
        textbox(m_anttab)->SetOriginal();
    }
    //Now translate the model:
    long handle = loadString(text.toUtf8().data());
    if (handle == -1) {
        //error condition
        char* error = getLastError();
        emit FailedAntimonyTranslation();
        textbox(0)->DisplayError(error);
        return;
    }
    //Translate to CellML if need be:
	if (m_cellmltab != -1) {
		ChangeableTextBox* cellmltab = textbox(m_cellmltab);
		char* mainmodel = getMainModuleName();
#ifdef NCELLML
    cellmltab->SetTranslatedText("Unable to translate CellML Text");
#else
    char* cellmltext = getCellMLString(mainmodel); //LS DEBUG CELLML
		cellmltab->SetTranslatedText(QString(cellmltext));
#endif
	}
    //Translate to SBML if need be:
	if (m_sbmltab != -1) {
		long nummods = getNumModules();
		long visibletabs = nummods + m_sbmltab;
		Translator* translator = static_cast<Translator*>(parent());
		while (count() != visibletabs) {
			if (count() > visibletabs) {
				removeTab(count()-1);
			}
			else {
				translator->AddSBMLTab();
			}
		}
		for (long mod=0; mod<nummods; mod++) {
			char* modname = getNthModuleName(mod);
			long tabnum = mod+m_sbmltab-1;
			if (mod==0) {
				//The '__main' module will always be model 0.  I want this to be the *last* tab for this translator, so since the Antimony tab is tab 0, model 0 (if it has any variables) goes to the end.
				long numvars = getNumSymbolsOfType(modname, allSymbols);
				if (numvars == 0 && nummods != 1) {
					removeTab(count()-1);
					continue;
				}
				tabnum = nummods+m_sbmltab-1;
			}
			ChangeableTextBox* tab_s = textbox(tabnum);
#ifdef USE_COMP
      if (m_flatten) {
        tab_s->SetTranslatedText(QString(getSBMLString(modname)));
      }
      else {
        tab_s->SetTranslatedText(QString(getCompSBMLString(modname)));
      }
#else
      tab_s->SetTranslatedText(QString(getSBMLString(modname)));
#endif
      tab_s->SetModelName(QString(modname));
			setTabText(tabnum, tab_s->GetTabName());
		}
	}
    clearPreviousLoads();
#ifndef WIN32
    freeAll();
#endif
}

void TabManager::TranslateSBML(int tab, const QString& text)
{
    ChangeableTextBox* tab_s = textbox(tab);
    QString oldmodelname = tab_s->GetModelName();
    int handle = loadSBMLString(text.toUtf8().data());
    if (handle == -1) {
        char* error = getLastError();
        emit FailedSBMLTranslation();
        tab_s->DisplayError(error);
        //do something about the error
        return;
    }
    unsigned long nummods = getNumModules();
    bool multiples = true;
    if (nummods==1 || (nummods==2 && getNumSymbolsOfType(getNthModuleName(0), allSymbols)==0) ) {
      multiples = false;
    }
    long modelnum = 0;
    if (getNumModules() == 2) {
        modelnum = 1;
    }
    QString modelname = getMainModuleName();
    tab_s->SetModelName(modelname);
    setTabText(tab, tab_s->GetTabName());

    char* antimonytext = getAntimonyString(NULL);
    AntimonyTab* anttab = static_cast<AntimonyTab*>(textbox(m_anttab));
    if (multiples) {
      anttab->SetTranslatedText(QString(antimonytext));
    }
    else {
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
    }
    clearPreviousLoads();
#ifndef WIN32
    freeAll();
#endif
}

void TabManager::TranslateCellML(QString& text)
{
    textbox(m_cellmltab)->SetOriginal();
#ifdef NCELLML
    long handle = loadSBMLString(text.toUtf8().data());
#else
    long handle = loadCellMLString(text.toUtf8().data());
#endif
    if (handle == -1) {
        //error condition
        char* error = getLastError();
        emit FailedCellMLTranslation();
        textbox(m_cellmltab)->DisplayError(error);
        return;
    }
    if (m_anttab != -1) {
        char* antimonytext = getAntimonyString(NULL);
        ChangeableTextBox* anttab = textbox(m_anttab);
        anttab->SetTranslatedText(QString(antimonytext));
    }
    if (m_sbmltab != -1) {
        Translator* translator = static_cast<Translator*>(parent());
        long nummods = getNumModules();
        while (count() - m_sbmltab != nummods) {
            if (count() - m_sbmltab > nummods) {
                removeTab(count()-1);
            }
            else {
                translator->AddSBMLTab();
            }
        }
        int tabnum = m_sbmltab;
        for (long mod=0; mod<nummods; mod++) {
            char* modname = getNthModuleName(mod);
            ChangeableTextBox* tab_s = textbox(tabnum);
#ifdef USE_COMP
            if (m_flatten) {
              tab_s->SetTranslatedText(QString(getSBMLString(modname)));
            }
            else {
              tab_s->SetTranslatedText(QString(getCompSBMLString(modname)));
            }
#else
            tab_s->SetTranslatedText(QString(getSBMLString(modname)));
#endif
            tab_s->SetModelName(QString(modname));
            setTabText(tabnum, tab_s->GetTabName());
            tabnum++;
        }
    }
    clearPreviousLoads();
#ifndef WIN32
    freeAll();
#endif
}

void TabManager::SetAllSBMLLevelsAndVersions()
{
  if (m_sbmltab == -1) return;
  QStringList lvs;
  lvs     << tr("Level 1 Version 2")
          << tr("Level 2 Version 1")
          << tr("Level 2 Version 2")
          << tr("Level 2 Version 3")
          << tr("Level 2 Version 4")
          << tr("Level 3 Version 1")
    ;
  bool ok;
  SBMLTab* sbmltab = static_cast<SBMLTab*>(textbox(m_sbmltab));

  int levelversion = sbmltab->GetLevelAndVersionCode();
  QString item = QInputDialog::getItem(this, tr("SBML Level and Version"),
    tr("Choose SBML Level and Version:"), lvs, levelversion, false, &ok);
  if (ok && !item.isEmpty()) {
    if (item == tr("Level 1 Version 2")) {
      levelversion = 0;
    }
    if (item == tr("Level 2 Version 1")) {
      levelversion = 1;
    }
    if (item == tr("Level 2 Version 2")) {
      levelversion = 2;
    }
    if (item == tr("Level 2 Version 3")) {
      levelversion = 3;
    }
    if (item == tr("Level 2 Version 4")) {
      levelversion = 4;
    }
    if (item == tr("Level 3 Version 1")) {
      levelversion = 5;
    }
  }
  if (levelversion <=4 && m_flatten==false) {
    m_actionFlatten->toggle();
  }
  for (int tnum=m_sbmltab; tnum<count(); tnum++) {
    sbmltab = static_cast<SBMLTab*>(textbox(tnum));
    sbmltab->SetLevelAndVersion(levelversion);
  }
}

void TabManager::SetFlatten(bool flatten)
{
#ifndef USE_COMP
  flatten = false;
#endif
  AntimonyTab* anttab = static_cast<AntimonyTab*>(textbox(m_anttab));
  anttab->SetFlatten(flatten);
  if (m_flatten==flatten) return; //Don't try to switch anything.
  m_flatten = flatten;
  //change the flattening state
  for (int tnum=m_sbmltab; tnum<count(); tnum++) {
    SBMLTab* sbmltab = static_cast<SBMLTab*>(textbox(tnum));
    QString SBML;
#ifdef USE_COMP
    if (flatten) {
#endif
      loadSBMLString(sbmltab->toPlainText().toAscii());
      SBML = getSBMLString(NULL);
#ifdef USE_COMP
    }
    else {
      QString modelname = sbmltab->GetModelName();
      loadAntimonyString(anttab->toPlainText().toAscii());
      SBML = getCompSBMLString(modelname.toAscii());
      sbmltab->StoreLevelAndVersion(3, 1);
    }
#endif
    sbmltab->SetTranslatedText(SBML);
  }
  clearPreviousLoads();
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
    textbox(m_anttab)->SaveTab();
}

void TabManager::SaveCellML()
{
    if (m_cellmltab == -1) return;
    textbox(m_cellmltab)->SaveTab();
}

void TabManager::SaveAllSBML()
{
    if (m_sbmltab == -1) return;
    for (int tab=m_sbmltab; tab<count(); tab++) {
        textbox(tab)->SaveTab();
    }
}

bool TabManager::CanIClose()
{
    QString message = "The ";
    vector<int> unsaved;
    for (int tab=0; tab<count(); tab++) {
        if (!(textbox(tab)->IsTranslated()) && !(textbox(tab)->IsSaved())) {
            if (tab==m_anttab) {
                message += "Antimony tab";
                unsaved.push_back(tab);
            }
            else if (tab==m_cellmltab) {
                message += "CellML tab";
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
    CopyMessageBox msgBox;
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
        msgBox2.setStyleSheet("QMessageBox { messagebox-text-interaction-flags: 1 }");
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

void TabManager::SaveFonts()
{
    QSettings qset(ORG, APP);
    qset.sync();
    qset.setValue("antimonyfont", textbox(m_anttab)->currentFont());
    if (m_sbmltab != -1) {
        qset.setValue("xmlfont", textbox(m_sbmltab)->currentFont());
    }
    else if (m_cellmltab != -1) {
        qset.setValue("xmlfont", textbox(m_cellmltab)->currentFont());
    }
}

void TabManager::SaveTabDisplay()
{
    QSettings qset(ORG, APP);
    qset.sync();
    qset.setValue("displaysbml", (m_sbmltab!= -1));
    qset.setValue("displaycellml", (m_cellmltab != -1));
    qset.setValue("flattensbml", m_flatten);
}

#ifdef SBW_INTEGRATION
void TabManager::startSBWAnalyzer()
{
    ChangeableTextBox* exporttab = GetActiveEditor();
    if (currentIndex()==m_anttab) {
        //We were on the Antimony tab--translate it if needed
        if (!exporttab->IsOriginal() &&
            !exporttab->IsTranslated() &&
            !exporttab->IsMixed()) {
            Translate(m_anttab);
        }
        //Assume the last SBML tab is the one to export
        exporttab = textbox(count()-1);
    }
    string sbml = exporttab->toPlainText().toUtf8().constData();
    if (sbml.length() == 0) return;
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        try
        {
            QStringList oModuleInfo = action->data().toStringList();

            int nModule =  SBWGetModuleInstance(oModuleInfo[0].toUtf8().constData());
            int nService =  SBWModuleFindServiceByName(nModule, oModuleInfo[1].toUtf8().constData());
            int nMethod = SBWServiceGetMethod(nModule, nService, "void doAnalysis(string)");
            SBWMethodSend(nModule, nService, nMethod,"void doAnalysis(string)", sbml.c_str());
        }
        catch(...)
        {
        }
    }
}
#endif
