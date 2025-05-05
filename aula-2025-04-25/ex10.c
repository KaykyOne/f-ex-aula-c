#include <stdio.h>
#define TAM 6

int main() {
    int vetor[TAM] = {5, 10, 15, 20, 25, 30};
    int valor = 20;
    int inicio = 0;
    int fim = TAM - 1;
    int meio;
    int encontrado = -1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        printf("Verificando posição %d: %d\n", meio, vetor[meio]);

        if (vetor[meio] == valor) {
            encontrado = meio;
            printf("Valor %d encontrado na posição %d.\n", valor, meio);
            break;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado == -1) {
        printf("Valor %d não encontrado no vetor.\n", valor);
    }

    return 0;
}
