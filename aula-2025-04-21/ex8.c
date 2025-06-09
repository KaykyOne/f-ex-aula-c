#include <stdio.h>
#define TAM 6

int main() {
    int vetor[TAM] = {5, 10, 15, 20, 30, 50};
    int valor = 20;
    int i;
    int encontrado = -1;

    for (i = 0; i < TAM; i++) {
        printf("Comparando com posição %d: %d\n", i, vetor[i]);

        if (vetor[i] == valor) {
            encontrado = i;
            printf("Valor %d encontrado na posição %d\n", valor, i);
            break;
        } else if (vetor[i] > valor) {
            printf("Parando: valor %d não está no vetor.\n", valor);
            break;
        }
    }

    if (encontrado == -1) {
        printf("Valor %d não encontrado no vetor.\n", valor);
    }

    return 0;
}
