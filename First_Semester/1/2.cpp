#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа нахождения неполного частного от деления a на b.\nВведите делимое a: ");
    int a = 0;
    scanf("%d", &a);
    printf("Введите делитель b: ");
    int b = 0;
    scanf("%d", &b);
    int ans = 0;
    while(a >= b)
    {
        a -= b;
        ans++;
    }
    printf("Неполное частное от деления: %d\n", ans);
    return 0;
}
