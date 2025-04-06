#include <stdio.h>

int main() {
    float notas[3][3];
    float media_aluno, media_materia;

    for (int i = 0; i < 3; i++) {
        printf("Digite as 3 notas do aluno %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Nota da materia %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    printf("\nMédia de cada aluno:\n");
    for (int i = 0; i < 3; i++) {
        media_aluno = 0;
        for (int j = 0; j < 3; j++) {
            media_aluno += notas[i][j];
        }
        media_aluno /= 3;
        printf("Aluno %d: %.2f\n", i + 1, media_aluno);
    }

    printf("\nMédia de cada matéria:\n");
    for (int j = 0; j < 3; j++) {
        media_materia = 0;
        for (int i = 0; i < 3; i++) {
            media_materia += notas[i][j];
        }
        media_materia /= 3;
        printf("Matéria %d: %.2f\n", j + 1, media_materia);
    }

    return 0;
}
