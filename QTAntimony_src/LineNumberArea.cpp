#include "LineNumberArea.h"
#include "ChangeableTextBox.h"
#include "QTAntimony.h"
#include "CopyMessageBox.h"
#include <QPalette>
#include <QMenu>
#include <QContextMenuEvent>
#include <iostream>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QApplication>
#include <QTextStream>
#include <QList>
#include <QUrl>

using namespace std;

LineNumberArea::LineNumberArea(ChangeableTextBox* editor) 
  : QWidget(editor) 
{
    m_codeEditor = editor;
}

QSize LineNumberArea::sizeHint() const 
{
    return QSize(m_codeEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    m_codeEditor->lineNumberAreaPaintEvent(event);
}
