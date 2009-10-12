#include <QInputDialog>

#include "SBMLTab.h"
#include "Settings.h"
#include <sbml/SBMLTypes.h>

#define DEFAULTCOMP "default_compartment" //Also defined in module.cpp and antimony_api.cpp

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent),
        m_modelname(""),
        m_levelversion(4)
{
    m_filetypes = "SBML files (*.xml *.sbml);;All files(*.*)";
    m_extension = ".xml";
    QSettings qset(ORG, APP);
    qset.sync();
    QFont newfont;
    newfont.fromString(qset.value("sbmlfont", currentFont()).toString());
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

bool SBMLTab::SetLevelAndVersion(int level, int version)
{
    SBMLDocument* sbmldoc = readSBMLFromString(toPlainText().toUtf8());
    bool success = sbmldoc->setLevelAndVersion(level, version);
    if (success) {
        ReplaceTextWith(writeSBMLToString(sbmldoc));
    }
    return success;
}

void SBMLTab::SetTranslated()
{
    ChangeableTextBox::SetTranslated();
    m_levelversion = 4;
}

void SBMLTab::WhichLevelAndVersion()
{
    QStringList lvs;
    lvs     << tr("Level 1 Version 2")
            << tr("Level 2 Version 1")
            << tr("Level 2 Version 2")
            << tr("Level 2 Version 3")
            << tr("Level 2 Version 4")
            //<< tr("Level 3 Version 1")
            ;
     bool ok;
     QString item = QInputDialog::getItem(this, tr("SBML Level and Version"),
                                          "Choose SBML Level and Version for " + GetTabName() + ":", lvs, m_levelversion, false, &ok);
     if (ok && !item.isEmpty()) {
         if (item == "Level 1 Version 2") {
             SetLevelAndVersion(1,2);
             m_levelversion = 0;
         }
         if (item == "Level 2 Version 1") {
             SetLevelAndVersion(2,1);
             m_levelversion = 1;
         }
         if (item == "Level 2 Version 2") {
             SetLevelAndVersion(2,2);
             m_levelversion = 2;
         }
         if (item == "Level 2 Version 3") {
             SetLevelAndVersion(2,3);
             m_levelversion = 3;
         }
         if (item == "Level 2 Version 4") {
             SetLevelAndVersion(2,4);
             m_levelversion = 4;
         }
         if (item == "Level 3 Version 1") {
             SetLevelAndVersion(3,1);
             m_levelversion = 5;
         }
     }
}
