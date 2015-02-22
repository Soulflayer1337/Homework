#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, печатающая все простые числа, не превосходящие данное!\nВведите это число: ");
    int n;
    scanf("%d", &n);
    printf("Все простые числа, не превосходящие %d:", n);

    bool *a = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = true;
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i])
        {
            printf(" %d", i);
            for (int j = i * 2; j <= n; j += i)
            {
                a[j] = false;
            }
        }
    }

    delete[] a;
    return 0;
}
