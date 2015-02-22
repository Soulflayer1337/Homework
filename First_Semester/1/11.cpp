#include <cstdio>
#include <locale.h>

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void quickSort(int left, int right, int forSort[])
{
    if (right == left)
        return;

    int i = left;
    int j = right;
    int middle = forSort[(left + right) / 2];

    //Основной цикл
    while (i <= j)
    {
        while (i <= j && forSort[i] < middle)
            i++;

        while (i <= j && forSort[j] > middle)
            j--;

        if (i > j)
            break;

        if (i != j)
        {
            swap(forSort[i], forSort[j]);
            j--;
        }

        i++;
    }

    quickSort(left, j, forSort);
    quickSort(i, right, forSort);
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //Считывание
    printf("Вас приветствует программа, реализующая алгоритм быстрой сортировки.\nВведите количество чисел: ");
    int n = 0;
    scanf("%d", &n);

    printf("Введите элементы массива: ");

    int *forSort = new int[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &forSort[i]);

    //Алгоритм и вывод
    quickSort(0, n - 1, forSort);

    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++)
        printf("%d ", forSort[i]);

    delete[] forSort;
    return 0;
}
