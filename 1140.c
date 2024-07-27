#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

int main(void) {
  char sentence[SIZE], delimiters[] = " ", *token;

  do {
    setbuf(stdin, NULL);
    fgets(sentence, SIZE, stdin);           // Lê a sentença do usuário
    token = strtok(sentence, delimiters);   // Divide a sentença em tokens
    
    do {      
      if (tolower(token[0]) != tolower(sentence[0])) { // Verifica a primeira letra do token
        printf("N\n"); 
        break;
      }
      token = strtok(NULL, delimiters);     // Pega o próximo token
      
    } while (token != NULL); 
    
    if (!token) 
      printf("Y\n"); 
  } while (sentence[0] != '*');             // Continua até encontrar '*'
  
  return 0;
}
