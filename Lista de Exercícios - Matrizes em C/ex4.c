#include <stdio.h>

int main() {
    char tabuleiro[3][3];
    int linha, coluna, jogador = 1;
    int jogadas = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    while (jogadas < 9) {
        printf("\nTabuleiro:\n");
        for (int i = 0; i < 3; i++) {
            printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            if (i < 2) printf("---|---|---\n");
        }

        printf("\nJogador %d (%c), informe linha e coluna (0-2): ", jogador, jogador == 1 ? 'X' : 'O');
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador == 1 ? 'X' : 'O';
        jogadas++;

        jogador = (jogador == 1) ? 2 : 1;
    }

    printf("\nTabuleiro final:\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("---|---|---\n");
    }

    return 0;
}
