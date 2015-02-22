#include <cstdio>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, решающая задачу Иосифа Флавия для заданных m и n.\nВведите количество воинов n: ");
    int n = 0;
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("n должно быть положительным, введите n еще раз: ");
        scanf("%d", &n);
    }

    printf("Введите период m: ");
    int m = 0;
    scanf("%d", &m);

    while (m <= 0)
    {
        printf("m должно быть положительным, введите m еще раз: ");
        scanf("%d", &m);
    }

    List *list = createList(n);
    printf("Последний выживший воин: %d\n\n", suicide(list, m));
    deleteList(list);
    return 0;
}
