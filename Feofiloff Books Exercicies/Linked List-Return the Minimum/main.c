#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

void insert_at_end(Node **list, int num);
int min(Node *list);

int main(){

    Node *list = NULL;
    int value, lower;

    do{
        printf("Add a node:\n");
        scanf("%i", &value);
        insert_at_end(&list, value);
        lower = min(list);

        printf("The lower value on the linked list is %i\n\n", lower);
        
    }while (value != 0);

}

int min(Node *list){

    Node *aux = list;
    int min = aux->value;

	for (aux = list->next; aux !=NULL; aux = aux->next)

		if (aux->value < min) min = aux->value;

    return min;
}

void insert_at_end(Node **list, int num){

    Node *aux, *new = malloc(sizeof(Node));

    if(new){

        new->value = num;
        new->next = NULL;

        if (*list == NULL) *list = new;
            
        else{

            aux = *list;

            while(aux->next)
                aux = aux->next;

            aux->next = new;
        }
    }else printf("Erro ao alocar memoria\n");
}