#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "mergesorter.h"
#include "quicksorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        mergeSorter = new MergeSorter;
        quickSorter = new QuickSorter;
    }

    void cleanup()
    {
        delete mergeSorter;
        delete quickSorter;
    }

    void sortTest()
    {
        int array[] = {12, 5, 16, 72, 13};
        int array2[] = {12, 5, 16, 72, 13};

        mergeSorter->sort(array, 5);
        quickSorter->sort(array2, 5);

        for (int i = 0; i < 4; i++)
            QVERIFY2(array[i] < array[i + 1], "MergeSorter class works wrong!");

        for (int i = 0; i < 4; i++)
            QVERIFY2(array2[i] < array2[i + 1], "MergeSorter class works wrong!");

    }

private:
    Sorter *mergeSorter;
    Sorter *quickSorter;
};
