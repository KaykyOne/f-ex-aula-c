#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    char valor;
    struct Lista* proximo;
} Lista;

Lista* push(Lista* inicio, char valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->proximo = inicio;
    return novo;
}

void imprimirLista(Lista* inicio) {
    Lista* atual = inicio;
    while (atual != NULL) {
        printf("%c -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

Lista* inverterLista(Lista* inicio) {
    Lista* nova = NULL;
    Lista* atual = inicio;
    while (atual != NULL) {
        nova = push(nova, atual->valor);
        atual = atual->proximo;
    }
    return nova;
}

int listasIguais(Lista* l1, Lista* l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->valor != l2->valor) {
            return 0; // diferente
        }
        l1 = l1->proximo;
        l2 = l2->proximo;
    }
    // Se uma acabou antes da outra, não são iguais
    return (l1 == NULL && l2 == NULL);
}

void liberarLista(Lista* inicio) {
    while (inicio != NULL) {
        Lista* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

int main() {
    char valor[100];
    printf("Digite uma palavra: \n");
    scanf("%s", valor);

    Lista* listaOriginal = NULL;
    for (int i = 0; i < strlen(valor); i++) {
        listaOriginal = push(listaOriginal, valor[i]);
    }

    Lista* listaInvertida = inverterLista(listaOriginal);

    printf("Original: ");
    imprimirLista(listaOriginal);

    printf("Invertida: ");
    imprimirLista(listaInvertida);

    if (listasIguais(listaOriginal, listaInvertida)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é palíndromo.\n");
    }

    liberarLista(listaOriginal);
    liberarLista(listaInvertida);

    return 0;
}
