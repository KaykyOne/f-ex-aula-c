#include <stdio.h>   // Biblioteca para entrada/saída padrão
#include <ctype.h>   // Biblioteca para manipulação de caracteres (toupper)

int main() {
    // Vetor com nomes dos 3 alunos
    char students[3][20] = {"Ana", "Carlos", "Beatriz"};

    // Vetor com os 5 dias da semana
    char days[5][10] = {"Mon", "Tue", "Wed", "Thu", "Fri"};

    // Matriz para armazenar a presença: 3 linhas (alunos) x 5 colunas (dias)
    char presence[3][5];

    // Leitura das presenças
    for (int i = 0; i < 3; i++) {
        printf("\nAttendance for %s:\n", students[i]);
        for (int j = 0; j < 5; j++) {
            char value;
            do {
                printf("%s - Enter 'P' for Present or 'F' for Absent: ", days[j]);
                scanf(" %c", &value); // espaço antes do %c ignora caracteres em branco
                value = toupper(value); // converte pra maiúsculo
                if (value == 'P' || value == 'F') {
                    presence[i][j] = value;
                } else {
                    printf("Invalid input. Use only P or F.\n");
                }
            } while (value != 'P' && value != 'F');
        }
    }

    // Exibição da tabela de presença
    printf("\nAttendance Table:\n");
    printf("%-10s", "Student");

    // Cabeçalho dos dias
    for (int j = 0; j < 5; j++) {
        printf("%4s", days[j]);
    }
    printf("\n");

    // Corpo da tabela
    for (int i = 0; i < 3; i++) {
        printf("%-10s", students[i]);
        for (int j = 0; j < 5; j++) {
            printf("%4c", presence[i][j]);
        }
        printf("\n");
    }

    return 0;
}
