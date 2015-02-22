#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    const int charNum = 26; //Количество букв английского алфавита. Изначально предполагается, что используются только строчные буквы.

    printf("Вас приветствует программа, проверяющая, возможно ли переставить символы\
 в одной строке так, чтобы получилась вторая.\nВведите размер строки: ");

    int size = 0; //Изначально предполагается, что обе строки имеют одинаковую длину.
    scanf("%d", &size);

    printf("Введите первую строку: ");
    char *firstString = new char[size];
    scanf("%s", firstString);

    printf("Введите вторую строку: ");
    char *secondString = new char[size];
    scanf("%s", secondString);

    int symbol[charNum] = { };

    for (int i = 0; i < size; i++)
    {
        symbol[firstString[i] - 'a']++;
        symbol[secondString[i] - 'a']--;
    }

    bool match = true;

    for (int i = 0; match && (i < charNum); i++)
        match = (symbol[i] == 0);

    delete[] firstString;
    delete[] secondString;
    printf((match ? "Перестановка возможна.\n" : "Перестановка невозможна."));
    return 0;
}
