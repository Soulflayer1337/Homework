#include <cstdio>
#include  <climits>

typedef unsigned long long ull;

bool *decToBin(double decNumber)
{
    const int sizeOfDouble = 64;
    bool *binNumber = new bool[sizeOfDouble];

    for (int i = 0; i < sizeOfDouble; i++)
        binNumber[i] = 0;

    if (decNumber < 0)
    {
        binNumber[0] = 1;
        decNumber = -decNumber;
    }

    int deg = 1023; //2^10 - 1

    {
        while (decNumber >= 2.0)
        {
            decNumber /= 2.0;
            deg++;
        }

        while (decNumber < 1.0)
        {
            decNumber *= 2.0;
            deg--;
        }
    }

    {
        int it = 11;

        while (deg != 0)
        {
            binNumber[it] = deg % 2;
            deg /= 2;
            it--;
        }
    }

    decNumber -= 1.0;

    {
        int it = 12;

        while (it != sizeOfDouble)
        {
            decNumber *= 2;

            if (decNumber >= 1.0)
            {
                decNumber -= 1.0;
                binNumber[it] = true;
            }

            it++;
        }
    }

    return binNumber;
}

ull gcd(ull first, ull second)
{
    while (second != 0)
    {
        first %= second;
        first ^= second;
        second ^= first;
        first ^= second;
    }
    return first;
}

void makeCoprime(ull &first, ull &second)
{
    ull _gcd = gcd(first, second);
    first /= _gcd;
    second /= _gcd;
}

void binToScientific(bool binNumber[])
{
    const int sizeOfDouble = 64;
    printf("Result: %c1.", (binNumber[0] ? '-' : '+'));
    ull mantissa = 0;
    ull degree2_52 = 1;

    for (int i = 12; i < sizeOfDouble; i++) {
        degree2_52 *= 2;
        mantissa = mantissa * 2 + (int)binNumber[i];
    }

    makeCoprime(degree2_52, mantissa);

    {
        ull lim = ULLONG_MAX / 5;

        while (degree2_52 != 1)
        {
            if (lim < mantissa)
                mantissa /= 2;
            else
                mantissa *= 5;

            degree2_52 /= 2;
        }
    }

    int exp = 0;

    for (int i = 1; i < 12; i++)
        exp = exp * 2 + binNumber[i];

    printf("%llu*2^(%d)\n", mantissa, exp - 1023);
}

int main()
{
    printf("This program will write entered number in his scientific notifications.\nEnter a number: ");
    double decNumber = 0;
    scanf("%lf", &decNumber);

    bool *binNumber = decToBin(decNumber);

    binToScientific(binNumber);

    delete[] binNumber;
    return 0;
}
