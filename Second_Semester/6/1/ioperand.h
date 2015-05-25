#pragma once

typedef long long ll;

/**
 * @brief The IOperand class - interface for operations and operands
 */
class IOperand
{
public:
    virtual ~IOperand() {}

    /**
     * @brief print - prints out the expression
     */
    virtual void print() const = 0;
    /**
     * @brief count - counts the expression
     */
    virtual ll count() const = 0;
};
