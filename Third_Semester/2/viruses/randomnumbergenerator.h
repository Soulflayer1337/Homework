#pragma once

#include "inumbergenerator.h"

class RandomNumberGenerator : public INumberGenerator
{
public:
    RandomNumberGenerator();
    int getNumber() override;
};
