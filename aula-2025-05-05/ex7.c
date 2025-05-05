#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
};

typedef struct ponto Ponto;

int main() {
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));

    p->x = 1;
    p->y = 5;

    printf("Ponto = (%.2f, %.2f)\n", p->x, p->y);

    free(p);

    return 0;
}
