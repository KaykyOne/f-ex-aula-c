#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
} Produto;

int main() {
    Produto produtos[3];

    for (int i = 0; i < 3; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        fflush(stdin); // limpar buffer
        fgets(produtos[i].nome, 50, stdin);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
    }

    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nome: %sPreço: %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    return 0;
}
