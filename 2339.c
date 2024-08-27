#include <stdio.h>

int main() {

    int C, P, F;
    
    // Lê os valores de C, P e F
    scanf("%d %d %d", &C, &P, &F);
    
    // Verifica se o número total de fatias necessárias é maior que o número de fatias disponíveis
    if (C * F > P)
        printf("N\n"); // Imprime "N" se não houver fatias suficientes
    else        
        printf("S\n"); // Imprime "S" se houver fatias suficientes

    return 0;
}
