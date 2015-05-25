#include "divisionoperator.h"
#include <iostream>
#include "../../../Some_Useful_Things/Exceptions/dividedbyzero.h"

DivisionOperator::DivisionOperator(IOperand *leftOperand, IOperand *rightOperand) : Operator(leftOperand, rightOperand)
{
}

DivisionOperator::~DivisionOperator()
{
}

void DivisionOperator::print() const
{
    std::cout << "(/ ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << ")";
}

ll DivisionOperator::count() const
{
    ll rightOperand = right->count();

    if (!rightOperand)
        throw DividedByZeroException();

    return (left->count() / rightOperand);
}


