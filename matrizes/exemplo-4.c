#include <stdio.h>
#include <stdlib.h> // necessário para malloc() e free()

int main() {
    int rows, columns;

    // Solicita o tamanho da matriz ao usuário
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Alocação dinâmica da matriz

    // Passo 1: aloca um vetor de ponteiros (linhas)
    int **matrix = (int**) malloc(rows * sizeof(int*));

    // Passo 2: para cada linha, aloca um vetor de inteiros (colunas)
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(columns * sizeof(int));
    }

    // Preenchendo a matriz
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Exibindo a matriz
    printf("\nTyped matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // libera cada linha
    }
    free(matrix); // libera o vetor de ponteiros

    return 0;
}
