#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pratos{
    char cor[20];
    struct pratos *next;
}Prato;

typedef struct Descritor{
    Prato *topo;
    Prato *base;
    unsigned int tam;
}Descritor;

Descritor *criaStackVazia(){
    Descritor *p = (Descritor*) calloc (1, sizeof(Descritor));
    p->topo = NULL;
    p->base = NULL;
    p->tam = 0;

    return p;
}

Prato *criaPrato(char cor[]){
    Prato *p = (Prato*) calloc (1, sizeof(Prato));
    strcpy(p->cor, cor);
    p->next = NULL;
}

bool vazia(Descritor *p){
    return(p->base == NULL && p->topo == NULL && p->tam == 0);
}

void empilhar(Descritor *p, Prato *n){
    if(vazia(p)){
        Prato *aux;
        p->topo = n;
        p->base = n;
        p->tam++;
    }
    else{
        n->next = p->topo;
        p->topo = n;
        p->tam++;
    }
}

void desempilhar(Descritor *p){
    if(!vazia(p)){
        Prato *aux = p->topo;
        p->topo = p->topo->next;
        free(aux);
        p->tam--;
    }
}

void printStack(Descritor *p){
    if(!vazia(p)){
        Prato *aux = p->topo;
        while(aux != NULL){
            printf("%s\n", aux->cor);
            aux = aux->next;
        }   
    }    
}

int  main(){
    int n;
    Descritor *p;
    Prato *c;
    char cor[20];
    
    p = criaStackVazia();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", cor);
        c = criaPrato(cor);
        empilhar(p, c);
    }   

    printStack(p);
    desempilhar(p);
    printStack(p);

    return (0);

}


