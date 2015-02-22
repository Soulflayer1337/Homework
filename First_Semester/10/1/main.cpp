
#include "scanner.h"

int main()
{
    std::cout << "This program is a scanner of the floating-point numbers.\nEnter the number: ";
    std::cout << (scanDouble() ? "Entered number is a floating-point number.\n" : "Entered number isn't a floating-point number.\n");
    return 0;
}
