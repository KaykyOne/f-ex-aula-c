#include <stdio.h>
#include <stdlib.h>

struct Aluno {
	char nome[40];
	float nota;
};

int main()
{
	struct Aluno *aluno = (struct Aluno *)malloc(sizeof(struct Aluno));

	if(aluno == NULL) {
		printf("Erro ao alocar memC3ria.\n");
		return 1;
	}

	printf("Digite o nome do aluno(sem espaC'os): ");
	scanf("%s", aluno->nome);
	printf("Digite a nota do aluno: ");
	scanf("%f", &aluno->nota);

	printf("\n=== DADOS do Aluno ===\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Nota: %f\n", aluno->nota);
    
    free(aluno);
	
	return 0;
}