/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#include <QtGui>
#include <QPlainTextEdit>
#include <QRegExp>
#include <QSettings>

#include "findreplaceform.h"
#include "ui_findreplaceform.h"

#define TEXT_TO_FIND "textToFind"
#define TEXT_TO_REPLACE "textToReplace"
#define DOWN_RADIO "downRadio"
#define UP_RADIO "upRadio"
#define CASE_CHECK "caseCheck"
#define WHOLE_CHECK "wholeCheck"
#define REGEXP_CHECK "regexpCheck"

FindReplaceForm::FindReplaceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindReplaceForm), m_textEdit(0)
{
    ui->setupUi(this);

    ui->errorLabel->setText("");

    connect(ui->textToFind, SIGNAL(textChanged(QString)), this, SLOT(textToFindChanged()));
    connect(ui->textToFind, SIGNAL(textChanged(QString)), this, SLOT(validateRegExp(QString)));

    connect(ui->regexCheckBox, SIGNAL(toggled(bool)), this, SLOT(regexpSelected(bool)));

    connect(ui->findButton, SIGNAL(clicked()), this, SLOT(find()));
    connect(ui->closeButton, SIGNAL(clicked()), parent, SLOT(close()));

    connect(ui->replaceButton, SIGNAL(clicked()), this, SLOT(replace()));
    connect(ui->replaceAllButton, SIGNAL(clicked()), this, SLOT(replaceAll()));
}

FindReplaceForm::~FindReplaceForm()
{
    delete ui;
}

void FindReplaceForm::hideReplaceWidgets() {
    ui->replaceLabel->setVisible(false);
    ui->textToReplace->setVisible(false);
    ui->replaceButton->setVisible(false);
    ui->replaceAllButton->setVisible(false);
}

void FindReplaceForm::setPlainTextEdit(QPlainTextEdit* textEdit) {
    m_textEdit = textEdit;
    connect(m_textEdit, SIGNAL(copyAvailable(bool)), ui->replaceButton, SLOT(setEnabled(bool)));
    connect(m_textEdit, SIGNAL(copyAvailable(bool)), ui->replaceAllButton, SLOT(setEnabled(bool)));
}

void FindReplaceForm::changeEvent(QEvent *e)
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

void FindReplaceForm::textToFindChanged() {
    ui->findButton->setEnabled(ui->textToFind->text().size() > 0);
}

void FindReplaceForm::regexpSelected(bool sel) {
    if (sel)
        validateRegExp(ui->textToFind->text());
    else
        validateRegExp("");
}

void FindReplaceForm::validateRegExp(const QString &text) {
    if (!ui->regexCheckBox->isChecked() || text.size() == 0) {
        ui->errorLabel->setText("");
        return; // nothing to validate
    }

    QRegExp reg(text,
                (ui->caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive));

    if (reg.isValid()) {
        showError("");
    } else {
        showError(reg.errorString());
    }
}

void FindReplaceForm::showError(const QString &error) {
    if (error == "") {
        ui->errorLabel->setText("");
    } else {
        ui->errorLabel->setText("<span style=\" font-weight:600; color:#ff0000;\">" +
                                error +
                                "</spam>");
    }
}

void FindReplaceForm::showMessage(const QString &message) {
    if (message == "") {
        ui->errorLabel->setText("");
    } else {
        ui->errorLabel->setText("<span style=\" font-weight:600; color:green;\">" +
                                message +
                                "</spam>");
    }
}

void FindReplaceForm::find(bool wrap) {
    find(ui->downRadioButton->isChecked(), wrap);
}

void FindReplaceForm::find() {
    find(ui->downRadioButton->isChecked(), true);
}

