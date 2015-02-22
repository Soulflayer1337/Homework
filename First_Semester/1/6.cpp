#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ���������, ������� ������ ���������� ��������� s1 � s, ��� ���������.\n������� ������ ������ s: ");
    int size = 0;
    scanf("%d", &size);
    printf("������� ������ ��������� s1: ");
    int subSize = 0;
    scanf("%d", &subSize);
    printf("������� ������ s: ");
    char *string = new char[size];
    scanf("%s", string);
    printf("������� ��������� s1: ");
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
    printf("���������� ��������� ��������� � ������: %d\n", answer);
    delete[] string;
    delete[] subString;
    return 0;
}
