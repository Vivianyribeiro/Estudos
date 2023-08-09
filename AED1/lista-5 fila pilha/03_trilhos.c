#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vagao {
    int num;
    struct vagao *next
}Vagao;

typedef struct descritor {
    Vagao *topo;
    Vagao *size;
}Descritor;

void startStack(Descritor *P){
    P->topo = NULL;
    P->size = 0;
}

bool emptyStack (Descritor *P) {
    return(P->size == 0);
}

//inserir no final
void push(Descritor *P, Vagao v ) { 
    Vagao *new = CriaVagao(v);
    if(emptyStack(P)) {
        P->topo->num = new->num;
        P->size = +1;
        P->topo =  new->next;
    }
    else {
        P->topo->num = new->num;
    }
}

void pop() {

}

Vagao* CriaVagao (Vagao v) { //cria vagao e retorna o vagao
    Vagao *p = (Vagao*) calloc (1, sizeof(Vagao));
    p->num = v.num;
    p->next = NULL;
    return p;
}

int main () {
    int count;
    Vagao v;
    Descritor D; 
    
    scanf("%d", &count);

    while(count--) {
        scanf("%d", v.num);
        criaVagao(v);

    }
}