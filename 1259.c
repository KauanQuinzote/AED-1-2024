#include <stdio.h>
#define SIZE 100000

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para imprimir um vetor
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

// Função Bubble Sort para ordem crescente
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Função Bubble Sort para ordem decrescente
void bubbleSortDesc(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(void) {
    int x, i = -1, num, even[SIZE], odd[SIZE], e = 0, o = 0;
    
    // Lê o número de elementos
    scanf("%i", &x);

    // Lê os elementos e separa em pares e ímpares
    while(++i < x) {
        scanf("%i", &num);

        if(num % 2 == 0)
            even[e++] = num;
        else
            odd[o++] = num;
    }

    // Ordena os elementos pares em ordem crescente
    bubbleSort(even, e);
    // Ordena os elementos ímpares em ordem decrescente
    bubbleSortDesc(odd, o);
    
    // Imprime os vetores ordenados
    printArray(even, e);
    printArray(odd, o);
    
    return 0;
}
