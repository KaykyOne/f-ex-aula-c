#include <stdio.h>
#define TAM 5

int main() {
    int numeros[TAM] = {50, 10, 30, 20, 40};
    int i, j, temp;

    for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");
    return 0;
}
