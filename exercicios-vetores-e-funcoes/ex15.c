#include <stdio.h>

int exibirMenu() {
    int opcao = 0;
    printf("\nMenu:\n");
    printf("1 - Inserir valores no vetor\n");
    printf("2 - Mostrar vetor\n");
    printf("3 - Somar elementos\n");
    printf("4 - Calcular média\n");
    printf("5 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void inserirValores(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("Digite o número da posição %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void mostrarVetor(int v[], int tamanho) {
    printf("Vetor: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int somarVetor(int v[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    return soma;
}

float mediaVetor(int v[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    if (tamanho > 0) {
        return (float)soma / tamanho;
    }
}

int pegarTamanho() {
    int tamanho = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    return tamanho;
}

int main() {
    int opcao = 0;
    int tamanho = pegarTamanho();
    int v[tamanho]; 
    for (int i = 0; i < tamanho; i++){
        v[i] = 0;
    }

    while(opcao != 5) {
        opcao = exibirMenu();
        switch (opcao) {
        case 1:
            inserirValores(v, tamanho);
            break;
        case 2:
            mostrarVetor(v, tamanho);
            break;
        case 3:
            {
                int soma = somarVetor(v, tamanho);
                printf("A soma dos elementos é: %d\n", soma);
            }
            break;
        case 4:
            {
                float media = mediaVetor(v, tamanho);
                if (tamanho > 0) {
                    printf("A média dos elementos é: %.2f\n", media);
                } else {
                    printf("Não é possível calcular a média. O vetor está vazio.\n");
                }
            }
            break;
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
