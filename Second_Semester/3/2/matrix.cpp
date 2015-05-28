#include "matrix.h"

Matrix::Matrix(unsigned int _width) : Matrix(_width, _width)
{
}

Matrix::Matrix(unsigned int _width, unsigned int _height) : width(_width), height(_height), matrix(new int*[_height])
{
    for (unsigned int i = 0; i < _height; i++)
        matrix[i] = new int[_width];
}

void Matrix::readMatrix(std::istream &stream)
{
    for (unsigned int i = 0; i < height; i++)
        for (unsigned int j = 0; j < width; j++)
            stream >> matrix[i][j];
}

int Matrix::element(unsigned int i, unsigned int j)
{
    return (i > height || j > width ? 0 : matrix[i][j]);
}

Matrix::~Matrix()
{
    for (unsigned int i = 0; i < height; i++)
        delete[] matrix[i];
    delete[] matrix;
}
