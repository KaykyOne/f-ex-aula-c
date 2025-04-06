#include <stdio.h>

int soma(int x, int y){
    return x + y;
}

int main()
{
    int x, y;
    printf("digite o primeiro numero: ");
    scanf("%d", &x);
    printf("digite o segundo numero: ");
    scanf("%d", &y);
    int res = soma(x, y);
    printf("%d", res);
}