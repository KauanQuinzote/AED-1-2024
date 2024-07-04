#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para os elementos da fila de prioridade
typedef struct {
    int end_time;
    int id;
} Elemento;

// Função de comparação para a fila de prioridade
int comparar(const void *a, const void *b) {
    Elemento *elem1 = (Elemento *)a;
    Elemento *elem2 = (Elemento *)b;
    return elem1->end_time - elem2->end_time;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int tempo[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &tempo[i]);
    }

    // Inicialização da fila de prioridade
    Elemento cliente[n];
    for (int i = 0; i < n; i++) {
        cliente[i].end_time = 0;
        cliente[i].id = i;
    }
    qsort(cliente, n, sizeof(Elemento), comparar);

    int max_time = 0;
    for (int i = 0; i < m; i++) {
        int c;
        scanf("%d", &c);

        // Obtenção do próximo cliente a ser atendido
        int end_time = cliente[0].end_time;
        int id = cliente[0].id;

        // Remoção do cliente da fila
        for (int j = 1; j < n; j++) {
            cliente[j - 1] = cliente[j];
        }

        // Cálculo do tempo de atendimento e atualização do max_time
        int time = tempo[id] * c;
        max_time = (max_time > end_time + time) ? max_time : (end_time + time);

        // Atualização do tempo de conclusão do atendimento e reinserção do cliente na fila
        cliente[n - 1].end_time = end_time + time;
        qsort(cliente, n, sizeof(Elemento), comparar);
    }

    printf("%d\n", max_time);

    return 0;
}
