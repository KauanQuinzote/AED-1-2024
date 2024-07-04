#include <cstdio>   // Biblioteca para operações de entrada e saída em C

// Função recursiva para resolver o problema de Josephus
// Retorna a posição final sobrevivente
int josephus(int n, int k) {
    if (n == 1)
        return 1;   // Caso base: se houver apenas uma pessoa, ela é a sobrevivente
    return (josephus(n - 1, k) + k - 1) % n + 1;   // Fórmula recursiva de Josephus
}

int main() {
    int cases;   // Variável para o número de casos
    scanf("%d", &cases);   // Lê o número de casos

    // Loop para processar cada caso
    for (int i = 1; i <= cases; i++) {
        int u, v;   // Variáveis para os parâmetros u e v do problema
        scanf("%d %d", &u, &v);   // Lê os valores de u e v

        // Calcula o resultado usando a função josephus e imprime o resultado formatado
        printf("Case %d: %d\n", i, josephus(u, v));
    }

    return 0;   // Retorna 0 para indicar que o programa foi executado com sucesso
}
