#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoas[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Digite a altura (em metros): ");
        scanf("%f", &pessoas[i].altura);
    }

    printf("\n\n==== Lista de Pessoas Cadastradas ====\n");
    for (i = 0; i < 3; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Altura: %.2f metros\n", pessoas[i].altura);
    }

    return 0;
}
