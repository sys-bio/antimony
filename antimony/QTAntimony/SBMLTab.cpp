#include "SBMLTab.h"

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent)
{
    m_filetypes = "SBML files (*.xml *.sbml);;All files(*.*)";
    m_extension = ".xml";
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

void SBMLTab::addSpecialCopyToMenu(QMenu* menu, QAction* defaultcut)
{
}

void SBMLTab::ReplaceModelWithString(QString modelname, QString text)
{
    //throw an error?  LS DEBUG
}

bool SBMLTab::IsMixed()
{
    return false;
}
