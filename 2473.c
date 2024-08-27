#include <stdio.h>

int main() {
    int i, j, cont, n[6], s[6];

    cont = 0;

    // Lê os seis números escolhidos pelo usuário
    scanf("%d %d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4], &n[5]);

    // Lê os seis números sorteados
    scanf("%d %d %d %d %d %d", &s[0], &s[1], &s[2], &s[3], &s[4], &s[5]);

    // Verifica quantos números escolhidos estão entre os sorteados
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (n[i] == s[j]) {
                cont++;
                break; // Evita contar o mesmo número mais de uma vez
            }
        }
    }

    // Imprime o resultado de acordo com a quantidade de acertos
    if (cont == 3)
        printf("terno\n");
    else if (cont == 4)
        printf("quadra\n");
    else if (cont == 5)
        printf("quina\n");
    else if (cont == 6)
        printf("sena\n");
    else
        printf("azar\n");

    return 0;
}
