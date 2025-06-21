#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    int valor;
    struct Lista* proximo;
}Lista;

Lista* inserirInicio(Lista* inicioDaLista, int valor){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->valor = valor;
    novaLista->proximo = inicioDaLista;
    return novaLista;
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
    listaNova = inserirInicio(listaNova, 12);
    listaNova = inserirInicio(listaNova, 15);
    listaNova = inserirInicio(listaNova, 10);
    imprimirLista(listaNova);
}