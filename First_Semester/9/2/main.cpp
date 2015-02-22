#include "MyString.h"

typedef unsigned int uint;

uint hash(MyString string, const uint base, const uint mod, int length = -1)
{
    if (length == -1)
        length = string.length();

    uint rValue = 0;
    uint exp = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        rValue = (rValue + (string[i] + 1) * exp) % mod;
        exp = (exp * base) % mod;
    }

    return rValue;
}

int searchRabinKarp(MyString string, MyString substring)
{
    if (string.length() < substring.length())
        return -1;

    const uint base = 127;
    const uint mod = 1046527;
    int expBase = 1;
    int place = 0;

    for (uint i = 1; i < substring.length(); i++)
        expBase = (expBase * base) % mod;

    int substringHash = hash(substring, base, mod);
    int stringHash = hash(string, base, mod, substring.length());


    for (uint i = 0; i + substring.length() <= string.length(); i++)
    {
        if (stringHash == substringHash)
        {
            bool equal = true;
            for (uint j = 0; equal && (j < substring.length()); j++)
                equal = (string[j + i] == substring[j]);

            if (equal)
            {
                place = i + 1;
                break;
            }
        }

        stringHash -= (expBase * (string[i] + 1)) % mod;

        if (stringHash < 0)
            stringHash += mod;

        if (i + substring.length() != string.length())
            stringHash = (stringHash * base + string[i + substring.length()] + 1) % mod;

    }

    return place;
}

int main()
{
    std::cout << "Enter the string: ";
    MyString string;
    std::cin >> string;
    std::cout << "Enter the substring: ";
    MyString substring;
    std::cin >> substring;

    int place = searchRabinKarp(string, substring);

    if (place != 0)
        std::cout << "The first letter of the substring is on " << place << std::endl;
    else
        std::cout << "The substring doesn't exist.\n";

    return 0;
}
