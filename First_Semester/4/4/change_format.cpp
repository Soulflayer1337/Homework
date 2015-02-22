#include <cstdio>
#include <clocale>
#include "support.h"
#include "queue.h"
#include "stack.h"
#include "change_format.h"

//Функция, выводящая элемент и убирающая его в стек.
void printPush(Queue<char> *queue, char symb)
{
    if (isNumber(symb) || isOperation(symb))
    {
        push_back(queue, symb);
        printf("%c ", symb);
    }
}

//Функция, преобразовывающая постфиксную запись в инфиксную, использующая алгоритм сортировочной станции Э. Дейкстры
bool postfixToInfix(Queue<char> *expression)
{
    printf("Введите выражение: ");

    Stack<char> *stack = createStack<char>();
    bool error = false;
    char symb = 'x';

    do
    {
        scanf("%c", &symb);

        if (isNumber(symb))
            printPush(expression, symb);
        else if (secondPriority(symb) || isOpened(symb))
            push(stack, symb);
        else if (firstPriority(symb))
        {
            while (!isEmpty(stack) && secondPriority(topElement(stack)))
                printPush(expression, pop(stack));
            push(stack, symb);
        }
        else if (isClosed(symb))
        {
            while (!isEmpty(stack) && !isOpened(topElement(stack)))
                printPush(expression, pop(stack));

            if (!isEmpty(stack))
                pop(stack);
            else
                error = true;
        }
    }
    while (symb != '\n');


    while (!isEmpty(stack))
        if (!isClosed(topElement(stack) && !isOpened(topElement(stack))))
            printPush(expression, pop(stack));
        else {
            error = true;
            pop(stack);
        }

    deleteStack(stack);
    return error;
}
