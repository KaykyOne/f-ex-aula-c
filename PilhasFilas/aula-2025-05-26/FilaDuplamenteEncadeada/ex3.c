#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
};

// Inserir no início
void inserirInicio(struct No** inicio, struct No** fim, int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    } else {
        *fim = novo; // Se a lista estava vazia, o novo também é o fim
    }

    *inicio = novo;
    printf("Inserido %d no início.\n", valor);
}

// Inserir no fim
void inserirFim(struct No** inicio, struct No** fim, int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = *fim;

    if (*fim != NULL) {
        (*fim)->proximo = novo;
    } else {
        *inicio = novo; // Se lista estava vazia, novo também é o início
    }

    *fim = novo;
    printf("Inserido %d no fim.\n", valor);
}

// Remover do início
void removerInicio(struct No** inicio, struct No** fim) {
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No* temp = *inicio;
    printf("Removendo %d do início.\n", temp->valor);

    *inicio = temp->proximo;

    if (*inicio != NULL) {
        (*inicio)->anterior = NULL;
    } else {
        *fim = NULL; // Lista ficou vazia
    }

    free(temp);
}

// Remover do fim
void removerFim(struct No** inicio, struct No** fim) {
    if (*fim == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No* temp = *fim;
    printf("Removendo %d do fim.\n", temp->valor);

    *fim = temp->anterior;

    if (*fim != NULL) {
        (*fim)->proximo = NULL;
    } else {
        *inicio = NULL; // Lista ficou vazia
    }

    free(temp);
}

// Mostrar do início para o fim
void mostrarInicioFim(struct No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do início para o fim: ");
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

// Mostrar do fim para o início
void mostrarFimInicio(struct No* fim) {
    if (fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do fim para o início: ");
    while (fim != NULL) {
        printf("%d ", fim->valor);
        fim = fim->anterior;
    }
    printf("\n");
}

// Remove o primeiro nó que contém o valor especificado
void removerPorValor(struct No **inicio, struct No **fim, int valor) {
    // Verifica se a lista está vazia
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *atual = *inicio; // Ponteiro auxiliar para percorrer a lista

    // Percorre até encontrar o valor ou chegar ao final
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    // Se não encontrou o valor
    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Se for o único elemento na lista
    if (atual == *inicio && atual == *fim) {
        *inicio = NULL;
        *fim = NULL;
    }
    // Se for o primeiro elemento
    else if (atual == *inicio) {
        *inicio = atual->proximo;
        (*inicio)->anterior = NULL;
    }
    // Se for o último elemento
    else if (atual == *fim) {
        *fim = atual->anterior;
        (*fim)->proximo = NULL;
    }
    // Se estiver no meio
    else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }

    printf("Valor %d removido da lista.\n", atual->valor);
    free(atual);
}


// Função principal
int main() {
    struct No* inicio = NULL;
    struct No* fim = NULL;
    int opcao, valor;

    do {
        printf("\n===== MENU LISTA DUPLAMENTE ENCADEADA =====\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do início\n");
        printf("4. Remover do fim\n");
        printf("5. Mostrar do início para o fim\n");
        printf("6. Mostrar do fim para o início\n");
        printf("7. Remover por valor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&inicio, &fim, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(&inicio, &fim, valor);
                break;
            case 3:
                removerInicio(&inicio, &fim);
                break;
            case 4:
                removerFim(&inicio, &fim);
                break;
            case 5:
                mostrarInicioFim(inicio);
                break;
            case 6:
                mostrarFimInicio(fim);
                break;
            case 7:
                printf("Entre o valor para remover:");
                scanf("%d", &valor);
                removerPorValor(&inicio, &fim, valor);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    // Liberar memória
    while (inicio != NULL) {
        struct No* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    return 0;
}
