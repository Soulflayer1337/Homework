#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arraystack.h"

class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        arrayStack = new ArrayStack;
    }

    void cleanup()
    {
        delete arrayStack;
    }

    void isEmptyTest()
    {
        QVERIFY(arrayStack->isEmpty());
    }

    void pushTest()
    {
        arrayStack->push(42);
        QVERIFY(!arrayStack->isEmpty());
    }

    void topTest()
    {
        arrayStack->push(42);
        QVERIFY(arrayStack->top() == 42);
    }

    void popTest()
    {
        arrayStack->push(42);
        arrayStack->push(53);
        QVERIFY(arrayStack->pop() == 53);
        QVERIFY(arrayStack->pop() == 42);
    }

    void complexTest()
    {
        arrayStack->push(42);
        arrayStack->push(53);
        QVERIFY(arrayStack->top() == 53);

        arrayStack->push(67);
        arrayStack->push(89);
        QVERIFY(arrayStack->pop() == 89);

        QVERIFY(arrayStack->top() == 67);
    }
private:
    ArrayStack *arrayStack;
};
