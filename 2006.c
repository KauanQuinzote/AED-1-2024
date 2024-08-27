#include <stdio.h>

int main() {
    
    int i, type, tea[5], amount = 0;
    
    // Lê o tipo de chá preferido
    scanf("%d", &type);
    
    // Loop para ler as respostas de 5 participantes
    for (i = 0; i < 5; i++) {
        scanf("%d", &tea[i]);
        
        // Verifica se a resposta é igual ao tipo de chá preferido
        if (tea[i] == type)
            amount++;
    }
    
    // Imprime a quantidade de respostas corretas
    printf("%d\n", amount);

    return 0;
}
