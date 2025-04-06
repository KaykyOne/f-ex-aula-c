#include <stdio.h>

void ordenar(int v[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (v[j] > v[j + 1]) {  
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int v[] = {5, 3, 8, 4, 2};
    int tamanho = 5;

    ordenar(v, tamanho);

    for (int i = 0; i < tamanho; i++)
        printf("%d ", v[i]);
    
    return 0;
}
