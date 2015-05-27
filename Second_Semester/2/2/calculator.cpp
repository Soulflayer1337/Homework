#include "calculator.h"

using std::cin;
using std::cout;

bool isSign(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int operation(char token, int left, int right)
{
    switch (token)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
}

Calculator::Calculator() : stack(nullptr)
{
}

int Calculator::calculate(std::istream &stream, int &error)
{
    error = 0;
    while (std::isspace(stream.peek()))
        stream.ignore();

    while (stream.peek() != '\n')
    {
        char symbol = stream.get();

        if (std::isspace(symbol))
            continue;

        if (isSign(symbol))
        {
            if (stack->isEmpty())
            {
                error = 1;
                return 0;
            }

            int first = stack->pop();

            if (stack->isEmpty())
            {
                error = 1;
                return 0;
            }

            int second = stack->pop();

            if (symbol == '/' && first == 0)
            {
                error = 2;
                return 0;
            }

            stack->push(operation(symbol, second, first));
        }
        else if (std::isdigit(symbol))
        {
            stream.unget();
            int number = 0;
            stream >> number;
            stack->push(number);
        }
        else
        {
            error = 1;
            return 0;
        }
    }

    int ans = 0;

    if (stack->isEmpty())
        error = 3;
    else
    {
        ans = stack->pop();

        if (!stack->isEmpty())
            error = 1;
    }

    return ans;
}

void Calculator::setStack(Stack *stack)
{
    if (this->stack != nullptr)
        delete this->stack;
    this->stack = stack;
}

Calculator::~Calculator()
{
    if (stack != nullptr)
        delete stack;
}
