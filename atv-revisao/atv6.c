#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    int valor;
    struct Lista* proximo;
}Lista;

Lista* push(Lista* inicioDaLista, int valor){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->valor = valor;
    novaLista->proximo = inicioDaLista;
    return novaLista;
}

Lista* pop(Lista* lista){
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
    Lista* listaNova = (Lista*)malloc(sizeof(Lista));
    listaNova = push(listaNova, 12);
    listaNova = push(listaNova, 15);
    listaNova = pop(listaNova);
    listaNova = push(listaNova, 10);
    imprimirLista(listaNova);
}