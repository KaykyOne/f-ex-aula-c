#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma página
struct Pagina {
    char url[100];
    struct Pagina *prox;
};

// Função para acessar uma nova página (push)
void acessarPagina(struct Pagina **topo, const char *endereco) {
    struct Pagina *nova = (struct Pagina *)malloc(sizeof(struct Pagina));
    strcpy(nova->url, endereco);      // Copia o endereço da nova página
    nova->prox = *topo;               // Aponta para a página anterior
    *topo = nova;                     // Atualiza o topo da pilha
}

// Função para voltar para a página anterior (pop)
void voltarPagina(struct Pagina **topo) {
    if (*topo == NULL) {
        printf("Nenhuma página para voltar.\n");
        return;
    }
    struct Pagina *temp = *topo;
    printf("Voltando da página: %s\n", temp->url);
    *topo = temp->prox;   // Atualiza o topo
    free(temp);           // Libera o nó removido
}

// Função para mostrar a página atual
void mostrarPaginaAtual(struct Pagina *topo) {
    if (topo == NULL) {
        printf("Nenhuma página aberta.\n");
    } else {
        printf("Página atual: %s\n", topo->url);
    }
}

// Função para mostrar o histórico (todos os nós da pilha)
void mostrarHistorico(struct Pagina *topo) {
    if (topo == NULL) {
        printf("Histórico vazio.\n");
        return;
    }
    printf("Histórico de páginas visitadas:\n");
    while (topo != NULL) {
        printf(" - %s\n", topo->url);
        topo = topo->prox;
    }
}

// Função principal com menu interativo
int main() {
    struct Pagina *pilha = NULL;  // Pilha de páginas
    int opcao;
    char url[100];

    do {
        printf("\n==== MENU DO NAVEGADOR ====\n");
        printf("1. Acessar nova página\n");
        printf("2. Voltar página anterior\n");
        printf("3. Ver página atual\n");
        printf("4. Mostrar histórico\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                printf("Digite a URL da nova página: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0'; // Remove o \n do final
                acessarPagina(&pilha, url);
                break;
            case 2:
                voltarPagina(&pilha);
                break;
            case 3:
                mostrarPaginaAtual(pilha);
                break;
            case 4:
                mostrarHistorico(pilha);
                break;
            case 0:
                printf("Saindo do navegador...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera memória restante (pilha completa)
    while (pilha != NULL) {
        voltarPagina(&pilha);
    }

    return 0;
}
