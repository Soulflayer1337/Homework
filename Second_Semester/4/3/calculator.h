#pragma once

/**
 * @brief The DividedByZero class used for exception.
 */
class DividedByZero
{
};

/**
 * @brief The Calculator class - a simple calculator class.
 */
class Calculator
{
public:
    Calculator();
    ~Calculator();

    /**
     * @brief count - counts the expression and writes result to leftOperand.
     * @param rightOperand - right operand of the expression.
     * @param newSign - the new sign. It'll replace the sign.
     * @return result of the epxression.
     */
    double count(const double rightOperand, const char newSign);
    /**
     * @brief result - returns the reults of the last expression.
     */
    double result() const;
private:
    /**
     * @brief leftOperand - contains the last result of the last expression. It's also a left operand of the next expression.
     */
    double leftOperand;
    /**
     * @brief sign - the sign of the next expression.
     */
    char sign;
};
