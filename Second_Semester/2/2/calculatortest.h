#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"
#include "arraystack.h"
#include <sstream>

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        calculator = new Calculator;
        calculator->setStack(new ArrayStack);
    }

    void cleanup()
    {
        delete calculator;
    }

    void ezTest()
    {
        std::stringstream stream;
        stream << "5 3 +\n";

        int error = 0;
        int ans = calculator->calculate(stream, error);

        QVERIFY(!error);
        QVERIFY(ans == 8);
    }

    void divideByZeroTest()
    {
        std::stringstream stream;
        stream << "5 0 /\n";

        int error = 0;
        calculator->calculate(stream, error);

        QVERIFY(error == 2);
    }

    void complexTest()
    {
        std::stringstream stream;
        stream << "5 3 + 7 * 6 - 5 /\n";

        int error = 0;
        int ans = calculator->calculate(stream, error);

        QVERIFY(!error);
        QVERIFY(ans == 10);
    }

private:
    Calculator *calculator;
};
