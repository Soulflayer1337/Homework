#pragma once

class OutOfRangeException
{
};

/**
 * @brief The Matrix class - wrapper class for the matrix
 */
class Matrix
{
public:
    /**
     * @brief Matrix - constructor for square matrix
     * @param _size - the number of rows and columns of the matrix
     */
    Matrix(unsigned int _size);

    ~Matrix();

    /**
     * @brief element - returns the value of an element from i row and j column
     * @return - value of the element or zero if outside array bounds.
     */
    int &element(unsigned int i, unsigned int j);
private:
    /**
     * @brief width - the number of rows and columns of the matrix
     */
    unsigned int size;
    /**
     * @brief matrix - the matrix
     */
    int **matrix;
};
