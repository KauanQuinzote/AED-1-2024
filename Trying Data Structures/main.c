#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;

} Node;

void insert_at_beginning(Node **list, int num);
void insert_at_end(Node **list, int num);
void printing_list(Node *list);
void removing_from_the_beginning(Node**list);

int main(void)
{

    int choice = 1, num;
    Node *list = NULL;

    while (choice != 0)
    {
        printf("\nSelecione uma atividade\n\n");
        printf("1 - Inserir no começo\n2 - Inserir no fim\n3 - Imprimir lista\n0 - Sair\n");
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            printf("Insira o valor a ser colocado na lista\n");
            scanf("%i", &num);
            insert_at_beginning(&list, num);
            break;
        case 2:
            printf("Insira o valor a ser colocado na lista\n");
            scanf("%i", &num);
            insert_at_end(&list, num);
            break;
        case 3:
            printing_list(list);
            break;

        case 4:
            removing_from_the_beginning(&list);
            printf("Nó removido do início\n");
            break;

        case 5:
            removing_from_the_end(&list);
            printf("Nó removido da cauda\n");
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}

void insert_at_beginning(Node **list, int num)
{

    Node *aux, *new = malloc(sizeof(Node));

    if (new)
    {
        new->value = num;
        new->next = NULL;

        if (*list == NULL)
            *list = new;

        else
        {
            aux = *list;
            new->next = aux->next;
            aux->next = new;
        }
    }
    else
        printf("Erro ao alocar memoria\n");
}

void insert_at_end(Node **list, int num)
{

    Node *aux, *new = malloc(sizeof(Node));

    if (new)
    {
        new->value = num;
        new->next = NULL;

        if (*list == NULL)
            *list = new;

        else
        {
            aux = *list;

            while (aux->next)
                aux = aux->next;
            aux->next = new;
        }
    }
    else
        printf("Erro ao alocar memoria\n");
}

void printing_list(Node *list)
{
    Node *aux = list;

    while (aux)
    {

        printf("Valor: %i\n", aux->value);
        aux = aux->next;
    }
}

void removing_from_the_beginning(Node **list)
{
    Node *aux;

    if (*list == NULL)
        printf("Sua lista está vazia\n");
    
    else
    {
        if((*list)->next)//se há só um nó na lista
            free(list);

        else
        {
            aux = *list;
            *list = aux->next;
            free(aux);
        }
    }
}

void removing_from_the_end(Node **list)
{
    Node *aux;

    if (*list == NULL)//se a lista está vazia
        printf("Sua lista está vazia\n");

    else
    {
        if((*list)->next == NULL)//se a lista tem um só nó
            free(list);

        else
        {
        aux = *list;

        while(aux->next->next)
            aux = aux->next;

        free(aux->next);
        aux->next = NULL;

        }
        
    }
    

}