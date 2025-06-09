/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define TAMANHO 10

int main()
{
    int vetor[TAMANHO] = {10, 20, 30};
    int n = 3;
    int valor = 30;
    
    int posisao = -1;
    
    for(int i = 0; i<n; i++){
        if(vetor[i] == valor){
            posisao = i;
            break;
        }
    }
    
    if(posisao != -1){
        for(int i = posisao; i < n - 1;i++ ){
            vetor[i] = vetor[i + 1];
        }
        n++;
        printf("Valor %d excluido.\n", valor);
    }else{
        printf("Valor %d não encontrado.\n", valor);
    }
    
    printf("Elementos de vetor após exclusão: \n");
    for(int i=0; i< n;i++){
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    
    return 0;
}