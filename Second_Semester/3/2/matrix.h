#pragma once

class Matrix
{
public:
    Matrix(unsigned int _width);
    Matrix(unsigned int _height, unsigned int _width);

    ~Matrix();

    void readMatrix();

    int element(unsigned int i, unsigned int j);
private:
    unsigned int width;
    unsigned int height;
    int **matrix;
};
