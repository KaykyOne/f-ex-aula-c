#include <stdio.h>

int main() {
    int rows, columns;

    // User defines the size of the array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Declaring a variable-length array (VLA - valid in C99+)
    int matrix[rows][columns];

    // Filling the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Displaying the matrix
    printf("\nTyped matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
