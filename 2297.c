#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <stdio.h>  // Biblioteca padrão para entrada e saída

int main()
{
    int z, a, b, i, r, sumA, sumB;

    for(z = 1;; z++) // Loop infinito com incremento de z a cada iteração
    {
        scanf("%i", &r); // Lê o valor de r
        if (r == 0) 
            break; // Se r for 0, sai do loop
        else
        {
            sumA = 0; // Inicializa a soma de A
            sumB = 0; // Inicializa a soma de B
            for (i = 0; i < r; i++) // Loop para ler r pares de valores
            {
                scanf("%i %i", &a, &b); // Lê os valores de a e b
                sumA = sumA + a; // Adiciona a ao total de sumA
                sumB = sumB + b; // Adiciona b ao total de sumB
            }
            if (sumA > sumB)
                printf("Teste %i\nAldo\n\n", z); // Imprime resultado se sumA for maior que sumB
                
            if (sumB > sumA)
                printf("Teste %i\nBeto\n\n", z); // Imprime resultado se sumB for maior que sumA
        }
    }
    return 0; // Termina o programa
}
