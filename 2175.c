#include <stdio.h>

int main() {
    
    float otavio, bruno, ian;
    
    // Lê os valores de Otavio, Bruno e Ian
    scanf("%f %f %f", &otavio, &bruno, &ian);
    
    // Verifica se há empate
    if (otavio == bruno || otavio == ian || bruno == ian)        
        printf("Empate\n");
    else {
        // Verifica quem tem o menor valor e imprime o nome correspondente
        if (otavio < bruno && otavio < ian)     
            printf("Otavio\n");
        else if (bruno < otavio && bruno < ian)            
            printf("Bruno\n");
        else
            printf("Ian\n");
    }
    
    return 0;
}
