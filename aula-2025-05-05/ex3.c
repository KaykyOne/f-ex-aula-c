#include <stdio.h>

struct Endereco {
    char rua[50];
    int numero;
};

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};

int main() {
    struct Pessoa p;

    printf("Digite o nome: ");
    scanf("%s", p.nome);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);

    printf("Digite o nome da rua: ");
    scanf("%s", p.endereco.rua);

    printf("Digite o número da casa: ");
    scanf("%d", &p.endereco.numero);

    printf("\n--- Dados Cadastrados ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereço: Rua %s, Nº %d\n", p.endereco.rua, p.endereco.numero);

    return 0;
}
