
#include "QTAntimony.h"
#include "Translator.h"
#include "resource.h"
#include "Settings.h"
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QRect>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QVariant>
#include <QIcon>

#ifdef Q_OS_WIN
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

QTAntimony::QTAntimony(int& argc, char**& argv)
        : QApplication(argc, argv),
        m_original(NULL),
        m_opened(false),
        m_currentdir(""), //will set this below.
        m_basewindow(NULL)
{
	// Set the app-level icon once, from the embedded multi-resolution .ico
	setWindowIcon(QIcon(":/antimony.ico"));

	QSettings qset(ORG, APP);
	qset.sync();
	m_currentdir = qset.value("currentdir", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)).toString();
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
    QSettings qset(ORG, APP);
    qset.setValue("currentdir", m_currentdir);
    t->setWindowTitle(qfi.fileName() + " - QTAntimony");

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
    m_basewindow = focus;
    QStringList files = QFileDialog::getOpenFileNames(
                         focus,
                         tr("Select one or more files to open"),
                         m_currentdir,
#ifndef NCELLML
                         tr("Antimony, SBML, and CellML files (*.txt *.xml *.sbml *.cellml);;Antimony files (*.txt);;SBML files (*.xml *.sbml);;CellML file (*.xml *.cellml);;All files(*.*)"));
#else
                         tr("Antimony and SBML files (*.txt *.xml *.sbml *.cellml);;Antimony files (*.txt);;SBML files (*.xml *.sbml);;All files(*.*)"));
#endif
    OpenFiles(files);
    m_basewindow = NULL;
}

QString QTAntimony::GetCurrentDir()
{
    return m_currentdir;
}

Translator* QTAntimony::NewWindow(QString filename)
{
    Translator* newt = new Translator(this, filename);
    if (m_original==NULL) {
        m_original = newt;
    }
    DisplayWindow(newt);
    return newt;
}

void QTAntimony::SaveCurrentDirectory(QString dir)
{
    m_currentdir = dir;
}

void QTAntimony::DisplayWindow(QMainWindow* t) {
    if (t==NULL) return;
    QWidget* focus = m_basewindow;
    if (focus==NULL) {
        focus = focusWidget();
    }
    QRect desk = desktop()->availableGeometry(focus);
    if (focus==NULL) {
        desk = desktop()->availableGeometry(desktop()->primaryScreen());
        QRect window;
        window.setTop(desk.height()/8);
        window.setBottom(desk.height()*7/8);
        window.setLeft(desk.width()/6);
        window.setRight(desk.width()*4/6);
        t->setGeometry(window);
        //New geometry
        //t->setGeometry(200, 200, 600, 600);
        QSettings qset(ORG, APP);
        qset.sync();
        t->restoreGeometry(qset.value("geometry", t->saveGeometry()).toByteArray());
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
			window.translate(10,30);
        }
        t->setGeometry(window);
    }
    ApplyWindowIcon(t);
    t->show();

    m_basewindow = t;
}

// Applies the app icon to any top-level widget.
void QTAntimony::ApplyWindowIcon(QWidget* w)
{
    if (w == NULL) return;
    w->setWindowIcon(QIcon(":/antimony.ico"));

#ifdef Q_OS_WIN
    // Fix Windows 11 bug: only use large icon for taskbar.
    HICON hIconLarge = static_cast<HICON>(LoadImageW(
        GetModuleHandleW(NULL), MAKEINTRESOURCEW(ANT_ICON1),
        IMAGE_ICON, 256, 256, LR_DEFAULTCOLOR));
    if (hIconLarge) {
        HWND hwnd = reinterpret_cast<HWND>(w->winId());
        SendMessage(hwnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hIconLarge));
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIconLarge));
        // Intentionally not destroyed: the icon needs to live as long as
        // the window does, and LoadImage-ed resource icons are cheap and
        // reclaimed by Windows on process exit.
    }
#endif
}
