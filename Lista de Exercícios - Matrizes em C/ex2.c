#include <stdio.h>

int main()
{
    int tamanho = 3;
    int matriz[tamanho][tamanho];
    int soma = 0;
    float media = 0;
    int diagonalPrincipal[tamanho];

    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            soma += matriz[i][j];
            if(i == j){
                diagonalPrincipal[i] = matriz[i][j];
            }
        }
    }

    media = (float)soma / (tamanho * tamanho);

    printf("\nSoma: %d\n", soma);
    printf("Média: %.2f\n", media);

    printf("Números da diagonal principal: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", diagonalPrincipal[i]);
    }
    printf("\n");

    return 0;
}
