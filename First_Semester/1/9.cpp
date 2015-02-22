#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("¬ас приветствует программа, вычисл€юща€ целую степень числа a^n!\n¬ведите, пожалуйста числа a и n: ");
    int a = 0;
    int n = 0;
    scanf("%d %d", &a, &n);
    unsigned int answer = 1;
    for (int i = 0; i < n; i++)
    {
        answer *= a;
    }
    printf("÷ела€ степень числа: %d\n", answer);
    return 0;
}
