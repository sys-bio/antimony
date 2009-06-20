#include "ChangeableTextBox.h"
#include <QPalette>
#include <QMenu>
#include <QContextMenuEvent>
#include <iostream>
#include <QFile>
#include <QFileInfo>

using namespace std;

ChangeableTextBox::ChangeableTextBox(QWidget* parent)
  : QTextEdit(parent),
    m_isactive(false),
    m_failedtranslation(false),
    m_copyavailable(false),
    m_undoavailable(false),
    m_redoavailable(false),
    m_origline(lineWidth()),
    m_origmidline(midLineWidth()),
    m_origshape(frameShape()),
    m_origshadow(frameShadow()),
    m_translated(""),
    m_original(""),
    m_filename("")

{
    connect(this, SIGNAL(textChanged()), this, SLOT(SetTextChanged()));
    connect(this, SIGNAL(copyAvailable(bool)), this, SLOT(SaveAndEmitCopyAvailable(bool)));
    connect(this, SIGNAL(undoAvailable(bool)), this, SLOT(SaveAndEmitUndoAvailable(bool)));
    connect(this, SIGNAL(redoAvailable(bool)), this, SLOT(SaveAndEmitRedoAvailable(bool)));
    setAcceptRichText(false);
    setLineWrapMode(QTextEdit::NoWrap);
    setAutoFillBackground(true);
    QPalette p = viewport()->palette();
    QColor pink;
    pink.setRgb(255, 187, 187);
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
    if (toPlainText() == m_translated) {
        SetTranslated();
        return;
    }
    if (toPlainText() == m_original) {
        SetOriginal();
        return;
    }
    cout << "Setting tab " << GetTabName().toStdString() << " to 'changed'" << endl;
    viewport()->setBackgroundRole(QPalette::Base);
    SetNormalBorder();
    m_failedtranslation = false;
}

void ChangeableTextBox::SetTranslated()
{
    cout << "Setting tab " << GetTabName().toStdString() << " to 'translated'" << endl;
    m_translated = toPlainText();
    m_failedtranslation = false;
    EmitPreviousAvailable();
    viewport()->setBackgroundRole(QPalette::Midlight);
    SetNormalBorder();
}

void ChangeableTextBox::SetFailedTranslation()
{
    cout << "Setting tab " << GetTabName().toStdString() << " to 'failed translation'" << endl;
    m_failedtranslation = true;
    viewport()->setBackgroundRole(QPalette::AlternateBase);
}

void ChangeableTextBox::SetOriginal()
{
    cout << "Setting tab " << GetTabName().toStdString() << " to 'original'" << endl;
    m_failedtranslation = false;
    m_original = toPlainText();
    EmitPreviousAvailable();
    viewport()->setBackgroundRole(QPalette::Base);
    setLineWidth(3);
    setMidLineWidth(3);
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Plain);
}

void ChangeableTextBox::SetNormalBorder()
{
    setLineWidth(m_origline);
    setMidLineWidth(m_origmidline);
    setFrameShape(m_origshape);
    setFrameShadow(m_origshadow);
}

void ChangeableTextBox:: SaveAndEmitCopyAvailable(bool yes)
{
    m_copyavailable = yes;
    if (m_isactive) {
        emit ActiveCopyAvailable(yes);
    }
}

void ChangeableTextBox:: SaveAndEmitUndoAvailable(bool yes)
{
    m_undoavailable = yes;
    if (m_isactive) {
        emit ActiveUndoAvailable(yes);
    }
}

void ChangeableTextBox:: SaveAndEmitRedoAvailable(bool yes)
{
    m_redoavailable = yes;
    if (m_isactive) {
        emit ActiveRedoAvailable(yes);
    }
}

void ChangeableTextBox::EmitPreviousAvailable()
{
    if (m_translated != "") {
        emit TranslatedAvailable(true);
    }
    else {
        emit TranslatedAvailable(false);
    }
    if (m_original != "") {
        emit OriginalAvailable(true);
    }
    else {
        emit OriginalAvailable(false);
    }
}

void ChangeableTextBox::RevertToTranslated()
{
    ReplaceTextWith(m_translated);
    SetTranslated();
}

void ChangeableTextBox::RevertToOriginal()
{
    ReplaceTextWith(m_original);
    SetOriginal();
}


void ChangeableTextBox::FileChanged(const QString& file)
{
    if (file != m_filename) return;
    //Do something.
}

void ChangeableTextBox::ReplaceTextWith(QString text)
{
    if (text == toPlainText()) return;
    //selectAll();
    //insertPlainText(text);
    QTextCursor ntcursor = textCursor();
    ntcursor.beginEditBlock();
    ntcursor.select(QTextCursor::Document);
    ntcursor.insertText(text);
    ntcursor.setPosition(0);
    ntcursor.endEditBlock();
    setTextCursor(ntcursor);
}

bool ChangeableTextBox::IsOriginal()
{
    return (toPlainText()==m_original);
}

bool ChangeableTextBox::IsTranslated()
{
    return (toPlainText()==m_translated);
}

void ChangeableTextBox::SetTranslatedText(QString text)
{
    ReplaceTextWith(text);
    SetTranslated();
}

void ChangeableTextBox::NewlyActive()
{
    SetActive();
    SaveAndEmitCopyAvailable(m_copyavailable);
    SaveAndEmitUndoAvailable(m_undoavailable);
    SaveAndEmitRedoAvailable(m_redoavailable);
    EmitPreviousAvailable();
}

void ChangeableTextBox::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu* menu = createStandardContextMenu();
    QList<QAction*> menuactions = menu->actions();
    QAction* paste = NULL;
    for (int act=0; act<menuactions.size(); act++) {
        QString actname = menuactions[act]->text();
        if (actname.contains("&Paste")) {
            paste = menuactions[act];
        }
    }
    addSpecialCopyToMenu(menu, paste);
    menu->exec(event->globalPos());
    delete menu;
}
