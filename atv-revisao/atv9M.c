#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
	char nome[40];
	float nota1;
	float nota2;
} Aluno;

int main() {
	Aluno* aluno1 = (Aluno*)malloc(sizeof(Aluno));
	Aluno* aluno2 = (Aluno*)malloc(sizeof(Aluno));
	Aluno* aluno3 = (Aluno*)malloc(sizeof(Aluno));
	Aluno* aluno4 = (Aluno*)malloc(sizeof(Aluno));
	Aluno* aluno5 = (Aluno*)malloc(sizeof(Aluno));

	Aluno* alunos[5] = {aluno1, aluno2, aluno3, aluno4, aluno5};

	for (int i = 0; i < 5; i++) {
		printf("Aluno %d:\n", i + 1);

		printf("Nome: ");
		scanf(" %[^\n]", alunos[i]->nome); // lC* atC) o enter (com espaC'os)

		printf("Nota 1: ");
		scanf("%f", &alunos[i]->nota1);

		printf("Nota 2: ");
		scanf("%f", &alunos[i]->nota2);

		printf("---------------------\n");
	}


	for (int i = 0; i < 5; i++) {
		float media = (alunos[i]->nota1 + alunos[i]->nota2) / 2;
		if(media > 7) {
			printf("Nome: %s\n", alunos[i]->nome);
			printf("Nota 1: %.2f\n", alunos[i]->nota1);
			printf("Nota 2: %.2f\n", alunos[i]->nota2);
			printf("MC)dia: %.2f\n", media);
			printf("----------------------\n");
		}
	}

	// Liberar a memC3ria alocada
	for (int i = 0; i < 5; i++) {
		free(alunos[i]);
	}

	return 0;
}
