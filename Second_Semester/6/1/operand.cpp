#include "operand.h"
#include <iostream>

Operand::Operand(const ll value) : number(value)
{
}

Operand::~Operand()
{

}

void Operand::print() const
{
    std::cout << number;
}

ll Operand::count() const
{
    return number;
}

