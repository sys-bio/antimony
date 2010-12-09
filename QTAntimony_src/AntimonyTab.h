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
    bool     m_ismixed;
    QString  m_filenodirectory;

    bool setupSBMLCopy();

public:
    AntimonyTab(QWidget* parent = 0);
    void SetModelName(QString name);
    QString GetModelName();
    QString GetTabName();
    virtual void addSpecialCopyToMenu(QMenu* menu, QAction* paste);
    virtual void ReplaceModelWithString(QString model, QString text);
    virtual bool IsMixed();
    virtual void SetFilename(QString filename);
    void SetMixed();

public slots:
    void CopySBML();
    virtual void SetTextChanged();

signals:
    void FilenameIsNow(const QString& filename);
};

#endif // ANTIMONYTAB_H
