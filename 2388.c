#include <stdio.h>

int main() {
    
    int i, x, time, speed, distance = 0;
    
    // Lê o número de pares de valores
    scanf("%d", &x);
    
    // Loop para ler tempo e velocidade e calcular a distância
    for (i = 0; i < x; i++) {
        scanf("%d %d", &time, &speed);
        distance += time * speed; // Calcula a distância acumulada
    }
    
    // Imprime a distância total
    printf("%d\n", distance);

    return 0;
}
