#include <cstdio>
#include <locale.h>

void swap(int &first, int &second)
{
    first ^= second;
    second ^= first;
    first ^= second;
}

void shiftDown(int array[], int n) //n - last element of not sorted array
{
    int element = 0; // parent
    int nextElement = element * 2 + 1; // left child
    while (nextElement <= n)
    {
        if (nextElement < n && array[nextElement + 1] > array[nextElement] && array[nextElement + 1] > array[element])
        {
            swap(array[element], array[nextElement + 1]);
            element = nextElement + 1;
        }
        else
        {
            if (array[element] < array[nextElement])
            {
                swap(array[element], array[nextElement]);
                element = nextElement;
            }
            else
                break;
        }
        nextElement = element * 2 + 1;
    }
    return;
}

void shiftUp(int array[], int n)
{
    while (n != 0 && array[n] > array[(n - 1) / 2])
    {
        swap(array[n], array[(n - 1) / 2]);
        n = (n - 1) / 2;
    }

    return;
}

void heapSort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        shiftUp(array, i);
    }

    for (int i = n - 1; i > 0; )
    {
        swap(array[i], array[0]);
        shiftDown(array, --i);
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("¬ас приветствует программа, реализующа€ алгоритм пирамидальной сортировки!\n¬ведите количество элементов массива: ");
    int n = 0;
    scanf("%d", &n);
    printf("¬ведите элементы массива: ");
    int *array = new int[n];

    heapSort(array, n);

    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
