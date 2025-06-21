#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
    char nome[40];
    float nota;
} Aluno;

int main()
{
    Aluno* aluno1 = (Aluno*)malloc(sizeof(Aluno));
    strcpy(aluno1->nome, "Roberto");
    aluno1->nota = 12.4;
    
    printf("Nome: %s \n", aluno1->nome);
    printf("Nota: %.2f \n", aluno1->nota);
}