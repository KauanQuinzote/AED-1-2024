#include <iostream>

using namespace std;

int main() {
    int i, j, v[10];
  
    // Lê um valor inteiro e armazena em j
    scanf("%d", &j);

    // Inicializa o primeiro elemento do array v com o valor lido
    v[0] = j;
  
    // Preenche o array v, onde cada elemento é o dobro do anterior
    for (i = 1; i < 10; i++) {
        v[i] = v[i-1] * 2;
    }

    // Imprime o array v
    for (i = 0; i < 10; i++) {
        printf("N[%d] = %d\n", i, v[i]);
    }

    return 0;
}
