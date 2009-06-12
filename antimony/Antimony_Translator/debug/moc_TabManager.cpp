/****************************************************************************
** Meta object code from reading C++ file 'TabManager.h'
**
** Created: Fri Jun 12 11:57:57 2009
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
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,
      59,   11,   11,   11, 0x0a,
      76,   72,   11,   11, 0x0a,
      92,   72,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabManager[] = {
    "TabManager\0\0undo()\0redo()\0cut()\0copy()\0"
    "paste()\0selectAll()\0revertText()\0tab\0"
    "SwitchTabs(int)\0Translate(int)\0"
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
        case 0: undo(); break;
        case 1: redo(); break;
        case 2: cut(); break;
        case 3: copy(); break;
        case 4: paste(); break;
        case 5: selectAll(); break;
        case 6: revertText(); break;
        case 7: SwitchTabs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: Translate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
