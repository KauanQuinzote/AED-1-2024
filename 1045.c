#include <iostream>

using namespace std;

int main() {
    float A, B, C, temp;

    // Lê três valores de ponto flutuante
    scanf("%f %f %f", &A, &B, &C);

    // Ordena os valores em ordem decrescente
    if (A < B) {
        temp = A;
        A = B;
        B = temp;
    }

    if (A < C) {
        temp = A;
        A = C;
        C = temp;
    }

    if (B < C) {
        temp = B;
        B = C;
        C = temp;
    }

    // Verifica se os valores formam um triângulo
    if (A >= (B + C) || B >= (A + C) || C >= (A + B) || A <= 0 || B <= 0 || C <= 0) {
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }

    // Verifica o tipo de triângulo
    if ((A * A) == ((B * B) + (C * C)) || (B * B) == ((A * A) + (C * C)) || (C * C) == ((A * A) + (B * B))) {
        printf("TRIANGULO RETANGULO\n");
    }

    if ((A * A) > (B * B + C * C) || (B * B) > (A * A + C * C) || (C * C) > (A * A + B * B)) {
        printf("TRIANGULO OBTUSANGULO\n");
    }

    if ((A * A) < ((B * B) + (C * C)) && (B * B) < (A * A + C * C) && (C * C) < (A * A + B * B)) {
        printf("TRIANGULO ACUTANGULO\n");
    }

    if (A == B && A == C) {
        printf("TRIANGULO EQUILATERO\n");
    }

    if ((A == B && A != C) || (B == C && B != A) || (A == C && A != B)) {
        printf("TRIANGULO ISOSCELES\n");
    }

    return 0;
}
