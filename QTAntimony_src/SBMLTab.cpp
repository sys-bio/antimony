#include <QInputDialog>

#include "CopyMessageBox.h"
#include "SBMLTab.h"
#include "Settings.h"
#include <sbml/SBMLTypes.h>

#define DEFAULTCOMP "default_compartment" //Also defined in module.cpp and antimony_api.cpp

//using namespace std;

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent),
        m_modelname(""),
        m_levelversion(5)
{
    m_filetypes = "SBML files (*.xml *.sbml);;All files(*.*)";
    m_extension = ".xml";
    QSettings qset(ORG, APP);
    qset.sync();
    QFont defaultfont;
    defaultfont.setFamily("Courier New");
    defaultfont.setPointSize(10);
    QFont newfont;
    newfont.fromString(qset.value("xmlfont", defaultfont).toString());
    setFont(newfont);
    //m_levelversion = qset.value("sbmlLV", m_levelversion).Int();
    // LS NOTE:  maybe do this at some point?  From an option in the menu, maybe?
    m_sbmlw.setProgramName("libAntimony");
    m_sbmlw.setProgramVersion(LIBANTIMONY_VERSION_STRING);
}

void SBMLTab::SetModelName(QString name)
{
    if (name=="") name = "__main";
    m_modelname = name;
}

QString SBMLTab::GetModelName()
{
    return m_modelname;
}

QString SBMLTab::GetTabName()
{
    QString tabname = "SBML";
    if (!(m_modelname == "__main")) {
        tabname += " - " + m_modelname;
    }
    if (!IsSaved()) {
        tabname += " *";
    }
    return tabname;
}

void SBMLTab::addSpecialCopyToMenu(QMenu*, QAction*)
{
}

void SBMLTab::ReplaceModelWithString(QString, QString)
{
    //throw an error?  LS DEBUG
}

bool SBMLTab::IsMixed()
{
    return false;
}

bool SBMLTab::SetLevelAndVersion(int levelversion)
{
  m_levelversion = levelversion;
  switch(levelversion) {
  case 0: return SetLevelAndVersion(1, 2);
  case 1: return SetLevelAndVersion(2, 1);
  case 2: return SetLevelAndVersion(2, 2);
  case 3: return SetLevelAndVersion(2, 3);
  case 4: return SetLevelAndVersion(2, 4);
  case 5: return SetLevelAndVersion(3, 1);
  default:
      CopyMessageBox msgBox;
      QDataStream messagest = "";
      messagest << "Programming error:  unable to set SBML level and version to '" << levelversion << "':  unknown code.";
      QString message;
      messagest >> message;
      msgBox.setText(message);
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();
      return false;
  }
}

bool SBMLTab::SetLevelAndVersion(int level, int version)
{
    if (toPlainText().toUtf8() == "") return true;
    SBMLDocument* sbmldoc = readSBMLFromString(toPlainText().toUtf8());
    SBMLErrorLog* log = sbmldoc->getErrorLog();
    std::string trueerrors = "";
    for (unsigned int err=0; err<log->getNumErrors(); err++) {
        const SBMLError* error = log->getError(err);
        if(error->getSeverity() >=2) {
            if (trueerrors != "") trueerrors += "\n";
            trueerrors += error->getMessage();
        }
    }
    if (trueerrors != "") {
      CopyMessageBox msgBox;
      QString message = "Error before attempting to translate '" + GetModelName() + "' to the selected level and version.";
      msgBox.setText(message);
      msgBox.setInformativeText(trueerrors.c_str());
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();
      return false;
    }
    sbmldoc->setConsistencyChecksForConversion(LIBSBML_CAT_UNITS_CONSISTENCY, false);
    bool success = sbmldoc->setLevelAndVersion(level, version);
    if (success) {
      ReplaceTextWith(m_sbmlw.writeSBMLToString(sbmldoc));
    }
    else {
        //sbmldoc->getErrorLog()->clearLog();
        //sbmldoc->checkL2v1Compatibility();
        SBMLErrorLog* log = sbmldoc->getErrorLog();
        std::string trueerrors = "";
        for (unsigned int err=0; err<log->getNumErrors(); err++) {
            const SBMLError* error = log->getError(err);
            if(error->getSeverity() >=2) {
                if (trueerrors != "") trueerrors += "\n";
                trueerrors += error->getMessage();
            }
        }
      CopyMessageBox msgBox;
      QString message = "Error when attempting to translate '" + GetModelName() + "' to the selected level and version.";
      msgBox.setText(message);
      msgBox.setInformativeText(trueerrors.c_str());
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.exec();
  }

    return success;
}

bool SBMLTab::StoreLevelAndVersion(int level, int version)
{
  switch(level) {
  case 1:
    if (version==2) {
      m_levelversion = 0;
      return true;
    }
    return false;
  case 2:
    switch(version) {
    case 1:
      m_levelversion = 1;
      return true;
    case 2:
      m_levelversion = 2;
      return true;
    case 3:
      m_levelversion = 3;
      return true;
    case 4:
      m_levelversion = 4;
      return true;
    default:
      return false;
    }
  case 3:
    switch(version) {
    case 1:
      m_levelversion = 5;
      return true;
    default:
      return false;
    }
  default:
    return false;
  }
}

void SBMLTab::SetTranslated()
{
    SetLevelAndVersion(m_levelversion);
    ChangeableTextBox::SetTranslated();
}
