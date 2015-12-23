#include "randomnumbergenerator.h"

#include <QtGlobal>

RandomNumberGenerator::RandomNumberGenerator()
{
}

int RandomNumberGenerator::getNumber()
{
    return qrand();
}


