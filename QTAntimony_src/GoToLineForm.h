/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#ifndef GOTOLINEFORM_H
#define GOTOLINEFORM_H

#include <QWidget>
#include <QTextCursor>

#include "findreplace_global.h"

namespace Ui {
    class GoToLineForm;
}

class QPlainTextEdit;
class QSettings;

/**
  * The form for the find/replace dialog.  The form presents the typical
  * widgets you find in standard find/replace dialogs, and it acts on a QPlainTextEdit.
  *
  * \image html Screenshot-GoToLine.png
  *
  * You need to set the QPlainTextEdit explicitly, using the method setPlainTextEdit(QPlainTextEdit *textEdit).
  *
  * For instance
  * \code
  * m_GoToLineDialog = new GoToLineDialog(this);
  * m_GoToLineDialog->setModal(false);
  * m_GoToLineDialog->setPlainTextEdit(ui->textEdit);
  * \endcode
  *
  * The find functionalities is available even if the find dialog is not shown: if something
  * to search for was already specified, the application can call the methods findNext() and
  * findPrev() (e.g., by connecting them to menu items).
  *
  * In case a regular expression is used as the search term, the form also checks whether the
  * expression is a valid regular expression (You may want to take a look at the syntax of regular expressions:
  * http://doc.trolltech.com/qregexp.html).
  *
  * The form provides also functionalities to save and restore its state using a QSettings object (i.e.,
  * the last word searched for, the options of the form, etc.) via the methods writeSettings()
  * and readSettings().
  *
  * You can take a look at the \ref examples page.
  */
class GoToLineForm : public QWidget {
    Q_OBJECT
public:
    GoToLineForm(QWidget *parent = 0);
    virtual ~GoToLineForm();
    void setPlainTextEdit(QPlainTextEdit* textEdit);


protected:
    void changeEvent(QEvent *e);

protected slots:
    /// when the text edit contents changed
    void goToLineChanged(QString line);

protected:
    Ui::GoToLineForm *ui;

    /// the text editor (possibly) associated with this form
    QPlainTextEdit* m_textEdit;
};

#endif // GOTOLINEFORM_H
