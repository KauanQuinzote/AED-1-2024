#include <stdio.h>
#include <math.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;

}Node;

int recursive_sum(int v[], int n)
{
    if (n == 0)
        return 0;
    else
        return v[n - 1] + recursive_sum(v, n - 1);
}
int major(int w[], int n)
{
    int x;
    if (n == 1)
        return w[0];

    else
    {
        x = major(w, n - 1);

        if (x > w[n - 1])
            return x;
        else
            return w[n - 1];
    }
}

int progression(int v[], int n)
{
    if (n == 0)
        return 1;

    else
        return v[n - 1] * progression(v, n - 1);
}

int fatorial(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return x * fatorial(x - 1);
}

int main(void) {
    int test_nbr = 12;

    printf("recursive: %d\n", fibonacci(test_nbr));
    return 0;
}
int main()
{
    int v[3] = {3, 4, 12}, x;

    x = recursive_sum(v, 3);

    printf("%i\n", x);

    printf("%i\n", major(v, 3));

    printf("%i\n", progression(v, 3));

    printf("%i\n", fatorial(4));

    return 0;
}
