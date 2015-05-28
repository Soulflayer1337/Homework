#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublelinkedlist.h"

class DoubleLinkedListTest : public QObject
{
    Q_OBJECT
public:
    explicit DoubleLinkedListTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        doubleLinkedList = new DoubleLinkedList;
    }

    void cleanup()
    {
        delete doubleLinkedList;
    }

    void isEmptyTest()
    {
        QVERIFY(doubleLinkedList->isEmpty());
    }

    void addingTest()
    {
        doubleLinkedList->add(42);
        QVERIFY(!doubleLinkedList->isEmpty());
    }

    void existsTest()
    {
        doubleLinkedList->add(42);
        QVERIFY(doubleLinkedList->exists(42));
        QVERIFY(!doubleLinkedList->exists(43));
    }

    void removeTest1()
    {
        doubleLinkedList->add(42);
        doubleLinkedList->remove(42);
        QVERIFY(!doubleLinkedList->exists(42));
    }

    void removeTest2()
    {
        doubleLinkedList->add(42);
        doubleLinkedList->add(42);
        doubleLinkedList->remove(42);
        QVERIFY(doubleLinkedList->exists(42));
    }

    void removeAllTest()
    {
        doubleLinkedList->add(42);
        doubleLinkedList->add(42);
        doubleLinkedList->removeAll(42);
        QVERIFY(!doubleLinkedList->exists(42));
    }

    void complexTest()
    {
        doubleLinkedList->add(42);
        doubleLinkedList->add(53);
        doubleLinkedList->add(67);
        doubleLinkedList->add(24);
        doubleLinkedList->add(13);
        doubleLinkedList->add(67);
        doubleLinkedList->add(24);

        QVERIFY(doubleLinkedList->exists(24));
        QVERIFY(!doubleLinkedList->exists(31));

        doubleLinkedList->remove(13);
        QVERIFY(!doubleLinkedList->exists(13));

        doubleLinkedList->remove(24);
        QVERIFY(doubleLinkedList->exists(24));

        doubleLinkedList->removeAll(67);
        QVERIFY(!doubleLinkedList->exists(67));
    }

private:
    DoubleLinkedList *doubleLinkedList;
};
