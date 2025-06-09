#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct No {
    int valor;
    struct No *prox;
};

// Função para remover um nó com valor específico
struct No* removerElemento(struct No *head, int valorRemover) {
    // 1. Lista vazia
    if (head == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    // 2. Se o valor está no primeiro nó
    if (head->valor == valorRemover) {
        struct No *temp = head; // guarda o nó para liberar depois
        head = head->prox;      // atualiza o início da lista
        free(temp);             // libera a memória
        return head;
    }

    // 3. Caso contrário, procura o valor na lista
    struct No *anterior = head;
    struct No *atual = head->prox;

    while (atual != NULL && atual->valor != valorRemover) {
        anterior = atual;
        atual = atual->prox;
    }

    // 4. Se não encontrou o valor
    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valorRemover);
        return head;
    }

    // 5. Valor encontrado: remove o nó
    anterior->prox = atual->prox;
    free(atual);
    return head;
}

// Função para imprimir a lista
void imprimirLista(struct No *head) {
    struct No *atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função auxiliar para inserir no fim da lista
struct No* inserirNoFim(struct No *head, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = NULL;

    if (head == NULL) return novo;

    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    return head;
}

int main() {
    struct No *lista = NULL;

    // Criando a lista [10 -> 20 -> 30 -> 40]
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);
    lista = inserirNoFim(lista, 40);

    imprimirLista(lista); // Mostra a lista inicial

    // Remove o valor 30
    lista = removerElemento(lista, 30);
    imprimirLista(lista); // Esperado: 10 -> 20 -> 40 -> NULL

    // Tenta remover valor inexistente
    lista = removerElemento(lista, 99);

    // Remove o primeiro elemento (10)
    lista = removerElemento(lista, 10);
    imprimirLista(lista); // Esperado: 20 -> 40 -> NULL

    return 0;
}
