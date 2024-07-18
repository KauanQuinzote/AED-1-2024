#include <iostream>   // Biblioteca para operações de entrada e saída em C++

using namespace std;

int main() 
{
    // Declaração das variáveis para número do funcionário, horas trabalhadas e valor por hora
    int numberfunc;
    int hour;
    float cash;
    
    // Leitura dos valores de entrada: número do funcionário, horas trabalhadas e valor por hora
    scanf("%d %d %f", &numberfunc, &hour, &cash);
    
    // Cálculo do salário do funcionário
    float salary = hour * cash;
    
    // Impressão do número do funcionário e do salário formatado
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", numberfunc, salary);
    
    return 0;   // Retorna 0 para indicar que o programa foi executado com sucesso
}
