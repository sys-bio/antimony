/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#ifndef GOTOLINEDIALOG_H
#define GOTOLINEDIALOG_H

#include <QDialog>

#include "findreplace_global.h"

namespace Ui {
    class GoToLineDialog;
}

class QPlainTextEdit;
class QSettings;

/**
  * A find/replace dialog.
  *
  * It relies on a GoToLineForm object (see that class for the functionalities provided).
  */
class GoToLineDialog : public QDialog {
    Q_OBJECT
public:
    GoToLineDialog(QWidget *parent = 0);
    virtual ~GoToLineDialog();

public slots:
    /**
      * Associates the text editor where to perform the search
      * @param textEdit_
      */
    void setPlainTextEdit(QPlainTextEdit *textEdit);

protected:
    void changeEvent(QEvent *e);

    Ui::GoToLineDialog *ui;
};

#endif // GOTOLINEDIALOG_H
