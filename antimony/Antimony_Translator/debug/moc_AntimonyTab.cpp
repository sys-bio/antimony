/****************************************************************************
** Meta object code from reading C++ file 'AntimonyTab.h'
**
** Created: Fri Jun 12 11:57:52 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AntimonyTab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AntimonyTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AntimonyTab[] = {

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

static const char qt_meta_stringdata_AntimonyTab[] = {
    "AntimonyTab\0"
};

const QMetaObject AntimonyTab::staticMetaObject = {
    { &ChangeableTextBox::staticMetaObject, qt_meta_stringdata_AntimonyTab,
      qt_meta_data_AntimonyTab, 0 }
};

const QMetaObject *AntimonyTab::metaObject() const
{
    return &staticMetaObject;
}

void *AntimonyTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AntimonyTab))
        return static_cast<void*>(const_cast< AntimonyTab*>(this));
    return ChangeableTextBox::qt_metacast(_clname);
}

int AntimonyTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ChangeableTextBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
