#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
struct No {
    int valor;
    struct No *prox;
};

// Função push: insere um novo elemento no topo da pilha
void push(struct No **topo, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Função pop: remove o topo da pilha e retorna seu valor
int pop(struct No **topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // Valor que indica erro
    }

    struct No *temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

// Função peek: retorna o valor do topo da pilha sem remover
int peek(struct No *topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // Valor sinalizador
    }
    return topo->valor;
}

// Função para imprimir a pilha
void imprimirPilha(struct No *topo) {
    printf("Topo da pilha\n");
    while (topo != NULL) {
        printf(" %d\n", topo->valor);
        topo = topo->prox;
    }
    printf("NULO\n");
}

// Função principal
int main() {
    struct No *pilha = NULL; // Pilha vazia

    // Inserções
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    imprimirPilha(pilha); // Mostra a pilha

    // Consulta o topo sem remover
    printf("Valor no topo (peek): %d\n", peek(pilha));

    // Remove o topo
    int valorRemovido = pop(&pilha);
    printf("Valor removido (pop): %d\n", valorRemovido);

    // Consulta novamente após remoção
    printf("Novo topo (peek): %d\n", peek(pilha));

    imprimirPilha(pilha); // Mostra a pilha final

    return 0;
}
