#pragma once
#include "ioperand.h"

/// @brief The Operand class - the Node for the number
class Operand : public IOperand
{
public:
    Operand(const ll value);
    ~Operand();

    void print() const;
    ll count() const;
private:
    ll number;
};
