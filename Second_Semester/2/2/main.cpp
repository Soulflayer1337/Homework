#include <iostream>
#include "calculator.h"
#include "linkedstack.h"
#include "arraystack.h"

using std::cin;
using std::cout;

int main()
{
    cout << "Enter:\n'1' - to use LinkedStack\n'2' - to use ArrayStack\nEnter anything else to exit the program.\n";
    int option = 0;
    cin >> option;

    Calculator *calculator = new Calculator;

    switch (option)
    {
    case 1:
    {
        calculator->setStack(new LinkedStack);
        break;
    }
    case 2:
    {
        calculator->setStack(new ArrayStack);
        break;
    }
    default:
        return 0;
    }

    cout << "Enter an expression using Reverse Polish Notation: ";
    calculator->calculate();

    delete calculator;
    return 0;
}
