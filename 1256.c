#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função que calcula o módulo
int mod(int x, int QUO)
{
  int y, z;
  y = x / QUO;
  return z = x - y * QUO;
}

// Função para inserir um valor na matriz
void insert(char *num, int keys, int **matrix)
{
  int i, id, col = -1;
  
  i = atoi(num); // Converte a string num para um inteiro
  id = mod(i, keys); // Calcula o índice id usando a função mod

  // Encontra a próxima coluna livre (valor 0) na linha especificada por id
  while (matrix[id][++col] != 0)
    continue;
  
  matrix[id][col] = i; // Insere o valor i na posição encontrada
}

// Função para alocar dinamicamente a matriz
void make_matrix(int keys, int values, int ***matrix)
{
  int i;
  int ***aux = matrix;
  *aux = (int **)malloc(keys * sizeof(int *));

  i = -1;
  while (++i < keys)
    *aux[i] = (int *)malloc(values * sizeof(int));
}

int main(void)
{
  int tests, keys, values, i, x;
  char string[100], string_2[200], *token, delimiters[] = " ";
  
  // Lê o número de testes
  scanf("%i", &tests);
  
  while (tests--)
  {
    setbuf(stdin, NULL);
    fgets(string, 100, stdin);
    sscanf(string, "%i %i", &keys, &values); // Lê o número de chaves e valores
    
    int i = -1, **matrix;
    matrix = (int **)malloc(keys * sizeof(int *));
    
    // Aloca dinamicamente a matriz
    while (++i < keys)
      matrix[i] = (int *)malloc(values * sizeof(int));
    
    setbuf(stdin, NULL);
    fgets(string_2, 200, stdin); // Lê a linha de valores

    token = strtok(string_2, delimiters); // Divide a string em tokens
    while (token)
    {
      insert(token, keys, matrix); // Insere cada token na matriz
      token = strtok(NULL, delimiters); // Pega o próximo token
    }
    
    i = -1;
    // Imprime a matriz resultante
    while (++i < keys)
    {
      printf("%i -> ", i);
      if (matrix[i] != 0)
      {
        x = -1;
        while (matrix[i][++x] != 0)
          printf("%i -> ", matrix[i][x]);
      }
      printf("\\\n");
    }
  }
  return 0;
}
