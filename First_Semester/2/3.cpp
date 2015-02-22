#include <cstdio>
#include <locale.h>

void remain(int rest, int numb[], int &sizeOfArray, int last)
{
    if (rest == 0)
    {
        printf("%d", numb[0]);

        for (int i = 1; i < sizeOfArray; i++)
            printf(" %d", numb[i]);

        printf("\n");
        return;
    }

    for (int i = (rest > last ? last : rest); i > 0; i--)
    {
        numb[sizeOfArray++] = i;
        remain(rest - i, numb, sizeOfArray, i);
        sizeOfArray--;
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Вас приветствует программа, выводящая число n в виде всех возможных сумм его слагаемых.\nВведите это число: ");
    int n = 0;
    scanf("%d", &n);
    printf("\n");
    int *numb = new int[n];
    int sizeOfArray = 0;

    remain(n, numb, sizeOfArray, n);

    delete[] numb;
    return 0;
}
