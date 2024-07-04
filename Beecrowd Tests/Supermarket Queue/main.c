#include <stdio.h>
#include <stdlib.h>

typedef struct cashier
{   
    int id;    // ID do caixa
    int time;
    int total_time;
    struct cashier *next; // Ponteiro para o próximo nó

} Cashier;

Cashier *new_cashier (int time);
void make_cashier (Cashier **head, int id);
void reorder (Cashier **head, int products);
int maximum (Cashier* head);

int id = 0;

int main()
{
    Cashier *cashier_queue = NULL;
    int n, m, i; // variaveis de caixa e cliente

    scanf("%i %i", &n, &m);

    for (i = 0; i < n; i++)
        make_cashier (&cashier_queue, i);
    
    for (i = 0; i < m; i++)
    {
        int products;
        scanf("%i", &products);
        reorder(&cashier_queue, products);
    }

    printf("%i\n", maximum(cashier_queue));
    

    return 0;
}

void make_cashier (Cashier **head, int id)
{
    Cashier *aux, *new = malloc(sizeof(Cashier));

    if(new)
    {
        new->id = id;
        scanf("%i", &new->time);
        new->total_time = 0;
        new->next = NULL;

        if ((*head) == NULL)
            *head = new;
        else
        {
            aux = *head;

            while(aux->next)
                aux = aux->next;

            aux->next = new;
        }
    }
    else printf("Erro\n");
}

void reorder (Cashier **head, int products)
{
    Cashier *aux = *head;
    while (aux)
    {
        aux->total_time = aux->time * products;
        aux = aux->next;
    }

    int minimum = (*head)->total_time;
    aux = *head;

    while (aux)
    {
        if (aux->total_time < minimum)
            minimum = aux->total_time;

        aux = aux->next;
    }

    aux = *head;

    while (aux)
    {
        if (minimum != aux->total_time)
            aux->total_time = aux->total_time - (aux->time * products);

        aux = aux->next;
    }
}

int maximum (Cashier *head)
{
    Cashier *aux = head;
    int max = head->total_time;

    while(aux)
    {
        if (aux->total_time > max)
            max = aux->total_time;
    }

    return max;
}