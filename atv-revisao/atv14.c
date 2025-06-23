#include <stdio.h>

void menorProMaior(int vetor[10]) {
	for(int i = 0; i < 10; i++) {
		for(int v = 0; v < 9 - i; v++) {
			if(vetor[v] > vetor[v + 1]) {
				int temp = vetor[v];
				vetor[v] = vetor[v + 1];
				vetor[v+1] = temp;
			}
		}
	}
}

int main()
{
	// Vetor com valores pré-definidos
	int vetor[10] = {8, 3, 10, 1, 4, 7, 9, 2, 6, 5};

	// Se quiser digitar os valores manualmente, descomenta esse trecho abaixo:
	/*
	printf("Digite os valores para os respectivos lugares:\n");
	for(int i = 0; i < 10; i++) {
		printf("Digite o valor para: %d\n", (i + 1));
		scanf("%d", &vetor[i]);
	}
	*/

	// Chama a função que ordena
	menorProMaior(vetor);

	// Imprime o vetor ordenado
	printf("Vetor ordenado:\n");
	for(int i = 0; i < 10; i++) {
		printf("%d\n", vetor[i]);
	}

	return 0;
}