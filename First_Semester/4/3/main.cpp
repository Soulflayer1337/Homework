#include <cstdio>
#include <locale.h>
#include "stack.h"

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

bool isNumber(char x)
{
    return (x >= '0' && x <= '9');
}

bool isOperation(char x)
{
    return (x == '*' || x == '/' || x == '+' || x == '-');
}

int charToInt(char x)
{
    return x - '0';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, вычисляющая значения выражения в постфиксной записи.\n\
Символы, отличающиеся от Введите выражение, которое нужно посчитать: ");

    bool error = false;
    bool dividedByZero = false;

    Stack<int> *stack = createStack<int>();

    char symb = 'x';

    do
    {
        scanf("%c", &symb);

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
    while (!dividedByZero && !error && symb != '\n');

    if (dividedByZero)
        printf("Деление на 0! Вы погубили нас!");
    else if (error)
        printf("В вашем выражении допущена ошибка, из-за которой его невозможно вычислить.\n");
    else
        printf("Ответ на выражение: %d\n", pop(stack));

    deleteStack(stack);
    return 0;
}
