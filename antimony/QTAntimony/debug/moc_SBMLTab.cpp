/****************************************************************************
** Meta object code from reading C++ file 'SBMLTab.h'
**
** Created: Tue Jun 23 10:49:35 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SBMLTab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SBMLTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SBMLTab[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_SBMLTab[] = {
    "SBMLTab\0"
};

const QMetaObject SBMLTab::staticMetaObject = {
    { &ChangeableTextBox::staticMetaObject, qt_meta_stringdata_SBMLTab,
      qt_meta_data_SBMLTab, 0 }
};

const QMetaObject *SBMLTab::metaObject() const
{
    return &staticMetaObject;
}

void *SBMLTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SBMLTab))
        return static_cast<void*>(const_cast< SBMLTab*>(this));
    return ChangeableTextBox::qt_metacast(_clname);
}

int SBMLTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ChangeableTextBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
