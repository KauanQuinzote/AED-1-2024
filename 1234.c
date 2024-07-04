#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int n;
    bool maiuscula;
    string sentenca;

    // Loop para ler múltiplas linhas de entrada até o final do arquivo (EOF)
    while (getline(cin, sentenca)) {
        maiuscula = true;

        // Loop para processar cada caractere da linha lida
        for (int i = 0; i < sentenca.length(); ++i) {
            // Ignora caracteres que não são letras
            if (!isalpha(sentenca[i])) {
                continue;
            }

            // Alterna entre maiúscula e minúscula
            if (maiuscula) {
                sentenca[i] = toupper(sentenca[i]);
            } else {
                sentenca[i] = tolower(sentenca[i]);
            }

            // Alterna o estado da variável maiuscula
            maiuscula = !maiuscula;
        }

        // Imprime a sentença modificada
        cout << sentenca << endl;
    }

    return 0;
}
