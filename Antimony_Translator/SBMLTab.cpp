#include "SBMLTab.h"

SBMLTab::SBMLTab(QWidget* parent)
        : ChangeableTextBox(parent)
{
}

void SBMLTab::SetModelName(QString name)
{
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
