#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        bag = new Bag<int>;
    }

    void cleanup()
    {
        delete bag;
    }

    void isEmptyTest()
    {
        QVERIFY(bag->isEmpty());
    }

    void additionTest()
    {
        bag->add(42);
        QVERIFY(!bag->isEmpty());
    }

    void existsTest()
    {
        bag->add(42);
        QVERIFY(bag->exists(42));
        QVERIFY(!bag->exists(24));
    }

    void removeTest()
    {
        bag->add(42);
        bag->remove(42);
        QVERIFY(!bag->exists(42));
    }

    void expressionTest()
    {
        bool exception = false;

        try
        {
            bag->remove(42);
        }
        catch (MissingElementException &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }

    void numberOfElementsTest1()
    {
        bag->add(42);
        QCOMPARE(bag->numberOfElements(42), 1);
        bag->add(42);
        QCOMPARE(bag->numberOfElements(42), 2);
    }

    void numberOfElementsTest2()
    {
        bag->add(42);
        bag->add(42);
        bag->remove(42);
        QCOMPARE(bag->numberOfElements(42), 1);
    }

    void complexTest()
    {
        bag->add(42);
        bag->add(15);
        bag->add(67);
        bag->add(13);
        bag->add(42);
        bag->add(67);

        QCOMPARE(bag->numberOfElements(67), 2);

        bag->remove(42);

        QCOMPARE(bag->numberOfElements(42), 1);
        QVERIFY(bag->exists(13));
        QVERIFY(!bag->exists(88));
    }

private:
    Bag<int> *bag;
};
