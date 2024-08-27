#include <stdio.h>

int main() {
    
    int grau;
    
    // Loop que continua até o fim da entrada (EOF)
    while (scanf("%d", &grau) != EOF) {
        
        // Verifica o valor do grau e imprime a mensagem correspondente
        if (grau == 360 || (grau >= 0 && grau < 90))
            printf("Bom Dia!!\n"); // Mensagem para graus de 0 a 90 (inclusive 360)
        else if (grau >= 90 && grau < 180)
            printf("Boa Tarde!!\n"); // Mensagem para graus entre 90 e 179
        else if (grau >= 180 && grau < 270)
            printf("Boa Noite!!\n"); // Mensagem para graus entre 180 e 269
        else
            printf("De Madrugada!!\n"); // Mensagem para graus entre 270 e 359
    }

    return 0;
}
