/****************************************************************************
** Meta object code from reading C++ file 'ChangeableTextBox.h'
**
** Created: Tue Jun 23 10:49:36 2009
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
      19,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x05,
      49,   19,   18,   18, 0x05,
      75,   19,   18,   18, 0x05,
     101,   19,   18,   18, 0x05,
     127,   19,   18,   18, 0x05,
     160,  151,   18,   18, 0x05,
     182,  151,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     205,   18,   18,   18, 0x0a,
     217,   18,   18,   18, 0x0a,
     231,   18,   18,   18, 0x0a,
     248,   18,   18,   18, 0x0a,
     271,   18,   18,   18, 0x0a,
     285,   18,   18,   18, 0x0a,
     301,   19,   18,   18, 0x0a,
     332,   19,   18,   18, 0x0a,
     363,   19,   18,   18, 0x0a,
     394,   18,   18,   18, 0x0a,
     415,   18,   18,   18, 0x0a,
     434,  151,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChangeableTextBox[] = {
    "ChangeableTextBox\0\0yes\0ActiveCopyAvailable(bool)\0"
    "ActiveUndoAvailable(bool)\0"
    "ActiveRedoAvailable(bool)\0"
    "TranslatedAvailable(bool)\0"
    "OriginalAvailable(bool)\0filename\0"
    "StopWatching(QString)\0StartWatching(QString)\0"
    "SetActive()\0SetInactive()\0SetTextChanged()\0"
    "SetFailedTranslation()\0SetOriginal()\0"
    "SetTranslated()\0SaveAndEmitCopyAvailable(bool)\0"
    "SaveAndEmitUndoAvailable(bool)\0"
    "SaveAndEmitRedoAvailable(bool)\0"
    "RevertToTranslated()\0RevertToOriginal()\0"
    "FileChanged(QString)\0"
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
        case 3: TranslatedAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: OriginalAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: StopWatching((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: StartWatching((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: SetActive(); break;
        case 8: SetInactive(); break;
        case 9: SetTextChanged(); break;
        case 10: SetFailedTranslation(); break;
        case 11: SetOriginal(); break;
        case 12: SetTranslated(); break;
        case 13: SaveAndEmitCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: SaveAndEmitUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: SaveAndEmitRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: RevertToTranslated(); break;
        case 17: RevertToOriginal(); break;
        case 18: FileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 19;
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
void ChangeableTextBox::TranslatedAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ChangeableTextBox::OriginalAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChangeableTextBox::StopWatching(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ChangeableTextBox::StartWatching(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
