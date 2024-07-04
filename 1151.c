#include <iostream>   // Biblioteca para operações de entrada e saída
#include <cmath>      // Biblioteca para funções matemáticas
using namespace std;

// Protótipo da função fibonacci
int fibonacci(int n);

int main()
{
    int n, i, j;   // Variáveis para o número de termos da sequência e iterações
    cin >> n;      // Lê o número de termos da sequência Fibonacci a serem gerados

    // Loop para gerar e imprimir os termos da sequência Fibonacci
    for (i = 0; i < n; i++) {
        if (i < (n - 1))
            cout << fibonacci(i) << " ";   // Imprime o termo seguido de espaço
        else
            cout << fibonacci(i) << endl;  // Imprime o último termo seguido de nova linha
    }

    return 0;   // Retorna 0 para indicar que o programa foi executado com sucesso
}

// Função recursiva para calcular o n-ésimo termo da sequência Fibonacci
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;   // Retorna 0 ou 1 para os casos base da sequência Fibonacci
    else
        return fibonacci(n - 1) + fibonacci(n - 2);   // Calcula o termo usando recursão
}
