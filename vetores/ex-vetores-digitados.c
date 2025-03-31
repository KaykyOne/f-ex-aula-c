#include <stdio.h>

int main() {
    int valores[3];
    
    for (int i = 0; i < 3; i++){
        printf("Digite o valor da posição %d:", i);
        scanf("%d", &valores[i]);
    }
    
    for(int i = 0; i < 3; i++){
        printf("valores[%d] = %d\n", i, valores[i]);
    }
    
    return 0;

}