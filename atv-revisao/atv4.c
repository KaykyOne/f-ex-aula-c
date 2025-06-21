#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto{
    char nome[50];
    float preco;
}Produto;

int main()
{
    Produto* produto1 = (Produto*)malloc(sizeof(Produto));
    strcpy(produto1->nome, "Arroz");
    produto1->preco = 13.99;
    
    Produto* produto2 = (Produto*)malloc(sizeof(Produto));
    strcpy(produto2->nome, "Peixe");
    produto2->preco = 49.99;
    
    printf("Produto 1:\n");
    printf("%s \n", produto1->nome);
    printf("%.2f \n", produto1->preco);
    printf("Produto 2:\n");
    printf("%s \n", produto2->nome);
    printf("%.2f \n", produto2->preco);
}