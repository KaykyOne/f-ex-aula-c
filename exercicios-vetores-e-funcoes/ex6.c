#include <stdio.h>

int mostrarVetor(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d \n",v[i]);
    }
}

int main()
{
    int vetor[6] = {1, 2, 3, 4, 5, 6};
    mostrarVetor(vetor, 6);
}