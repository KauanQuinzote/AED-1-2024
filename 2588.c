#include <stdio.h>    // Biblioteca para operações de entrada e saída padrão em C
#include <stdlib.h>   // Biblioteca para funções utilitárias padrão em C
#include <string.h>   // Biblioteca para operações com strings em C

#define true 1       // Definição do valor true como 1
#define false 0      // Definição do valor false como 0

int main(int argc, char **argv)
{
    int c[200];        // Array para contar a frequência de cada caractere ASCII estendido
    int i, ans;        // Variáveis para iteração e armazenamento da resposta
    char string[1010]; // Array para armazenar a string de entrada

    while (scanf("%s", string) != EOF)   // Loop enquanto houver entrada para ler
    {
        i = 0;
        memset(c, 0, sizeof(c));   // Inicializa o array de contagem com zeros

        // Loop para contar a frequência de cada caractere na string
        while (string[i])
            c[string[i++]]++;

        // Verifica quantos caracteres têm frequência ímpar
        for (i = 0, ans = 0; i < 200; ++i)
            if (c[i] & 1)
                ++ans;

        // Imprime 0 se houver no máximo 1 caractere com frequência ímpar, senão imprime ans - 1
        printf("%d\n", ans <= 1 ? 0 : ans - 1);
    }

    return 0;   // Retorna 0 para indicar que o programa foi executado com sucesso
}
