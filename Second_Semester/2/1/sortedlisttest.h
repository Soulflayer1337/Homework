#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sortedlist.h"

class SortedListTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedListTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        sortedList = new SortedList;
    }

    void cleanup()
    {
        delete sortedList;
    }

    void isEmptyTest()
    {
        QVERIFY(sortedList->isEmpty());
    }

    void addingTest()
    {
        sortedList->add(42);
        QVERIFY(!sortedList->isEmpty());
    }

    void existsTest()
    {
        sortedList->add(42);
        QVERIFY(sortedList->exists(42));
        QVERIFY(!sortedList->exists(43));
    }

    void removeTest1()
    {
        sortedList->add(42);
        sortedList->remove(42);
        QVERIFY(!sortedList->exists(42));
    }

    void removeTest2()
    {
        sortedList->add(42);
        sortedList->add(42);
        sortedList->remove(42);
        QVERIFY(sortedList->exists(42));
    }

    void removeAllTest()
    {
        sortedList->add(42);
        sortedList->add(42);
        sortedList->removeAll(42);
        QVERIFY(!sortedList->exists(42));
    }

    void complexTest()
    {
        sortedList->add(42);
        sortedList->add(53);
        sortedList->add(67);
        sortedList->add(24);
        sortedList->add(13);
        sortedList->add(67);
        sortedList->add(24);

        QVERIFY(sortedList->exists(24));
        QVERIFY(!sortedList->exists(31));

        sortedList->remove(13);
        QVERIFY(!sortedList->exists(13));

        sortedList->remove(24);
        QVERIFY(sortedList->exists(24));

        sortedList->removeAll(67);
        QVERIFY(!sortedList->exists(67));
    }

private:
    SortedList *sortedList;
};
