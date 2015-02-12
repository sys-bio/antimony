/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#include <QtGui>
#include <QPlainTextEdit>
#include <QRegExp>
#include <QSettings>

#include "GoToLineForm.h"
#include "ui_GoToLineForm.h"

GoToLineForm::GoToLineForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoToLineForm), m_textEdit(NULL)
{
    ui->setupUi(this);

    connect(ui->goToLine, SIGNAL(textChanged(QString)), this, SLOT(goToLineChanged(QString)));
}

GoToLineForm::~GoToLineForm()
{
    delete ui;
}

void GoToLineForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GoToLineForm::setPlainTextEdit(QPlainTextEdit* textEdit) {
    m_textEdit = textEdit;
}

void GoToLineForm::goToLineChanged(QString line) {
  if (m_textEdit==NULL) return;
  if (line.size()==0) return;
  if (line.contains("[^0-9]")) {
    //set an error;
    return;
  }
  int line_number = line.toInt();
  int max_line = m_textEdit->document()->blockCount();
  if (max_line < line_number) {
    line_number = max_line;
  }
  QTextCursor text_cursor(m_textEdit->document()->findBlockByNumber(line_number - 1));
  m_textEdit->setTextCursor(text_cursor);
}

