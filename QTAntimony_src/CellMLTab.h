#ifndef CELLMLTAB_H
#define CELLMLTAB_H
#include "ChangeableTextBox.h"

class CellMLTab : public ChangeableTextBox
{
    Q_OBJECT;
private:
    QString m_modelname;

public:
    CellMLTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();
    virtual void addSpecialCopyToMenu(QMenu* menu, QAction* paste);
    virtual void ReplaceModelWithString(QString model, QString text);
    virtual bool IsMixed();

public slots:
    void SetTranslated();
};

#endif // CELLMLTAB_H
