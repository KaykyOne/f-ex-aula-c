#include <stdio.h>
#define TAMANHO 10

int main()
{
    int vetor[TAMANHO];
    int n =0;
    
    vetor[n++] = 10;
    vetor[n++] = 30;
    vetor[n++] = 20;

    printf("Elementos do Vetor:\n");
    for(int i = 0; i < n; i++){
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    
    return 0;
}