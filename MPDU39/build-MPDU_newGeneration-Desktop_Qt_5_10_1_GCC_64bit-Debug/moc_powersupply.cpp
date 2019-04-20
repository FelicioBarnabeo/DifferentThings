/****************************************************************************
** Meta object code from reading C++ file 'powersupply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MPDU_newGeneration Source/powersupply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powersupply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PowerSupplySingleton_t {
    QByteArrayData data[24];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowerSupplySingleton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowerSupplySingleton_t qt_meta_stringdata_PowerSupplySingleton = {
    {
QT_MOC_LITERAL(0, 0, 20), // "PowerSupplySingleton"
QT_MOC_LITERAL(1, 21, 18), // "currentVoltChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "currentVolt"
QT_MOC_LITERAL(4, 53, 15), // "chargingChanged"
QT_MOC_LITERAL(5, 69, 8), // "charging"
QT_MOC_LITERAL(6, 78, 16), // "isSuspendChanged"
QT_MOC_LITERAL(7, 95, 7), // "suspend"
QT_MOC_LITERAL(8, 103, 18), // "suspendTimeChanged"
QT_MOC_LITERAL(9, 122, 11), // "suspendTime"
QT_MOC_LITERAL(10, 134, 16), // "sigSuspendSystem"
QT_MOC_LITERAL(11, 151, 12), // "wakeUpSystem"
QT_MOC_LITERAL(12, 164, 16), // "lowChargeChanged"
QT_MOC_LITERAL(13, 181, 9), // "lowCharge"
QT_MOC_LITERAL(14, 191, 18), // "getChargingPercent"
QT_MOC_LITERAL(15, 210, 9), // "mkVoltage"
QT_MOC_LITERAL(16, 220, 18), // "checkBatteryStatus"
QT_MOC_LITERAL(17, 239, 14), // "setCurrentVolt"
QT_MOC_LITERAL(18, 254, 11), // "setCharging"
QT_MOC_LITERAL(19, 266, 13), // "suspendSystem"
QT_MOC_LITERAL(20, 280, 12), // "setIsSuspend"
QT_MOC_LITERAL(21, 293, 14), // "setSuspendTime"
QT_MOC_LITERAL(22, 308, 12), // "setLowCharge"
QT_MOC_LITERAL(23, 321, 9) // "isSuspend"

    },
    "PowerSupplySingleton\0currentVoltChanged\0"
    "\0currentVolt\0chargingChanged\0charging\0"
    "isSuspendChanged\0suspend\0suspendTimeChanged\0"
    "suspendTime\0sigSuspendSystem\0wakeUpSystem\0"
    "lowChargeChanged\0lowCharge\0"
    "getChargingPercent\0mkVoltage\0"
    "checkBatteryStatus\0setCurrentVolt\0"
    "setCharging\0suspendSystem\0setIsSuspend\0"
    "setSuspendTime\0setLowCharge\0isSuspend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowerSupplySingleton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       5,  126, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,
       8,    1,   98,    2, 0x06 /* Public */,
      10,    0,  101,    2, 0x06 /* Public */,
      11,    0,  102,    2, 0x06 /* Public */,
      12,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  106,    2, 0x0a /* Public */,
      16,    0,  109,    2, 0x0a /* Public */,
      17,    1,  110,    2, 0x0a /* Public */,
      18,    1,  113,    2, 0x0a /* Public */,
      19,    0,  116,    2, 0x0a /* Public */,
      20,    1,  117,    2, 0x0a /* Public */,
      21,    1,  120,    2, 0x0a /* Public */,
      22,    1,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   13,

 // properties: name, type, flags
       3, QMetaType::Float, 0x00495103,
       5, QMetaType::Bool, 0x00495103,
      23, QMetaType::Bool, 0x00495103,
       9, QMetaType::Int, 0x00495103,
      13, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       6,

       0        // eod
};

void PowerSupplySingleton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowerSupplySingleton *_t = static_cast<PowerSupplySingleton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentVoltChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->chargingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->isSuspendChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->suspendTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sigSuspendSystem(); break;
        case 5: _t->wakeUpSystem(); break;
        case 6: _t->lowChargeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { int _r = _t->getChargingPercent((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->checkBatteryStatus(); break;
        case 9: _t->setCurrentVolt((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->setCharging((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->suspendSystem(); break;
        case 12: _t->setIsSuspend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setSuspendTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setLowCharge((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PowerSupplySingleton::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::currentVoltChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::chargingChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::isSuspendChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::suspendTimeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::sigSuspendSystem)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::wakeUpSystem)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (PowerSupplySingleton::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PowerSupplySingleton::lowChargeChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        PowerSupplySingleton *_t = static_cast<PowerSupplySingleton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->currentVolt(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->charging(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isSuspend(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->suspendTime(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->lowCharge(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        PowerSupplySingleton *_t = static_cast<PowerSupplySingleton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentVolt(*reinterpret_cast< float*>(_v)); break;
        case 1: _t->setCharging(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setIsSuspend(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setSuspendTime(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setLowCharge(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PowerSupplySingleton::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PowerSupplySingleton.data,
      qt_meta_data_PowerSupplySingleton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PowerSupplySingleton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowerSupplySingleton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PowerSupplySingleton.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PowerSupplySingleton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PowerSupplySingleton::currentVoltChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowerSupplySingleton::chargingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PowerSupplySingleton::isSuspendChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PowerSupplySingleton::suspendTimeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PowerSupplySingleton::sigSuspendSystem()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PowerSupplySingleton::wakeUpSystem()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PowerSupplySingleton::lowChargeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
