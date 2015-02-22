#include <cstdio>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int const variation = 28;
    int const maxSize = 1000;
    int vArray[variation] = { };

    for (int i = 0; i < maxSize; i++)
    {
        vArray[(i / 100) + ((i / 10) % 10) + (i % 10)]++;
    }

    int answer = 0;
    for (int i = 0; i < variation; i++)
    {
        answer += vArray[i] * vArray[i];
    }
    printf("Число счастливых билетов: %d\n", answer);
    return 0;
}
