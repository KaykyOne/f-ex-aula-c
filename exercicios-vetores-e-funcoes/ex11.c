#include <stdio.h>

int buscarElemento(int v[], int tamanho, int valor){
    if(valor <= tamanho){
        return v[valor];
    }else{
        return -1;
    }

}

int main()
{
    int numeros[4] = {4, 8, 22, 1};
    int res = buscarElemento(numeros, 4, 7);
    printf("valor: %d", res);
}