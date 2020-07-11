/****************************************************************************
** Meta object code from reading C++ file 'ParticleSystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ParticleSystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ParticleSystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParticleSystem_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParticleSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParticleSystem_t qt_meta_stringdata_ParticleSystem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ParticleSystem"
QT_MOC_LITERAL(1, 15, 11), // "addParticle"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "ClearButton"
QT_MOC_LITERAL(4, 40, 15), // "AttractorButton"
QT_MOC_LITERAL(5, 56, 14), // "RepulsorButton"
QT_MOC_LITERAL(6, 71, 14), // "ParticleButton"
QT_MOC_LITERAL(7, 86, 15), // "GeneratorButton"
QT_MOC_LITERAL(8, 102, 10), // "ChangeMass"
QT_MOC_LITERAL(9, 113, 1) // "a"

    },
    "ParticleSystem\0addParticle\0\0ClearButton\0"
    "AttractorButton\0RepulsorButton\0"
    "ParticleButton\0GeneratorButton\0"
    "ChangeMass\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParticleSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void ParticleSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParticleSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addParticle(); break;
        case 1: _t->ClearButton(); break;
        case 2: _t->AttractorButton(); break;
        case 3: _t->RepulsorButton(); break;
        case 4: _t->ParticleButton(); break;
        case 5: _t->GeneratorButton(); break;
        case 6: _t->ChangeMass((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParticleSystem::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ParticleSystem.data,
    qt_meta_data_ParticleSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParticleSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParticleSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParticleSystem.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ParticleSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
