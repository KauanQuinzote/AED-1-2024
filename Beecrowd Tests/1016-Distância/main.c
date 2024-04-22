#include <stdio.h>

int velocity(int time, int x);

int main()
{
    int time = 0, x, result;

    scanf("%i", &time);
    x = time;
    result = velocity(time, x);

    printf("%i minutos\n", result);

    return 0;
}

int velocity(int time, int x)
{
    if (time == x*2)
    {
        return time;
    }
    else
    {
        ++time;
        return velocity(time, x);
    }
}