#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sortedset.h"
#include "sortedlist.h"

class SortedSetTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedSetTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        sortedSet = new SortedSet;
        comparisonList1 = comparisonList2 = nullptr;

    }

    void cleanup()
    {
        delete sortedSet;
        delete comparisonList1;

        if (comparisonList2)
            delete comparisonList2;
    }

    void additionAndExistsTest()
    {
        SortedList *firstList = new SortedList;

        firstList->add(53);
        firstList->add(144);
        firstList->add(42);

        comparisonList1 = dynamic_cast<SortedList *>(firstList->copy());

        sortedSet->add(firstList);
        QVERIFY(sortedSet->exists(comparisonList1));

        comparisonList1->add(115);
        QVERIFY(!sortedSet->exists(comparisonList1));
    }

    void removeTest()
    {
        SortedList *firstList = new SortedList;

        firstList->add(53);
        firstList->add(144);
        firstList->add(42);

        SortedList *removeList = dynamic_cast<SortedList *> (firstList->copy());
        comparisonList1 = dynamic_cast<SortedList *> (firstList->copy());

        SortedList *secondList = new SortedList;

        secondList->add(67);
        secondList->add(144);
        secondList->add(42);

        comparisonList2 = dynamic_cast<SortedList *> (secondList->copy());

        sortedSet->add(firstList);
        sortedSet->add(secondList);
        sortedSet->remove(removeList);
        delete removeList;

        QVERIFY(!sortedSet->exists(comparisonList1));
        QVERIFY(sortedSet->exists(comparisonList2));
    }

private:
    SortedSet *sortedSet;
    SortedList *comparisonList1;
    SortedList *comparisonList2;
};
