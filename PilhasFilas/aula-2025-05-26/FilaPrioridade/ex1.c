#include <stdio.h>
#include <stdlib.h>

struct Paciente {
    char nome[30];
    int idade;
    struct Paciente *prox;
};

// Insere paciente na fila com prioridade (idade >= 60)
void enfileirarComPrioridade(struct Paciente **inicio, struct Paciente **fim) {
    struct Paciente *novo = (struct Paciente*) malloc(sizeof(struct Paciente));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%29s", novo->nome);  // Limita a 29 chars + \0

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);

    novo->prox = NULL;

    if (novo->idade >= 60) {
        // Insere no início da fila (prioritário)
        novo->prox = *inicio;
        *inicio = novo;

        // Se a fila estava vazia, fim aponta para novo
        if (*fim == NULL) {
            *fim = novo;
        }

        printf("Paciente prioritario inserido!\n");
    } else {
        // Insere no fim da fila (comum)
        if (*fim == NULL) {
            // Fila vazia
            *inicio = novo;
            *fim = novo;
        } else {
            (*fim)->prox = novo;
            *fim = novo;
        }

        printf("Paciente comum inserido!\n");
    }
}

// Atende (remove) o paciente do início da fila
void atenderPaciente(struct Paciente **inicio, struct Paciente **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Paciente *temp = *inicio;
    printf("Atendendo: %s (idade %d)\n", temp->nome, temp->idade);

    *inicio = temp->prox;
    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp);
}

// Mostra a fila de pacientes
void mostrarFila(struct Paciente *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\nFila de pacientes (prioritarios no começo):\n");
    while (inicio != NULL) {
        printf("- %s (idade %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

int main() {
    struct Paciente *start = NULL;
    struct Paciente *end = NULL;
    int option;

    do {
        printf("\n===== MENU QUEUE WITH PRIORITY =====\n");
        printf("1. Insert patient in queue\n");
        printf("2. Attend next patient\n");
        printf("3. Show queue\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enfileirarComPrioridade(&start, &end);
                break;
            case 2:
                atenderPaciente(&start, &end);
                break;
            case 3:
                mostrarFila(start);
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    // Liberar memória dos pacientes restantes
    while (start != NULL) {
        atenderPaciente(&start, &end);
    }

    return 0;
}
