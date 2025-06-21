#include <stdio.h>

int main()
{
	int vetor[6] = {3, 4, 1, 10, 22, 10};

	int maior = vetor[0];
	int menor = vetor[0];

	for(int i = 0; i < 6; i++) {
		if(vetor[i] > maior) {
			maior = vetor[i];
		}else{
		    menor = vetor[i];
		}
	}
	printf("maior: %d", maior);
}