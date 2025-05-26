#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
struct No {
    int valor;
    struct No *prox;
};

// Função para enfileirar (enqueue): insere no fim da fila
void enqueue(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No)); // Aloca novo nó
    novo->valor = valor;               // Atribui valor ao novo nó
    novo->prox = NULL;                 // Novo nó será o último, então prox = NULL

    if (*fim == NULL) {
        // Se a fila está vazia, novo nó será o primeiro e o último
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;           // Conecta o atual último ao novo nó
        *fim = novo;                   // Atualiza o fim da fila
    }
}

// Função para desenfileirar (dequeue): remove do início da fila
int dequeue(struct No **inicio, struct No **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    struct No *temp = *inicio;         // Guarda o nó a ser removido
    int valor = temp->valor;           // Armazena o valor para retorno
    *inicio = temp->prox;              // Avança o ponteiro de início

    if (*inicio == NULL) {             // Se a fila ficou vazia, zera também o fim
        *fim = NULL;
    }

    free(temp);                        // Libera a memória do nó removido
    return valor;
}

// Função para consultar o início da fila (peek)
int peek(struct No *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    return inicio->valor;             // Retorna o valor do início sem remover
}

// Função para imprimir a fila do início ao fim
void imprimirFila(struct No *inicio) {
    printf("Início da fila\n");
    while (inicio != NULL) {
        printf(" %d\n", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL (fim)\n");
}

// Função principal
int main() {
    struct No *inicio = NULL; // Ponteiro para o início da fila
    struct No *fim = NULL;    // Ponteiro para o fim da fila

    // Enfileira três elementos
    enqueue(&inicio, &fim, 10);
    enqueue(&inicio, &fim, 20);
    enqueue(&inicio, &fim, 30);

    // Mostra a fila atual
    imprimirFila(inicio);

    // Consulta o primeiro elemento
    printf("Início da fila (peek): %d\n", peek(inicio));

    // Remove um elemento da fila
    int removido = dequeue(&inicio, &fim);
    printf("Removido da fila (dequeue): %d\n", removido);

    // Mostra a fila após remoção
    imprimirFila(inicio);

    return 0;
}
