#include <QInputDialog>

#include "CopyMessageBox.h"
#include "CellMLTab.h"
#include "Settings.h"

#define DEFAULTCOMP "default_compartment" //Also defined in module.cpp and antimony_api.cpp

//using namespace std;

CellMLTab::CellMLTab(QWidget* parent)
        : ChangeableTextBox(parent),
        m_modelname("")
{
    m_filetypes = "CellML files (*.xml *.cellml);;All files(*.*)";
    m_extension = ".cellml";
    QSettings qset(ORG, APP);
    qset.sync();
    QFont defaultfont;
    defaultfont.setFamily("Courier New");
    defaultfont.setPointSize(10);
    QFont newfont;
    newfont.fromString(qset.value("xmlfont", defaultfont).toString());
    setFont(newfont);
}

void CellMLTab::SetModelName(QString name)
{
    if (name=="") name = "__main";
    m_modelname = name;
}

QString CellMLTab::GetModelName()
{
    return m_modelname;
}

QString CellMLTab::GetTabName()
{
    QString tabname = "CellML";
    if (!(m_modelname == "__main")) {
        tabname += " - " + m_modelname;
    }
    if (!IsSaved()) {
        tabname += " *";
    }
    return tabname;
}

void CellMLTab::addSpecialCopyToMenu(QMenu*, QAction*)
{
}

void CellMLTab::ReplaceModelWithString(QString, QString)
{
    //throw an error?  LS DEBUG
}

bool CellMLTab::IsMixed()
{
    return false;
}

void CellMLTab::SetTranslated()
{
    ChangeableTextBox::SetTranslated();
}
