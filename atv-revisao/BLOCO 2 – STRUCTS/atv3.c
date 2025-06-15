#include <stdio.h>

typedef struct {
    char nome[40];
    float nota;
} Aluno;

int main() {
    Aluno aluno;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 40, stdin);

    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno.nota);

    printf("\nAluno: %sNota: %.2f\n", aluno.nome, aluno.nota);

    return 0;
}
