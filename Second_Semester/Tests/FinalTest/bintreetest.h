#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bintree.h"

class BinTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit BinTreeTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        tree = new BinTree;
    }

    void cleanup()
    {
        delete tree;
    }

    void isEmptyTest()
    {
        QVERIFY(tree->isEmpty());
    }

    void additionTest1()
    {
        tree->add(42);
        QVERIFY(!tree->isEmpty());
        QVERIFY(tree->exists(42));
    }

    void additionTest2()
    {
        tree->add(42);
        tree->add(53);
        tree->add(67);
        tree->add(89);
        tree->add(56);
        tree->add(15);

        QVERIFY(tree->exists(15));
        QVERIFY(tree->exists(67));
    }

    void removeTest()
    {
        tree->add(42);
        tree->remove(42);
        QVERIFY(tree->isEmpty());
        QVERIFY(!tree->exists(42));
    }

    void complexTest()
    {
        tree->add(42);
        tree->add(53);
        tree->add(67);
        tree->add(89);
        tree->add(56);
        tree->add(15);

        tree->remove(67);
        tree->remove(15);

        QVERIFY2(tree->exists(89), "Element still exist, but...\n");
        QVERIFY2(!tree->exists(67), "Element doesn't exist, but... we still can find it! GREAT!\n");
    }
private:
    BinTree *tree;
};
