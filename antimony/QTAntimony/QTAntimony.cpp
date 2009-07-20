
#include "QTAntimony.h"
#include "Translator.h"
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QRect>
#include <QDesktopWidget>

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
    DisplayWindow(t);
}

void QTAntimony::OpenFiles(QStringList filenames)
{
    for (int file=0; file<filenames.size(); file++) {
        OpenFile(filenames[file]);
    }
}

void QTAntimony::OpenNewFile()
{
    QWidget* focus = focusWidget();
    QStringList files = QFileDialog::getOpenFileNames(
                         focus,
                         tr("Select one or more files to open"),
                         m_currentdir,
                         tr("Antimony and SBML files (*.txt *.xml *.sbml);;Antimony files (*.txt);;SBML files (*.xml *.sbml);;All files(*.*)"));
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
    DisplayWindow(newt);
}

void QTAntimony::SetCurrentDirectory(QString dir)
{
    m_currentdir = dir;
}

#ifdef SBW_INTEGRATION

 bool QTAntimony::eventFilter(QObject * /*obj*/, QEvent *oEvent)
 {
	 QSBMLEvent *sbmlEvent = dynamic_cast<QSBMLEvent *>( oEvent );
	 if (sbmlEvent != NULL)
	 {
		 // here we would open a new tab with the SBML string ... 

		 NewWindow();

		 return true;
	 }
	 return false;
 }
#endif


void QTAntimony::DisplayWindow(Translator* t) {
    if (t==NULL) return;
    QWidget* focus = focusWidget();
    QRect desk = desktop()->availableGeometry(focus);
    if (focus==NULL) {
        desk = desktop()->availableGeometry(desktop()->primaryScreen());
        QRect window;
        window.setTop(desk.height()/8);
        window.setBottom(desk.height()*7/8);
        window.setLeft(desk.width()/6);
        window.setRight(desk.width()*4/6);
        //New geometry
        //t->setGeometry(200, 200, 600, 600);
        t->setGeometry(window);
    }
    else {
        while (focus->parent() != NULL) {
            focus = static_cast<QWidget*>(focus->parent());
        }
        QRect window = focus->geometry();
        window.translate(10, 10);
        if (window.bottomLeft().y() > desk.bottomLeft().y()) {
            window.setBottom(desk.bottomLeft().y());
        }
        if (window.bottomRight().x() > desk.bottomRight().x()) {
            window.setRight(desk.bottomRight().x());
        }
        if (window.bottomRight() == desk.bottomRight()) {
            window.translate(desk.x()-window.x(), desk.y()-window.y());
        }
        t->setGeometry(window);
    }
    t->show();
}


