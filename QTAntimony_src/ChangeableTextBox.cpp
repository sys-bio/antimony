#include "ChangeableTextBox.h"
#include "LineNumberArea.h"
#include "QTAntimony.h"
#include "CopyMessageBox.h"
#include <QPalette>
#include <QPainter>
#include <QMenu>
#include <QContextMenuEvent>
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QApplication>
#include <QTextStream>
#include <QTextBlock>
#include <QList>
#include <QUrl>

using namespace std;

ChangeableTextBox::ChangeableTextBox(QWidget* parent)
  : QPlainTextEdit(parent),
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
    m_saved(""),
    m_filename(""),
    m_filetypes(""),
    m_extension(""),
    m_lineNumberArea(new LineNumberArea(this))

{
//    m_lineNumberArea = new LineNumberArea(this);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
    connect(this, SIGNAL(textChanged()), this, SLOT(SetTextChanged()));
    connect(this, SIGNAL(copyAvailable(bool)), this, SLOT(SaveAndEmitCopyAvailable(bool)));
    connect(this, SIGNAL(undoAvailable(bool)), this, SLOT(SaveAndEmitUndoAvailable(bool)));
    connect(this, SIGNAL(redoAvailable(bool)), this, SLOT(SaveAndEmitRedoAvailable(bool)));
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

//    setAcceptRichText(false);
    setLineWrapMode(QPlainTextEdit::WidgetWidth);
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
    emit IsActive(this);
}

void ChangeableTextBox::SetInactive()
{
    m_isactive = false;
}

void ChangeableTextBox::SetTextChanged()
{
    emit TabNameIsNow(GetTabName(), this);
    if (!m_original.isEmpty() && toPlainText() == m_original) {
        SetOriginal();
        return;
    }
    if (!m_translated.isEmpty() && toPlainText() == m_translated) {
        SetTranslated();
        return;
    }
    // cout << "Setting tab " << GetTabName().toStdString() << " to 'changed'" << endl;
    viewport()->setBackgroundRole(QPalette::Base);
    SetNormalBorder();
    m_failedtranslation = false;
}

void ChangeableTextBox::SetTranslated()
{
    // cout << "Setting tab " << GetTabName().toStdString() << " to 'translated'" << endl;
    m_translated = toPlainText();
    m_failedtranslation = false;
    EmitPreviousAvailable();
    viewport()->setBackgroundRole(QPalette::Midlight);
    SetNormalBorder();
}

void ChangeableTextBox::SetFailedTranslation()
{
    // cout << "Setting tab " << GetTabName().toStdString() << " to 'failed translation'" << endl;
    m_failedtranslation = true;
    viewport()->setBackgroundRole(QPalette::AlternateBase);
    SetNormalBorder();
}

void ChangeableTextBox::SetOriginal()
{
    // cout << "Setting tab " << GetTabName().toStdString() << " to 'original'" << endl;
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

void ChangeableTextBox::SaveAndEmitCopyAvailable(bool yes)
{
    m_copyavailable = yes;
    if (m_isactive) {
        emit ActiveCopyAvailable(yes);
    }
}

void ChangeableTextBox::SaveAndEmitUndoAvailable(bool yes)
{
    m_undoavailable = yes;
    if (m_isactive) {
        emit ActiveUndoAvailable(yes);
    }
}

void ChangeableTextBox::SaveAndEmitRedoAvailable(bool yes)
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

void ChangeableTextBox::SaveTab()
{
    QTAntimony* app = static_cast<QTAntimony*>(QApplication::instance());
    if (m_filename == "") {
        QString suggestedname = app->GetCurrentDir();
#ifdef Q_OS_WIN
        suggestedname += "\\";
#else
        suggestedname += "/";
#endif
        suggestedname += GetModelName() + m_extension;
        SetFilename(QFileDialog::getSaveFileName(
                this,
                tr("Save file"),
                suggestedname,
                m_filetypes));
        if (m_filename=="") return; //User probably chose 'cancel'
    }
    QFile file(m_filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        CopyMessageBox msgBox;
        QString message = "Unable to open file '" + m_filename + "' for writing.";
        msgBox.setText(message);
        msgBox.setInformativeText("Try to save again, or cancel?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch(ret)  {
        case QMessageBox::Save:
            return SaveTab();
        case QMessageBox::Cancel:
        default:
            return;
        }
    }
    QTextStream out(&file);
    out << toPlainText();
    m_saved = toPlainText();
    QFileInfo qfi(m_filename);
    app->SaveCurrentDirectory(qfi.absoluteDir().absolutePath());
    QWidget* mainw = parentWidget();
    while (mainw->parentWidget() != NULL) {
        mainw = mainw->parentWidget();
    }
    mainw->setWindowTitle(qfi.fileName() + " - QTAntimony");
    emit TabNameIsNow(GetTabName(), this);
}

void ChangeableTextBox::SaveTabAs()
{
    if (m_filename != "") {
        emit StopWatching(m_filename);
    }
    m_filename = QFileDialog::getSaveFileName(
        this,
        tr("Save file"),
        m_filename,
        m_filetypes);
    if (m_filename=="") return; //User probably chose 'cancel'
    SaveTab();
}

void ChangeableTextBox::DisplayError(QString error)
{
    CopyMessageBox msgBox;
    QString message = "Error when attempting to translate " + GetModelName() + ":";
    msgBox.setText(message);
    if (error.size() > 2000) {
      error.replace(2000, error.size() - 2000, "\n[...]");
    }
    msgBox.setInformativeText(error);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void ChangeableTextBox::dropEvent(QDropEvent* e)
{
    if (e->mimeData()->hasUrls()) {
        QList<QUrl> files = e->mimeData()->urls();
        for (int file=0; file<files.size(); file++) {
            QTAntimony* app = static_cast<QTAntimony*>(QApplication::instance());
            app->OpenFile(files[file].toLocalFile());
        }
    }
    else {
        QPlainTextEdit::dropEvent(e);
    }
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

bool ChangeableTextBox::IsSaved()
{
    return (toPlainText()==m_saved);
}

bool ChangeableTextBox::IsFailed()
{
    return m_failedtranslation;
}

void ChangeableTextBox::SetFilename(QString filename)
{
    m_filename = filename;
    emit StartWatching(filename);
}

void ChangeableTextBox::SetSavedFilename(QString filename)
{
    SetFilename(filename);
    m_saved = toPlainText();
    emit TabNameIsNow(GetTabName(), this);
}

QString ChangeableTextBox::GetFilename()
{
  return m_filename;
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

int ChangeableTextBox::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
     int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;
     return space;
}

void ChangeableTextBox::zoomIn()
{
    QFont mfont = font();
    int size = mfont.pointSize();
    size = size*1.1;
    if (size == mfont.pointSize()) {
      size++;
    }
    mfont.setPointSize(size);
    setFont(mfont);
}

void ChangeableTextBox::zoomOut()
{
    QFont mfont = font();
    int size = mfont.pointSize();
    size = size/1.1;
    if (size == mfont.pointSize()) {
      size--;
    }
    if (size==0) {
      size=1;
    }
    mfont.setPointSize(size);
    setFont(mfont);
}
void ChangeableTextBox::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void ChangeableTextBox::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
      m_lineNumberArea->scroll(0, dy);
    else
      m_lineNumberArea->update(0, rect.y(), m_lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
      updateLineNumberAreaWidth(0);
}

void ChangeableTextBox::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    m_lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void ChangeableTextBox::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
 }

void ChangeableTextBox::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(m_lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, m_lineNumberArea->width(), fontMetrics().height(),
              Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}