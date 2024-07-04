#include <iostream>

using namespace std;

int main() 
{
    float lanche, qntd, valor, vf;

    // Lê o código do lanche e a quantidade desejada
    scanf("%f %f", &lanche, &qntd);

    // Verifica qual é o lanche e atribui o valor correspondente
    if (lanche == 1)
    {
        valor = 4;
    }
    else if (lanche == 2)
    {
        valor = 4.5;
    }
    else if (lanche == 3)
    {
        valor = 5;
    }
    else if (lanche == 4)
    {
        valor = 2;
    }
    else if (lanche == 5)
    {
        valor = 1.5;
    }
    else
    {
        // Se o código do lanche não for válido, o programa termina
        return 0;
    }

    // Calcula o valor final
    vf = valor * qntd;

    // Imprime o valor final com duas casas decimais
    printf("Total: R$ %.2f\n", vf);

    return 0;
}
