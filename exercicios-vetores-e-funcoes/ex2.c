#include <stdio.h>

int dobro(int x){
    return x * 2;
}

int main()
{
    int res = dobro(2);
    printf("%d", res);
}