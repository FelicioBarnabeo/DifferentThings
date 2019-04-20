/****************************************************************************
** Meta object code from reading C++ file 'myapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MPDU_newGeneration Source/myapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyApplication_t {
    QByteArrayData data[11];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyApplication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyApplication_t qt_meta_stringdata_MyApplication = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 15),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 8),
QT_MOC_LITERAL(4, 40, 19),
QT_MOC_LITERAL(5, 60, 12),
QT_MOC_LITERAL(6, 73, 19),
QT_MOC_LITERAL(7, 93, 6),
QT_MOC_LITERAL(8, 100, 11),
QT_MOC_LITERAL(9, 112, 15),
QT_MOC_LITERAL(10, 128, 15)
    },
    "MyApplication\0languageChanged\0\0language\0"
    "langEmptyStrChanged\0langEmptyStr\0"
    "applyChangeLanguage\0wakeUp\0setLanguage\0"
    "setlangEmptyStr\0setLangEmptyStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      10,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void MyApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyApplication *_t = static_cast<MyApplication *>(_o);
        switch (_id) {
        case 0: _t->languageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->langEmptyStrChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->applyChangeLanguage(); break;
        case 3: _t->wakeUp(); break;
        case 4: _t->setLanguage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setlangEmptyStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setLangEmptyStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyApplication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyApplication::languageChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MyApplication::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyApplication::langEmptyStrChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyApplication::staticMetaObject = {
    { &QGuiApplication::staticMetaObject, qt_meta_stringdata_MyApplication.data,
      qt_meta_data_MyApplication,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyApplication.stringdata))
        return static_cast<void*>(const_cast< MyApplication*>(this));
    return QGuiApplication::qt_metacast(_clname);
}

int MyApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGuiApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = language(); break;
        case 1: *reinterpret_cast< QString*>(_v) = langEmptyStr(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLanguage(*reinterpret_cast< QString*>(_v)); break;
        case 1: setLangEmptyStr(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MyApplication::languageChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyApplication::langEmptyStrChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
