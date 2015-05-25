#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "expressionparser.h"

class ExpressionParserTest : public QObject
{
    Q_OBJECT
public:
    explicit ExpressionParserTest(QObject *parent = 0) :QObject(parent) {}

private slots:
    void init()
    {
        expression = nullptr;
    }

    void cleanup()
    {
        delete expression;
    }

    void onlyNumberTest()
    {
        expression = ExpressionParser::parse("42");
        int result = expression->count();
        QVERIFY(result == 42);
    }

    void additionTest()
    {
        expression = ExpressionParser::parse("(+ 173 15)");
        int result = expression->count();
        QVERIFY(result == 188);
    }

    void subtractionTest()
    {
        expression = ExpressionParser::parse("(- 27 13)");
        int result = expression->count();
        QVERIFY(result == 14);
    }

    void multiplicationTest()
    {
        expression = ExpressionParser::parse("(* 16 46)");
        int result = expression->count();
        QVERIFY(result == 736);
    }

    void divisionTest()
    {
        expression = ExpressionParser::parse("(/ 1813 37)");
        int result = expression->count();
        QVERIFY(result == 49);
    }

    void divisionByZeroTest()
    {
        bool dividedByZero = 0;
        expression = ExpressionParser::parse("(/ 1337 0)");

        try
        {
            expression->count();
        }
        catch (DividedByZeroException)
        {
            dividedByZero = 1;
        }
        QVERIFY(dividedByZero);
    }

    void tooManySpacesTest()
    {
        expression = ExpressionParser::parse("             (+                   137                   14       )");
        int result = expression->count();
        QVERIFY(result == 151);
    }

    void complexExpressionTest()
    {
        expression = ExpressionParser::parse("(/ (+ 26 130) (- 132 (* 18 6)))");
        int result = expression->count();
        QVERIFY(result == 6);
    }

    void complexExpressionTest2()
    {
        expression = ExpressionParser::parse("(- (+ (* 2 4) (/ 9 3)) (/ (* 4 5) 2))");
        int result = expression->count();
        QVERIFY(result == 1);
    }

    void complexExpressionTest3()
    {
        expression = ExpressionParser::parse("(/ (+ 153 (- 137 178)) (- 200 (* 13 16)))");
        int result = expression->count();
        QVERIFY(result == -14);
    }
private:
    IOperand *expression;
};
