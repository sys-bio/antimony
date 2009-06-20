#include "AntimonyTab.h"
#include "antimony_api.h"
#include "Translator.h"
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QTextCursor>
#include <QMenu>

#include <iostream>
using namespace std;

AntimonyTab::AntimonyTab(QWidget* parent)
        : ChangeableTextBox(parent),
        m_actionCopySBML(NULL),
        m_selectedasSBML(""),
        m_ismixed(false)
{
    m_actionCopySBML= new QAction(tr("Copy &SBML"), this);
    m_actionCopySBML->setEnabled(false);
    connect(m_actionCopySBML, SIGNAL(triggered()), this, SLOT(CopySBML()));
}

void AntimonyTab::SetModelName(QString name)
{
}

QString AntimonyTab::GetModelName()
{
    return "";
}

QString AntimonyTab::GetTabName()
{
    return "Antimony";
}

void AntimonyTab::addSpecialCopyToMenu(QMenu* menu, QAction* paste)
{
    m_actionCopySBML->setEnabled(setupSBMLCopy());
    menu->insertAction(paste, m_actionCopySBML);
}

bool AntimonyTab::setupSBMLCopy()
{
    QString antimony = textCursor().selectedText();
    antimony.replace(QChar::ParagraphSeparator, "\n");
    if (antimony == "") return false;
    long handle = loadString(antimony.toAscii().data());
    if (handle==-1) {
        return false;
    }
    long mod=0;
    long nummods = getNumModules();
    if (nummods == 1) {
        mod=0;
    }
    else if (nummods == 2) {
        char* mod0name = getNthModuleName(0);
        if (getNumSymbolsOfType(mod0name, allSymbols) > 0) return false;
        mod = 1;
    }
    char* modname = getNthModuleName(mod);
    char* SBML = getSBMLString(modname);
    m_selectedasSBML = SBML;
    clearPreviousLoads();
    freeAll();
    return true;
}

void AntimonyTab::CopySBML()
{
    QApplication::clipboard()->setText(m_selectedasSBML);
}

void AntimonyTab::ReplaceModelWithString(QString modelname, QString text)
{
    text = text.trimmed();
    QString model = toPlainText();
    std::string DEBUGST = model.toStdString();
    DEBUGST = text.toStdString();
    if (modelname != "__main") {
        QString pattern = "(model|module)\\s+" + modelname + ".*end";
        QRegExp text_to_find(pattern, Qt::CaseInsensitive);
        text_to_find.setMinimal(true);
        if (model.contains(text_to_find)) {
            model.replace(text_to_find, text);
        }
        else {
            model.append(text);
        }
    }
    else {
        QString nomain = "";
        //Save all the existing model/end text
        QRegExp text_to_find("(model|module).*end", Qt::CaseInsensitive);
        text_to_find.setMinimal(true);
        int pos = 0;
        while ((pos = text_to_find.indexIn(model, pos)) != -1) {
            nomain += text_to_find.cap(0) + "\n\n";
            pos += text_to_find.matchedLength();
        }
        model = nomain + text;
    }

    model = model.trimmed();
    ReplaceTextWith(model);
}

void AntimonyTab::SetMixed()
{
    cout << "Setting tab " << GetTabName().toStdString() << " to 'mixed'" << endl;
    m_ismixed = true;
    viewport()->setBackgroundRole(QPalette::Midlight);
    setLineWidth(3);
    setMidLineWidth(3);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Plain);
}

bool AntimonyTab::IsMixed()
{
    return m_ismixed;
}

void AntimonyTab::SetTextChanged()
{
    m_ismixed = false;
    ChangeableTextBox::SetTextChanged();
}