void FindReplaceForm::find(bool next, bool wrap) {
    if (!m_textEdit)
        return; // TODO: show some warning?

    m_textCursor = m_textEdit->textCursor();
    if (m_textCursor.hasSelection()) {

    }

    // backward search
    bool back = !next;

    const QString &toSearch = ui->textToFind->text();

    bool result = false;

    QTextDocument::FindFlags flags;

    if (back)
        flags |= QTextDocument::FindBackward;
    if (ui->caseCheckBox->isChecked())
        flags |= QTextDocument::FindCaseSensitively;
    if (ui->wholeCheckBox->isChecked())
        flags |= QTextDocument::FindWholeWords;

    QRegExp reg;
    if (ui->regexCheckBox->isChecked()) {
        reg.setCaseSensitivity(ui->caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
        reg.setPattern(toSearch);

        qDebug() << "searching for regexp: " << reg.pattern();

        QTextCursor tempCursor = m_textEdit->document()->find(reg, m_textCursor, flags);
        if (!tempCursor.isNull()) {
          m_textEdit->setTextCursor(tempCursor);
          result = true;
        }
    } 
    else {
        qDebug() << "searching for: " << toSearch;

        result = m_textEdit->find(toSearch, flags);
    }

    if (result) {
        showError("");
    } 
    else {
      if (wrap) {
        showError(tr("Wrapping search..."));
        if (next) {
          QTextCursor tempCursor = m_textCursor;
          tempCursor.setPosition(0);
          m_textEdit->setTextCursor(tempCursor);
        }
        else {
          QTextCursor tempCursor(m_textEdit->document()->lastBlock());  
          m_textEdit->setTextCursor(tempCursor);
        }
        if (ui->regexCheckBox->isChecked()) {
          QTextCursor tempCursor = m_textEdit->document()->find(reg, m_textEdit->textCursor(), flags);
          if (!tempCursor.isNull()) {
            m_textEdit->setTextCursor(tempCursor);
            result = true;
          }
        }
        else {
          result = m_textEdit->find(toSearch, flags);
        }
      }
      if (!result) {
        showError(tr("Not found"));
        m_textEdit->setTextCursor(m_textCursor);
      }
    }
}

void FindReplaceForm::replace() {
    if (!m_textEdit->textCursor().hasSelection()) {
        find(true);
    } else {
        m_textEdit->textCursor().insertText(ui->textToReplace->text());
        find(true);
    }
}

void FindReplaceForm::replaceAll() {
    int i=0;
    QTextCursor qtc = m_textEdit->textCursor();
    qtc.setPosition(0);
    m_textEdit->setTextCursor(qtc);
    find(true, false);
    while (m_textEdit->textCursor().hasSelection()){
        m_textEdit->textCursor().insertText(ui->textToReplace->text());
        find(true, false);
        i++;
    }
    showMessage(tr("Replaced %1 occurrence(s)").arg(i));
}

void FindReplaceForm::writeSettings(QSettings &settings, const QString &prefix) {
    settings.beginGroup(prefix);
    settings.setValue(TEXT_TO_FIND, ui->textToFind->text());
    settings.setValue(TEXT_TO_REPLACE, ui->textToReplace->text());
    settings.setValue(DOWN_RADIO, ui->downRadioButton->isChecked());
    settings.setValue(UP_RADIO, ui->upRadioButton->isChecked());
    settings.setValue(CASE_CHECK, ui->caseCheckBox->isChecked());
    settings.setValue(WHOLE_CHECK, ui->wholeCheckBox->isChecked());
    settings.setValue(REGEXP_CHECK, ui->regexCheckBox->isChecked());
    settings.endGroup();
}

void FindReplaceForm::readSettings(QSettings &settings, const QString &prefix) {
    settings.beginGroup(prefix);
    ui->textToFind->setText(settings.value(TEXT_TO_FIND, "").toString());
    ui->textToReplace->setText(settings.value(TEXT_TO_REPLACE, "").toString());
    ui->downRadioButton->setChecked(settings.value(DOWN_RADIO, true).toBool());
    ui->upRadioButton->setChecked(settings.value(UP_RADIO, false).toBool());
    ui->caseCheckBox->setChecked(settings.value(CASE_CHECK, false).toBool());
    ui->wholeCheckBox->setChecked(settings.value(WHOLE_CHECK, false).toBool());
    ui->regexCheckBox->setChecked(settings.value(REGEXP_CHECK, false).toBool());
    settings.endGroup();
}
