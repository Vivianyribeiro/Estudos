//
// conjunto.h
//
#include <stdio.h>

typedef struct conjunto Conjunto;

typedef struct conjunto {
    int n;
    int capacidade;
    int *vet;
}Conjunto;

Conjunto *criaConjunto(int cap);

void liberaConjunto(Conjunto *c);

void insereConjunto(Conjunto *c, int x);

void retornaElement(Conjunto *c, int x, int cap);

void removeConjunto(Conjunto *c, int x);

void imprimeConjunto(Conjunto *c);

int tamanhoConjunto(Conjunto *c);

int buscaConjunto(Conjunto *c, int x);

void unionConjunto(Conjunto *c1, Conjunto *c2);

void interConjunto(Conjunto *c1, Conjunto *c2);

//
// conjunto.c
//

Conjunto *criaConjunto(int cap) {
    Conjunto *c = (Conjunto *) calloc(1,sizeof(Conjunto));
    c->n = 0;
    c->capacidade = cap;
    c->vet = (int *) calloc(cap,sizeof(int));
    return c;
}

void liberaConjunto(Conjunto *c) {
    free(c->vet);
    free(c);
}

void insereConjunto(Conjunto *c, int x) {
    if (c->n < c->capacidade) {
        c->vet[c->n] = x;
        c->n++;
    }
    else {
        printf("Conjunto cheio\n");
    }
    return;
}

void retornaElement(Conjunto *c, int x, int cap) {
    int i;
    for (i = 0; i < c->n; i++) {
        if (c->vet[i] == x) {
            c->vet[i] = cap;
            return;
        } 
    }
    printf("Nao encontrado o elemento %d", x);
    return;
}

void removeConjunto(Conjunto *c, int x) {
    int i;
    for (i = 0; i < c->n; i++) {
        if (c->vet[i] == x) {
            while (i < c->n - 1) {
                c->vet[i] = c->vet[i + 1];
                i++;
            }
            c->n--;
            return;
        }
    }
    printf("Elemento nao encontrado\n");
    return;
}

void imprimeConjunto(Conjunto *c) {
    int i;
    for (i = 0; i < c->n; i++) {
        printf("%d ", c->vet[i]);
    }
    printf("\n");
    return;
}

int tamanhoConjunto(Conjunto *c) {
    return c->n;
}

int buscaConjunto(Conjunto *c, int x) {
    int i;
    for (i = 0; i < c->n; i++) {
        if (c->vet[i] == x) {
            return 1;
        }
    }
    return 0;
}

void unionConjunto(Conjunto *c1, Conjunto *c2) {
    int i;
    for (i = 0; i < c2->n; i++) {
        insereConjunto(c1, c2->vet[i]);
    }
    return;
}

void interConjunto(Conjunto *c1, Conjunto *c2) {
    int i;
    for (i = 0; i < c1->n; i++) {
        if (buscaConjunto(c2, c1->vet[i])) {
            removeConjunto(c1, c1->vet[i]);
        }
    }
    return;
}

//
// Main
//
int main() {
    int n;
    Conjunto *c1, *c2;
    scanf("%d", &n);
    c1 = criaConjunto(n);
    scanf("%d", &n);
    c2 = criaConjunto(n);
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        insereConjunto(c1, x);
    }
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        insereConjunto(c2, x);
    }
    unionConjunto(c1, c2);
    interConjunto(c1, c2);
    imprimeConjunto(c1);
    imprimeConjunto(c2);
    liberaConjunto(c1);
    liberaConjunto(c2);

    return 0;


    return 0;
}




