#include "calculator.h"
#include <iostream>

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

void Calculator::calculate()
{
    while (std::isspace(cin.peek()))
        cin.ignore();

    while (cin.peek() != '\n')
    {
        char symbol = cin.get();

        if (std::isspace(symbol))
            continue;

        if (isSign(symbol))
        {
            if (stack->isEmpty())
            {
                cout << "'" << symbol << "' can't be the first symbol!\n";
                return;
            }

            int first = stack->pop();

            if (stack->isEmpty())
            {
                cout << "Incorrect expression!\n";
                return;
            }

            int second = stack->pop();

            if (symbol == '/' && first == 0)
            {
                //cout << "D1V1D3D 8Y 23R0!\n";
                cout << "|)1\/1|)3|) 8*/ 23|>0!\n";
                return;
            }

            stack->push(operation(symbol, second, first));
        }
        else if (std::isdigit(symbol))
        {
            cin.unget();
            int number = 0;
            cin >> number;
            stack->push(number);
        }
        else
        {
            cout << "Unknown symbol: " << char(symbol) << std::endl;
            return;
        }
    }

    if (stack->isEmpty())
        cout << "No expression!\n";
    else
    {
        int ans = stack->pop();

        if (!stack->isEmpty())
            cout << "Incorrect expression!\n";

        cout << "Answer: " << ans << std::endl;
    }
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
