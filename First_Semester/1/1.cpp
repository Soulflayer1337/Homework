#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");  //Возможность вывода русского языка в консоли.
    printf("Вас приветствует программа, вычисляющая значение формулы x^4+x^3+x^2+x за два умножения.\nВведите, пожалуйста, x: ");
    int x = 0;
    scanf("%d", &x);
    int y = x * x;
    int ans = (y + x) * (y + 1);
    printf("Значение формулы: %d", ans);
    return 0;
}
