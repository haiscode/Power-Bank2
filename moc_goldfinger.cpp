/****************************************************************************
** Meta object code from reading C++ file 'goldfinger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "goldfinger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goldfinger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Goldfinger_t {
    QByteArrayData data[12];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Goldfinger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Goldfinger_t qt_meta_stringdata_Goldfinger = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Goldfinger"
QT_MOC_LITERAL(1, 11, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 32), // "on_listWidget_currentItemChanged"
QT_MOC_LITERAL(4, 69, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 86, 7), // "current"
QT_MOC_LITERAL(6, 94, 8), // "previous"
QT_MOC_LITERAL(7, 103, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(8, 127, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 149, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(10, 173, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(11, 195, 5) // "index"

    },
    "Goldfinger\0on_pushButton_3_clicked\0\0"
    "on_listWidget_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous\0"
    "on_pushButton_4_clicked\0on_pushButton_clicked\0"
    "on_pushButton_5_clicked\0on_comboBox_activated\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Goldfinger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    2,   45,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    1,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Goldfinger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Goldfinger *_t = static_cast<Goldfinger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_listWidget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Goldfinger::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Goldfinger.data,
      qt_meta_data_Goldfinger,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Goldfinger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Goldfinger::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Goldfinger.stringdata0))
        return static_cast<void*>(const_cast< Goldfinger*>(this));
    return QDialog::qt_metacast(_clname);
}

int Goldfinger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
