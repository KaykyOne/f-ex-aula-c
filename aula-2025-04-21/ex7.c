#include <stdio.h>

#define TAM 10

int main()
{
    int vetor[TAM] = {10, 20, 30, 50};
    int n = 4;
    int novo = 25;
    int i = n - 1;
    
    while(i >= 0 && vetor[i] > novo){
        vetor[i + 1] = vetor[i];
        i--;
    }
    
    vetor[i + 1] = novo;
    n++;
    
    printf("Vetor após inserção: ");
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}