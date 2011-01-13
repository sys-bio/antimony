#ifndef SBMLTAB_H
#define SBMLTAB_H
#include "ChangeableTextBox.h"

class SBMLTab : public ChangeableTextBox
{
    Q_OBJECT;
private:
    QString m_modelname;
    int m_levelversion;

public:
    SBMLTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();
    virtual void addSpecialCopyToMenu(QMenu* menu, QAction* paste);
    virtual void ReplaceModelWithString(QString model, QString text);
    virtual bool IsMixed();
    bool SetLevelAndVersion(int levelversion);
    bool SetLevelAndVersion(int level, int version);
    int  GetLevelAndVersionCode() {return m_levelversion;};

public slots:
    void SetTranslated();
};
#endif // SBMLTAB_H
