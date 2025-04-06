#include <stdio.h>

int main() {
    int array[2][2]; // Declara uma matriz 2x2 de inteiros

    // Preenchendo a matriz com valores fornecidos pelo usuário
    for (int i = 0; i < 2; i++) {
        // Loop para percorrer as linhas
        for (int j = 0; j < 2; j++) {
            // Loop para percorrer as colunas
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]); // Lê o valor e armazena na posição correta
        }
    }

    // Exibindo a matriz
    printf("\nTyped matrix:\n");
    for (int i = 0; i < 2; i++) {
        // Loop para percorrer as linhas novamente
        for (int j = 0; j < 2; j++) {
            // Loop para percorrer as colunas
            printf("%d\t", array[i][j]); // Imprime o valor da posição i,j
        }
        printf("\n"); // Quebra de linha após cada linha da matriz
    }

    return 0;
}
