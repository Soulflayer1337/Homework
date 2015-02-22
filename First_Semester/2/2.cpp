#include <cstdio>
#include <locale.h>

int sqr(int x)
{
    return x * x;
}

int exp(int ex, int &number)
{
    int multipler = ex % 2 * number;
    if (multipler == 0)
        multipler = 1;
    return (ex == 0 ? 1 : (sqr(exp(ex / 2, number)) * multipler));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("¬ас приветствует программа, считающа€ степень числа за O(log n).\n¬ведите число, которое нужно возвести в степень: ");
    int number = 0;
    scanf("%d", &number);
    printf("¬ведите степень числа: ");
    int ex = 0;
    scanf("%d", &ex);
    printf("„исло %d в степени %d = %d\n", number, ex, exp(ex, number));
    return 0;
}
