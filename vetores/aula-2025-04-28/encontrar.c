#include <stdio.h>
#define TAMANHO 10

int main()
{
    int vetor[TAMANHO] = {10, 20, 30};
    int n = 3;
    int valor = 30;
    
    int encontrado = -1;
    
    for(int i = 0; i<n; i++){
        if(vetor[i] == valor){
            encontrado = i;
            break;
        }
    }
    
    if(encontrado != -1){
        printf("Valor %d encontrado na posição %d.\n", valor, encontrado);
    }else{
        printf("Valor %d não encontrado.\n", valor);
    }
    
    return 0;
}