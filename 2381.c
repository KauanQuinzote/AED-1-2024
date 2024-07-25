#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

// Estrutura para armazenar o nome e o ponteiro para o próximo elemento da lista
typedef struct pearson {
  char name[SIZE];
  struct pearson *next;
} Pearson;

// Função para dividir a lista em duas metades
void splitList(Pearson* source, Pearson** front, Pearson** back) {
  Pearson* fast;
  Pearson* slow;
  slow = source;
  fast = source->next;

  // Usa dois ponteiros para encontrar o meio da lista
  while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
          slow = slow->next;
          fast = fast->next;
      }
  }

  *front = source;
  *back = slow->next;
  slow->next = NULL;
}

// Função para mesclar duas listas encadeadas ordenadas
Pearson* mergeSortedLists(Pearson* a, Pearson* b) {
  Pearson* result = NULL;

  if (a == NULL)
      return b;
  else if (b == NULL)
      return a;

  if (strcmp(a->name, b->name) <= 0) {
      result = a;
      result->next = mergeSortedLists(a->next, b);
  } else {
      result = b;
      result->next = mergeSortedLists(a, b->next);
  }
  return result;
}

// Função principal para o Merge Sort
void mergeSort(Pearson** headRef) {
  Pearson* head = *headRef;
  Pearson* a;
  Pearson* b;

  if ((head == NULL) || (head->next == NULL)) {
      return;
  }

  // Divide a lista em duas metades
  splitList(head, &a, &b);

  // Ordena cada metade recursivamente
  mergeSort(&a);
  mergeSort(&b);

  // Combina as duas metades ordenadas
  *headRef = mergeSortedLists(a, b);
}

// Função para criar um novo elemento na lista
void create_pearson(Pearson **list) {
  Pearson *new = malloc(sizeof(Pearson)), *aux = *list;

  if (new) {
    setbuf(stdin, NULL);
    fgets(new->name, SIZE, stdin);
    new->next = NULL;

    // Adiciona o novo elemento ao final da lista
    if (*list) {
      while (aux->next)
        aux = aux->next;
      aux->next = new;
    } else {
      *list = new;
    }
  } else {
    printf("Error\n");
  }
}

int main(void) {
  Pearson *list = NULL, *aux;
  int people, i = 0, num;
  char input[5];

  setbuf(stdin, NULL);
  fgets(input, 5, stdin);
  sscanf(input, "%i %i", &people, &num);

  // Lê os nomes das pessoas e cria a lista encadeada
  while (people--)
    create_pearson(&list);

  // Ordena a lista usando Merge Sort
  mergeSort(&list);

  // Encontra o nome na posição 'num'
  aux = list;
  while (++i < num)
    aux = aux->next;

  // Imprime o nome na posição 'num'
  printf("%s\n", aux->name);

  return 0;
}
