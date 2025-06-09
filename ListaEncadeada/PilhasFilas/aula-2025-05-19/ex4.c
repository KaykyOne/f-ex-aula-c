#include <stdio.h>
#include <stdlib.h>

// Estrutura do paciente (nó da fila)
struct Paciente {
    char nome[30];          // Nome (sem espaços)
    int idade;              // Idade
    struct Paciente *prox;  // Próximo paciente na fila
};

// Inserir paciente no fim da fila (enqueue)
void enfileirar(struct Paciente **inicio, struct Paciente **fim) {
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente)); // Cria novo paciente
    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", novo->nome);    // Lê nome do paciente
    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);  // Lê idade
    novo->prox = NULL;          // Como é o último da fila, não aponta para ninguém

    if (*inicio == NULL) {
        // Se a fila estiver vazia, novo será o primeiro e o último
        *inicio = novo;
        *fim = novo;
    } else {
        // Se já houver pacientes, novo vai para o fim
        (*fim)->prox = novo;
        *fim = novo;
    }

    printf("Paciente inserido na fila com sucesso.\n");
}

// Atender paciente (remover do início da fila)
void atenderPaciente(struct Paciente **inicio, struct Paciente **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Paciente *temp = *inicio; // Pega o paciente que será atendido
    printf("Atendendo paciente: %s (idade %d)\n", temp->nome, temp->idade);

    *inicio = temp->prox; // Avança o início da fila para o próximo

    if (*inicio == NULL) {
        // Se a fila ficou vazia após atender, fim também vira NULL
        *fim = NULL;
    }

    free(temp); // Libera a memória do paciente atendido
}

// Mostrar todos os pacientes da fila
void mostrarFila(struct Paciente *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nFila de pacientes:\n");
    while (inicio != NULL) {
        printf("- %s (idade %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox; // Avança para o próximo paciente
    }
}

// Função principal com menu
int main() {
    struct Paciente *inicio = NULL; // Ponteiro para o início da fila
    struct Paciente *fim = NULL;    // Ponteiro para o fim da fila
    int opcao;

    do {
        // Mostra o menu
        printf("\n===== MENU - FILA DE PACIENTES =====\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida

        // Executa a opção escolhida
        if (opcao == 1) {
            enfileirar(&inicio, &fim);
        } else if (opcao == 2) {
            atenderPaciente(&inicio, &fim);
        } else if (opcao == 3) {
            mostrarFila(inicio);
        } else if (opcao == 0) {
            printf("Encerrando o programa...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera a memória da fila (se ainda restar alguém)
    while (inicio != NULL) {
        atenderPaciente(&inicio, &fim);
    }

    return 0;
}
