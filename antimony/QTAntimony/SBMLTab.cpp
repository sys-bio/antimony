#include "SBMLTab.h"

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent)
{
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
    if (QString(m_modelname) == QString("__main")) {
        return QString("SBML");
    }
    else {
        return QString("SBML - ") + QString(m_modelname);
    }
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
