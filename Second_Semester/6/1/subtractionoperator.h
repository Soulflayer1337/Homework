#pragma once
#include "operator.h"

/// @brief The SubstractionOperator class - the Node for subtraction
class SubtractionOperator : public Operator
{
public:
    SubtractionOperator(IOperand *leftOperand, IOperand *rightOperand);
    ~SubtractionOperator();

    void print() const;
    ll count() const;
};
