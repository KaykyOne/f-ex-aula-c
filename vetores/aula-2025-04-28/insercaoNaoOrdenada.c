#include <stdio.h>

int main()
{
    int vetor[5];
    int n = 0;
    
    vetor[n++] = 10;
    vetor[n++] = 40;
    vetor[n++] = 20;
    
    printf("Vetor não ordenado (Array Estático):\n");
    for(int i = 0; i < n; i++){
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    return 0;
}