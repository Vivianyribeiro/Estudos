//
// conjunto.h
//
#include <stdio.h>
#include <math.h>
#define TAM 100

typedef struct conjunto Conjunto;

struct conjunto {
    int elementos[TAM];
    int index[TAM];
};

Conjunto* criaConjunto (Conjunto a, int n);

void inicializaConjunto (Conjunto a, int n);

void inserirElemento(int x, Conjunto a);

int pertence(int x, Conjunto a);

Conjunto* uniaoC(Conjunto a, Conjunto b, Conjunto C); 

Conjunto* interC(Conjunto a, Conjunto b, Conjunto C);

//
// conjunto.c
//
void inicializaConjunto (Conjunto a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        a.index[i] = -1;
    }
}

Conjunto* criaConjunto (Conjunto a, int n) {
    a.elementos = n;
    inicializaConjunto(a, n);
    return &a;
}

void inserirElemnto(int x, Conjunto a){
    int igual = 0, index = 0;
    for (int i =0; i < TAM; i++) {
        if (a.elementos[i] == x) {
            printf("Ja possui");
            igual++;
        }
    }
    if (igual == 0) {
        for(int i=0; i < TAM; i++) {
            if(a.elementos[i] == -1) {
                index = i;
                break;
            }
        }
        a.elementos = x;
    }
}

Conjunto* uniaoC(Conjunto a, Conjunto b, Conjunto c){
    for(int i =0; i < TAM; i++){
        inserirElemento(a.elementos[i], c);
        inserirElemento(b.elementos[i], c);
    }
    return &c;
}

Conjunto* interC(Conjunto a, Conjunto b, Conjunto c){
    for(int i=0; i < TAM ; i++){
        if (pertence(a.elementos[i], b)){
            inserirElemento(a.elementos[i], c);
        }
    }
    return &c;
}
//
// MAIN
//
int main() {


    return
}

























