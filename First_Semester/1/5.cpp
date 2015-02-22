#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("������� ������ ������: ");
    int size = 0;
    scanf("%d", &size);
    size += 10;  //�������� �� ������ ���������� ���������

    printf("������� ������, ��������� �� ������: ");
    char *str = new char[size];
    scanf("%s", str);

    int balance = 0;
    for (int i = 0; i < size && balance >= 0; i++)
    {
        if (str[i] == '(')
            balance++;
        if (str[i] == ')')
            balance--;
    }
    if (balance)
        printf("������ ������ �������.\n");
    else
        printf("������ ������ �� �������.\n");

    delete[] str;
    return 0;
}
//1337 |>|_|135
