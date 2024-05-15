#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

void infix_posfix(char *expression);
void push(char ch, Node *stack);
char pop(Node *stack);
int prio(char op);

int main() 
{
  int x;
  scanf("%d", &x);

  for (int i = 0; i < x; i++) 
  {
    char expression[301];
    scanf("%s", expression);
    infix_posfix(expression);
  }
  return 0;
}

void infix_posfix(char *expression) 
{
  //cria a cabeça da pilha
  Node head;
  Node *stack;
  stack = &head;
  stack->next = NULL;

  for (int i = 0; expression[i] != '\0'; i++)//enquanto não se findou a expressão
  {
    char sign = expression[i];//colete o caractere vigente
    
    if (isalnum(sign))//caso seja alfanumerico, já imprima
      printf("%c", sign); 
  
    else if (sign == '(') //caso seja um abre parenteses, começe a empilhar os caracteres
        push(sign, stack);

    else if (sign == ')')//caso seja um fecha, começa a desempilhar
    {
      while (stack->next != NULL && stack->next->data != '(') 
        printf("%c", pop(stack));
      
      pop(stack); 
    } 
    else//caso sign seja um operador
    {  
      while (stack->next != NULL && prio(sign) <= prio(stack->next->data))//enquanto não findou a pilha e o valor atual tem prioridade sobre o valor posterior
        printf("%c", pop(stack));
      
      push(sign, stack);
    }
  }
  while (stack->next) 
    printf("%c", pop(stack));
  
  printf("\n");
}

void push(char ch, Node *stack)//para empilhar um caractere 
{
  Node *new;
  new = malloc(sizeof(Node));
  new->data = ch;
  new->next = stack->next;
  stack->next = new;
}

char pop(Node *stack)//para desempilhar um caractere
{
  Node *trash;
  char sign;
  trash = stack->next;
  sign = trash->data;
  stack->next = trash->next;
  free(trash);
  return sign;
}

int prio(char op)//verifica a prioridade dos operadores
{
  if (op == '(')
    return 0;
  
  if (op == '+' || op == '-') 
    return 1;
  
  if (op == '*' || op == '/') 
    return 2;
  
  if (op == '^') 
    return 3;
  
  return -1;
}
  

