#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

struct No* inserirNoFim(struct No *head, int novoValor){
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = novoValor;
    novoNo->prox = NULL;
    if(head == NULL){
        return novoNo;
    }
    struct No *atual = head;
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    
    atual->prox = novoNo;
    return head;
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

    lista =inserirNoFim(lista, 30);
    lista =inserirNoFim(lista, 20);
    lista =inserirNoFim(lista, 10);

    lista =inserirNoFim(lista, 5);

    imprimirLista(lista);
    return 0;
}