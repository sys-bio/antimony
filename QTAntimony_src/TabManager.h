#ifndef TABMANAGER_H
#define TABMANAGER_H
#include <QTabWidget>

class ChangeableTextBox;
class TabManager : public QTabWidget
{
    Q_OBJECT;
private:
    int m_oldtab;
    int m_anttab;
    int m_sbmltab;
    int m_cellmltab;
public:
    TabManager(QWidget* parent);
    //~TabManager();  //Hmm, do we need destructors here?
    int addTab(ChangeableTextBox* page, const QString& label);
    int addTab(ChangeableTextBox* page, const QIcon& icon, const QString& label);
    ChangeableTextBox* textbox(int tabnum);
    void Translate(int tab);
    bool CanIClose();
    void SaveFonts();
    void SaveTabDisplay();

public slots:
    //We provide the functions and pass them to the underlying active editor tab
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void print();
    void selectAll();
    void revertToTranslated();
    void revertToOriginal();
    void addCellMLTab();
    void setAntimonyFont();
    void setXMLFont();
    void zoomIn();
    void zoomOut();

    void sbmlTabs(bool);
    void cellmlTabs(bool);

    //Whenever we switch tabs:
    void SwitchTabs(int tab);
    void nextTab();

    void SaveCurrent();
    void SaveCurrentAs();
    void SaveAntimony();
    void SaveAllSBML();
    void SaveCellML();

    void TranslateCurrent();
    void TranslateAntimony();
    void TranslateSBML();
    void TranslateCellML();

    void SetAllSBMLLevelsAndVersions();

    void TabNameIs(const QString& tabname, ChangeableTextBox* tab);

#ifdef SBW_INTEGRATION
    void startSBWAnalyzer();
#endif

signals:
    void FailedAntimonyTranslation();
    void FailedSBMLTranslation();
    void FailedCellMLTranslation();

private:
    ChangeableTextBox* GetActiveEditor();
    void TranslateAntimony(QString& text);
    void TranslateSBML(int tab, const QString& text);
    void TranslateCellML(QString& text);
    void SetOthersTranslated(int oldtab);
};

#endif // TABMANAGER_H
