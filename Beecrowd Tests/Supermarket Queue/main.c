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
    struct cashier *next;
    Customer *queue;

} Cashier;

int amount_customers = 1;

void make_cashier(Cashier **cashiers, int N);
void make_customer(Customer **customers, int M);
int distributing_to_cashiers(Cashier **array_cashiers, Customer **customers);
Cashier *the_faster_cashier(Cashier **cashiers, int products);
Customer *the_slower_customer(Customer **customer);
void add_to_queue(Cashier **faster_cashier, Customer **slower_customer, Customer **customers);
int the_amount_time(Cashier **cashier);
void printing_queue(Cashier *cashier, Customer *customer);

int main()
{

    Cashier *array_cashiers = NULL; //vetor de ponteiros para os caixas
    Customer *customers = NULL; //lista encadeada de clientes

    int N, M, amount_time; //variáveis 

    scanf("%i %i", &N, &M); //insere quantidade de caixas e clientes

    make_cashier(&array_cashiers, N); //cria uma lista de caixas
    make_customer(&customers, M); //cria uma lista de clientes

    amount_time = distributing_to_cashiers(&array_cashiers, &customers);

    printf("%i\n", amount_time);

    return 0;
}

void make_cashier(Cashier **cashiers, int N)
{
    int amount_cashiers = 1;

    // Aloca memória para o array de ponteiros para Cashier
    Cashier *aux;

    while (amount_cashiers <= N)
    {
        Cashier *new = malloc(sizeof(Cashier));

        if(new)
        {
            scanf("%i", &new->time);
            new->id = amount_cashiers;
            new->total_time = 0;
            new->next = NULL;
            new->queue = NULL;

            if ((*cashiers) == NULL)
                *cashiers = new;
            
            else
            {
                aux = *cashiers;

                while (aux->next)
                    aux = aux->next;
                
                aux->next = new;
            }
        }
        else
            printf("Erro ao alocar memoria para cashier\n");

        printf("Caixa %i feito com tempo %i\n", new->id, new->time);
        amount_cashiers++;
    }
}

void make_customer(Customer **customers, int M)
{
    Customer *aux;

    while (amount_customers <= M)
    {
        Customer *new = malloc(sizeof(Customer)); // faça um novo nó para *customers
        
        if (new)
        {
            scanf("%i", &new->itens); // veja quanto produtos esse cliente possui
            new->next = NULL;

            if ((*customers) == NULL) // se é o primeiro cliente
                *customers = new; // o novo cliente será a cabeça
        
            else
            {
                aux = *customers;

                while (aux->next)
                    aux = aux->next;
                aux->next = new;
            }
        }
        else
            printf("Erro ao alocar memoria\n");

        printf("CLIENTE %i FEITO COM %i PRODUTOS\n", amount_customers, new->itens);
        amount_customers++; // itera o loop para concluir fazer esse cliente        
    }
}

int distributing_to_cashiers(Cashier **cashiers, Customer **customers)
{

    int amount_time;
    Cashier *faster_cashier;
    Customer *slower_customer, *aux = *customers;

    while (--amount_customers) // enquanto há clientes não distribuidos nos caixas
    {
        slower_customer = the_slower_customer(&aux);

        faster_cashier = the_faster_cashier(cashiers, slower_customer->itens);

        add_to_queue(&faster_cashier, &slower_customer, customers);

        printing_queue((*cashiers), (*customers));
    }

    amount_time = the_amount_time(cashiers);

    return amount_time;
}

Cashier *the_faster_cashier(Cashier **cashiers, int products)
{
    Cashier *the_fast_cashier, *aux = *cashiers;
    the_fast_cashier = aux; // estipule que o primeiro caixa seria supostamente o mais rápido

    while (aux)//simule o que aconteceria se todos os caixas passasem o produto
    {
        aux->total_time = aux->total_time + (aux->time * products);

        aux = aux->next;
    }

    aux = (*cashiers)->next;//retorne aux para o início

    while(aux) //encontre o caixa com menor tempo possível dentre todos da lista
    {
        if(aux->total_time < the_fast_cashier->total_time)
            the_fast_cashier = aux;

        aux = aux->next;
    }   
    
    aux = *cashiers; //retorne aux para o início

    while(aux) // retire do tempo total a simulação feita com o cliente dessa situação;
    {
        if(aux != the_fast_cashier)
            aux->total_time = aux->total_time - (aux->time * products);
        aux = aux->next;
    }

    printf("o caixa mais rapido passa a cada %i segundos\n", the_fast_cashier->time);
    return the_fast_cashier;
}

Customer *the_slower_customer(Customer **customer)
{
    Customer *current_customer = *customer; // Começa com o primeiro cliente
    Customer *the_slow_customer = current_customer;

    // Avança para o próximo cliente na lista e compara
    while (current_customer != NULL)
    {
        if (current_customer->itens > the_slow_customer->itens)
            the_slow_customer = current_customer;
        
        current_customer = current_customer->next; // Avança para o próximo cliente
    }
    printf("O slow cust tem %i itens\n", the_slow_customer->itens);

    return the_slow_customer;
}

void add_to_queue(Cashier **faster_cashier, Customer **slower_customer, Customer **customers)
{
    Customer *aux_slow_customer = *slower_customer, *aux_customer = *customers;
    Cashier *aux_cashier = *faster_cashier;
    

    if (aux_cashier->queue == NULL)
    {
        aux_cashier->queue = *slower_customer;
    }
        
    else
    {
        aux_slow_customer = aux_cashier->queue;

        while (aux_slow_customer->next)
            aux_slow_customer = aux_slow_customer->next;

        aux_slow_customer = *slower_customer;
    }
    
    while(aux_customer)
    {
        if(aux_customer == *slower_customer)
            *customers = aux_customer->next;

        if (aux_customer->next == *slower_customer)
                aux_customer->next = aux_customer->next->next;

        aux_customer = aux_customer->next;
    }
}

int the_amount_time(Cashier **cashier)
{
    Cashier *aux = *cashier, *current;
    current = aux;

    int time = current->total_time;

    while (aux)
    {
       if (aux->total_time > time)
            time = aux->total_time;
        
        aux = aux->next;
    }

    return time;
}

void printing_queue(Cashier *cashier, Customer *customer)
{
    Cashier *aux_cashier = cashier;
    Customer *aux_customer = customer;

    while(aux_cashier)
    {
        printf("Caixa: %i\nTempo: %i\nTempo total: %i\n\n", aux_cashier->id, aux_cashier->time, aux_cashier->total_time);

        aux_cashier = aux_cashier->next;
    }

    int x = 1;
    while(aux_customer)
    {
        printf("Cliente: %i\nItens: %i\n\n", x, aux_customer->itens);
        aux_customer = aux_customer->next;
        x++;
    }
}