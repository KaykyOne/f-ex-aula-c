#include <stdio.h>

int main()
{
    int vetor[5];
    for(int i = 0; i < 5; i++){
        printf(" digite o numero da posição: %d \n",i + 1);
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("%d \n",vetor[i]);
    }
}