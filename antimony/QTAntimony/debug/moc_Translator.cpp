/****************************************************************************
** Meta object code from reading C++ file 'Translator.h'
**
** Created: Mon Jun 22 16:23:00 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Translator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Translator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Translator[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      24,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Translator[] = {
    "Translator\0\0isClosing()\0SetPasteAvailability()\0"
};

const QMetaObject Translator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Translator,
      qt_meta_data_Translator, 0 }
};

const QMetaObject *Translator::metaObject() const
{
    return &staticMetaObject;
}

void *Translator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Translator))
        return static_cast<void*>(const_cast< Translator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Translator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: isClosing(); break;
        case 1: SetPasteAvailability(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Translator::isClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
