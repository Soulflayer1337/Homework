#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "linkedstack.h"

class LinkedStackTest : public QObject
{
    Q_OBJECT
public:
    explicit LinkedStackTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        linkedStack = new LinkedStack;
    }

    void cleanup()
    {
        delete linkedStack;
    }

    void isEmptyTest()
    {
        QVERIFY(linkedStack->isEmpty());
    }

    void pushTest()
    {
        linkedStack->push(42);
        QVERIFY(!linkedStack->isEmpty());
    }

    void topTest()
    {
        linkedStack->push(42);
        QVERIFY(linkedStack->top() == 42);
    }

    void popTest()
    {
        linkedStack->push(42);
        linkedStack->push(53);
        QVERIFY(linkedStack->pop() == 53);
        QVERIFY(linkedStack->pop() == 42);
    }

    void complexTest()
    {
        linkedStack->push(42);
        linkedStack->push(53);
        QVERIFY(linkedStack->top() == 53);

        linkedStack->push(67);
        linkedStack->push(89);
        QVERIFY(linkedStack->pop() == 89);

        QVERIFY(linkedStack->top() == 67);
    }
private:
    LinkedStack *linkedStack;
};
