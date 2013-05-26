/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sun 26. May 16:56:35 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      33,   11,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      79,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     140,   11,   11,   11, 0x0a,
     169,   11,   11,   11, 0x0a,
     193,   11,   11,   11, 0x0a,
     226,   11,   11,   11, 0x0a,
     258,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0onCenterChanged(int)\0"
    "onLifetimeChanged(int)\0onVelocityChanged(int)\0"
    "onSizeChanged(int)\0onRadiusChanged(int)\0"
    "onNbItemChanged(int)\0onNbItemPerFrameChanged(int)\0"
    "onFrametimeChanged(int)\0"
    "ageAttenuationFactorChanged(int)\0"
    "ageAttenuationLimitChanged(int)\0"
    "setCurrentValues()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onCenterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onLifetimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onVelocityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: onSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: onRadiusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: onNbItemChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: onNbItemPerFrameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: onFrametimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: ageAttenuationFactorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: ageAttenuationLimitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setCurrentValues(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
