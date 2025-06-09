#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    int n = 0;
    int tamanho = 0;

    vetor = malloc(tamanho * sizeof(int));
    
    vetor[n++] = 15;
    vetor[n++] = 25;
    vetor[n++] = 5;
    
    printf("Vetor não ordenado (Array Dinamico):\n");
    for(int i = 0; i < n; i++){
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    return 0;
}