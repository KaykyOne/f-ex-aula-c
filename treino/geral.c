#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Insere um novo nó no início da lista
No* inserirNoInicio(No* inicioDaLista, int novoValor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = novoValor;
    novoNo->proximo = inicioDaLista;
    return novoNo;
}

// Insere um novo nó no final da lista
No* inserirNoFim(No* inicioDaLista, int novoValor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = novoValor;
    novoNo->proximo = NULL;

    if (inicioDaLista == NULL) {
        return novoNo;
    }

    No* ponteiroAtual = inicioDaLista;
    while (ponteiroAtual->proximo != NULL) {
        ponteiroAtual = ponteiroAtual->proximo;
    }

    ponteiroAtual->proximo = novoNo;
    return inicioDaLista;
}

// Imprime todos os valores da lista
void imprimirLista(No* inicioDaLista) {
    No* ponteiroAtual = inicioDaLista;
    while (ponteiroAtual != NULL) {
        printf("%d -> ", ponteiroAtual->valor);
        ponteiroAtual = ponteiroAtual->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* listaEncadeada = NULL; // começa vazia

    listaEncadeada = inserirNoInicio(listaEncadeada, 10);
    listaEncadeada = inserirNoInicio(listaEncadeada, 20);

    listaEncadeada = inserirNoInicio(listaEncadeada, 30);
    listaEncadeada = inserirNoFim(listaEncadeada, 30);
    listaEncadeada = inserirNoFim(listaEncadeada, 5);
    listaEncadeada = inserirNoFim(listaEncadeada, 0);

    imprimirLista(listaEncadeada); // deve imprimir 30 -> 20 -> 10 -> 5 -> 0 -> NULL

    return 0;
}
