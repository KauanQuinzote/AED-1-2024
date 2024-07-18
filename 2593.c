#include <stdio.h>
#include <string.h>

// Função para verificar a existência de uma palavra em uma string a partir de um índice
int exist(char *str, char *word, int index)
{
  char *ptr, *adr;
  
  // Procura a palavra na string
  ptr = strstr(str, word);
  adr = str;
  
  if(ptr) // se encontrei a palavra na frase
  {
    // enquanto o endereço apontado não for o mesmo endereço da palavra encontrada,
    // itere o índice e o endereço de memória de adr
    while(adr != ptr)
    {
      adr++;
      index++;
    }
  }
  else
    return -1; // Retorna -1 se a palavra não for encontrada
  
  return index; // Retorna o índice onde a palavra foi encontrada
}

int main(void) {

  char sentence[10000], word[128][50], *cutting;
  int words, index;
  
  setbuf(stdin, NULL); // Desabilita o buffer do stdin
  fgets(sentence, 10000, stdin); // Lê uma linha de entrada
  
  // Remove o caractere de nova linha ao final da string, se existir
  sentence[strcspn(sentence, "\n")] = '\0';

  scanf("%i", &words); // Lê o número de palavras a serem buscadas

  // Lê as palavras a serem buscadas
  for(int i = 0 ; i < words; i++)
    scanf("%49s", word[i]);
  
  int i = -1;
  while(++i < words)
  {
    int id = 0;
    // Remove o caractere de nova linha ao final da string, se existir
    word[i][strcspn(word[i], "\n")] = '\0';

    cutting = sentence;
    
    while(*cutting)
    {
      index = exist(cutting, word[i], id); // busca o índice da palavra na string
      if(index == -1)
        break; // Se a palavra não for encontrada, saia do loop
    
      printf("%i ", index); // Imprime o índice
      // Atualiza o ponteiro 'cutting' para continuar a busca a partir do final da palavra encontrada
      cutting += (index + strlen(word[i]));
      // Atualiza o índice 'id' para continuar a busca a partir do final da palavra encontrada
      id += (index + strlen(word[i]));
    }
    printf("\n");
  }             
  return 0;
}
