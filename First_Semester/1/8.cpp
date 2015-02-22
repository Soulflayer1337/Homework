#include <cstdio>
#include <locale.h>

int countFactorial(int n)
{
    return (n > 1? n * countFactorial(n - 1): 1);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветсвует программа подсчета факториала.\nВведите число, факториал которого нужно сосчитать: ");
    int n = 0;
    scanf("%d", &n);
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;

    printf("Факториал, подсчитанный рекурсивно: %d\nФакториал, подсчитанный итеративно: %d\n", countFactorial(n), factorial);
    return 0;
}
