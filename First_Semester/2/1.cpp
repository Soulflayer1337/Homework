#include <cstdio>
#include <locale.h>

int fib(int n)
{
    return (n > 1 ? fib(n - 1) + fib(n - 2) : 1);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("��� ������������ ���������, �������������� n-�� ����� ������������������ ��������.\n������� n: ");
    int n = 0;
    scanf("%d", &n);
    int fibonachi = 1;

    for (int i = 1, help1 = 1, help2 = 0; i < n; i++)
    {
        help2 = help1;
        help1 = fibonachi;
        fibonachi = help1 + help2;
    }

    printf("\n%d ����� � ������������������ ��������\n���������� - %d \t���������� - %d\n", n, fib(n), fibonachi);
    return 0;
}
