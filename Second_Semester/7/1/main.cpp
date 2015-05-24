#include <iostream>

class EzClass
{
public:
    EzClass()
    {
        std::cout << "EzClass was created!\n";
    }

    ~EzClass()
    {
        std::cout << "EzClass was deleted!\n";
    }
};

class ExceptionClass
{
public:
    ExceptionClass()
    {
        std::cout << "Exception was created!\n";
    }
    ~ExceptionClass()
    {
        std::cout << "Exception was deleted!\n";
    }
};

int main()
{
    try
    {
        EzClass ezClass;
        throw ExceptionClass();
    }
    catch (ExceptionClass &)
    {
        std::cout << "Exception block!\n";
    }

    return 0;
}

