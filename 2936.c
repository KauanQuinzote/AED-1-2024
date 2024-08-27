#include <stdio.h>
#define y 5  // Define o tamanho do array

int main() {
    int x[y], amount[5] = {300, 1500, 600, 1000, 150};  // Array de entradas e valores associados
    int i = -1, sum = 0;  // Índice e soma total

    // Lê 5 valores do usuário para o array x
    while (++i < y)
        scanf("%i", &x[i]);

    i = -1;
    // Calcula a soma ponderada dos valores em x
    while (++i < y)
        sum += x[i] * amount[i];
    
    printf("%d\n", sum + 225);  // Imprime a soma total acrescida de 225

    return 0;
}
