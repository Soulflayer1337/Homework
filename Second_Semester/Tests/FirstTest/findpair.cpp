#include "findpair.h"
#include "cstdio"
#include "cstdlib"
#include "ctime"

FindPair::FindPair(unsigned int size) : matrix(new Matrix(size)) , numberOfPairs(0)
{
    srand(time(NULL));

    if (size < 2)
    {
        delete matrix;
        throw NotAllowedSizeException();
    }

    int numberOfOne = 0;

    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size; j++)
            numberOfOne += (matrix->element(i, j) = rand() % 2);

    if (size % 2)
    {
        int &middle = matrix->element(size / 2, size / 2);
        numberOfOne -= middle;
        middle = -1;
    }

    if (numberOfOne % 2)
    {
        unsigned int left = rand() % size;
        unsigned int right = rand() % size;

        int &changeable = matrix->element(left, right + (size % 2 && left == size / 2 && right == size / 2));
        changeable = !changeable;
        numberOfOne--;
    }

    numberOfPairs = (size * size) / 2;
}

int FindPair::numberIn(unsigned int row, unsigned int column)
{
    return (matrix->element(row, column));
}

short FindPair::check(unsigned int rowFirst, unsigned int columnFirst, unsigned int rowSecond, unsigned int columnSecond)
{
    int &firstElement = matrix->element(rowFirst, columnFirst);
    int &secondElement = matrix->element(rowSecond, columnSecond);

    if (firstElement != -1 && firstElement == secondElement)
    {
        numberOfPairs--;
        firstElement = secondElement = -1;
        return (1 + (numberOfPairs == 0));
    }
    else
        return 0;
}

FindPair::~FindPair()
{
    delete matrix;
}

