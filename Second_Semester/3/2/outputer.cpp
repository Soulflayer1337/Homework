#include "outputer.h"

int *Outputer::makeOutputArray(Matrix *matrix, int size)
{
    int *array = new int[size * size];
    int iterator = 0;
    array[iterator++] = matrix->element(size / 2, size / 2);

    for (int border = size / 2 - 1; border >= 0; border--)
    {
        int i = border;
        int j = border;

        while (i + 1 < size - border)
            array[iterator++] = matrix->element(++i, j);

        while (j + 1 < size - border)
            array[iterator++] = matrix->element(i, ++j);

        while (i > border)
            array[iterator++] = matrix->element(--i, j);

        while (j > border)
            array[iterator++] = matrix->element(i, --j);
    }

    return array;
}
