#include <stdio.h>

int parImpar(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(v[i] % 2 == 0){
            printf("esse e par: %d \n", v[i]);
        }else{
            printf("esse e impar: %d \n", v[i]);
        }
    }
}

int main()
{
    int numeros[4] = {4, 8, 22, 1};
    parImpar(numeros, 4);
}