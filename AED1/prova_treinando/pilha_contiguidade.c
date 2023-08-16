#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 100

typedef struct pratos{
    int numeracao;
}Prato;

typedef struct stack{
    Prato elementos[TAM_MAX];
    unsigned int tam;
}Stack;

void criaStackVazia(Stack *p){
    p->tam = 0;
}

bool stackCheia(Stack *p){
    return(p->tam == TAM_MAX);
}

bool stackVazia(Stack *p){
    return (p->tam == 0);
}

void pushP(Stack *p, int n){
    if(!stackCheia(p)){
        p->elementos[p->tam].numeracao = n;
        p->tam++;
    }
}

void popP(Stack *p){
    if(!stackVazia(p)){
        p->tam--;
    }
}

void printStack(Stack *p){
    if(!stackVazia(p)){
        for(int i = p->tam - 1; i >= 0; i--){
            printf("%d", p->elementos[i].numeracao);
            printf("\n");
        }
    }
}

int main(){
    int n, num;
    Stack p;

    criaStackVazia(&p);

    scanf("%d", &n);
    for(int i =0; i < n; i++){
        scanf("%d", &num);
        pushP(&p, num);
    }

    printStack(&p);
    popP(&p);
    popP(&p);
    printStack(&p);

    return 0;
}