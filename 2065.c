#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
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
=======
// Função principal do programa
int main()
{
    int customer, cashier, *itens, *velocity, *time, t = 0;

    // Lê o número de caixas e o número de clientes
    scanf("%d %d", &cashier, &customer);
    
    // Aloca memória para os arrays de itens, velocidades e tempos
    itens = (int *)malloc(customer * sizeof(int));
    velocity = (int *)malloc(cashier * sizeof(int));
    time = (int *)malloc(cashier * sizeof(int));

    int i = 0;
    
    // Lê as velocidades dos caixas
    while(i < cashier && scanf("%i", &velocity[i]))
        i++;

    i = 0;

    // Lê a quantidade de itens de cada cliente
    while(i < customer && scanf("%i", &itens[i]))
        i++;
    
    // Processa cada cliente
    while(t < customer) 
    {
        if(t < cashier)
        {
            // Se o número de clientes atendidos for menor que o número de caixas,
            // atribui o tempo de atendimento diretamente ao tempo do caixa correspondente
            time[t] = velocity[t] * itens[t];
            t++;
        }
        else
        {
            // Quando há mais clientes que caixas disponíveis, encontra o caixa que ficará livre primeiro
            int aux = time[0];
            int free = 0;

            for(int i = 0; i < cashier; i++)
            {
                if(aux > time[i]) 
                {
                    aux = time[i];
                    free = i;
                }
            }

            // Adiciona o tempo de atendimento do próximo cliente ao caixa que ficou livre
            time[free] += velocity[free] * itens[t];
            t++;
        }
    }
    
    // Encontra o maior tempo de atendimento entre todos os caixas
    int maior = time[0];

    for(int i = 0; i < cashier; i++)
    {
        if(maior < time[i])
        {
            maior = time[i];
        }
    }

    // Imprime o maior tempo de atendimento (tempo total necessário para atender todos os clientes)
    printf("%d\n", maior);

    // Libera a memória alocada
    free(itens);
    free(velocity);
    free(time);
>>>>>>> edac3ad42ad014ce9f2cb0824cc8516883c9333b
}
