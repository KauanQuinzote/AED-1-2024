#include <stdio.h>

#define SIZE 100

int main() {
    
    int i, j, greather = 0, value[SIZE];
    
    // Lê 100 valores e armazena no array
    for (i = 0; i < SIZE; i++)
        scanf("%d", &value[i]);

    greather = value[0]; // Inicializa o maior valor com o primeiro elemento
    
    // Percorre o array para encontrar o maior valor
    for (i = 0; i < SIZE; i++) {  
        if (value[i] >= greather) {
            greather = value[i];
            j = i + 1; // Armazena a posição (1-based) do maior valor
        }
    }
    
    // Imprime o maior valor e sua posição
    printf("%d\n", greather);
    printf("%d\n", j);
    
    return 0;
}
