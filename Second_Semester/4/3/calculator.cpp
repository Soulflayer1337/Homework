#include "calculator.h"

Calculator::Calculator() : leftOperand(0), sign('=')
{
}

Calculator::~Calculator()
{
}

double Calculator::count(const double rightOperand, const char newSign)
{
    switch (sign)
    {
    case '+':
    {
        leftOperand += rightOperand;
        break;
    }
    case '-':
    {
        leftOperand -= rightOperand;
        break;
    }
    case '*':
    {
        leftOperand *= rightOperand;
        break;
    }
    case '/':
    {
        if (rightOperand == 0)
            throw DividedByZero();

        leftOperand /= rightOperand;
        break;
    }
    case '=':
    {
        leftOperand = rightOperand;
        break;
    }
    }

    sign = newSign;
    return leftOperand;
}

double Calculator::result() const
{
    return leftOperand;
}
