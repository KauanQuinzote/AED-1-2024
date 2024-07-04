#include <iostream>
 
using namespace std;
 
int main(){
    
    int seconds, hour, minutes, restsec;
    
    scanf("%d", &seconds);
    
    hour = seconds/3600;
    minutes = (seconds%3600)/60;
    restsec = seconds%60;
    
    printf("%d:%d:%d\n", hour, minutes, restsec);
    
}