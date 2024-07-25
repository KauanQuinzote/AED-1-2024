#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 5000  // Definição do tamanho máximo para os arrays de entrada

// Estrutura para representar um nó na lista ligada
typedef struct node{
  int id;
  struct node *next;
} Node;

// Função para procurar e remover um nó com valor x da lista
void search(Node **lst, int x)
{
  Node *aux = *lst, *trash;

  // Percorre a lista até encontrar o nó cujo próximo nó tem o id igual a x
  while(aux->next->id != x)
    aux = aux->next;

  // Remove o nó da lista
  trash = aux->next;
  aux->next = trash->next;
  free(trash);
}

// Função para inserir um novo nó com valor x no final da lista
void insert(Node **lst, int x)
{
  Node *aux, *new = malloc(sizeof(Node));

  if(new)
  {
    new->id = x;  // Define o id do novo nó
    new->next = NULL;

    if(*lst)
    {
      aux = *lst;
      // Percorre até o final da lista
      while(aux->next)
        aux = aux->next;
      
      // Insere o novo nó no final da lista
      aux->next = new;
    }
  }
}

int main(void) {
  int i = 0, N, j = 0, f = -1;
  char numbers[SIZE], exit[SIZE];
  Node *list = malloc(sizeof(Node)), *aux;
  list->next = NULL;  // Inicializa a lista como vazia
  
  // Lê o número de elementos a serem inseridos
  scanf(" %i", &N);
  getchar();
  // Lê a sequência de números a serem inseridos
  fgets(numbers, SIZE, stdin);

  // Processa cada número e insere na lista
  while(i++ < N)
  {  
    while(isdigit(numbers[++f]))
      j = j * 10 + numbers[f] - '0';
    
    insert(&list, j);
    j = 0;
  }

  // Lê o número de elementos a serem removidos
  scanf("%i", &N);
  getchar();
  // Lê a sequência de números a serem removidos
  fgets(exit, SIZE, stdin);
  
  i = 0, f = -1, j = 0;
  // Processa cada número e remove da lista
  while(i++ < N)
  {
    while(isdigit(exit[++f]))
      j = j * 10 + exit[f] - '0';
    
    search(&list, j);
    j = 0;
  }

  // Imprime os elementos restantes na lista
  aux = list->next;
  while(aux)
  {
    printf("%i ", aux->id);
    aux = aux->next;
  }
  printf("\n");
  
  return 0;
}
