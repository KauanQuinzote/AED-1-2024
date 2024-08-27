#include <iostream>
#include <vector>

#define MAX_N 500

// Matrizes globais para armazenar o tabuleiro e prefix sums.
int tabuleiro[MAX_N][MAX_N];
int black_prefix[MAX_N + 1][MAX_N + 1];
int white_prefix[MAX_N + 1][MAX_N + 1];

// Dimensões do tabuleiro e número de pedras.
int N, P;

// Função para marcar as pedras no tabuleiro para um jogador específico.
void marcarPedras(int pedras, int jogador) {
    for (int i = 0; i < pedras; i++) {
        int L, C;
        std::cin >> L >> C; // Lê a posição da pedra (linha, coluna)
        tabuleiro[L-1][C-1] = jogador; // Marca a pedra no tabuleiro
    }
}

// Função para preencher as somas prefixadas para pedras pretas e brancas.
void preencherPrefixSums() {
    // Calcula as somas prefixadas para pedras pretas e brancas
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // Calcula o prefix sum para pedras pretas e brancas
            black_prefix[i][j] = black_prefix[i-1][j] + black_prefix[i][j-1] - black_prefix[i-1][j-1];
            white_prefix[i][j] = white_prefix[i-1][j] + white_prefix[i][j-1] - white_prefix[i-1][j-1];
            
            // Atualiza o prefix sum com base na pedra no tabuleiro
            if (tabuleiro[i-1][j-1] == 1) {
                black_prefix[i][j]++;
            } else if (tabuleiro[i-1][j-1] == 2) {
                white_prefix[i][j]++;
            }
        }
    }
}

// Função para contar o número de subáreas contendo apenas pedras de um jogador específico.
int contarSubareas(int jogador) {
    int count = 0;

    // Verifica todos os tamanhos possíveis de subáreas
    for (int tamanho = 1; tamanho <= N; tamanho++) {
        for (int i = 0; i <= N - tamanho; i++) {
            for (int j = 0; j <= N - tamanho; j++) {
                // Coordenadas do canto superior esquerdo e inferior direito da subárea
                int x1 = i + 1, y1 = j + 1;
                int x2 = i + tamanho, y2 = j + tamanho;

                // Calcula o número de pedras pretas e brancas na subárea atual
                int black_count = black_prefix[x2][y2] - black_prefix[x1-1][y2] - black_prefix[x2][y1-1] + black_prefix[x1-1][y1-1];
                int white_count = white_prefix[x2][y2] - white_prefix[x1-1][y2] - white_prefix[x2][y1-1] + white_prefix[x1-1][y1-1];

                // Conta a subárea se ela contém apenas pedras do jogador específico
                if (jogador == 1 && black_count > 0 && white_count == 0) {
                    count++;
                } else if (jogador == 2 && white_count > 0 && black_count == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    std::cin >> N >> P; // Lê o tamanho do tabuleiro e o número de pedras

    // Marca as pedras para os dois jogadores
    marcarPedras(P, 1);  // Jogador das pedras pretas
    marcarPedras(P, 2);  // Jogador das pedras brancas

    preencherPrefixSums(); // Preenche as somas prefixadas

    // Conta o número de subáreas para cada jogador
    int pretas = contarSubareas(1);
    int brancas = contarSubareas(2);

    // Imprime o resultado
    std::cout << pretas << " " << brancas << std::endl;

    return 0;
}
