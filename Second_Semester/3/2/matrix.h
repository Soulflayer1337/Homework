#pragma once

/**
 * @brief The Matrix class - wrapper class for the matrix
 */
class Matrix
{
public:
    /**
     * @brief Matrix - constructor for square matrix
     * @param _width - the number of rows/columns of the matrix
     */
    Matrix(unsigned int _width);
    /**
     * @brief Matrix - constructor for arbitrary matrix
     * @param _height - the number of rows of the matrix
     * @param _width - the number of columns of the matrix
     */
    Matrix(unsigned int _height, unsigned int _width);

    ~Matrix();

    /**
     * @brief readMatrix - reads matrix
     */
    void readMatrix();

    /**
     * @brief element - returns the value of an element from i row and j column
     * @return - value of the element or zero if outside array bounds.
     */
    int element(unsigned int i, unsigned int j);
private:
    /**
     * @brief width - the number of columns of the matrix
     */
    unsigned int width;
    /**
     * @brief height - the number of rows of the matrix
     */
    unsigned int height;
    /**
     * @brief matrix - the matrix. Who would have thought?
     */
    int **matrix;
};
