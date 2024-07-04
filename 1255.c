#include <iostream>   // Biblioteca para operações de entrada e saída
#include <cctype>     // Biblioteca para operações com caracteres
#include <map>        // Biblioteca para uso de mapas (estrutura de dados)

using namespace std;

int main(){
    int N, maior;               // Variáveis inteiras para armazenar o número de casos e a maior frequência
    string frase;               // Variável para armazenar a frase a ser analisada
    map<char, int> frequencias; // Mapa para armazenar a frequência dos caracteres

    cin >> N;                   // Lê o número de casos
    cin.ignore();               // Ignora o caractere de nova linha após o número

    // Loop para processar cada caso
    for(int i = 0; i < N; ++i){
        frequencias.clear();    // Limpa o mapa de frequências para cada nova frase

        getline(cin, frase);    // Lê a frase completa

        // Loop para processar cada caractere da frase
        for(int j = 0; j < frase.length(); ++j){
            if(isalpha(frase[j])){               // Verifica se o caractere é uma letra
                frase[j] = tolower(frase[j]);    // Converte a letra para minúscula
                if(!frequencias.count(frase[j])) // Se a letra não está no mapa
                    frequencias[frase[j]] = 0;   // Inicializa a frequência da letra
                frequencias[frase[j]]++;         // Incrementa a frequência da letra
            }
        }

        maior = 0; // Inicializa a maior frequência como 0
        // Loop para encontrar a maior frequência no mapa
        for(map<char, int>::iterator it = frequencias.begin(); it != frequencias.end(); ++it){
            if(it->second > maior)  maior = it->second; // Atualiza a maior frequência
        }

        // Loop para imprimir as letras com a maior frequência
        for(map<char, int>::iterator it = frequencias.begin(); it != frequencias.end(); ++it){
            if(it->second == maior) cout << it->first; // Imprime a letra se sua frequência é a maior
        }
        cout << endl; // Nova linha após imprimir todas as letras com a maior frequência
    }

    return 0; // Retorno da função principal
}
