#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para encontrar as posições das palavras de busca no texto
void encontrar_posicoes(char *texto, char **palavras, int num_palavras) {
    // Loop sobre as palavras de busca
    for (int i = 0; i < num_palavras; i++) {
        // Ponteiro para a posição atual no texto
        char *posicao_atual = texto;

        // Loop para buscar todas as ocorrências da palavra no texto
        while (1) {
            // Ponteiro para a primeira ocorrência da palavra no texto
            char *ocorrencia = strstr(posicao_atual, palavras[i]);

            // Se a palavra foi encontrada
            if (ocorrencia != NULL) {
                // Calcula a posição da palavra no texto
                int posicao = ocorrencia - texto;

                // Verifica se é o início da palavra
                if (posicao == 0 || *(ocorrencia - 1) == ' ') {
                    // Imprime a posição da palavra
                    printf("%d ", posicao);
                }

                // Atualiza a posição atual para a posição após a última ocorrência encontrada
                posicao_atual = ocorrencia + 1;
            } else {
                break;
            }
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
