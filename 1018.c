#include <iostream>
 
using namespace std;
 
int main(){
    
    int money, quanticem, restcem, quanticinqueta, restcinquenta, quantivinte, restvinte,
    quantidez, restdez,quanticinco, restcinco, quantidois, restdois, quantium;
    
    scanf("%d", &money);
    
    //divide por 100
    
    quanticem = money/100;
    restcem = money%100;
    
    //divide por 50
    
    
    quanticinqueta = restcem/50;
    restcinquenta = restcem%50;
    
    //divide por 20
    
    quantivinte = restcinquenta/20;
    restvinte = restcinquenta%20;
    
    //divide por 10
    
    quantidez = restvinte/10;
    restdez = restvinte%10;
    
    //divide por 5
    
    quanticinco = restdez/5;
    restcinco = restdez%5;
    
    //divide por 2
    
    quantidois = restcinco/2;
    restdois = restcinco%2;
    
    //divide por 1
    
    quantium = restdois/1;
    
    //imprime resultado
    
    printf("%d\n", money);
    printf("%d nota(s) de R$ 100,00\n", quanticem);
    printf("%d nota(s) de R$ 50,00\n", quanticinqueta);
    printf("%d nota(s) de R$ 20,00\n", quantivinte);
    printf("%d nota(s) de R$ 10,00\n", quantidez);
    printf("%d nota(s) de R$ 5,00\n", quanticinco);
    printf("%d nota(s) de R$ 2,00\n", quantidois);
    printf("%d nota(s) de R$ 1,00\n", quantium);

    return 0;
}