#include <stdio.h>
#include <stdbool.h>

// Declaração das funções
int which_instances();
void filling_matrix(int matrix[9][9]);
bool scanning_matrix_columns(int matrix[9][9]);
bool scanning_matrix_rows(int matrix[9][9]);
bool scanning_matrix_blocks(int matrix[9][9]);
void printing_no(int instance);
void printing_yes(int instance);

int main() {
    int instances, i, matrix[9][9];

    instances = which_instances(); // Solicita quantidade de instâncias

    for(i = 0; i < instances; i++) {
        filling_matrix(matrix); // Preenchendo matriz

        // Verificação das colunas, linhas e blocos
        if (scanning_matrix_columns(matrix) || scanning_matrix_rows(matrix) || scanning_matrix_blocks(matrix)) {
            printing_no(i); // Imprime NAO se houver algum problema
        } else {
            printing_yes(i); // Imprime SIM se não houver problemas
        }
    }

    return 0;
}

// Função para solicitar a quantidade de instâncias ao usuário
int which_instances() {
    int instances;
    scanf("%i", &instances);
    return instances;
}

// Função para preencher a matriz do jogo Sudoku
void filling_matrix(int matrix[9][9]) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%i", &matrix[i][j]);
        }
    }
}

// Função para verificar se há números repetidos em colunas
bool scanning_matrix_columns(int matrix[9][9]) {
    int current_numb;
    bool used_number[9] = {false};

    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            current_numb = matrix[row][col];
            if (used_number[current_numb]) {
                return true;
            }
            used_number[current_numb] = true;
        }
        // Resetar o array used_number para false após cada coluna ser verificada
        for (int k = 0; k < 9; k++) {
            used_number[k] = false;
        }
    }
    return false;
}

// Função para verificar se há números repetidos em linhas
bool scanning_matrix_rows(int matrix[9][9]) {
    int current_numb;
    bool used_number[9] = {false};

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            current_numb = matrix[row][col];
            if (used_number[current_numb]) {
                return true;
            }
            used_number[current_numb] = true;
        }
        // Resetar o array used_number para false após cada linha ser verificada
        for (int k = 0; k < 9; k++) {
            used_number[k] = false;
        }
    }
    return false;
}

// Função para verificar se há números repetidos em blocos
bool scanning_matrix_blocks(int matrix[9][9]) {
    int current_numb;
    bool used_number[9] = {false};

    for (int block_row = 0; block_row < 9; block_row += 3) {
        for (int block_col = 0; block_col < 9; block_col += 3) {
            // Reinicializar o array used_number para cada novo bloco
            for (int k = 0; k < 9; k++) {
                used_number[k] = false;
            }

            for (int row = block_row; row < block_row + 3; row++) {
                for (int col = block_col; col < block_col + 3; col++) {
                    current_numb = matrix[row][col];
                    if (used_number[current_numb - 1]) {
                        return true;
                    }
                    used_number[current_numb - 1] = true;
                }
            }
        }
    }
    return false;
}

// Função para imprimir o resultado quando há um problema
void printing_no(int instance) {
    printf("Instancia %i\n", instance + 1);
    printf("NAO\n");
}

// Função para imprimir o resultado quando está tudo correto
void printing_yes(int instance) {
    printf("Instancia %i\n", instance + 1);
    printf("SIM\n");
}
