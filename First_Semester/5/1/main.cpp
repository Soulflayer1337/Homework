#include <cstdio>
#include <string.h>

void moreMemory(char **word, int &size)
{
    char *newArray = new char[size + 10];

    memcpy(newArray, (*word), size);

    delete[] word;

    size += 10;
    (*word) = newArray;
}

bool isLowercase(char &symb)
{
    return (symb >= 'a' && symb <= 'z');
}

bool isUppercsase(char &symb)
{
    return (symb >= 'A' && symb <= 'Z');
}

bool isLetter(char &symb)
{
    return (isLowercase(symb) || isUppercsase(symb));
}

char *readWord(FILE *file)
{
    int size = 10;
    char *word = new char[size];

    int it = 0;
    char symb = '\0';

    do
    {
        fscanf(file, "%c", &symb);
        if  (isLetter(symb))
        {
            if (it + 1 == size)
                moreMemory(&word, size);

            word[it++] = symb;
        }
    }
    while (!feof(file) && isLetter(symb));

    word[it] = '\0';

    if (it == 0)
    {
        delete[] word;
        word = nullptr;
    }

    return word;
}

void writeWord(char *word)
{
    const int count = 26;
    bool lowercase[count] = { };
    bool uppercase[count] = { };

    int it = 0;

    while (word[it] != '\0')
    {
        if (isLowercase(word[it]) && !lowercase[word[it] - 'a'])
        {
            printf("%c", word[it]);
            lowercase[word[it] - 'a'] = true;
        }
        else if (isUppercsase(word[it]) && !uppercase[word[it] - 'A'])
        {
            printf("%c", word[it]);
            uppercase[word[it] - 'A'] = true;
        }
        it++;
    }

    printf("\n");
}

int main()
{
    FILE *file;

    file = fopen("input.txt", "r");

    if (file == NULL)
        printf("There is no file in here!");
    else
        while (!feof(file))
        {
            char *word = readWord(file);

            if (word != nullptr)
            {
                writeWord(word);
                delete[] word;
            }
        }

    fclose(file);
    return 0;
}
