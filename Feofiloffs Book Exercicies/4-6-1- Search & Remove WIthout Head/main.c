#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{

    int conteudo;
    struct celula *seg;

}Celula;

void insert_at_end(Celula **list, int num);
int BuscaERemove(int x, Celula **lst);
void printing_list(Celula *list);

int main()
{
    Celula *list = NULL;

    int choice = 1, value, x;

    while (choice)
    {
        printf("1 - Add a Celula\n2 - Delete a Celula\n3 - Print list\n");
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            printf("What value?\n");
            scanf("%i", &value);
            insert_at_end(&list, value);
            break;

        case 2:
            printf("Which value do you want to remove?\n");
            scanf("%i", &value);
            x = BuscaERemove(value, &list);

            if (x)
                printf("Value removed from linked list\n");
            else
                printf("Value not in the list\n");
            break;

        case 3:
            printing_list(list);
            break;

        default:
            break;
        }
    }

    free(list);

    return 0;
}

void insert_at_end(Celula **list, int num)
{

    Celula *aux, *new = malloc(sizeof(Celula));

    if (new)
    {

        new->conteudo = num;
        new->seg = NULL;

        if (*list == NULL)
        {
            *list = new;
        }
        else
        {
            aux = *list;
            while (aux->seg)
                aux = aux->seg;

            aux->seg = new;
        }
    }
    else
        printf("Erro ao alocar memoria\n");
}

int BuscaERemove(int x, Celula **lst)
{
    Celula *p, *q;
    p = *lst;
    q = (*lst)->seg;

    while (q != NULL && q->conteudo != x)
    {
        p = q;
        q = q->seg;
    }
    if (q != NULL)
    {
        p->seg = q->seg;
        free(q);
    }
    else
        return 0;

    return 1;
}

void printing_list(Celula *list)
{

    Celula *aux = list;

    if (aux != NULL)
    {

        while (aux)
        {
            printf("\nCelula value: %i\n", aux->conteudo);
            aux = aux->seg;
        }
    }
    else
        printf("\nThere aren't Celulas at list\n");
}
