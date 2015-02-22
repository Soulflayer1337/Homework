#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ���������, ������� ���������, �������� �� ��������� ���� ������ �����������.\n������� ������ ������: ");
    int n = 0;
    scanf("%d", &n);

    printf("������� ������: ");
    char *s = new char[n];

    scanf("%s", s);
    bool isPalindrome = true;

    for (int i = 0; isPalindrome && i * 2 < n; i++)
    {
        isPalindrome = (s[i] == s[n - i]);
    }

    if (isPalindrome)
        printf("������ �� �������� �����������.\n");
    else
        printf("��������� ������ - ���������.\n");

    delete[] s;
    return 0;
}
