#include <stdio.h>

void contarNumeroDeVezes(int v[], int tamanho, int valor){
    int quantidade = 0;
    for(int i = 0; i < tamanho; i++){
        if(v[i] == valor){
            quantidade++;
        }
    }
    printf("O valor %d se repete %d vezes", valor, quantidade);
    
}

int main()
{
    int numeros[4] = {4, 1, 4, 1};
    contarNumeroDeVezes(numeros, 4, 1);
}