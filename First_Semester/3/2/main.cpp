#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    const int charNum = 26; //���������� ���� ����������� ��������. ���������� ��������������, ��� ������������ ������ �������� �����.

    printf("��� ������������ ���������, �����������, �������� �� ����������� �������\
 � ����� ������ ���, ����� ���������� ������.\n������� ������ ������: ");

    int size = 0; //���������� ��������������, ��� ��� ������ ����� ���������� �����.
    scanf("%d", &size);

    printf("������� ������ ������: ");
    char *firstString = new char[size];
    scanf("%s", firstString);

    printf("������� ������ ������: ");
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
    printf((match ? "������������ ��������.\n" : "������������ ����������."));
    return 0;
}
