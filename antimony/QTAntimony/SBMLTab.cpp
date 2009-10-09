#include "SBMLTab.h"
#include "Settings.h"

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent)
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
