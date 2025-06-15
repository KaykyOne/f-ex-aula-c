#include <stdio.h>

int encontrarMaior(int v[], int tamanho) {
    int maior = v[0];
    for (int i = 1; i < tamanho; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int main() {
    int numeros[6] = {12, 45, 7, 89, 23, 56};

    int maior = encontrarMaior(numeros, 6);
    printf("Maior valor: %d\n", maior);

    return 0;
}
