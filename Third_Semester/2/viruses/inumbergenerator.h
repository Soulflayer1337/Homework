#pragma once

/// \brief INumberGenerator - an interface for generators.
class INumberGenerator
{
public:
    virtual ~INumberGenerator() {}
    virtual int getNumber() = 0;
};
