#ifndef TABMANAGER_H
#define TABMANAGER_H
#include <QTabWidget>

class ChangeableTextBox;
class TabManager : public QTabWidget
{
    Q_OBJECT;
private:
    int m_oldtab;
public:
    TabManager(QWidget* parent);
    //~TabManager();  //Hmm, do we need destructors here?
    int addTab(ChangeableTextBox* page, const QString& label);
    int addTab(ChangeableTextBox* page, const QIcon& icon, const QString& label);
    ChangeableTextBox* textbox(int tabnum);
public slots:
    //We provide the functions and pass them to the underlying active editor tab
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void selectAll();
    void revertToTranslated();
    void revertToOriginal();

    //Whenever we switch tabs:
    void SwitchTabs(int tab);
    void Translate(int tab);

signals:
    void FailedAntimonyTranslation(QString error);
    void FailedSBMLTranslation(QString error);

private:
    ChangeableTextBox* GetActiveEditor();
    void TranslateAntimony(const QString& text);
    void TranslateSBML(int tab, const QString& text);
    void SetOthersOriginal(int oldtab);
    void SetOthersTranslated(int oldtab);
};

#endif // TABMANAGER_H
