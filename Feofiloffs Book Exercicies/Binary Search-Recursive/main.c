#include <stdio.h>

int BuscaBinaria(int x, int n, int v[])
{
    int e, m, d;
    e = -1;
    d = n;
    while (e < d - 1)
    {
        m = (e + d) / 2;
        if (v[m] < x)
            e = m;
        else
            d = m;
    }
    return d;
}

int BinarySearch(int x, int n, int w[])
{
    int e, m, d;

    if (n == 0)
        return w[n];
    else
    {
        e = w;
        d = w + n-1;

        m = (e + d) / 2;

        if (w[m] < x)
            e = m;
        else
            d = m;
        return BinarySearch(x, n, w);
    }
}

int main()
{
    int v[10] = { 1,
                  2,
                  3,
                  4,
                  5,
                  6,
                  7,
                  8,
                  9,
                  10 };

    int *w = v;
    printf("%i\n", BuscaBinária(7, 10, v));
    printf("%i\n", BinarySearch(7, 10, w));
}