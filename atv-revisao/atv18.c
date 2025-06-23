#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
} No;

No* inserirFim(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    if (lista == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        return novo;
    }

    No* ultimo = lista->anterior;

    novo->proximo = lista;
    novo->anterior = ultimo;
    ultimo->proximo = novo;
    lista->anterior = novo;

    return lista;
}

No* removerPorValor(No* lista, int valor) {
    if (lista == NULL) return NULL;

    No* atual = lista;
    do {
        if (atual->valor == valor) {
            if (atual->proximo == atual) {
                free(atual);
                return NULL;
            }
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            if (atual == lista) lista = atual->proximo;
            free(atual);
            return lista;
        }
        atual = atual->proximo;
    } while (atual != lista);

    return lista;
}

void imprimirLista(No* lista) {
    if (lista == NULL) return;

    No* atual = lista;
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista);
    printf("\n");
}

int main() {
    No* lista = NULL;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);
    lista = inserirFim(lista, 40);

    printf("Lista atual:\n");
    imprimirLista(lista);

    lista = removerPorValor(lista, 30);

    printf("Após remover 30:\n");
    imprimirLista(lista);

    return 0;
}
