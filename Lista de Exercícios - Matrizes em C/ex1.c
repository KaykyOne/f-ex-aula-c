#include <stdio.h>

int main()
{
    int matriz[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("digite o valor da: %d-%d: ", i, j);
            scanf("%d", &matriz[j][i]);
        }
    }
        for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("valor da matriz: %d-%d: %d \n", i, j, matriz[j][i]);
        }
    }
    return 0;
}