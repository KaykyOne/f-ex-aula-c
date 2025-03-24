#include <stdio.h>

int main() {
    float notas[4];
    float soma = 0;
    float media = 0;
    
    for(int i = 0; i < 4; i++){
        printf("Digita ai a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    
    media = soma / 4;
    
    printf("Média das notas: %.2f\n", media); // Corrigido: %.2f para float

    return 0;
}
