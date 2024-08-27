#include <stdio.h>
#include <stdlib.h>

// Declaração da função searching que irá analisar o array
void searching(int array[], int size);

int main(void) {
  char *loop;
  int x;
  
  // Loop que lê o tamanho do array enquanto for um número válido
  while(1)
  {
    scanf("%i", &x);

    if (x == 0)
      break;
    // Alocação dinâmica de memória para o array de inteiros
    int *array = (int*) malloc(x * sizeof(int));

    int i = -1;
    // Loop que lê os elementos do array
    while(++i < x)
      scanf("%i", &array[i]);
    
    // Chama a função searching para analisar o array
    searching(array, x);

    // Libera a memória alocada
    free(array);
  }  
  return 0;
}

// Função que analisa o array e conta as mudanças de tendência
void searching(int array[], int size)
{
  int p = 0; // Contador de mudanças de tendência
  
  char loop[size]; // Array para armazenar as tendências ('U' ou 'D')
  
  int i = -1;

  // Loop que analisa o array e define as tendências
  while(++i < size)
  {
    if(i == 0) // Se for o primeiro número analisado
    {
      if(array[0] < array[size-1])
        loop[0] = 'D'; // Se o primeiro for menor que o último, tendência é descendente
      else if(array[0] > array[size-1])
        loop[0] = 'U'; // Se o primeiro for maior que o último, tendência é ascendente
      else
        continue; // Se forem iguais, continua sem definir a tendência
    }
    else
    {
      if(array[i] < array[i-1])
        loop[i] = 'D'; // Se o atual for menor que o anterior, tendência é descendente
      else
        loop[i] = 'U'; // Caso contrário, tendência é ascendente
    }
  }

  i = 0;

  // Loop que conta as mudanças de tendência
  while (++i < size)
  {
    if(loop[i] != loop[i-1])
      p++; // Incrementa o contador se houver mudança de tendência
  }

  // Incrementa o contador se a primeira tendência for diferente da última
  if(loop[0] != loop[size-1])
    p++;

  // Imprime o número total de mudanças de tendência
  printf("%i\n", p);
}
