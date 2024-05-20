#include <stdio.h>
#include <stdlib.h>

#define DISCARTED 50  // Define a capacidade máxima do array de cartas descartadas

typedef struct node {
  int value;            // Valor armazenado no nó
  struct node *next;    // Ponteiro para o próximo nó
} Node;

int size;  // Variável global para acompanhar o tamanho da pilha

void push(Node **head, int x);  // Declaração da função push
int pop(Node **head);           // Declaração da função pop
void printing(int x, int array[]);  // Declaração da função de impressão

int main() {
  Node *head = (Node*)malloc(sizeof(Node));  // Cria a cabeça da pilha
  head->next = NULL;  // Inicializa o próximo nó como NULL

  int x, i;

  // Loop principal para ler entradas até que um 0 seja lido
  while (scanf("%i", &x) && x != 0) {
    int discarted[DISCARTED] = {0};  // Vetor para armazenar as cartas descartadas
    i = 0;
    size = 0;  // Inicializa o tamanho da pilha

    // Preenche a pilha com valores de 1 a x
    while (i++ < x)
      push(&head, i);

    i = -1;
    // Descarte das cartas de acordo com as regras
    while (++i < size)
      discarted[i] = pop(&head);

    // Chama a função de impressão para mostrar as cartas descartadas e a restante
    printing(head->next->value, discarted);
  }

  return 0;
}

// Função para adicionar um novo valor à pilha
void push(Node **head, int x) {
  Node *new = malloc(sizeof(Node));  // Aloca memória para o novo nó
  if (new) {
    new->value = x;
    new->next = (*head)->next;
    (*head)->next = new;  // Insere o novo nó no topo da pilha
    size++;  // Incrementa o tamanho da pilha
  }
}

// Função para remover o último elemento da pilha
int pop(Node **head) {
  Node *c = (*head)->next, *p = *head, *trash;
  int data;

  // Se houver mais de um elemento na pilha
  if (p->next->next) {
    // Percorre a pilha até o penúltimo nó
    while (c->next->next) {
      c = c->next;
      p = p->next;
    }

    // Remove o último nó e armazena seu valor
    trash = c->next;
    data = trash->value;
    c->next = NULL;
    free(trash);
    p->next = NULL;

    // Move o nó para o topo da pilha
    c->next = (*head)->next;
    (*head)->next = c;

    return data;
  } else {
    return 0;  // Se houver apenas um elemento, retorna 0
  }
}

// Função para imprimir as cartas descartadas e a carta restante
void printing(int x, int array[]) {
  int i = 0;

  printf("Discarded cards:");
  // Imprime as cartas descartadas até encontrar um valor 0 no array
  while (array[i] != 0) {
    if (array[i+1] != 0)
      printf(" %i,", array[i]);
    else
      printf(" %i\n", array[i]);
    i++;
  }

  // Imprime a carta restante
  printf("Remaining card: %i\n", x);
}
