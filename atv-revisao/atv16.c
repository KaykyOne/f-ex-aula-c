#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

void push(No** topo, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *topo;
    *topo = novo;
}

int pop(No** topo) {
    if (*topo == NULL) return 0;
    No* temp = *topo;
    int val = temp->valor;
    *topo = temp->proximo;
    free(temp);
    return val;
}

int main() {
    No* pilha = NULL;
    int valor, soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        push(&pilha, valor);
    }

    printf("\nEsvaziando pilha e somando:\n");
    while (pilha != NULL) {
        int retirado = pop(&pilha);
        printf("Retirado: %d\n", retirado);
        soma += retirado;
    }

    printf("Soma total: %d\n", soma);

    return 0;
}
