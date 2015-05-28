#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "fileoutputer.h"
#include <fstream>
#include <sstream>
#include <iostream>

class OutputerTest : public QObject
{
    Q_OBJECT
public:
    explicit OutputerTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        fileOutputer = new FileOutputer;
        matrix = new Matrix(5);
    }

    void cleanup()
    {
        delete fileOutputer;
        delete matrix;
    }

    void correctWorkTest()
    {

        std::stringstream matrixStream;
        matrixStream << "25 24 23 22 21\n"
                     << "10  9  8  7 20\n"
                     << "11  2  1  6 19\n"
                     << "12  3  4  5 18\n"
                     << "13 14 15 16 17\n";

        matrix->readMatrix(matrixStream);

        fileOutputer->output(matrix, 5);
        std::ifstream in("output.txt");

        QVERIFY(in.is_open());

        for (int i = 1; i < 26; i++)
        {
            int current = 0;
            in >> current;
            QVERIFY(current == i);
        }

        in.close();
    }

private:
    FileOutputer *fileOutputer;
    Matrix *matrix;
};
