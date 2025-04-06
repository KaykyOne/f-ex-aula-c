#include <stdio.h>

void mediaMaiorQue(float v[], int tamanho, float media) {
    for(int i = 0; i < tamanho; i++) {
        if(v[i] > media) {
            printf("Esse item %.2f é maior que a média: %.2f\n", v[i], media);
        }
    }
}

int main() {
    float v[] = {5.0, 3.0, 8.0, 4.0, 2.0};
    int tamanho = 5;
    float media = 4.0;
    mediaMaiorQue(v, tamanho, media);
    return 0;
}

