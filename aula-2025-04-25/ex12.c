#include <stdio.h>
#define TAM 5

int main() {
    int numeros[TAM] = {29, 10, 14, 37, 13};
    int i, j, min, temp;

    for (i = 0; i < TAM - 1; i++) {
        min = i;
        for (j = i + 1; j < TAM; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = numeros[i];
            numeros[i] = numeros[min];
            numeros[min] = temp;
        }
    }

    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");
    return 0;
}
