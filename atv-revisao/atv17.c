#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[40];
    int idade;
    struct Paciente* proximo;
} Paciente;

void inserir(Paciente** inicio, char nome[], int idade) {
    Paciente* novo = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->proximo = NULL;

    if (*inicio == NULL || idade >= 60) {
        novo->proximo = *inicio;
        *inicio = novo;
    } else {
        Paciente* atual = *inicio;
        while (atual->proximo != NULL && atual->proximo->idade >= 60)
            atual = atual->proximo;
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

void imprimirFila(Paciente* inicio) {
    while (inicio != NULL) {
        printf("Nome: %s - Idade: %d\n", inicio->nome, inicio->idade);
        inicio = inicio->proximo;
    }
}

int main() {
    Paciente* fila = NULL;
    char nome[40];
    int idade;

    for (int i = 0; i < 5; i++) {
        printf("Nome do paciente %d: ", i + 1);
        scanf(" %[^\n]", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        inserir(&fila, nome, idade);
    }

    printf("\nOrdem de atendimento:\n");
    imprimirFila(fila);

    return 0;
}
