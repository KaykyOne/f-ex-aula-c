#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila (cliente)
typedef struct No {
    int numero;
    struct No* proximo;
} No;

// Estrutura da fila, guardando o início e o fim
typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

// Inicializa fila vazia
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Enqueue: insere no fim da fila
void enqueue(Fila* fila, int numero) {
    No* novo = (No*)malloc(sizeof(No));
    novo->numero = numero;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        // fila vazia
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    printf("Cliente %d entrou na fila.\n", numero);
}

// Dequeue: remove do início da fila (atende cliente)
int dequeue(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia! Nenhum cliente para atender.\n");
        return -1; // fila vazia
    }
    No* temp = fila->inicio;
    int numCliente = temp->numero;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL; // fila ficou vazia
    }
    free(temp);
    printf("Cliente %d atendido.\n", numCliente);
    return numCliente;
}

// Mostra a fila atual
void mostrarFila(Fila* fila) {
    printf("Fila atual: ");
    No* atual = fila->inicio;
    if (atual == NULL) {
        printf("vazia");
    }
    while (atual != NULL) {
        printf("%d ", atual->numero);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Enfileira 5 clientes
    for (int i = 1; i <= 5; i++) {
        enqueue(&fila, i);
    }
    mostrarFila(&fila);

    // Atende os clientes na ordem
    for (int i = 0; i < 5; i++) {
        dequeue(&fila);
        mostrarFila(&fila);
    }

    return 0;
}
