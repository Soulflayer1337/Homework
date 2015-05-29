#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "avltree.h"

class AVLTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit AVLTreeTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        avlTree = new AVLTree<int>;
    }

    void cleanup()
    {
        delete avlTree;
    }

    void isEmptyTest()
    {
        QVERIFY(avlTree->isEmpty());
    }

    void additionTest()
    {
        avlTree->add(42);
        QVERIFY(!avlTree->isEmpty());
    }

    void existsTest()
    {
        avlTree->add(42);
        QVERIFY(avlTree->exists(42));
    }

    void doesntExistTest()
    {
        avlTree->add(42);
        QVERIFY(!avlTree->exists(24));
    }

    void removeTest()
    {
        avlTree->add(42);
        avlTree->remove(42);
        QVERIFY(!avlTree->exists(42));
    }

    void getArrayTest()
    {
        int example[] = {13, 25, 53, 67, 73};

        for  (int i = 0; i < 5; i++)
            avlTree->add(example[i]);

        int sizeOfArray = 0;
        int *array = avlTree->getArray(sizeOfArray);

        bool correct = (sizeOfArray == 5);

        while (correct && sizeOfArray)
        {
            sizeOfArray--;
            correct = (example[sizeOfArray] == array[sizeOfArray]);
        }

        delete[] array;

        QVERIFY(correct);
    }

private:
    AVLTree<int> *avlTree;
};
