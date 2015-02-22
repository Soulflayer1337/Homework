#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Вас приветствует программа, выводящая спиралью все символы массива размером N*N, где N - нечетное число.\n\
Введите число N: ");

    int n = 0;
    scanf("%d", &n);

    printf("Введите массив:\n");

    int *array = new int[n * n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &array[i * n + j]);

    int middle = n / 2;
    printf("Содержимое массива при обходе спиралью:\n%d ", array[n * n / 2]);

    for (int k = 1; k <= middle; k++)
    {
        int i = middle - k;
        int j = middle + k;

        do
        {
            i++;
            printf("%d ", array[i * n + j]);
        }
        while (i < middle + k);

        do
        {
            j--;
            printf("%d ", array[i * n + j]);
        }
        while (j > middle - k);

        do
        {
            i--;
            printf("%d ", array[i * n + j]);
        }
        while (i > middle - k);

        do
        {
            j++;
            printf("%d ", array[i * n + j]);
        }
        while (j < middle + k);
    }

    delete[] array;
    return 0;
}
