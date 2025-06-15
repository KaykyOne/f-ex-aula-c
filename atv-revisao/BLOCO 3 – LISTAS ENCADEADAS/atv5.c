#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

void inserirInicio(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

void imprimir(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);

    printf("Lista: ");
    imprimir(lista);

    return 0;
}
