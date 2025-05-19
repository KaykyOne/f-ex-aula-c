#include <stdio.h>

struct Produto {
    char nome[30];
    float preco;
};

int main() {
    struct Produto produtos[3];
    struct Produto *ptr = produtos;

    printf("Digite o nome do produto 1: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 1: ");
    scanf("%f", &ptr->preco);

    ptr++;

    printf("Digite o nome do produto 2: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 2: ");
    scanf("%f", &ptr->preco);

    ptr++;

    printf("Digite o nome do produto 3: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 3: ");
    scanf("%f", &ptr->preco);

    printf("\n=== Lista de Produtos ===\n");
    for(int i = 0; i < 3; i++){
        printf("Produto %d: %s - %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }

    return 0;
}
