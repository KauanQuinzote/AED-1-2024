#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void insert_at_end(Node **list, int num);
bool remove_node(Node **list, int num);
void printing_list(Node *list);

int main()
{

    Node *list = NULL;
    int value;
    bool x;

    do
    {
        printf("\n1 - Add a node\n2 - Remove value\n3 - Print List\n");
        scanf("%i", &value);

        switch (value)
        {
        case 1:
            printf("Add a node:\n");
            scanf("%i", &value);
            insert_at_end(&list, value);
            break;

        case 2:
            printf("Which value do you want to remove?\n");
            scanf("%i", &value);
            x = remove_node(&list, value);

            if (x)
                printf("Value removed from linked list\n");
            else
                printf("Value not in the list\n");
            break;

        case 3:
            printing_list(list);

        default:
            break;
        }

    } while (value != 0);
}

void insert_at_end(Node **list, int num)
{

    Node *aux, *new = malloc(sizeof(Node));

    if (new)
    {

        new->value = num;
        new->next = NULL;

        if (*list == NULL)
        {
            *list = new;
        }
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

bool remove_node(Node **list, int num)
{

    Node *aux = *list, *trash;

    if (aux == NULL)
        return false;

    if (aux->value == num)
    {

        if (aux->next == NULL)
        {
            free(aux);
            *list = NULL;
        }
        else
        {
            *list = aux->next;
            printf("%i\n", (*list)->value);
            free(aux);
        }
        return true;
    }
    else if (aux->next->value == num)
    {

        trash = aux->next;
        aux->next = aux->next->next;
        free(trash);
        return true;
    }
    else
        return remove_node(&aux->next, num);

    return false;
}

void printing_list(Node *list)
{

    Node *aux = list;

    if (aux != NULL)
    {

        while (aux)
        {
            printf("\nNode value: %i\n", aux->value);
            aux = aux->next;
        }
    }
    else
        printf("\nThere aren't nodes at list\n");
}