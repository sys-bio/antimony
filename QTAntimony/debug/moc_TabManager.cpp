/****************************************************************************
** Meta object code from reading C++ file 'TabManager.h'
**
** Created: Wed Jun 17 14:10:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TabManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TabManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TabManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      53,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      84,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x0a,
     104,   11,   11,   11, 0x0a,
     111,   11,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     152,   11,   11,   11, 0x0a,
     175,  171,   11,   11, 0x0a,
     191,  171,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabManager[] = {
    "TabManager\0\0error\0FailedAntimonyTranslation(QString)\0"
    "FailedSBMLTranslation(QString)\0undo()\0"
    "redo()\0cut()\0copy()\0paste()\0selectAll()\0"
    "revertToTranslated()\0revertToOriginal()\0"
    "tab\0SwitchTabs(int)\0Translate(int)\0"
};

const QMetaObject TabManager::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_TabManager,
      qt_meta_data_TabManager, 0 }
};

const QMetaObject *TabManager::metaObject() const
{
    return &staticMetaObject;
}

void *TabManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabManager))
        return static_cast<void*>(const_cast< TabManager*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int TabManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: FailedAntimonyTranslation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: FailedSBMLTranslation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: undo(); break;
        case 3: redo(); break;
        case 4: cut(); break;
        case 5: copy(); break;
        case 6: paste(); break;
        case 7: selectAll(); break;
        case 8: revertToTranslated(); break;
        case 9: revertToOriginal(); break;
        case 10: SwitchTabs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: Translate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TabManager::FailedAntimonyTranslation(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TabManager::FailedSBMLTranslation(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
