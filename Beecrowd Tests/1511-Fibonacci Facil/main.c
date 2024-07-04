#include <stdio.h>
#include <math.h>

int fibonacci(int n);

int main()
{
    int n, i, j;
    scanf("%i", &n);

    for (i = 0; i < n; i++)
    {
        if (i <= (n - 2))
            printf("%i ", fibonacci(i));
        else
            printf("%i", fibonacci(i));
    }
    return 0;
}
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}