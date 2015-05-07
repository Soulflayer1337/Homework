#pragma once
#include "matrix.h"

class NotAllowedSizeException
{
};

class FindPair
{
public:
    FindPair(unsigned int size);
    short numberIn(unsigned int row, unsigned int column);
    short check(unsigned int rowFirst, unsigned int columnFirst, unsigned int rowSecond, unsigned int columnSecond);
    ~FindPair();
private:
    Matrix *matrix;
    int numberOfPairs;
};
