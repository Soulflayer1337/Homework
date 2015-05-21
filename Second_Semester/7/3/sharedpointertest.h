#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"

typedef SharedPointer<int> spInt;

class ezClass
{
public:
    ezClass(bool &del) : deleted(del) {}
    ~ezClass()
    {
        deleted = true;
    }
private:
    bool &deleted;
};

class SharedPointerTest : public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    void correctWorkTest()
    {
        bool deleted = false;
        {
            SharedPointer<ezClass> ptr(new ezClass(deleted));
        }
        QVERIFY(deleted);
    }

    void intPointerTest()
    {
        spInt theAnswer(new int(42));
        QCOMPARE(*theAnswer, 42);
        QCOMPARE(theAnswer.getCount(), 1);
    }

    void copyTest1()
    {
        spInt firstPtr(new int(42));
        spInt secondPtr(firstPtr);
        QCOMPARE(firstPtr.getCount(), 2);
    }

    void copyTest2()
    {
        spInt firstPtr(new int(42));
        spInt secondPtr(firstPtr);
        secondPtr.release();
        QCOMPARE(firstPtr.getCount(), 1);
        QCOMPARE(secondPtr.getCount(), 0);
    }

    void copyTest3()
    {
        bool deleted = false;
        {
            SharedPointer<ezClass> firstPtr(new ezClass(deleted));
            {
                SharedPointer<ezClass> secondPtr(firstPtr);
            }
            QVERIFY(!deleted);
        }
        QVERIFY(deleted);
    }
};
