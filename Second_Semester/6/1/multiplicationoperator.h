#pragma once
#include "operator.h"

/// @brief The MultiplicationOperator class - the Node for multiplication
class MultiplicationOperator : public Operator
{
public:
    MultiplicationOperator(IOperand *leftOperand, IOperand *rightOperand);
    ~MultiplicationOperator();

    void print() const;
    ll count() const;
};
