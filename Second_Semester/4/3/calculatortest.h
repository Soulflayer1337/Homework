#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) { }

private slots:
    void init()
    {
        calculator = new Calculator;
    }

    void cleanup()
    {
        delete calculator;
    }

    void additionTest()
    {
        calculator->count(5.3, '+');
        QCOMPARE(calculator->count(3.7, '='), 9.0);
    }

    void subtractionTest()
    {
        calculator->count(5.3, '-');
        QCOMPARE(calculator->count(3.7, '='), 1.6);
    }

    void multiplicationTest()
    {
        calculator->count(5.3, '*');
        QCOMPARE(calculator->count(3.7, '*'), 19.61);
    }

    void dividingTest()
    {
        calculator->count(6.3, '/');
        QCOMPARE(calculator->count(3.0, '='), 2.1);
    }

    void divideByZeroTest()
    {
        calculator->count(4, '/');
        bool dividedByZero = false;

        try
        {
            calculator->count(0, '=');
        }
        catch (DividedByZero &)
        {
            dividedByZero = true;
        }

        QVERIFY(dividedByZero);
    }

    void resultTest()
    {
        calculator->count(5.3, '+');
        calculator->count(3.7, '=');
        QCOMPARE(calculator->result(), 9.0);
    }

private:
    Calculator *calculator;
};
