#pragma once
#include "outputer.h"

/**
 * @brief The ConsoleOutputer class - Displays array to the console.
 */
class ConsoleOutputer : public Outputer
{
public:
    void output(Matrix *matrix, int size);
};
