#pragma once
#include "operator.h"

/// @brief The DivisionOperator class - the Node for division
class DivisionOperator : public Operator
{
public:
    DivisionOperator(IOperand *leftOperand, IOperand *rightOperand);
    ~DivisionOperator();

    void print() const;
    ll count() const;
};
