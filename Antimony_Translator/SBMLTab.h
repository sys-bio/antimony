#ifndef SBMLTAB_H
#define SBMLTAB_H
#include "ChangeableTextBox.h"

class SBMLTab : public ChangeableTextBox
{
    Q_OBJECT;
private:
    QString m_modelname;

public:
    SBMLTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();
};
#endif // SBMLTAB_H
