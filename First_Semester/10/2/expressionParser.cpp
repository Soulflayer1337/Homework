#include "expressionParser.h"
#include "scanner.h"

enum Token
{
    _end, _begin, _num, _error,
    _sum = '+', _mult = '*',
    _lp = '(', _rp = ')'
};

void missSpaces(int &position)
{
    while (isspace(std::cin.peek()) && std::cin.peek() != '\n')
    {
        position++;
        std::cin.ignore();
    }
}

void error(int position)
{
    for (int i = 1; i < position; i++)
        std::cout << " ";
    std::cout << char(30) << std::endl;
}

bool expr(Token &currentToken, int &position);

// fact()->ident|(expr())
bool fact(Token &currentToken, int &position)
{
    char symb = 0;
    position++;
    switch (std::cin.get())
    {
    // fact() -> (expr())
    case '(':
    {
        currentToken = _lp;

        if (!expr(currentToken, position))
            return false;

        position++;
        if ((symb = std::cin.get()) != ')')
        {
            std::cin.unget();
            error(position);
            std::cout << "Error: expected ')' before ";
            if (scanDouble(position))
                std::cout << "numeric constant found\n";
            else if (std::cin.peek() == '\n')
                std::cout << " newline found\n";
            else
                std::cout << " '" << symb << "'" << " found\n";
            currentToken = _error;
            return false;
        }

        currentToken = _rp;
        missSpaces(position);
        return true;
    }
    // fact() -> ident
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case'8': case '9': case '+': case '-':
    {
        std::cin.unget();
        position--;
        if (!scanDouble(position))
        {
            error(position);
            std::cout << "Error: numeric constant is incorrect! ";
            if (std::cin.peek() != '\n')
                std::cout << "'" << char(std::cin.get()) << "'";
            else
                std::cout << "newline";
            std::cout << " found\n";
            currentToken = _error;
            return false;
        }

        missSpaces(position);
        currentToken = _num;
        return true;
    }
    // Pointer reached newline
    case '\n':
    {
        error(position);
        std::cout << "Error: expected primary-expression before reached newline\n";
        currentToken = _error;
        return false;
    }
    // Any other symbols at this point is a syntax error
    default:
    {
        error(position);
        std::cin.unget();
        std::cout << "Error: expected '(' or numeric constant before " << char(std::cin.get()) << " found\n";
        currentToken = _error;
        return false;
    }
    }
}

// term'()->(*|/)fact()term'()|eps
bool term2(Token &currentToken, int &position)
{
    char symb = std::cin.get();

    if (symb == '*' || symb == '/')
    {
        position++;
        currentToken = _mult;
        missSpaces(position);

        if (!fact(currentToken, position))
            return false;

        return term2(currentToken, position);
    }

    std::cin.unget();
    return true;
}

// term()->fact()term'()
bool term(Token &currentToken, int &position)
{
    if (!fact(currentToken, position))
        return false;
    return term2(currentToken, position);
}

// expr'()->(+|-)term()expr'()|eps
bool expr2(Token &currentToken, int &position)
{
    position++;
    switch (std::cin.get())
    {
    case '+': case '-':
    {
        currentToken = _sum;
        missSpaces(position);

        if (!term(currentToken, position))
            return false;

        return expr2(currentToken, position);
    }
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    {
        error(position);
        std::cout << "Error: expected operator before numeric constant found\n";
        currentToken = _error;
        return false;
    }
    case '\n':
        currentToken = _end;
    case ')':
    {
        std::cin.unget();
        position--;
        return true;
    }
    default:
    {
        error(position);
        std::cin.unget();
        std::cout << "Error: expected operator before '" << char(std::cin.get()) << "' found\n";
        currentToken = _error;
        return false;
    }
    }
}

// expr()->term()expr'()
bool expr(Token &currentToken, int &position)
{
    missSpaces(position);
    if (!term(currentToken, position))
        return false;
    return expr2(currentToken, position);
}

bool scanExpression()
{
    Token currentToken = _begin;
    int position = 0;
    expr(currentToken, position);

    if (currentToken == _end)
        std::cout << "No errors found\n";

    return (currentToken == _end);
}
