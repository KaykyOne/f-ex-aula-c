#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

void push(No** topo, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(No** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No* temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

void imprimir(No* topo) {
    while (topo) {
        printf("%d -> ", topo->valor);
        topo = topo->prox;
    }
    printf("NULL\n");
}

int main() {
    No* pilha = NULL;

    push(&pilha, 5);
    push(&pilha, 10);
    push(&pilha, 15);

    printf("Pilha:\n");
    imprimir(pilha);

    printf("Pop: %d\n", pop(&pilha));
    printf("Pilha após pop:\n");
    imprimir(pilha);

    return 0;
}
