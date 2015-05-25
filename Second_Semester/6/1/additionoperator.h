#pragma once
#include "operator.h"

/// @brief The AdditionOperator class - the Node for addtion
class AdditionOperator : public Operator
{
public:
    AdditionOperator(IOperand *leftOperand, IOperand *rightOperand);
    ~AdditionOperator();

    void print() const;
    ll count() const;
};
