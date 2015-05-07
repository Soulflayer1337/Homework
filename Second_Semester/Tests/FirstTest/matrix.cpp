#include "matrix.h"

Matrix::Matrix(unsigned int _size) : matrix (new int*[_size])
{
    for (unsigned int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

int &Matrix::element(unsigned int i, unsigned int j)
{
    if (i > size || j > size)
        throw OutOfRangeException();

    return matrix[i][j];
}

Matrix::~Matrix()
{
    for (unsigned int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}
