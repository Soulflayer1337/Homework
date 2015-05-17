#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0) :QObject(parent) {}

private slots:
    void init()
    {
        set = new Set<int>;
    }

    void cleanup()
    {
        delete set;
    }

    void isEmptyTest()
    {
        QVERIFY(set->isEmpty());
    }

    void additionTest()
    {
        set->add(42);
        QVERIFY(!set->isEmpty());
    }

    void existsTest()
    {
        set->add(42);
        QVERIFY(set->exists(42));
    }

    void doesntExistTest()
    {
        set->add(42);
        QVERIFY(!set->exists(24));
    }

    void removeTest()
    {
        set->add(42);
        set->remove(42);
        QVERIFY(!set->exists(42));
    }

    void getArrayTest()
    {
        int example[] = {13, 25, 53, 67, 73};

        for  (int i = 0; i < 5; i++)
            set->add(example[i]);

        int sizeOfArray = 0;
        int *array = set->getArray(sizeOfArray);

        bool correct = (sizeOfArray == 5);

        while (correct && sizeOfArray)
        {
            sizeOfArray--;
            correct = (example[sizeOfArray] == array[sizeOfArray]);
        }

        delete[] array;

        QVERIFY(correct);
    }

    void intersectionTest()
    {
        int firstArray[] = {1, 2, 3, 4};
        Set<int> *firstSet = new Set<int>;

        for (int i = 0; i < 4; i++)
            firstSet->add(firstArray[i]);

        int secondArray[] = {3, 4, 5, 6};
        Set<int> *secondSet = new Set<int>;

        for (int i = 0; i < 4; i++)
            secondSet->add(secondArray[i]);

        set = firstSet->setIntersection(secondSet);
        int intersectionExample[] = {3, 4};
        int sizeOfIntersection = 0;
        int *intersectionArray = set->getArray(sizeOfIntersection);

        bool correct = (sizeOfIntersection == 2);

        while (correct && sizeOfIntersection)
        {
            sizeOfIntersection--;
            correct = (intersectionExample[sizeOfIntersection] == intersectionArray[sizeOfIntersection]);
        }

        delete firstSet;
        delete secondSet;
        delete[] intersectionArray;

        QVERIFY(correct);
    }

    void unionTest()
    {
        int firstArray[] = {1, 2, 3, 4};
        Set<int> *firstSet = new Set<int>;

        for (int i = 0; i < 4; i++)
            firstSet->add(firstArray[i]);

        int secondArray[] = {3, 4, 5, 6};
        Set<int> *secondSet = new Set<int>;

        for (int i = 0; i < 4; i++)
            secondSet->add(secondArray[i]);

        set = firstSet->setUnion(secondSet);
        int unionExample[] = {1, 2, 3, 4, 5, 6};
        int sizeOfUnion = 0;
        int *unionArray = set->getArray(sizeOfUnion);

        bool correct = (sizeOfUnion == 6);

        while (correct && sizeOfUnion)
        {
            sizeOfUnion--;
            correct = (unionExample[sizeOfUnion] == unionArray[sizeOfUnion]);
        }

        delete firstSet;
        delete secondSet;
        delete[] unionArray;

        QVERIFY(correct);
    }

private:
    Set<int> *set;
};
