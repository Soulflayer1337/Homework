#include <cstdio>
#include <locale.h>
#include "stack.h"

bool isNumber(char symb)
{
    return (symb <= '9' && symb >= '0');
}

bool secondPriority(char symb)
{
    return (symb == '*' || symb == '/');
}

bool firstPriority(char symb)
{
    return (symb == '+' || symb == '-');
}

bool isOpened(char symb)
{
    return symb == '(';
}

bool isClosed(char symb)
{
    return symb == ')';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, преобразующая выражения инфиксной формы в выражения постфиксной формы!\n\
Символы, не соответствующие задаче будут проигнорированы.\nПри неверной расстановке скобок, программа может работать некорректно.\nВведите строку, в конце нажмите Enter: ");

    bool error = false;
    Stack<char> *stack = createStack<char>();
    char symb = ' ';

    do
    {
        scanf("%c", &symb);

        if (isNumber(symb))
            printf("%c ", symb);
        else if (secondPriority(symb) || isOpened(symb))
            push(stack, symb);
        else if (firstPriority(symb))
        {
            while (!isEmpty(stack) && (secondPriority(topElement(stack))))
                printf("%c ", pop(stack));
            push(stack, symb);
        }
        else if (isClosed(symb))
        {
            while (!isEmpty(stack) && !isOpened(topElement(stack)))
                printf("%c ", pop(stack));

            if (!isEmpty(stack))
                pop(stack);
            else
                error = true;
        }
    }
    while (symb != '\n');

    while (!isEmpty(stack))
        if (!isClosed(topElement(stack) && !isOpened(topElement(stack))))
            printf("%c ", pop(stack));
        else {
            error = true;
            pop(stack);
        }

    if (error)
        printf("\nВ вашей формуле была нарушена последовательность скобок.\
 Из-за этого некоторые скобки были проигнорированны и предполагаемый порядок операций был нарушен.");

    deleteStack(stack);
    return 0;
}
