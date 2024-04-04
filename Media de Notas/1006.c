#include <stdio.h>

int main(void)
{
    float a, b, c, media;

    scanf("%f %f %f", &a, &b, &c);

    media = ((a * 2) + (b * 3) + (c * 5))/10;

    printf("MEDIA = %.1f\n", media);
}