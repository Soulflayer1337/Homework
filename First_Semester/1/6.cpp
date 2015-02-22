#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, которая найдет количество вхождений s1 в s, как подстроки.\nВведите размер строки s: ");
    int size = 0;
    scanf("%d", &size);
    printf("Введите размер подстроки s1: ");
    int subSize = 0;
    scanf("%d", &subSize);
    printf("Введите строку s: ");
    char *string = new char[size];
    scanf("%s", string);
    printf("Введите подстроку s1: ");
    char *subString = new char[subSize];
    scanf("%s", subString);

    int answer = 0;
    for (int i = 0; i <= size - subSize; i++)
    {
        bool isSubstring = true;
        for(int j = 0; isSubstring && j <= subSize; j++)
            isSubstring = (subString[j] == '\0' || (string[i + j] == subString[j]));
        answer += isSubstring;
    }
    printf("Количество вхождений подстроки в строку: %d\n", answer);
    delete[] string;
    delete[] subString;
    return 0;
}
