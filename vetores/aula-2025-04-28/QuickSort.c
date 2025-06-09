#include <stdio.h>
#define TAM 6

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = vetor[inicio];
        int i = inicio + 1;
        int j = fim;

        while (i <= j) {
            if (vetor[i] <= pivo) {
                i++;
            } else if (vetor[j] > pivo) {
                j--;
            } else {
                troca(&vetor[i], &vetor[j]);
                i++;
                j--;
            }
        }

        troca(&vetor[inicio], &vetor[j]);

        quicksort(vetor, inicio, j - 1);
        quicksort(vetor, j + 1, fim);
    }
}

int main() {
    int numeros[TAM] = {20, 10, 40, 30, 60, 50};
    int i;

    quicksort(numeros, 0, TAM - 1);

    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
