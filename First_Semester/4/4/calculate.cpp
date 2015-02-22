#include <cstdio>
#include <clocale>
#include "support.h"
#include "stack.h"
#include "queue.h"
#include "calculate.h"

void printAnswer(bool dividedByZero, bool error, Stack<int> *stack)
{
    if (dividedByZero)
        printf("\nDividing by zero! Just don't do it... OK?");
    else if (error)
        printf("\nВ выражение закралась ошибка, из-за которой его невозможно вычислить.\n");
    else
        printf("\nОтвет на выражение: %d\n", pop(stack));
}

//Функция, считающая выражение в постфиксной форме записи.
void countInfix(Queue<char> *expression)
{
    bool error = false;
    bool dividedByZero = false;

    Stack<int> *stack = createStack<int>();

    while (!dividedByZero && !error && !isEmpty(expression))
    {
        char symb = pop(expression);

        if (isNumber(symb))
            push(stack, charToInt(symb));
        else if (isOperation(symb))
        {
            if (isEmpty(stack))
            {
                error = true;
                break;
            }

            int right = pop(stack);

            if (isEmpty(stack))
            {
                error = true;
                break;
            }

            int left = pop(stack);

            if (symb != '/' || right != 0)
                push(stack, newValue(symb, left, right));
            else
                dividedByZero = true;
        }
    }

    printAnswer(dividedByZero, error, stack);

    deleteStack(stack);
}
