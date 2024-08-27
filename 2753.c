#include <stdio.h>
#define X 26

int main() {
    int vet[X], i = -1, a = 97;  // Array vet e variáveis i e a (código ASCII de 'a')

    // Preenche vet com valores ASCII de 'a' a 'z'
    while (++i < X)
        vet[i] = a++;

    i = -1;
    // Imprime valores e caracteres
    while (++i < X)
        printf("%i e %c\n", vet[i], vet[i]);

    return 0;
}

