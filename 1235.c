#include <algorithm>   // Biblioteca para operações com algoritmos (ex: reverse)
#include <iostream>    // Biblioteca para operações de entrada e saída

using namespace std;

int main(){
    int N;            // Variável para armazenar o número de frases a serem invertidas
    string frase;     // Variável para armazenar cada frase

    cin >> N;         // Lê o número de frases
    cin.ignore();     // Ignora o caractere de nova linha após o número

    // Loop para processar cada frase
    for(int i = 0; i < N; ++i){
        getline(cin, frase);    // Lê a linha inteira como uma frase

        // Inverte a primeira metade da frase
        reverse(frase.begin(), frase.begin() + frase.length()/2);
        // Inverte a segunda metade da frase
        reverse(frase.begin() + frase.length()/2, frase.end());

        // Imprime a frase invertida
        cout << frase << endl;
    }

    return 0;   // Retorna 0 para indicar que o programa foi executado com sucesso
}
