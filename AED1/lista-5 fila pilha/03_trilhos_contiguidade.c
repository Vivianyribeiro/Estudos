#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

//.h

typedef struct pilha{
    int num[MAX_SIZE];
    int topo;
}Pilha;

void inicializaPilha(Pilha* pilha);

bool pilhaVazia(Pilha* pilha);

int pilhaCheia (Pilha* pilha);

void push(Pilha* pilha, int item);

int pop (Pilha* pilha);

void printPilha(Pilha* pilha);


// main.c

int main () {

    Pilha pilha;
    int cont, item, i, dff =0;
    inicializaPilha(&pilha);

    scanf("%d", &cont);

    for(i = 1; i <= cont; i++){
        push(&pilha, i);
    }
    //printPilha(&pilha);

    while (cont!=0) {
        scanf("%d", &item);
        if(item == (pilha.topo)+1) {
            pop(&pilha);
        }
        else {
            dff++;
        }
        cont--;
    }
    
    if (dff > 0) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
    }
    return 0;
}


// .c

void inicializaPilha(Pilha* pilha){
    pilha->topo = -1; // inicializa dando -1 ao topo e de acordo com entrada e saida de elementos aumenta ou diminui o topo
}

bool pilhaVazia(Pilha* pilha) {
    return (pilha->topo == -1); // retorna tipo um vdd se topo ta igual a -1
}

int pilhaCheia (Pilha* pilha) {
    return pilha->topo == MAX_SIZE - 1;
}

void push(Pilha* pilha, int item) {
    if (pilhaCheia(pilha)) {
        return;
    }
    pilha->num[++pilha->topo] = item; // a variavel num na posicao topo+1 recebe o novo
}

int pop (Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        return -1;//vazia
    }
    return pilha->num[pilha->topo--]; // se nao ta vazia tira o num no topo
}

void printPilha(Pilha* pilha) {
    int i;
    if (pilhaVazia(pilha)) {
        return;
    }
    for (i = pilha->topo; i >= 0; i--) {
        printf("%d", pilha->num[i]);
        puts("");
    }
}