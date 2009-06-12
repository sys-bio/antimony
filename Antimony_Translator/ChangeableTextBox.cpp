#include "ChangeableTextBox.h"
#include <QPalette>

ChangeableTextBox::ChangeableTextBox(QWidget* parent)
  : QTextEdit(parent),
    m_isactive(false),
    m_textchanged(false),
    m_textuntranslated(true),
    m_copyavailable(false),
    m_undoavailable(false),
    m_redoavailable(false)

{
    connect(this, SIGNAL(textChanged()), this, SLOT(SetTextChanged()));
    connect(this, SIGNAL(copyAvailable(bool)), this, SLOT(SetCopyAvailable(bool)));
    connect(this, SIGNAL(undoAvailable(bool)), this, SLOT(SetUndoAvailable(bool)));
    connect(this, SIGNAL(redoAvailable(bool)), this, SLOT(SetRedoAvailable(bool)));
    setAcceptRichText(false);
    setLineWrapMode(QTextEdit::NoWrap);
    setAutoFillBackground(true);
    QPalette p = viewport()->palette();
    QColor pink;
    pink.setRgb(255, 187, 187);
    //altenatebase
    p.setColor(QPalette::AlternateBase, pink);
    viewport()->setPalette(p);
}



void ChangeableTextBox::SetActive()
{
    m_isactive = true;
}

void ChangeableTextBox::SetInactive()
{
    m_isactive = false;
}

void ChangeableTextBox::SetTextChanged()
{
    if (toPlainText() == m_lasttext) {
        SetTextUnchanged();
        return;
    }
    m_textchanged = true;
    viewport()->setBackgroundRole(QPalette::Base);
}

void ChangeableTextBox::SetTextUnchanged()
{
    m_textchanged = false;
    viewport()->setBackgroundRole(QPalette::Midlight);
}

void ChangeableTextBox::SetUntranslated()
{
    m_textuntranslated = true;
    viewport()->setBackgroundRole(QPalette::AlternateBase);
}

void ChangeableTextBox::SetOriginal()
{
    document()->documentLayout();
}

void ChangeableTextBox:: SetCopyAvailable(bool yes)
{
    m_copyavailable = yes;
    if (m_isactive) {
        emit ActiveCopyAvailable(yes);
    }
}

void ChangeableTextBox:: SetUndoAvailable(bool yes)
{
    m_undoavailable = yes;
    if (m_isactive) {
        emit ActiveUndoAvailable(yes);
    }
}

void ChangeableTextBox:: SetRedoAvailable(bool yes)
{
    m_redoavailable = yes;
    if (m_isactive) {
        emit ActiveRedoAvailable(yes);
    }
}

void ChangeableTextBox::SaveLastText()
{
    m_lasttext = toPlainText();
    SetLastTextAvailable();
}

void ChangeableTextBox::SetLastTextAvailable()
{
    if (m_lasttext != "") {
        emit LastTextAvailable(true);
    }
    else {
        emit LastTextAvailable(false);
    }
}

void ChangeableTextBox::RevertToLastText()
{
    setText(m_lasttext);
}

void ChangeableTextBox::SetText(QString text)
{
    if (text == toPlainText()) return;
    selectAll();
    insertPlainText(text);
    QTextCursor ntcursor = textCursor();
    ntcursor.setPosition(0);
    ntcursor.endEditBlock();
    setTextCursor(ntcursor);
}

void ChangeableTextBox::SetLastText(QString text)
{
    SetText(text);
    SaveLastText();
    SetTextUnchanged();
}

void ChangeableTextBox::NewlyActive()
{
    SetActive();
    SetCopyAvailable(m_copyavailable);
    SetUndoAvailable(m_undoavailable);
    SetRedoAvailable(m_redoavailable);
    SetLastTextAvailable();
}

bool ChangeableTextBox::GetTextChanged()
{
    return m_textchanged;
}

void ChangeableTextBox::ReplaceModelWithString(QString modelname, QString text)
{
    QString pattern = "(model|module) " + modelname + ".*end";
    QRegExp text_to_find(pattern, Qt::CaseInsensitive);
    text_to_find.setMinimal(true);
    QString model = toPlainText();
    model.replace(text_to_find, text);
    model = model.trimmed();
    SetLastText(model);
}
