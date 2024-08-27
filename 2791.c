#include <stdio.h>

int main() {
    int i, x[4], aux = 0;  // Declara variáveis e array

    // Loop para ler 4 inteiros do usuário
    for (i = 1; i <= 4; i++) {
        scanf("%d", &x[i]);  // Lê um valor para x[i]
        
        // Atualiza aux se x[i] for 1
        if (x[i] == 1)
            aux = i;
    }
    
    printf("%d\n", aux);  // Imprime o índice onde o valor 1 foi encontrado

    return 0;
}
