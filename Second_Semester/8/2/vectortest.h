#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void initTest()
    {
        Vector<5> vector;
    }

    void copyTest()
    {
        int array[] = {13, 24, -14, -17, 2};
        Vector<5> vector;

        for (int i = 0; i < 5; i++)
            vector[i] = array[i];

        Vector<5> copyOfVector(vector);

        for (int i = 0; i < 5; i++)
            QCOMPARE(copyOfVector[i], array[i]);
    }

    void sumTest()
    {
        int firstArray[] = {13, 24, -14, -17, 2};
        Vector<5> firstVector;

        for (int i = 0; i < 5; i++)
            firstVector[i] = firstArray[i];

        int secondArray[] = {10, -4, -1, 12, 7};
        Vector<5> secondVector;

        for (int i = 0; i < 5; i++)
            secondVector[i] = secondArray[i];

        Vector<5> sumOfVectors = firstVector + secondVector;

        for (int i = 0; i < 5; i++)
            QCOMPARE(sumOfVectors[i], firstArray[i] + secondArray[i]);
    }

    void difTest()
    {
        int firstArray[] = {13, 24, -14, -17, 2};
        Vector<5> firstVector;

        for (int i = 0; i < 5; i++)
            firstVector[i] = firstArray[i];

        int secondArray[] = {10, -4, -1, 12, 7};
        Vector<5> secondVector;

        for (int i = 0; i < 5; i++)
            secondVector[i] = secondArray[i];

        Vector<5> difOfVectors = firstVector - secondVector;

        for (int i = 0; i < 5; i++)
            QCOMPARE(difOfVectors[i], firstArray[i] - secondArray[i]);
    }

    void dotProductTest()
    {
        int firstArray[] = {13, 24, -14, -17, 2};
        Vector<5> firstVector;

        for (int i = 0; i < 5; i++)
            firstVector[i] = firstArray[i];

        int secondArray[] = {10, -4, -1, 12, 7};
        Vector<5> secondVector;

        for (int i = 0; i < 5; i++)
            secondVector[i] = secondArray[i];

        int productOfVectors = firstVector * secondVector;
        int dotProduct = 0;

        for (int i = 0; i < 5; i++)
            dotProduct += firstArray[i] * secondArray[i];

        QCOMPARE(dotProduct, productOfVectors);
    }
};
