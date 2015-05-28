#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "matrix.h"
#include <sstream>

class MatrixTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        matrix = new Matrix(3, 4);
    }

    void cleanup()
    {
        delete matrix;
    }

    void test()
    {
        std::stringstream stringStream;
        stringStream << "0  1  2  3\n"
                     << "4  6  7  8\n"
                     << "9 10 11 12\n";

        matrix->readMatrix(stringStream);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                QVERIFY(matrix->element(i, j) == i * 4 + j + 1);
    }
    //Can't come up with more tests, cause they'll be similar to the one above
private:
    Matrix *matrix;
};
