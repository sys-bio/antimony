#ifndef ANTIMONYTAB_H
#define ANTIMONYTAB_H
#include "ChangeableTextBox.h"

class AntimonyTab : public ChangeableTextBox
{
    Q_OBJECT;

    public:
    AntimonyTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();

};

#endif // ANTIMONYTAB_H
