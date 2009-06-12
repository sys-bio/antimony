#ifndef CHANGEABLETEXTBOX_H
#define CHANGEABLETEXTBOX_H

#include<QTextEdit>

class ChangeableTextBox: public QTextEdit
{
    Q_OBJECT

    private:
        bool m_isactive;
        bool m_textchanged;
        bool m_textuntranslated;
        bool m_copyavailable;
        bool m_undoavailable;
        bool m_redoavailable;

        QString m_lasttext;

    public:
        ChangeableTextBox(QWidget* parent = 0);
        void NewlyActive();
        bool GetTextChanged();
        void ReplaceModelWithString(QString model, QString text);
        virtual void SetModelName(QString name) = 0;
        virtual QString GetModelName() = 0;
        virtual QString GetTabName() = 0;

    public slots:
        void SetActive();
        void SetInactive();
        void SetTextChanged();
        void SetTextUnchanged();
        void SetUntranslated();
        void SetOriginal();
        void SetCopyAvailable(bool yes);
        void SetUndoAvailable(bool yes);
        void SetRedoAvailable(bool yes);
        void SetLastTextAvailable();
        void SaveLastText();
        void RevertToLastText();
        void SetText(QString text);
        void SetLastText(QString text);

    signals:
        void ActiveCopyAvailable(bool yes);
        void ActiveUndoAvailable(bool yes);
        void ActiveRedoAvailable(bool yes);
        void LastTextAvailable(bool yes);

};

#endif // CHANGEABLETEXTBOX_H
