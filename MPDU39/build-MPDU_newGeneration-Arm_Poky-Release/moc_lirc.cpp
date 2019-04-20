/****************************************************************************
** Meta object code from reading C++ file 'lirc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MPDU_newGeneration Source/lirc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lirc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Lirc_t {
    QByteArrayData data[11];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lirc_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lirc_t qt_meta_stringdata_Lirc = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 10),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 11),
QT_MOC_LITERAL(4, 29, 11),
QT_MOC_LITERAL(5, 41, 12),
QT_MOC_LITERAL(6, 54, 9),
QT_MOC_LITERAL(7, 64, 3),
QT_MOC_LITERAL(8, 68, 6),
QT_MOC_LITERAL(9, 75, 8),
QT_MOC_LITERAL(10, 84, 11)
    },
    "Lirc\0sendedOnce\0\0sendStarted\0sendStopped\0"
    "startProcess\0startSend\0key\0device\0"
    "stopSend\0sendCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lirc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x0a /* Public */,
       6,    2,   58,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x0a /* Public */,
      10,    2,   68,    2, 0x0a /* Public */,
      10,    1,   73,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void Lirc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Lirc *_t = static_cast<Lirc *>(_o);
        switch (_id) {
        case 0: _t->sendedOnce(); break;
        case 1: _t->sendStarted(); break;
        case 2: _t->sendStopped(); break;
        case 3: _t->startProcess(); break;
        case 4: _t->startSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->stopSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Lirc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Lirc::sendedOnce)) {
                *result = 0;
            }
        }
        {
            typedef void (Lirc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Lirc::sendStarted)) {
                *result = 1;
            }
        }
        {
            typedef void (Lirc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Lirc::sendStopped)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Lirc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Lirc.data,
      qt_meta_data_Lirc,  qt_static_metacall, 0, 0}
};


const QMetaObject *Lirc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lirc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Lirc.stringdata))
        return static_cast<void*>(const_cast< Lirc*>(this));
    return QObject::qt_metacast(_clname);
}

int Lirc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Lirc::sendedOnce()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Lirc::sendStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Lirc::sendStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
