/****************************************************************************
** Meta object code from reading C++ file 'tablefilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../StadiumTourProject/tablefilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablefilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tablefilter_t {
    QByteArrayData data[9];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tablefilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tablefilter_t qt_meta_stringdata_tablefilter = {
    {
QT_MOC_LITERAL(0, 0, 11), // "tablefilter"
QT_MOC_LITERAL(1, 12, 32), // "on_individualTeamEntry_activated"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "arg1"
QT_MOC_LITERAL(4, 51, 28), // "on_exitFiltersButton_clicked"
QT_MOC_LITERAL(5, 80, 12), // "applyFilters"
QT_MOC_LITERAL(6, 93, 34), // "on_sortByEntry_currentIndexCh..."
QT_MOC_LITERAL(7, 128, 5), // "index"
QT_MOC_LITERAL(8, 134, 36) // "on_onlyShowEntry_currentIndex..."

    },
    "tablefilter\0on_individualTeamEntry_activated\0"
    "\0arg1\0on_exitFiltersButton_clicked\0"
    "applyFilters\0on_sortByEntry_currentIndexChanged\0"
    "index\0on_onlyShowEntry_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tablefilter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void tablefilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tablefilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_individualTeamEntry_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_exitFiltersButton_clicked(); break;
        case 2: _t->applyFilters(); break;
        case 3: _t->on_sortByEntry_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_onlyShowEntry_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tablefilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_tablefilter.data,
    qt_meta_data_tablefilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tablefilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tablefilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tablefilter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int tablefilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
