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
    void revertText();

    //Whenever we switch tabs:
    void SwitchTabs(int tab);
    void Translate(int tab);

private:
    ChangeableTextBox* GetActiveEditor();
    void TranslateAntimony(const QString& text);
    void TranslateSBML(int tab, const QString& text);
};

#endif // TABMANAGER_H
