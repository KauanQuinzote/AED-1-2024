#include <stdio.h>
#include <stdlib.h>

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
}
