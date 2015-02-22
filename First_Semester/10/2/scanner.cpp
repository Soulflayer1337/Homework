#include "scanner.h"

enum Status{_error, _begin, _numSign, _intDig, _fracBegin, _fracDig, _expBegin, _expSign, _expDig, _end};

bool isSeparator(char symb)
{
    return (symb != '\n' && isspace(symb));
}

bool isSign(char symb)
{
    return (symb == '+' || symb == '-');
}

void move(Status &state, char symb)
{
    switch(state)
    {
    case _begin:
    {
        if (isSeparator(symb))
            break;
        if (isSign(symb))
        {
            state = _numSign;
            break;
        }
    }
    case _numSign:
    {
        if (isdigit(symb))
        {
            state = _intDig;
            break;
        }

        state = _error;
        break;
    }
    case _intDig:
    {
        if (isdigit(symb))
            break;
        if (symb == '.')
        {
            state = _fracBegin;
            break;
        }
        if (symb == 'E' || symb == 'e')
        {
            state = _expBegin;
            break;
        }
        state = _end;
        break;
    }
    case _fracBegin:
    {
        if (isdigit(symb))
        {
            state = _fracDig;
            break;
        }
        state = _error;
        break;
    }
    case _fracDig:
    {
        if (isdigit(symb))
            break;
        if (symb == 'E' || symb == 'e')
        {
            state = _expBegin;
            break;
        }
        state = _end;
        break;
    }
    case _expBegin:
    {
        if (isSign(symb))
        {
            state = _expSign;
            break;
        }
    }
    case _expSign:
    {
        if (isdigit(symb))
        {
            state = _expDig;
            break;
        }
        state = _error;
        break;
    }
    case _expDig:
    {
        if (isdigit(symb))
            break;

        state = _end;
        break;
    }
    default:
        break;
    }
}

bool scanDouble(int &position)
{
    char symb = 0;
    Status state = _begin;

    while ((state != _end) && (state != _error))
    {
        position++;
        std::cin.get(symb);
        move(state, symb);
    }

    position--;
    std::cin.unget();
    //std::cout << "scanDouble " << char(std::cin.peek()) << "\n";
    return (state == _end);
}
