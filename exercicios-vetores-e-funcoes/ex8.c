#include <stdio.h>

int mediaNotas(int v[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += v[i];
    }
    
    printf("Média: %d \n",(soma / tamanho));
}

int main()
{
    int numeros[4];
    for(int i = 0; i < 4; i++){
        printf("Digite o numero %dº:", (i + 1));
        scanf("%d", &numeros[i]);
    }
    mediaNotas(numeros, 4);
}