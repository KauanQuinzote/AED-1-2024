#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para encontrar as posições das palavras de busca no texto
void encontrar_posicoes(char *texto, char **palavras, int num_palavras) {
    // Ponteiro para a posição atual no texto
    char *posicao_atual = texto;

    // Loop sobre as palavras de busca
    for (int i = 0; i < num_palavras; i++) {
        // Ponteiro para a primeira ocorrência da palavra no texto
        char *ocorrencia = strstr(posicao_atual, palavras[i]);

        // Se a palavra foi encontrada
        if (ocorrencia != NULL) {
            // Calcula e imprime a posição da palavra
            int posicao = ocorrencia - texto;
            printf("%d", posicao);

            // Procura por outras ocorrências da mesma palavra no texto
            char *proxima_ocorrencia = strstr(ocorrencia + 1, palavras[i]);
            while (proxima_ocorrencia != NULL) {
                // Calcula e imprime a posição da próxima ocorrência
                int posicao_proxima = proxima_ocorrencia - texto;
                printf(" %d", posicao_proxima);
                
                // Encontra a próxima ocorrência da palavra no texto
                proxima_ocorrencia = strstr(proxima_ocorrencia + 1, palavras[i]);
            }

            printf("\n");
        } else {
            // Se a palavra não foi encontrada, imprime -1
            printf("-1\n");
        }
    }
}

int main() {
    // Variáveis para armazenar o texto e as palavras de busca
    char texto[10001];
    int num_palavras;
    char **palavras;

    // Lê o texto
    fgets(texto, sizeof(texto), stdin);

    // Remove a quebra de linha do texto
    texto[strcspn(texto, "\n")] = '\0';

    // Lê o número de palavras de busca
    scanf("%d", &num_palavras);

    // Aloca memória para armazenar as palavras de busca
    palavras = (char **)malloc(num_palavras * sizeof(char *));

    // Lê as palavras de busca
    for (int i = 0; i < num_palavras; i++) {
        palavras[i] = (char *)malloc(51 * sizeof(char)); // 50 caracteres + 1 para o terminador nulo
        scanf("%s", palavras[i]);
    }

    // Encontra e imprime as posições das palavras de busca no texto
    encontrar_posicoes(texto, palavras, num_palavras);

    // Libera a memória alocada para as palavras de busca
    for (int i = 0; i < num_palavras; i++) {
        free(palavras[i]);
    }
    free(palavras);

    return 0;
}
