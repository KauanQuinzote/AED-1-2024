#include <stdio.h>
#include <stdbool.h>

int verifying_instances();//verifica quantas instancias de sudoku serão preenchidas
void filling_matrix(int matrix[9][9]);//preenche a matriz 9x9
bool verifying_number_is_correct(int x);//verifica se os numeros preenchidos estão entre 1 e 9
bool verifying_rows(int matrix[9][9]);//verifica se as linhas do sudoku contém algarismos duplicados
bool verifying_columns(int matrix[9][9]);//verifica se as colunas do sudoku contém algarismos duplicados
bool verifying_blocks(int matrix[9][9]);//verifica se as submatrizes do sudoku contém algarismos duplicados
void printing_no(int i);//imprimirá não caso não seja um sudoku
void printing_yes(int i);//imprimirá sim caso seja um sudoku
void update_bool(bool aux[9]);//atualizará o vetor auxiliar inteiro para false novamente

int main(){ 
    int matrix[9][9], instances, i;

    instances = verifying_instances();

    for (i = 1; i <= instances; i++)
    {
        filling_matrix(matrix);//preenche a matriz 9x9 da instancia vigente

        if (verifying_rows(matrix )&& verifying_columns(matrix) && verifying_blocks(matrix))//se todas as linhas não estiverem corretas, a matriz não atende ao sudoku
            { 
                printing_yes(i);
            }
            else printing_no(i); 
    }
return 0;
}

int verifying_instances(){
    
    int instances;

    scanf("%i", &instances);//quantas instâncias serão analizadas?
    
    if(instances > 0) return instances;

}

void filling_matrix(int matrix[9][9]){

    int i,j;

    for ( i = 0; i < 9; i++)//preenche todas as entradas da matriz 9x9
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%i", &matrix[i][j]);

            if(!verifying_number_is_correct(matrix[i][j]))//se o número não for de 1 a 9, saia!
            {
            }         
        }
    }
}

bool verifying_number_is_correct(int x){

    if(x < 1 || x > 9) return false;//se o número for menor que 0 ou maior que 9, retorne que ele não está correto!

    return true;
}

void printing_no(int i){
    printf("Instancia %i\nNAO\n\n", i);//Não é um Sudoku
}

void printing_yes(int i){
    printf("Instancia %i\nSIM\n\n", i);//É um sudoku
}

bool verifying_rows(int matrix[9][9]){

    int i, j;
    bool aux[9] = {false};

    for ( i = 0; i < 9; i++)//ordem de iteração: de linha em linha
    {
        for (j = 0; j < 9; j++)
        {
            int x = matrix[i][j] - 1;
            if(aux[x])//caso o algarismo em questão corresponda a uma entrada verdadeira, então ele já foi verificado (não é um sudoku)
            {
                return false;
            }
            aux[x] = true;//caso não tenha sido verificado o algarismo em questão, a sua posição congruente no vetor auxiliar será atualizada
        }
        update_bool(aux);//seta bool para false novamente
    }
    return true;
}

bool verifying_columns(int matrix[9][9]){

    int i, j;
    bool aux[9] = {false};

    for ( j = 0; j < 9; j++)//ordem de iteração: colunas em colunas
    {
        for (i = 0; i < 9; i++)
        {
            int x = matrix[i][j]-1;

            if (aux[x])//caso o algarismo já tenha sido verificado(true), ele está duplicado (não é um sudoku)
            {
                return false;
            }
            aux[x] = true;//caso ainda não tenha sido verificado, atualize sua respectiva posição no vetor auxiliar
        }
        update_bool(aux);//seta bool para false novamente
    }
    return true;

}

bool verifying_blocks(int matrix[9][9]){

    int i, j, lin = 0, col = 0, block = 1;
    
    bool aux[9] = {false};

    while(block <= 9){//enquanto não se verificou os nove blocos

        for (i = lin; i < lin+3; i++)//verifica as colunas do bloco
        {
            for (j = col; j < col+3; j++)//verifica as linhas do bloco
            {
                int x = matrix[i][j]-1;

                if(aux[x]) return false;//se o algarismo já foi verificado (true), não é um sudoku

                aux[x] = true;//caso contrario, atualize a respectiva posição no vetor auxiliar
            }
            
        }
        update_bool(aux);
    
        col+=3;//colunas devem iterar de 3 em 3 a cada bloco verificado, pois suas dimensões são 3x3

        if(block%3 == 0){//caso o bloco verificado estejam à direita, siginifica que deve-se resetar as colunas (para voltar a verificar da esquerda para direita)
            lin +=3;//a liha iterará +3 pois o sudoku tem dimensões 3 colunas x 3 linhas
            col = 0;
        }

    
        block++;
    }
    
    return true;
}

void update_bool(bool aux[9])
{
    for (int i = 0; i < 10; i++)//vetor auxiliar é resetado novamente para validar a proxima verificação
    {
        aux[i] = false;
    }
}
