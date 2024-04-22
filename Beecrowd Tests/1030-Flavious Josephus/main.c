#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pearson{

    int index;
    bool alive;
    struct pearson *next;

}Pearson;

void insert_at_end(Pearson **list, int people);
void killing_pearson(Pearson **list, int jump);
void printing_list(Pearson *list);

int people;

int main()
{
    Pearson *list = NULL;

    int jump, n, m;

    scanf("%i %i", &people, &jump);

    insert_at_end(&list, people);

    printing_list(list);
    
    return 0;
}

void insert_at_end(Pearson **list, int people)
{
    int index = 1;

    while (index <= people)
    {
        Pearson *aux, *new = malloc(sizeof(Pearson));

        if (new)
        {
            
            new->index = index;
            new->alive = true;
            new->next = NULL;

            if (index == people)
                new->next = *list;

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
        index++;
    }
}

void killing_pearson(Pearson **list, int jump)
{
    Pearson *aux = *list;
    int i = 0;

    while(i < jump)//pula jump vezes
    {
        if(aux->alive)//caso a pessoa atual esteja viva
        {
            aux = aux->next;//vá a proxima pessoa
            i++;//
        }
    }
}
void printing_list(Pearson *list)
{

    Pearson *aux = list;

    if (aux != NULL)
    {

        while (aux)
        {
            printf("\nPearson value: %i\n", aux->index);
            sleep(1);
            aux = aux->next;
        }
    }
    else
        printf("\nThere aren't Pearsons at list\n");
}