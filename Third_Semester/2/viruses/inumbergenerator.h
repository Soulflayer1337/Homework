#pragma once

class INumberGenerator
{
public:
    virtual ~INumberGenerator() {}
    virtual int getNumber() = 0;
};
