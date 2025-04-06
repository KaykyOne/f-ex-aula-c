#include <stdio.h>

int main() {
    int matriz[2][2];
    int soma = 0;

    // Leitura da matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j]; // Acumula a soma dos elementos
        }
    }

    // Exibe a soma
    printf("Sum of all elements: %d\n", soma);

    return 0;
}
