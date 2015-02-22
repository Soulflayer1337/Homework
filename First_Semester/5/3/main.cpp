#include <cstdio>
#include <cstring>

void moreMemory(char **array, int &size)
{
    char *newArray = new char[size + 10];

    memcpy(newArray, (*array), size);

    delete[] (*array);

    size += 10;
    (*array) = newArray;
}

char *getline(FILE *file = nullptr)
{
    int size = 10;
    char *string = new char[size];

    char symb = '\0';
    int it = 0;

    do
    {
        if (file == nullptr)
            scanf("%c", &symb);
        else
            fscanf(file, "%c", &symb);

        if (symb != '\n' && symb != '\0')
        {
            if (it + 1 == size)
                moreMemory(&string, size);

            string[it++] = symb;
        }
    }
    while (symb != '\n' && symb != '\0');

    string[it] = '\0';

    if (it == 0)
    {
        delete[] string;
        string = nullptr;
    }

    return string;
}

void printComment(char *string)
{
    static bool bigCommentary = false;
    bool smallCommentary = false;
    bool quotes1 = false;
    bool quotes2 = false;

    int it = 0;

    while (string[it] != '\0')
    {
        if (smallCommentary)
            printf("%c", string[it]);
        else if (bigCommentary)
        {
            if (it > 0 && string[it - 1] == '*' && string[it] == '/')
                bigCommentary = false;
        }
        else if (quotes1)
        {
            if (string[it] == '\'')
                quotes1 = false;
        }
        else if (quotes2)
        {
            if (string[it] == '"')
                quotes2 = false;
        }
        else if (it > 0 && string[it - 1] == '/')
        {
            if (string[it] == '/') {
                smallCommentary = true;
                printf("//");
            }
            if (string[it] == '*')
                bigCommentary = true;
        }
        else if (string[it] == '\'')
            quotes1 = true;
        else if (string[it] == '"')
            quotes2 = true;

        it++;
    }

    if (smallCommentary)
        printf("\n");
}

int main()
{
    printf("That program will print all c++ comment's from the file.\nEnter file's name: ");
    char *s = nullptr;

    s = getline();

    while (s == nullptr)
    {
        printf("Enter file's name: ");
        s = getline();
    }

    FILE *file = fopen(s, "r");


    if (file == nullptr)
        printf("File not found!\n");
    else
        while (!feof(file))
        {
            char *string = getline(file);

            if (string != nullptr)
            {
                printComment(string);
                delete[] string;
            }
        }

    fclose(file);
    return 0;
}
