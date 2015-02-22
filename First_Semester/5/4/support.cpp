#include <cstdio>
#include "support.h"

void moreMemory(char **string, int &size)
{
    char *newString = new char[size + 10];

    for (int i = 0; i < size; i++)
        newString[i] = (*string)[i];

    delete[] (*string);
    size += 10;
    (*string) = newString;
}

bool isTheSame(char *first, char *second)
{
    bool different = false;

    if (first != nullptr && second != nullptr)
    {
        int it = -1;

        do
        {
            it++;
            different = (first[it] != second[it]);
        }
        while (first[it] != '\0' && second[it] != '\0' && !different);
    }
    else
        different = (first != second);

    return !different;
}

char *readUntil(char lastSymbol, FILE *file)
{
    int size = 10;
    int it = 0;
    char *string = new char[size];
    char symb = lastSymbol - 1;

    while ((file == nullptr || !feof(file)) && (symb != lastSymbol))
    {
        if (file != nullptr)
            fscanf(file, "%c", &symb);
        else
            scanf("%c", &symb);

        if (symb != lastSymbol)
        {
            if (it + 1 == size)
                moreMemory(&string, size);
            string[it++]= symb;
        }
    }

    string[it] = '\0';

    if (it == 0)
    {
        delete[] string;
        string = nullptr;
    }

    return string;
}
