#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, которая определит, является ли введенная вами строка палиндромом.\nВведите размер строки: ");
    int n = 0;
    scanf("%d", &n);

    printf("Введите строку: ");
    char *s = new char[n];

    scanf("%s", s);
    bool isPalindrome = true;

    for (int i = 0; isPalindrome && i * 2 < n; i++)
    {
        isPalindrome = (s[i] == s[n - i]);
    }

    if (isPalindrome)
        printf("Строка не является палиндромом.\n");
    else
        printf("Введенная строка - палиндром.\n");

    delete[] s;
    return 0;
}
