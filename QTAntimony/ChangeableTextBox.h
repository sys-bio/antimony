#ifndef CHANGEABLETEXTBOX_H
#define CHANGEABLETEXTBOX_H

#include<QTextEdit>

class QFile;

class ChangeableTextBox: public QTextEdit
{
    Q_OBJECT

private:
    bool m_isactive;
    bool m_failedtranslation;
    bool m_copyavailable;
    bool m_undoavailable;
    bool m_redoavailable;

    int m_origline;
    int m_origmidline;
    Shape m_origshape;
    Shadow m_origshadow;

    QString m_translated;
    QString m_original;
    QString m_saved;

protected:
    QString m_filename;
    QString m_filetypes;
    QString m_extension;

public:
    ChangeableTextBox(QWidget* parent = 0);
    void NewlyActive();
    bool GetTextChanged();
    virtual void ReplaceModelWithString(QString model, QString text) = 0;
    virtual void SetModelName(QString name) = 0;
    virtual QString GetModelName() = 0;
    virtual QString GetTabName() = 0;
    virtual void contextMenuEvent(QContextMenuEvent* event);
    virtual void addSpecialCopyToMenu(QMenu* menu, QAction* paste) = 0;
    void SetTranslatedText(QString text);
    void EmitPreviousAvailable();
    void ReplaceTextWith(QString text);
    bool IsOriginal();
    bool IsTranslated();
    virtual bool IsMixed() = 0;
    bool IsSaved();
    virtual void SetFilename(QString filename);
    virtual void SetSavedFilename(QString filename);
    void SaveTab();
    void SaveTabAs();
    void DisplayError(QString error);

public slots:
    void SetActive();
    void SetInactive();
    virtual void SetTextChanged();
    void SetFailedTranslation();
    void SetOriginal();
    void SetTranslated();
    void SaveAndEmitCopyAvailable(bool yes);
    void SaveAndEmitUndoAvailable(bool yes);
    void SaveAndEmitRedoAvailable(bool yes);
    void RevertToTranslated();
    void RevertToOriginal();
    void FileChanged(const QString& filename);

signals:
    void ActiveCopyAvailable(bool yes);
    void ActiveUndoAvailable(bool yes);
    void ActiveRedoAvailable(bool yes);
    void TranslatedAvailable(bool yes);
    void OriginalAvailable(bool yes);
    void StopWatching(const QString& filename);
    void StartWatching(const QString& filename);
    void TabNameIsNow(const QString& tabname, ChangeableTextBox* tab);

private:
    void SetNormalBorder();
};

#endif // CHANGEABLETEXTBOX_H
