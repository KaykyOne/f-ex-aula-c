#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alunos{
    char nome[40];
    float nota;
    struct Lista* proximo;
}Alunos;

Lista* inserirInicio(Lista* inicioDaLista, float nota){
    
    return inicioDaLista;
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