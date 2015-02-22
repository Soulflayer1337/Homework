#include <cstdio>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ���������, �������� ������ ������ ������ ��� �������� m � n.\n������� ���������� ������ n: ");
    int n = 0;
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("n ������ ���� �������������, ������� n ��� ���: ");
        scanf("%d", &n);
    }

    printf("������� ������ m: ");
    int m = 0;
    scanf("%d", &m);

    while (m <= 0)
    {
        printf("m ������ ���� �������������, ������� m ��� ���: ");
        scanf("%d", &m);
    }

    List *list = createList(n);
    printf("��������� �������� ����: %d\n\n", suicide(list, m));
    deleteList(list);
    return 0;
}
