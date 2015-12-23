#pragma once

#include "inumbergenerator.h"

/// \brief The RandomNumberGenerator class is a random generator
class RandomNumberGenerator : public INumberGenerator
{
public:
    RandomNumberGenerator();
    /// \brief returns random number
    int getNumber() override;
};
