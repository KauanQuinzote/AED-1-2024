#include <stdio.h>
#include <stdbool.h>

#define SIZE 1000

// Função para ordenar o array em ordem decrescente usando Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Verifica se a sequência de saída pode ser uma fila de prioridade
bool is_priority(int in[], int out[]) {
    int i = -1, size = 1;

    // Calcula o tamanho da entrada
    while (in[++i] != 0)
        size++;

    // Ordena a entrada em ordem decrescente
    bubbleSort(in, size);

    i = -1;
    // Compara a saída ordenada com a saída dada
    while (out[++i] != 0) {
        if (out[i] != in[i])
            return false;
    }

    return true;
}

// Verifica se a sequência de saída pode ser uma pilha
bool is_stack(int in[], int out[]) {
    int i = -1, size = -1;

    // Calcula o tamanho da entrada
    while (in[++i] != 0)
        size++;

    i = -1;
    // Compara a saída com a entrada em ordem inversa
    while (out[++i] != 0) {
        if (out[i] != in[size--])
            return false;
    }
    return true;
}

// Verifica se a sequência de saída pode ser uma fila
bool is_queue(int in[], int out[]) {
    int i = -1;

    // Compara a saída com a entrada na mesma ordem
    while (out[++i] != 0) {
        if (out[i] != in[i])
            return false;
    }

    return true;
}

int main(void) {
    int in[SIZE], out[SIZE], i = -1, turn, choice, f = 0, g = 0;
    bool queue, stack, priority_queue;

    // Lê o número de operações
    scanf("%i", &turn);

    // Processa cada operação
    while (++i < turn) {
        scanf("%i", &choice);

        switch (choice) {
            case 1:
                // Inserção na estrutura
                scanf("%i", &in[f++]);
                break;

            case 2:
                // Remoção da estrutura
                scanf("%i", &out[g++]);
                break;
        }
    }

    // Verifica o tipo da estrutura
    queue = is_queue(in, out);
    stack = is_stack(in, out);
    priority_queue = is_priority(in, out);

    // Determina o resultado
    if (queue && stack || queue && priority_queue || stack && priority_queue)
        printf("not sure\n");
    else if (queue)
        printf("queue\n");
    else if (stack)
        printf("stack\n");
    else if (priority_queue)
        printf("priority queue\n");
    else
        printf("impossible\n");

    return 0;
}
