#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ��������� ���������� ��������� �������� �� ������� a �� b.\n������� ������� a: ");
    int a = 0;
    scanf("%d", &a);
    printf("������� �������� b: ");
    int b = 0;
    scanf("%d", &b);
    int ans = 0;
    while(a >= b)
    {
        a -= b;
        ans++;
    }
    printf("�������� ������� �� �������: %d\n", ans);
    return 0;
}
