#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

struct No* inserirNoInicio(struct No *head, int novoValor){
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = novoValor;
    novoNo->prox = head;
    return novoNo;
}

void imprimirLista(struct No *head){
    struct No *atual = head;
    printf("Lista: ");
    while(atual != NULL){
        printf("%d -> ", atual -> valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main(){
    struct No *lista = NULL;

    lista =inserirNoInicio(lista, 30);
    lista =inserirNoInicio(lista, 20);
    lista =inserirNoInicio(lista, 10);

    lista =inserirNoInicio(lista, 5);

    imprimirLista(lista);
    return 0;
}