#include <stdio.h>
#include <stdbool.h>


#define TAM_MAX 100

typedef struct casa {
    int numeracao;
}Casas;

typedef struct fila{
    Casas elementos[TAM_MAX];
    unsigned int tam;
}Fila;

void *criarFilaVazia(Fila *fila){
    fila->tam = 0;

}

bool filaVazia(Fila *f){
    return(f->tam == 0);
}

bool filaCheia(Fila *f){
    return(f->tam == TAM_MAX);
}

void enfileirar(Fila *f, int num){
    if(filaCheia(f)){
        return;
    }
    else{
        f->elementos[f->tam].numeracao = num;
        f->tam++;
    }
}

void printFila(Fila *f){
    int i;
    for(i = 0; i < f->tam; i++){
        printf("%d ", f->elementos[i].numeracao);
    }

}

void desenfileirar(Fila *f){
    if(!filaVazia(f)){
        for(int i = 0; i < f->tam; i++){
            f->elementos[i] = f->elementos[i+1];
        }
        f->tam--;
    }

}

void removeEle(Fila *f, int n){
    int i;
    int j;
    for(i = 0; i < f->tam; i++){
        if(f->elementos[i].numeracao == n){
            for(j = i; j < f->tam - 1; j++){
                f->elementos[j].numeracao = f->elementos[j+1].numeracao;
            }
            f->tam--;
            break;
        }
    }
}

int main (){
    int num;
    int n;
    Fila f;

    criarFilaVazia(&f);

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        enfileirar(&f, num);
    }

    printFila(&f);
    desenfileirar(&f);
    desenfileirar(&f);
    printFila(&f);

    return 0;
}