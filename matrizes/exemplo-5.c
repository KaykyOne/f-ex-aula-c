#include <stdio.h>
#include <string.h>

int main() {
    // Matriz de strings: 5 dias, 3 aulas por dia, até 30 caracteres cada
    char grade[5][3][30];

    // Lista com os nomes dos dias da semana
    char dias[5][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // Leitura das matérias
    for (int i = 0; i < 5; i++) {
        printf("\nDay: %s\n", dias[i]);
        for (int j = 0; j < 3; j++) {
            printf("Enter the subject of class %d: ", j + 1);

            // Antes de usar scanf com %[^\n], é bom limpar o buffer
            getchar(); 
            scanf("%[^\n]", grade[i][j]);
        }
    }

    // Exibição da grade de horários
    printf("\nTimetable:\n");
    for (int i = 0; i < 5; i++) {
        printf("\n%s:\n", dias[i]);
        for (int j = 0; j < 3; j++) {
            printf("  Class %d: %s\n", j + 1, grade[i][j]);
        }
    }

    return 0;
}
