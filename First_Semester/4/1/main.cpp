#include <cstdio>
#include <locale.h>

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d", array[i]);
    printf("\n");
}

void mergeSort(int array[], int n)
{
    if (n == 0)
        return;

    int m = n / 2;

    int *leftArray = new int[m + 1];
    int *rightArray = new int[n - m];

    for (int i = 0; i <= m; i++)
        leftArray[i] = array[i];

    for (int i = m; i < n; i++)
        rightArray[i - m] = array[i + 1];

    mergeSort(leftArray, m);
    mergeSort(rightArray, n - m - 1);

    int i = 0;
    int j = 0;

    while(i + j <= n)
    {
        if ((i > m) || (j < n - m && (leftArray[i] > rightArray[j])))
        {
            array[i + j] = rightArray[j];
            j++;
        }
        else
        {
            array[i + j] = leftArray[i];
            i++;
        }
    }

    delete[] leftArray;
    delete[] rightArray;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Вас приветствует программа, находящая в массиве максимальный элемент, встречающийся более одного раза.\nВведите размер массива: ");
    int n = 0;
    scanf("%d", &n);

    int *array = new int[n];

    printf("Введите содержимое массива: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    mergeSort(array, n - 1);
    int m = array[0] - 1;

    for (int i = n - 1; m < array[0] && i >= 0; i--)
        if (array[i] == array[i - 1])
            m = array[i];

    if (m >= array[0])
        printf("Ответ: %d\n", m);
    else
        printf("Такого числа не существует.\n");

    delete[] array;
    return 0;
}
