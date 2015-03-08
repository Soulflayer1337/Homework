#pragma once
#include "outputer.h"

/**
 * @brief The FileOutputer class - Writes an array to a file
 */
class FileOutputer : public Outputer
{
public:
    void output(Matrix *matrix, int size);
};
