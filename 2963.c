#include <stdio.h>

int main() {
    int i, n, bobo = 0, rest = 0, ans = 1;  // Declara variáveis

    scanf("%d", &n);  // Lê o número de elementos
    scanf("%d", &bobo);  // Lê o primeiro valor

    // Loop para ler os próximos n-1 valores
    for (i = 0; i < n-1; i++) {
        scanf("%d", &rest);  // Lê o próximo valor
        
        // Verifica se algum valor é maior que bobo
        if (rest > bobo)
            ans = 0;  // Define ans como 0 se encontrar um valor maior
    }
    
    // Imprime "S" se nenhum valor foi maior que bobo, caso contrário, "N"
    if (ans == 1)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
