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
        m_levelversion(4)
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
      ReplaceTextWith(writeSBMLToString(sbmldoc));
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

void SBMLTab::SetTranslated()
{
    ChangeableTextBox::SetTranslated();
    m_levelversion = 4;
}
