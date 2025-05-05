#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No*proximo;
}No;

void inserir_inicio(No **inicio, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}

void imprimir(No *inicio){
    No *atual = inicio;
    printf("Lista: ");
    while(atual != NULL){
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main()
{
    No *lista = NULL;
    inserir_inicio(&lista, 30);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 10);
    imprimir(lista);
    return 0;
}