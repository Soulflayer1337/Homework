#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите размер строки: ");
    int size = 0;
    scanf("%d", &size);
    size += 10;  //Прибавка на случай небольшого недосчета

    printf("Введите строку, состоящую из скобок: ");
    char *str = new char[size];
    scanf("%s", str);

    int balance = 0;
    for (int i = 0; i < size && balance >= 0; i++)
    {
        if (str[i] == '(')
            balance++;
        if (str[i] == ')')
            balance--;
    }
    if (balance)
        printf("Баланс скобок нарушен.\n");
    else
        printf("Баланс скобок не нарушен.\n");

    delete[] str;
    return 0;
}
//1337 |>|_|135
