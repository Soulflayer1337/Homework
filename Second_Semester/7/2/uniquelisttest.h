#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"

class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        list = new UniqueList;
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
        QVERIFY(!list->exists(42));
    }

    void doubleAddExceptionTest()
    {
        list->add(42);

        bool exception = false;

        try
        {
            list->add(42);
        }
        catch (ElementExistsException &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }

    void exceptionTest()
    {
        bool exception = false;

        try
        {
            list->remove(24);
        }
        catch (MissingElementException &)
        {
            exception = true;
        }

        QVERIFY(exception);
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

        try
        {
            list->add(42);
        }
        catch (...)
        {
        }

        QVERIFY(list->getLength() == 1);
    }
private:
    UniqueList *list;
};
