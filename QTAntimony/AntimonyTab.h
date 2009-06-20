#ifndef ANTIMONYTAB_H
#define ANTIMONYTAB_H
#include "ChangeableTextBox.h"

class QAction;
class AntimonyTab : public ChangeableTextBox
{
    Q_OBJECT;
private:
    QAction* m_actionCopySBML;
    QString  m_selectedasSBML;
    bool m_ismixed;

    bool setupSBMLCopy();

public:
    AntimonyTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();
    virtual void addSpecialCopyToMenu(QMenu* menu, QAction* paste);
    virtual void ReplaceModelWithString(QString model, QString text);
    virtual bool IsMixed();
    void SetMixed();

public slots:
    void CopySBML();
    virtual void SetTextChanged();
};

#endif // ANTIMONYTAB_H
