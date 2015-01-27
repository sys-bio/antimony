/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#include "GoToLineDialog.h"
#include "ui_GoToLineDialog.h"

GoToLineDialog::GoToLineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToLineDialog)
{
    ui->setupUi(this);
}

GoToLineDialog::~GoToLineDialog()
{
    delete ui;
}

void GoToLineDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GoToLineDialog::setPlainTextEdit(QPlainTextEdit *textEdit) {
    ui->goToLineForm->setPlainTextEdit(textEdit);
}
