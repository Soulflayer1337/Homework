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
        list = new SortedList;
        secondList = nullptr;
    }

    void cleanup()
    {
        delete list;

        if (secondList)
            delete secondList;

    }

    void additionAndExistsTest()
    {
        list->add(42);
        QVERIFY(list->exists(42));
        QVERIFY(!list->exists(45));
    }

    void countTest()
    {
        list->add(42);
        QVERIFY(list->count(42) == 1);
        QVERIFY(!list->count(53));
        list->add(42);
        list->add(42);
        list->add(53);
        QVERIFY(list->count(42));
    }

    void removeTest1()
    {
        list->add(42);
        list->add(53);
        list->remove(42);
        QVERIFY(list->exists(53));
        QVERIFY(!list->exists(42));
    }

    void removeTest2()
    {
        list->add(42);
        list->add(42);
        list->remove(42);
        QVERIFY(list->exists(42));
    }

    void removeAllTest()
    {
        list->add(42);
        list->add(42);
        list->removeAll(42);
        QVERIFY(!list->exists(42));
    }

    void converToArrayTest()
    {
        list->add(53);
        list->add(42);
        list->add(31);
        list->add(42);
        list->add(67);
        list->add(13);

        int *array = list->convertToArray();
        int compareArray[] = {13, 31, 42, 42, 53, 67};

        for (int i = 0; i < 6; i++)
            QVERIFY(array[i] == compareArray[i]);

        delete[] array;
    }

    void comparisonTest()
    {
        secondList = new SortedList;

        list->add(42);
        list->add(53);
        list->add(13);

        secondList->add(42);
        secondList->add(13);

        QVERIFY(!list->isEqual(secondList));
        QVERIFY(list->compareTo(secondList));

        secondList->add(53);

        QVERIFY(list->isEqual(secondList));
        QVERIFY(!list->compareTo(secondList));
    }

    void copyTest()
    {
        list->add(53);
        list->add(42);
        list->add(31);
        list->add(42);
        list->add(67);
        list->add(13);

        IComparable *copy = list->copy();
        secondList = dynamic_cast<SortedList*>(copy);

        if (secondList == nullptr)
        {
            delete copy;
            QFAIL("dynamic_cast failed");
        }

        int *array = secondList->convertToArray();
        int compareArray[] = {13, 31, 42, 42, 53, 67};

        for (int i = 0; i < 6; i++)
            QVERIFY(array[i] == compareArray[i]);

        delete[] array;
    }

private:
    SortedList *list;
    SortedList *secondList;
};
