#include "QTAntimony.h"
#include "Translator.h"
#include <QStringList>
#include <QString>
#include <QFileDialog>

QTAntimony::QTAntimony(int& argc, char**& argv)
        : QApplication(argc, argv),
        m_original(NULL),
        m_opened(false),
        m_currentdir(QDir::homePath())
{
}

void QTAntimony::OpenFile(QString filename)
{
    if (m_opened==false && m_original != NULL && m_original->IsBlank()) {
        m_original->close();
    }
    m_opened = true;
    setOverrideCursor(QCursor(Qt::WaitCursor));
    Translator* t = new Translator(this, filename);
    restoreOverrideCursor();
    QFileInfo qfi(filename);
    m_currentdir = qfi.absoluteDir().absolutePath();
    t->show();
}

void QTAntimony::OpenFiles(QStringList filenames)
{
    for (int file=0; file<filenames.size(); file++) {
        OpenFile(filenames[file]);
    }
}

void QTAntimony::OpenNewFile()
{
    QWidget* temp = new QWidget();
    QStringList files = QFileDialog::getOpenFileNames(
                         temp,
                         tr("Select one or more files to open"),
                         m_currentdir,
                         tr("Antimony and SBML files (*.txt *.xml *.sbml);;Antimony files (*.txt);;SBML files (*.xml *.sbml);;All files(*.*)"));
    delete temp;
    OpenFiles(files);
}

QString QTAntimony::GetCurrentDir()
{
    return m_currentdir;
}

void QTAntimony::NewWindow()
{
    Translator* newt = new Translator(this);
    if (m_original==NULL) {
        m_original = newt;
    }
    newt->show();
}

void QTAntimony::SetCurrentDirectory(QString dir)
{
    m_currentdir = dir;
}
