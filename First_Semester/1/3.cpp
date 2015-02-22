#include <cstdio>
#include <locale.h>

//Inversion array
void reverse(int leftBorder, int size, int x[])
{
    for (int i = 0; i * 2 + 1 < size; i++)
    {
        x[leftBorder + i] = x[leftBorder + i] ^ x[leftBorder + size - i - 1];
        x[leftBorder + size - i - 1] = x[leftBorder + i] ^ x[leftBorder + size - i - 1];
        x[leftBorder + i] = x[leftBorder + i] ^ x[leftBorder + size - i - 1];
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Input(size)

    printf("��� ������������ ���������, �������� ��� ����� ������� ������� ��� ������������� ������� �������.\n������� ������� ������ �����: ");
    int n = 0;
    scanf("%d", &n);
    printf("������� ������� ������ �����: ");
    int m = 0;
    scanf("%d", &m);

    // Input(Array)

    printf("������� �� ������� ��� �������� ��������: ");
    int *x = new int[n + m];
    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &x[i]);
    }

    reverse(0, n, x);
    reverse(n, m, x);
    reverse(0, n + m, x);

    // Output
    printf("���������� �������:\n");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", x[i]);
    }

    delete[] x;
    return 0;
}
