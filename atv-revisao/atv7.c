#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    int valor;
    struct Lista* proximo;
}Lista;

Lista* enqueue(Lista* inicioDaLista, int valor){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->valor = valor;
    novaLista->proximo = NULL;
    if (inicioDaLista == NULL) {
        return novaLista;
    }

    Lista* atual = inicioDaLista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novaLista;
    return inicioDaLista;
}

Lista* dequeue(Lista* lista){
    Lista* temp = lista;
    lista=lista->proximo;
    free(temp);
    return lista;
}

void imprimirLista(Lista* inicioDaLista) {
    Lista* ponteiroAtual = inicioDaLista;
    while (ponteiroAtual != NULL) {
        printf("%d -> ", ponteiroAtual->valor);
        ponteiroAtual = ponteiroAtual->proximo;
    }
    printf("NULL\n");
}

int main()
{
    Lista* listaNova = NULL;
    listaNova = enqueue(listaNova, 12);
    listaNova = enqueue(listaNova, 15);
    listaNova = dequeue(listaNova);
    listaNova = enqueue(listaNova, 10);
    imprimirLista(listaNova);
}