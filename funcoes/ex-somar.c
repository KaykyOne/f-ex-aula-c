#include <stdio.h>

int somar(int a, int b){
    return  a + b;
}

int main()
{
    int x = 10, y = 5;
    int resultado;
    
    resultado = somar(x, y);
    
    printf("Resultado da soma: %d\n", resultado);

    return 0;
}