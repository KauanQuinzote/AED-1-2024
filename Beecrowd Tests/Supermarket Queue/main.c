#include <stdio.h>
#include <stdlib.h>

typedef struct customers
{
    int itens;
    struct customers *next;

} Customer;

typedef struct cashier
{
    int id;
    int time;
    int total_time;
    Customer *queue;

} Cashier;

Cashier **make_cashier(int N);
Customer make_customer(Customer **customers, int M);
int distributing_to_cashiers(Cashier **array_cashiers, Customer **customers, int N, int M);
Cashier *the_faster_cashier(Cashier **cashiers, int products, int N);
Customer *the_slower_customer(int M, Customer **customer);
void add_to_queue(Cashier **faster_cashier, Customer **slower_customer);
int the_amount_time(Cashier **cashier, int N);

int main()
{

    Cashier **array_cashiers = NULL;
    Customer *customers = NULL;

    int N, M, amount_time;

    scanf("%i %i", &N, &M);

    array_cashiers = make_cashiers(N);
    make_customers(&customers, M);
    amount_time = distributing_to_cashiers(array_cashiers, &customers, N, M);

    printf("%i\n", amount_time);

    return 0;
}

Cashier **make_cashier(int N)
{
    // Aloca memória para o array de ponteiros para Cashier
    Cashier **cashiers = (Cashier **)malloc(N * sizeof(Cashier *));

    if (cashiers == NULL)
    {

        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa cada ponteiro no vetor
    for (int i = 0; i < N; i++)
    {
        cashiers[i] = (Cashier *)malloc(sizeof(Cashier));

        if (cashiers[i] == NULL)
        {
            fprintf(stderr, "Erro ao alocar memória.\n");
            exit(EXIT_FAILURE);
        }
        cashiers[i]->id = i + 1; // define um ID para o caixa
    }

    return cashiers;
}

Customer make_customer(Customer **customers, int M)
{

    int amount_customers = 1, products;
    Customer *aux;

    do
    {
        Customer *new = malloc(sizeof(Customer)); // faça um novo nó para *customers

        if (new)
        {
            scanf("%i", &products); // veja quanto produtos esse cliente possui
            new->itens = products;  // armazene no tipo cliente
            new->next = NULL;

            if ((*customers) == NULL) // se é o primeiro cliente
            {
                *customers = new; // o novo cliente será a cabeça
            }
            else
            {
                aux = *customers;

                while (aux)
                    aux = aux->next;
                aux = new;
            }
        }
        else
            printf("Erro ao alocar memoria\n");

        amount_customers++; // itera o loop para concluir fazer esse cliente

    } while (amount_customers < M);
}

int distributing_to_cashiers(Cashier **cashiers, Customer **customers, int N, int M)
{

    int amount_time;
    Cashier *faster_cashier;
    Customer *slower_customer, *aux = customers;

    while (aux) // enquanto há clientes não distribuidos nos caixas
    {
        slower_customer = the_slower_customer(&customers, M);
        faster_cashier = the_faster_cashier(&cashiers, slower_customer->itens, N);

        add_to_queue(&faster_cashier, &slower_customer);

        aux = aux->next;
    }

    amount_time = the_amount_time(&cashiers, N);

    return amount_time;
}

Cashier *the_faster_cashier(Cashier **cashiers, int products, int N)
{

    for (int i = 0; i < N; i++)
    {
        cashiers[i]->total_time = cashiers[i]->total_time + (cashiers[i]->time * products); // simule quanto tempo total o caixar levaria para atender mais esse cliente
    }

    Cashier *the_fast_cashier = cashiers[0]; // estipule que o primeiro caixa seria supostamente o mais rápido

    for (int i = 1; i < N; i++) // verifique se de fato o primeiro caixa é com menos tempo total. Do contrario, encontre o com menor tempo total
    {
        if (cashiers[i]->total_time < the_fast_cashier->total_time)
        {
            the_fast_cashier = cashiers[i];
        }
    }

    for (int i = 0; i < N; i++) // retire do tempo total a simulação feita com o cliente dessa situação;
    {
        cashiers[i]->total_time = cashiers[i]->total_time - (cashiers[i]->time * products);
    }

    return the_fast_cashier;
}

Customer *the_slower_customer(int M, Customer **customer)
{

    Customer *the_slow_customer = customer[0];

    for (int i = 0; i < M; i++)
    {
        if (customer[i]->itens > the_slow_customer->itens)
            the_slow_customer = customer[i];
    }

    return the_slow_customer;
}

void add_to_queue(Cashier **faster_cashier, Customer **slower_customer)
{

    Customer *aux_customer = *slower_customer;

    (*faster_cashier)->queue = aux_customer;
    (*slower_customer)->next = aux_customer->next;

    (*faster_cashier)->total_time = (*faster_cashier)->total_time + ((*faster_cashier)->time * aux_customer->itens); // não se esqueça de manter a atualização do caixa eleito mais efetivo, pois agora o cliente será alocado para ele e seu tempo total aumentará
}

int the_amount_time(Cashier **cashier, int N)
{
    Cashier *aux = *cashier;

    int i, time = aux[0].total_time;

    for (i = 0; i < N; i++)
    {
        if (aux[i].total_time > time)
            time = aux[i].total_time;
    }

    return time;
}