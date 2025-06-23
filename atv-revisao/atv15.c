#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[40];
    float nota;
    struct Aluno* proximo;
} Aluno;

Aluno* inserirOrdenado(Aluno* inicio, char nome[], float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->proximo = NULL;

    if (inicio == NULL || strcmp(nome, inicio->nome) < 0) {
        novo->proximo = inicio;
        return novo;
    }

    Aluno* atual = inicio;
    while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) > 0) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return inicio;
}

void imprimir(Aluno* inicio) {
    Aluno* atual = inicio;
    while (atual != NULL) {
        printf("Nome: %s - Nota: %.2f\n", atual->nome, atual->nota);
        atual = atual->proximo;
    }
}

int main() {
    Aluno* lista = NULL;
    lista = inserirOrdenado(lista, "Carlos", 7.5);
    lista = inserirOrdenado(lista, "Amanda", 8.0);
    lista = inserirOrdenado(lista, "Bruno", 9.0);

    printf("Lista de alunos:\n");
    imprimir(lista);

    return 0;
}
