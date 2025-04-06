#include <stdio.h>

int somarVetor(int v[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += v[i];
    }
    printf("%d \n",soma);
}

int main()
{
    int vetor[6] = {1, 2, 3, 4, 5, 6};
    somarVetor(vetor, 6);
}