#include <cstdio>
#include <locale.h>

#define min(a, b) ((a) > (b) || (a) == 0 ? (b) : (a))

int main()
{
    setlocale(LC_ALL, "Russian");
    const int digNum = 10;

    printf("¬ас приветствует программа, переставл€юща€ цифры исходного числа так, чтобы получилось минимальное число.\n\
¬ведите это число: ");
    int number = 0;
    scanf("%d", &number);

    int digit[digNum] = { };
    int minDig = 10;

    while (number > 0)
    {
        digit[number % digNum]++;
        minDig = min(number % digNum, minDig);
        number /= digNum;
    }

    printf("%d", (minDig < 9 ? minDig : 0));

    digit[minDig]--;

    for (int i = 0; i < digNum; i++)
        for (int j = 0; j < digit[i]; j++)
            printf("%d", i);

    delete[] digit;
    return 0;
}
