#pragma once
#include "ioperand.h"

/// @brief The Operator class - the Node for operations
class Operator : public IOperand
{
public:
    Operator(IOperand *leftOperand, IOperand *rightOperand);
    ~Operator();

    virtual ll count() const = 0;
    virtual void print() const = 0;
protected:
    IOperand *left;
    IOperand *right;
};
