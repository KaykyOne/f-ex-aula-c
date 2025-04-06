#include <stdio.h>

int main()
{
	int id_alunos[4] = {1, 2, 3, 4};
	int dias = 5;

	char presenca[4][5];

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 4; j++) {
			printf("Qual o estado de presenC'a desse aluno: %d, nesse dia da semana: %d \n", id_alunos[j], i + 1);
			printf("p = presenca \nf = falta \n");
			scanf(" %c", &presenca[j][i]); 
		}
	}
	printf("dias:  |");
	printf(" 1 | 2 | 3 | 4 | 5 \n");
	printf("___________________________\n");
	for(int i = 0; i < 4; i++) {
	    printf("aluno %d", id_alunos[i]);
		for(int j = 0; j < 5; j++) {
			printf("| %c ", presenca[i][j]);
		}
		printf("\n");
	}


	return 0;
}
