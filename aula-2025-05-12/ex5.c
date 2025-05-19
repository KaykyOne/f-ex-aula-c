#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct No {
    int value;
    struct No *prox;
};

// Função para buscar um elemento na lista
struct No* buscarElemento(struct No *head, int valorBusca) {
    struct No *atual = head;

    while (atual != NULL) {
        if (atual->value == valorBusca) {
            return atual; // Achou o valor
        }
        atual = atual->prox;
    }

    return NULL; // Não achou
}

// Função para imprimir a lista
void imprimirLista(struct No *head) {
    struct No *atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->value);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Inserir elemento no final da lista
struct No* inserirNoFim(struct No *head, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->value = valor;
    novo->prox = NULL;

    if (head == NULL) {
        return novo;
    }

    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    return head;
}

int main() {
    struct No *lista = NULL;

    // Criando a lista: 10 -> 20 -> 30 -> NULL
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);

    imprimirLista(lista);

    // Buscar valor existente
    struct No *resultado = buscarElemento(lista, 20);
    if (resultado != NULL) {
        printf("Valor %d encontrado no endereço %p.\n", resultado->value, (void*) resultado);
    } else {
        printf("Valor 20 não encontrado.\n");
    }

    // Buscar valor inexistente
    resultado = buscarElemento(lista, 99);
    if (resultado != NULL) {
        printf("Valor %d encontrado no endereço %p.\n", resultado->value, (void*) resultado);
    } else {
        printf("Valor 99 não encontrado.\n");
    }

    return 0;
}
