#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    char *name;
    struct node *next;
    
}Node;

void stringtok(char *str, char delim, int x);
void make_list(Node **list, char *token);
void printing(Node *list);

int main()
{
    char current_list[100], new_list[100];// indication[10];

    fgets(current_list, sizeof(current_list), stdin);
    setbuf(stdin, NULL);
    fgets(new_list, sizeof(new_list), stdin);


    stringtok(current_list, " ", 1);
    stringtok(new_list, " ", 2);

    return 0;
}

void stringtok(char *str, char delim, int x)
{
    Node *current = NULL, *newest = NULL;

    char *token = strtok(str, delim);

    while (token != NULL)
    {
        if ( x == 1)
            make_list(&current, token);
        else
            make_list(&newest, token);

        token = strtok(NULL, delim);
    }
    printing(current);
    printing(newest);
}

void make_list(Node **list, char *token)
{
    Node *aux, *new = (Node *)malloc(sizeof(Node));

    if(new)
    {
        new->name = strdup(token);
        printf("%s\n", new->name);
        new->next = NULL;

        if((*list) == NULL)
            *list = new;
        
        else
        {
            aux = *list;

            while(aux->next)
                aux = aux->next;
            
            aux = new;
        }
    }
}

void printing(Node *list)
{
    Node *aux = list;

    while (aux)
    {
        printf("%s ", list->name);
        aux = aux->next;
    }
}