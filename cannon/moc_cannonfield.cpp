/****************************************************************************
** Meta object code from reading C++ file 'cannonfield.h'
**
** Created: Sat Oct 30 16:44:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cannonfield.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cannonfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CannonField[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   13,   12,   12, 0x05,
      49,   40,   12,   12, 0x05,
      67,   12,   12,   12, 0x05,
      73,   12,   12,   12, 0x05,
      86,   82,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,  101,   12,   12, 0x0a,
     127,  121,   12,   12, 0x0a,
     141,   12,   12,   12, 0x0a,
     149,   12,   12,   12, 0x0a,
     161,   12,   12,   12, 0x0a,
     175,   12,   12,   12, 0x0a,
     189,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CannonField[] = {
    "CannonField\0\0newAngle\0angleChanged(int)\0"
    "newForce\0forceChanged(int)\0hit()\0"
    "missed()\0can\0canShoot(bool)\0angle\0"
    "setAngle(int)\0force\0setForce(int)\0"
    "shoot()\0newTarget()\0setGameOver()\0"
    "restartGame()\0moveShot()\0"
};

const QMetaObject CannonField::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CannonField,
      qt_meta_data_CannonField, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CannonField::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField))
        return static_cast<void*>(const_cast< CannonField*>(this));
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: angleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: forceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: hit(); break;
        case 3: missed(); break;
        case 4: canShoot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: setAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: setForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: shoot(); break;
        case 8: newTarget(); break;
        case 9: setGameOver(); break;
        case 10: restartGame(); break;
        case 11: moveShot(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CannonField::angleChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CannonField::forceChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CannonField::hit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CannonField::missed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CannonField::canShoot(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
