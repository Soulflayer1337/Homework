#pragma once
#include "matrix.h"

/**
 * @brief The Outputer class - Abstract type for spiral output
 */
class Outputer
{
public:
    /**
     * @brief output - Outputs the content of the array in the spiral order
     * @param matrix - Matrix for output
     * @param size - Width of the matrix
     */
    virtual void output(Matrix *matrix, int size) = 0;
protected:
    /**
     * @brief makeOutputArray - Creates an output array
     * @param matrix - Matrix for output
     * @param size - Width of the matrix
     * @return - Returns the array of the elements of the spiral
     */
    int *makeOutputArray(Matrix *matrix, int size);
};
