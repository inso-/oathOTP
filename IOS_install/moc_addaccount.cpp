/****************************************************************************
** Meta object code from reading C++ file 'addaccount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../work/otp/inc/addaccount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addaccount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddAccount_t {
    QByteArrayData data[7];
    char stringdata[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AddAccount_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AddAccount_t qt_meta_stringdata_AddAccount = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 20),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 24),
QT_MOC_LITERAL(4, 58, 4),
QT_MOC_LITERAL(5, 63, 17),
QT_MOC_LITERAL(6, 81, 34)
    },
    "AddAccount\0on_AddModify_clicked\0\0"
    "on_AccountList_activated\0arg1\0"
    "on_Delete_clicked\0on_AccountList_currentIndexChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddAccount[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    1,   35,    2, 0x08,
       5,    0,   38,    2, 0x08,
       6,    1,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void AddAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddAccount *_t = static_cast<AddAccount *>(_o);
        switch (_id) {
        case 0: _t->on_AddModify_clicked(); break;
        case 1: _t->on_AccountList_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_Delete_clicked(); break;
        case 3: _t->on_AccountList_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AddAccount::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddAccount.data,
      qt_meta_data_AddAccount,  qt_static_metacall, 0, 0}
};


const QMetaObject *AddAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddAccount.stringdata))
        return static_cast<void*>(const_cast< AddAccount*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
