#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enqueue(Fila* fila, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (fila->fim != NULL) {
        fila->fim->prox = novo;
    } else {
        fila->inicio = novo;
    }

    fila->fim = novo;
}

int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    No* temp = fila->inicio;
    int valor = temp->valor;
    fila->inicio = temp->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
    return valor;
}

void imprimir(Fila fila) {
    No* atual = fila.inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    Fila fila = {NULL, NULL};

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);

    printf("Fila:\n");
    imprimir(fila);

    printf("Dequeue: %d\n", dequeue(&fila));
    printf("Fila após dequeue:\n");
    imprimir(fila);

    return 0;
}
