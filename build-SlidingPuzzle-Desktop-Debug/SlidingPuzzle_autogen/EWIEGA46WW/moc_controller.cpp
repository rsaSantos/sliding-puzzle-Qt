/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SlidingPuzzle/controller.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Controller_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[12];
    char stringdata5[11];
    char stringdata6[13];
    char stringdata7[11];
    char stringdata8[10];
    char stringdata9[6];
    char stringdata10[13];
    char stringdata11[8];
    char stringdata12[6];
    char stringdata13[6];
    char stringdata14[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Controller_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
        QT_MOC_LITERAL(0, 10),  // "Controller"
        QT_MOC_LITERAL(11, 12),  // "boardChanged"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 19),  // "initialBoardChanged"
        QT_MOC_LITERAL(45, 11),  // "createBoard"
        QT_MOC_LITERAL(57, 10),  // "difficulty"
        QT_MOC_LITERAL(68, 12),  // "pieceClicked"
        QT_MOC_LITERAL(81, 10),  // "pieceIndex"
        QT_MOC_LITERAL(92, 9),  // "resetGame"
        QT_MOC_LITERAL(102, 5),  // "board"
        QT_MOC_LITERAL(108, 12),  // "initialBoard"
        QT_MOC_LITERAL(121, 7),  // "nPieces"
        QT_MOC_LITERAL(129, 5),  // "nRows"
        QT_MOC_LITERAL(135, 5),  // "nCols"
        QT_MOC_LITERAL(141, 9)   // "voidPiece"
    },
    "Controller",
    "boardChanged",
    "",
    "initialBoardChanged",
    "createBoard",
    "difficulty",
    "pieceClicked",
    "pieceIndex",
    "resetGame",
    "board",
    "initialBoard",
    "nPieces",
    "nRows",
    "nCols",
    "voidPiece"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Controller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       6,   53, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    7 /* Public */,
       3,    0,   45,    2, 0x06,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   46,    2, 0x02,    9 /* Public */,
       6,    1,   49,    2, 0x02,   11 /* Public */,
       8,    0,   52,    2, 0x02,   13 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::Int,    7,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QStringList, 0x00015103, uint(0), 0,
      10, QMetaType::QStringList, 0x00015103, uint(1), 0,
      11, QMetaType::Int, 0x00015401, uint(-1), 0,
      12, QMetaType::Int, 0x00015401, uint(-1), 0,
      13, QMetaType::Int, 0x00015401, uint(-1), 0,
      14, QMetaType::QString, 0x00015401, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.offsetsAndSizes,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Controller_t,
        // property 'board'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // property 'initialBoard'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // property 'nPieces'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'nRows'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'nCols'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'voidPiece'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Controller, std::true_type>,
        // method 'boardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initialBoardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createBoard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'pieceClicked'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'resetGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->boardChanged(); break;
        case 1: _t->initialBoardChanged(); break;
        case 2: _t->createBoard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { bool _r = _t->pieceClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->resetGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::boardChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::initialBoardChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->board(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->initialBoard(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->nPieces(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->nRows(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->nCols(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->voidPiece(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBoard(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 1: _t->setInitialBoard(*reinterpret_cast< QList<QString>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Controller::boardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controller::initialBoardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE