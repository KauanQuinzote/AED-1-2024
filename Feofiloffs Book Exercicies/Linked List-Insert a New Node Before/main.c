#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *previous;

} Node;

void insert_at_end(Node **list, int num);
void print_list(Node *list);

int main()
{

    int value = 1;
    Node *list = NULL;

    while (value)
    {
        printf("1 - Add a node\n2 - Print list\n");
        scanf("%i", &value);

        switch (value)
        {
        case 1:
            printf("Which value?\n");
            scanf("%i", &value);
            insert_at_end(&list, value);
            break;

        case 2:
            print_list(list);
            break;

        default:
            break;
        }
    }
    return 0;
}

void insert_at_end(Node **list, int num)
{

    Node *aux, *new = malloc(sizeof(Node)), *prev;

    if (new)
    {
        new->value = num;
        new->next = NULL;

        if (*list == NULL)
        {
            *list = new;
            new->previous = new;
            
        }
        else
        {
            aux = *list;

            while (aux->next)
                aux = aux->next;

            aux->next = new;

            prev = *list;

            while (prev->next->next)
                prev = prev->next;

            new->previous = prev;
        }
    }
    else
        printf("Error\n");
}

void print_list(Node *list){

    Node *aux = list;

    while(aux)
    {
        printf("\n\nValue: %i\nPrevious: %i\nNext: %i\n\n", aux->value, aux->previous->value, aux->next->value);
        aux = aux->next;
    }
}