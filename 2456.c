#include <stdio.h>

int main() {
    int c1, c2, c3, c4, c5;

    // Lê os cinco valores
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);

    // Verifica se os valores estão em ordem crescente
    if (c1 < c2 && c2 < c3 && c3 < c4 && c4 < c5)
        printf("C\n");
    // Verifica se os valores estão em ordem decrescente
    else if (c1 > c2 && c2 > c3 && c3 > c4 && c4 > c5)
        printf("D\n");
    // Caso contrário, imprime "N"
    else
        printf("N\n");

    return 0;
}
