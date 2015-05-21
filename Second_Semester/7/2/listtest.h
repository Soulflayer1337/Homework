#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new List;
    }

    void cleanup()
    {
        delete list;
    }

    void isEmptyTest()
    {
        QVERIFY(list->isEmpty());
    }

    void addTest()
    {
        list->add(42);
        QVERIFY(!list->isEmpty());
    }

    void existsTest()
    {
        list->add(42);
        QVERIFY(list->exists(42));
    }

    void removeTest()
    {
        list->add(42);
        list->remove(42);
        QVERIFY(list->isEmpty());
    }

    void lengthTest1()
    {
        list->add(42);
        QVERIFY(list->getLength() == 1);
    }

    void lengthTest2()
    {
        list->add(42);
        list->add(15);
        list->add(32);
        QVERIFY(list->getLength() == 3);
    }

    void lengthTest3()
    {
        list->add(42);
        list->add(42);
        QVERIFY(list->getLength() == 2);
    }

    void exceptionTest()
    {
        bool exception = false;

        try
        {
            list->remove(42);
        }
        catch (MissingElementException &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }

private:
    List *list;
};
