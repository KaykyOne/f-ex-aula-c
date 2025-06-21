#include <stdio.h>

int main()
{
    int vetor[5];
    
    printf("Digite os valores para os respectivos lugares:\n");
    for(int i = 0; i < 5; i++){
        printf("Digite o valor para: %d\n", (i + 1));
        scanf("%d", &vetor[i]);
    }
    
    printf("Leitura:\n");
    for(int i = 0; i < 5; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}