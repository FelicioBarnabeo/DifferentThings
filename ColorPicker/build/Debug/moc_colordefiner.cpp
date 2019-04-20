/****************************************************************************
** Meta object code from reading C++ file 'colordefiner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source/colordefiner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colordefiner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorDefiner_t {
    QByteArrayData data[31];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorDefiner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorDefiner_t qt_meta_stringdata_ColorDefiner = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ColorDefiner"
QT_MOC_LITERAL(1, 13, 15), // "rndPointChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "rndPoint"
QT_MOC_LITERAL(4, 39, 16), // "rndPoint2Changed"
QT_MOC_LITERAL(5, 56, 9), // "rndPoint2"
QT_MOC_LITERAL(6, 66, 21), // "getAngleByCoordinates"
QT_MOC_LITERAL(7, 88, 1), // "x"
QT_MOC_LITERAL(8, 90, 1), // "y"
QT_MOC_LITERAL(9, 92, 2), // "x0"
QT_MOC_LITERAL(10, 95, 2), // "y0"
QT_MOC_LITERAL(11, 98, 8), // "oddAngle"
QT_MOC_LITERAL(12, 107, 5), // "angle"
QT_MOC_LITERAL(13, 113, 8), // "getColor"
QT_MOC_LITERAL(14, 122, 17), // "getColorByRadians"
QT_MOC_LITERAL(15, 140, 17), // "getColorByDegrees"
QT_MOC_LITERAL(16, 158, 14), // "randomizePoint"
QT_MOC_LITERAL(17, 173, 9), // "findColor"
QT_MOC_LITERAL(18, 183, 3), // "clr"
QT_MOC_LITERAL(19, 187, 21), // "makeColorWheelMapFile"
QT_MOC_LITERAL(20, 209, 11), // "degreesStep"
QT_MOC_LITERAL(21, 221, 9), // "lightStep"
QT_MOC_LITERAL(22, 231, 13), // "getColorValue"
QT_MOC_LITERAL(23, 245, 4), // "name"
QT_MOC_LITERAL(24, 250, 7), // "procent"
QT_MOC_LITERAL(25, 258, 6), // "setRad"
QT_MOC_LITERAL(26, 265, 3), // "rad"
QT_MOC_LITERAL(27, 269, 9), // "setCenter"
QT_MOC_LITERAL(28, 279, 6), // "center"
QT_MOC_LITERAL(29, 286, 11), // "setRndPoint"
QT_MOC_LITERAL(30, 298, 12) // "setRndPoint2"

    },
    "ColorDefiner\0rndPointChanged\0\0rndPoint\0"
    "rndPoint2Changed\0rndPoint2\0"
    "getAngleByCoordinates\0x\0y\0x0\0y0\0"
    "oddAngle\0angle\0getColor\0getColorByRadians\0"
    "getColorByDegrees\0randomizePoint\0"
    "findColor\0clr\0makeColorWheelMapFile\0"
    "degreesStep\0lightStep\0getColorValue\0"
    "name\0procent\0setRad\0rad\0setCenter\0"
    "center\0setRndPoint\0setRndPoint2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorDefiner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       4,  158, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    4,  105,    2, 0x0a /* Public */,
      11,    1,  114,    2, 0x0a /* Public */,
      13,    2,  117,    2, 0x0a /* Public */,
      14,    1,  122,    2, 0x0a /* Public */,
      15,    1,  125,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    1,  129,    2, 0x0a /* Public */,
      19,    2,  132,    2, 0x0a /* Public */,
      19,    1,  137,    2, 0x2a /* Public | MethodCloned */,
      19,    0,  140,    2, 0x2a /* Public | MethodCloned */,
      22,    2,  141,    2, 0x0a /* Public */,
      25,    1,  146,    2, 0x0a /* Public */,
      27,    1,  149,    2, 0x0a /* Public */,
      29,    1,  152,    2, 0x0a /* Public */,
      30,    1,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    5,

 // slots: parameters
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Int, QMetaType::Float,   12,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::QString, QMetaType::Double,   12,
    QMetaType::QString, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   23,   24,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QPoint,   28,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    5,

 // properties: name, type, flags
      26, QMetaType::Int, 0x00095401,
      28, QMetaType::QPoint, 0x00095401,
       3, QMetaType::QPoint, 0x00495103,
       5, QMetaType::QPoint, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       1,

       0        // eod
};

void ColorDefiner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorDefiner *_t = static_cast<ColorDefiner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rndPointChanged((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->rndPoint2Changed((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: { int _r = _t->getAngleByCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->oddAngle((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getColorByRadians((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getColorByDegrees((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->randomizePoint(); break;
        case 8: { bool _r = _t->findColor((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->makeColorWheelMapFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->makeColorWheelMapFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->makeColorWheelMapFile(); break;
        case 12: { QString _r = _t->getColorValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setRad((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setCenter((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 15: _t->setRndPoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 16: _t->setRndPoint2((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ColorDefiner::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorDefiner::rndPointChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ColorDefiner::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorDefiner::rndPoint2Changed)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ColorDefiner *_t = static_cast<ColorDefiner *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->rad(); break;
        case 1: *reinterpret_cast< QPoint*>(_v) = _t->center(); break;
        case 2: *reinterpret_cast< QPoint*>(_v) = _t->rndPoint(); break;
        case 3: *reinterpret_cast< QPoint*>(_v) = _t->rndPoint2(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ColorDefiner *_t = static_cast<ColorDefiner *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setRndPoint(*reinterpret_cast< QPoint*>(_v)); break;
        case 3: _t->setRndPoint2(*reinterpret_cast< QPoint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ColorDefiner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ColorDefiner.data,
      qt_meta_data_ColorDefiner,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ColorDefiner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorDefiner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorDefiner.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ColorDefiner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ColorDefiner::rndPointChanged(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ColorDefiner::rndPoint2Changed(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
