#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0) :QObject(parent) {}

private slots:
    void init()
    {
        list = new List;
    }

    void cleanup()
    {
        delete list;
    }

    void testEmpty()
    {
        QVERIFY(list->isEmpty());
    }

    void testAddTo()
    {
        list->add("sword");
        QVERIFY(!list->isEmpty());
    }

    void testExists()
    {
        list->add("sword");
        QVERIFY(list->exists("sword"));
    }

    void testExists2()
    {
        list->add("sword");
        QVERIFY(!list->exists("blade"));
    }

    void testRemove()
    {
        list->add("blade");
        list->remove("blade");
        QVERIFY(list->isEmpty());
    }

    void testPop()
    {
        list->add("blade");
        list->pop();
        QVERIFY(list->isEmpty());
    }
private:
    List *list;
};
