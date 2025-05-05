#include <stdio.h>
#define TAM 10

int main() {
    int vetor[TAM] = {5, 10, 20, 25, 30};
    int n = 5;
    int valor = 20;
    int i, j;
    int encontrado = -1;

    for (i = 0; i < n; i++) {
        printf("Comparando com posição %d: %d\n", i, vetor[i]);

        if (vetor[i] == valor) {
            encontrado = i;
            printf("Valor %d encontrado na posição %d\n", valor, i);
            break;
        } else if (vetor[i] > valor) {
            printf("Valor não encontrado (interrompido pela ordenação).\n");
            break;
        }
    }

    if (encontrado != -1) {
        for (j = encontrado; j < n - 1; j++) {
            vetor[j] = vetor[j + 1];
        }

        n--;
        printf("Valor %d removido do vetor.\n", valor);
    } else {
        printf("Valor %d não encontrado no vetor.\n", valor);
    }

    printf("Vetor após exclusão: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}
