#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char *name;
    struct node *next;

}Node;

void stringtok(char *str, int x);
void make_list(Node **list, char *token);
void printing(Node *list);
void searching_name(char *name_);
char *remove_n(char *str);
int strcmp_ignore_newline(const char *str1, const char *str2);

Node *current = NULL, *newest = NULL;

int main()
{
    char current_list[100], new_list[100], indication[10];

    fgets(current_list, sizeof(current_list), stdin);
    setbuf(stdin, NULL);
    fgets(new_list, sizeof(new_list), stdin);
    setbuf(stdin, NULL);
    fgets(indication, 10, stdin);

    stringtok(current_list, 1);
    stringtok(new_list, 2);

    int cmp = strcmp_ignore_newline(indication, "nao");
    
    if (cmp != 0)//se houver indicação
        searching_name(indication);
        
    else
    {
        Node *first = current;

        while(first->next)
            first = first->next;
        first->next = newest;

        printing(current);
    }

    // Liberando memória
    Node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    while (newest != NULL) {
        temp = newest;
        newest = newest->next;
        free(temp->name);
        free(temp);
    }
    return 0;
}

void stringtok(char *str, int x)
{
    char *token = strtok(str, " ");

    while (token != NULL)
    {
        if ( x == 1)
            make_list(&current, token);
        else
            make_list(&newest, token);

        token = strtok(NULL, " ");
    }
}

void make_list(Node **list, char *token)
{
    Node *aux, *new = (Node *)malloc(sizeof(Node));

    if(new)
    {
        new->name = remove_n(token);
        new->next = NULL;

        if((*list) == NULL)
            *list = new;

        else
        {
            aux = *list;

            while(aux->next)
                aux = aux->next;

            aux->next = new;
        }
    }
}

void printing(Node *list)
{
    Node *aux = list;

    while (aux)
    {
        printf("%s ", aux->name);
        aux = aux->next;
    }
}

void searching_name(char *name_)
{
    Node *first = current, *last = newest;
    int cmp;

    while (first)
        {   cmp = strcmp_ignore_newline(first->next->name, name_);      
            if(cmp == 0)//se o nome do proximo nó é igual ao da indicação 
            {
                while(last->next)//percorra todo o laço dos novos amigos
                    last = last->next;
                
                last->next = first->next;//o laço dos novos amigos passa a apontar para o nome de indicaçao
                
                first->next = newest;//invés de apontar para o nome de indicação, o nó passa a apontar para a lista de amigos novos, empurrando o nome de indicação par ao final    
                break;//saia do loop
            }
            else
                first = first->next;//caso o nome do proximo nó não seja o de indicação, percorra a lista até achar
        }
    printing(current);
}

int strcmp_ignore_newline(const char *str1, const char *str2) 
{
    int i = 0;

    while (isalpha(str2[i]))
        {
            if (str1[i] != str2[i])
                return 1;
            i++;
        }
    return 0; // As strings são iguais
}
char *remove_n(char *str)
{
    int n = strlen(str)+1, i = 0;
    char *str_N = malloc(n * sizeof(char));
    while (isalpha(str[i]))
        {
            str_N[i] = str[i];
            i++;
        }
    i++;
    str_N[i] = '\0';
    return str_N;
}
