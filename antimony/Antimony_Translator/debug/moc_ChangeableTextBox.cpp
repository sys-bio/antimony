/****************************************************************************
** Meta object code from reading C++ file 'ChangeableTextBox.h'
**
** Created: Fri Jun 12 11:57:55 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ChangeableTextBox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChangeableTextBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangeableTextBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x05,
      49,   19,   18,   18, 0x05,
      75,   19,   18,   18, 0x05,
     101,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,   18,   18,   18, 0x0a,
     137,   18,   18,   18, 0x0a,
     151,   18,   18,   18, 0x0a,
     168,   18,   18,   18, 0x0a,
     187,   18,   18,   18, 0x0a,
     205,   18,   18,   18, 0x0a,
     219,   19,   18,   18, 0x0a,
     242,   19,   18,   18, 0x0a,
     265,   19,   18,   18, 0x0a,
     288,   18,   18,   18, 0x0a,
     311,   18,   18,   18, 0x0a,
     326,   18,   18,   18, 0x0a,
     350,  345,   18,   18, 0x0a,
     367,  345,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChangeableTextBox[] = {
    "ChangeableTextBox\0\0yes\0ActiveCopyAvailable(bool)\0"
    "ActiveUndoAvailable(bool)\0"
    "ActiveRedoAvailable(bool)\0"
    "LastTextAvailable(bool)\0SetActive()\0"
    "SetInactive()\0SetTextChanged()\0"
    "SetTextUnchanged()\0SetUntranslated()\0"
    "SetOriginal()\0SetCopyAvailable(bool)\0"
    "SetUndoAvailable(bool)\0SetRedoAvailable(bool)\0"
    "SetLastTextAvailable()\0SaveLastText()\0"
    "RevertToLastText()\0text\0SetText(QString)\0"
    "SetLastText(QString)\0"
};

const QMetaObject ChangeableTextBox::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_ChangeableTextBox,
      qt_meta_data_ChangeableTextBox, 0 }
};

const QMetaObject *ChangeableTextBox::metaObject() const
{
    return &staticMetaObject;
}

void *ChangeableTextBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeableTextBox))
        return static_cast<void*>(const_cast< ChangeableTextBox*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int ChangeableTextBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ActiveCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: ActiveUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: ActiveRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: LastTextAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: SetActive(); break;
        case 5: SetInactive(); break;
        case 6: SetTextChanged(); break;
        case 7: SetTextUnchanged(); break;
        case 8: SetUntranslated(); break;
        case 9: SetOriginal(); break;
        case 10: SetCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: SetUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: SetRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: SetLastTextAvailable(); break;
        case 14: SaveLastText(); break;
        case 15: RevertToLastText(); break;
        case 16: SetText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: SetLastText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ChangeableTextBox::ActiveCopyAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChangeableTextBox::ActiveUndoAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChangeableTextBox::ActiveRedoAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChangeableTextBox::LastTextAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
