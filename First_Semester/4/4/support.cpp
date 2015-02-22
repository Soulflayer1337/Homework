#include "support.h"

//Набор функций, проверяющих принадлежность символа к числам, к операциям и к скобкам.
bool isNumber(char symb)
{
    return (symb >= '0' && symb <= '9');
}

bool isClosed(char symb)
{
    return (symb == ')');
}

bool isOpened(char symb)
{
    return (symb == '(');
}

bool firstPriority(char symb)
{
    return (symb == '+' || symb == '-');
}

bool secondPriority(char symb)
{
    return (symb == '*' || symb == '/');
}

bool isOperation(char symb)
{
    return (secondPriority(symb) || firstPriority(symb));
}

//Функция, считающее значение операции:
int newValue(char symb, int left, int right)
{
    int value = 0;

    if (symb == '+')
        value = left + right;
    else if (symb == '-')
        value = left - right;
    else if (symb == '*')
        value = left * right;
    else
        value = left / right;

    return value;
}

//Функция, переводящая символ в число
int charToInt(char symb)
{
    return (symb - '0');
}
