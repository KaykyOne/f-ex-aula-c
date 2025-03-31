#include <stdio.h>

int marioMenor(int v[], int tamanho){
    int maior = v[0];
    int menor = v[0];

    for(int i = 0; i < tamanho; i++){
        if(v[i] < menor) menor = v[i];
        if(v[i] > maior) maior = v[i];
    }
    
    printf("Menor: %d", menor);
    printf("Maior: %d", maior);

}

int main()
{
    int numeros[4] = {4, 8, 22, 1};
    marioMenor(numeros, 4);
}