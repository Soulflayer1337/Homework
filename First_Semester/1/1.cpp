#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");  //����������� ������ �������� ����� � �������.
    printf("��� ������������ ���������, ����������� �������� ������� x^4+x^3+x^2+x �� ��� ���������.\n�������, ����������, x: ");
    int x = 0;
    scanf("%d", &x);
    int y = x * x;
    int ans = (y + x) * (y + 1);
    printf("�������� �������: %d", ans);
    return 0;
}
