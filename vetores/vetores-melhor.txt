#include <stdio.h>

int main() {
    int numeros[5] = { 2, 4, 6, 8, 10};
    
    for(int i = 0; i < 5; i++){
        printf("numeros[%d] - %d\n", i, numeros[i]);
    }
    
    return 0;

}