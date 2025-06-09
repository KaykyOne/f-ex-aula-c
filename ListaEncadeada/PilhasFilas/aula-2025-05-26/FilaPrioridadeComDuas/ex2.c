#include <stdio.h>
#include <stdlib.h>

// Estrutura paciente
struct Patient {
    char name[30];
    int age;
    struct Patient *prox;
};

// Função para inserir paciente na fila correta (prioritária ou comum)
void insertPatient(struct Patient **priorityStart, struct Patient **priorityEnd,
                   struct Patient **commonStart, struct Patient **commonEnd) {
    struct Patient *newPatient = (struct Patient*) malloc(sizeof(struct Patient));
    if (!newPatient) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", newPatient->name);

    printf("Digite a idade do paciente: ");
    scanf("%d", &newPatient->age);

    newPatient->prox = NULL;

    if (newPatient->age >= 60) {
        // Insere na fila prioritária
        if (*priorityStart == NULL) {
            *priorityStart = newPatient;
            *priorityEnd = newPatient;
        } else {
            newPatient->prox = *priorityStart;
            *priorityStart = newPatient;
        }
        printf("Paciente PRIORITÁRIO inserido!\n");
    } else {
        // Insere na fila comum
        if (*commonStart == NULL) {
            *commonStart = newPatient;
            *commonEnd = newPatient;
        } else {
            (*commonEnd)->prox = newPatient;
            *commonEnd = newPatient;
        }
        printf("Paciente COMUM inserido!\n");
    }
}

// Função para atender paciente (prioritária tem preferência)
void servePatient(struct Patient **priorityStart, struct Patient **priorityEnd,
                  struct Patient **commonStart, struct Patient **commonEnd) {
    struct Patient *temp;

    if (*priorityStart != NULL) {
        temp = *priorityStart;
        printf("Atendendo PRIORITÁRIO: %s (idade %d)\n", temp->name, temp->age);
        *priorityStart = temp->prox;
        if (*priorityStart == NULL) {
            *priorityEnd = NULL;
        }
        free(temp);
    } else if (*commonStart != NULL) {
        temp = *commonStart;
        printf("Atendendo COMUM: %s (idade %d)\n", temp->name, temp->age);
        *commonStart = temp->prox;
        if (*commonStart == NULL) {
            *commonEnd = NULL;
        }
        free(temp);
    } else {
        printf("Não há pacientes na fila.\n");
    }
}

// Função para mostrar fila (prioritária ou comum)
void showQueue(const char *title, struct Patient *start) {
    printf("\n%s\n", title);

    if (start == NULL) {
        printf("(vazia)\n");
        return;
    }

    while (start != NULL) {
        printf("- %s (idade %d)\n", start->name, start->age);
        start = start->prox;
    }
}

int main() {
    struct Patient *priorityStart = NULL;
    struct Patient *priorityEnd = NULL;
    struct Patient *commonStart = NULL;
    struct Patient *commonEnd = NULL;
    int option;

    do {
        printf("\n===== MENU FILA COM PRIORIDADE (DUAS FILAS) =====\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Mostrar filas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertPatient(&priorityStart, &priorityEnd, &commonStart, &commonEnd);
                break;
            case 2:
                servePatient(&priorityStart, &priorityEnd, &commonStart, &commonEnd);
                break;
            case 3:
                showQueue("Fila PRIORITÁRIA:", priorityStart);
                showQueue("Fila COMUM:", commonStart);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != 0);

    // Liberar memória dos pacientes restantes
    while (priorityStart != NULL || commonStart != NULL) {
        servePatient(&priorityStart, &priorityEnd, &commonStart, &commonEnd);
    }

    return 0;
}
