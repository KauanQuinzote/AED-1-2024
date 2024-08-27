#include <stdio.h>

int main(void) {

    int i, n;
    char quest[100][100]; // Array para armazenar múltiplas strings

    // Lê o número de perguntas
    scanf("%d", &n);

    // Lê cada string e imprime a mensagem correspondente
    for (i = 0; i < n; i++) {
        scanf("%s", quest[i]); // Lê uma string e armazena no array

        // A condição `if(1)` é sempre verdadeira
        printf("I am Toorg!\n");
    }

    return 0;
}
