#include <stdio.h>
#include <string.h>

#define SIZE 1000  // Define o tamanho máximo do array 'mine'

int main(void) 
{
  char mine[SIZE] = {'\0'};  // Inicializa o array 'mine' com caracteres nulos
  int time;  // Declara uma variável para armazenar o número de casos de teste
  scanf(" %i", &time);  // Lê o número de casos de teste a partir da entrada padrão
  
  while(time--)  // Loop para processar cada caso de teste
  {
    int i = -1, half = 0, j, diamonds = 0;  // Declara e inicializa variáveis
    
    setbuf(stdin, NULL);  // Limpa o buffer de entrada
    fgets(mine, SIZE, stdin);  // Lê uma linha de entrada e armazena no array 'mine'
    
    while(mine[++i] != '\0')  // Loop para percorrer cada caractere da linha lida
    {
      if(mine[i] == '<')  // Verifica se o caractere atual é '<'
      {
        half++;  // Incrementa o contador 'half' para indicar a metade do diamante
        mine[i] = '0';  // Substitui o caractere '<' por '0'
        j = i-1;  // Inicializa a variável 'j' para procurar a outra metade do diamante
        while(mine[++j] != '\0')  // Loop para procurar a outra metade do diamante
        {
          if(mine[j] == '>')  // Verifica se o caractere atual é '>'
          {
            half++;  // Incrementa o contador 'half' para indicar a outra metade do diamante
            mine[j] = '0';  // Substitui o caractere '>' por '0'
            i = -1;  // Reinicia a variável 'i' para recomeçar a busca por diamantes
            break;  // Sai do loop interno
          }
        }
      }
      if (half == 2)  // Verifica se ambas as metades do diamante foram encontradas
        diamonds++;  // Incrementa o contador de diamantes encontrados
      half = 0;  // Reinicializa o contador 'half' para a próxima busca
    }
    printf("%i\n", diamonds);  // Imprime o número de diamantes encontrados
    
    i = -1;  // Reinicializa a variável 'i' para limpar o array 'mine'
    while(mine[++i] != '\0')  // Loop para limpar o array 'mine'
      mine[i] = '\0';  // Substitui cada caractere por '\0'
  }
  return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}
