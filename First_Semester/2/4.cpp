#include <cstdio>
#include <locale.h>

struct Fraction
{
    int numerator;
    int denominator;
};

bool check(int numerator, int denominator)
{
    bool simple = (numerator == 1 || (denominator % numerator != 0));

    for (int i = 2; simple && (i * i <= numerator); i++)
        if (numerator % i == 0)
            simple = ((denominator % i != 0) && (denominator % (numerator / i) != 0));

    return simple;
}

void swap(int &l, int &r)
{
    l ^= r;
    r ^= l;
    l ^= r;
}

void swap(Fraction &left, Fraction &right)
{
    if (left.numerator * right.denominator > right.numerator * left.denominator)
    {
        swap(left.numerator, right.numerator);
        swap(left.denominator, right.denominator);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Вас приветствует программа, выводящая все положительные несократимые дроби, меньшие единицы, знаменатель которых не превышает некоторого числа.\n");
    printf("Введите это число: ");
    int n = 0;
    scanf("%d", &n);
    int size = 0;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            size += check(j, i);

    Fraction *array = new Fraction[size];
    int pointer = 0;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (check(j, i))
            {
                array[pointer].numerator = j;
                array[pointer].denominator = i;
                pointer++;
            }

    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            swap(array[j - 1], array[j]);

    printf("\nВсе простые дроби, удовлетворяющие данным условиям в порядке возрастания:\n");

    for (int i = 0; i < size; i++)
        printf("%d/%d ", array[i].numerator, array[i].denominator);

    printf("\n");

    delete[] array;
    return 0;
}
