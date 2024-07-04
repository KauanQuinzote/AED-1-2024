#include <iostream>

using namespace std;

int main() {
    int line, counter;

    // Lê o número de linhas
    scanf("%d", &line);

    // Loop para imprimir os valores e "PUM"
    for (counter = 1; counter <= (line * 4); counter++) {
        if (counter % 4 == 0) {
            // Imprime "PUM" ao invés do número a cada múltiplo de 4
            printf("PUM\n");
        } else {
            // Imprime o número
            printf("%d ", counter);
        }
    }

    return 0;
}
