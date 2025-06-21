#include <stdio.h>

int main()
{
    int vetor[10];
    
    printf("Digite os valores para os respectivos lugares:\n");
    for(int i = 0; i < 10; i++){
        printf("Digite o valor para: %d\n", (i + 1));
        scanf("%d", &vetor[i]);
    }
    
    for(int i = 0; i < 10; i++){
        if(vetor[i] % 2 == 0){
            vetor[i] = NULL;
        }
    }
    printf("Leitura:\n");
    for(int i = 0; i < 10; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}