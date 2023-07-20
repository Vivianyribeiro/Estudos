#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int dado[MAX_SIZE];
    int topo;//sempre aponta para o topo, onde sera inserido um novo elemento
}Pilha;

void inicializaPilha(Pilha* pilha){
    pilha->topo = -1; // inicializa dando -1 ao topo e de acordo com entrada e saida de elementos aumenta ou diminui o topo
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1; // retorna tipo um vdd se topo ta igual a -1
}

int pilhaCheia (Pilha* pilha) {
    return pilha->topo == MAX_SIZE - 1;
}

void push(Pilha* pilha, int item) {
    if (pilhaCheia(pilha)) {
        printf("Pilha ta cheia!\n");
        return;
    }
    pilha->dado[++pilha->topo] = item; // a variavel dado na posicao topo+1 recebe o novo elemento
}

int pop (Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha esta vazia! \n");
        return -1; // pilha vazia sai com falha
    }
    return pilha->dado[pilha->topo--]; // se nao ta vazia tira o dado no topo
}

void printPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Elementos da pilhaa: \n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d", pilha->dado[i]);
        puts("");
    }
    
}

int main () {

    Pilha pilha;
    int item;
    inicializaPilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 16);
    push(&pilha, 20);

    printf("Digite um dado para inserir na lista:\n");
    scanf("%d", &item);
    push(&pilha, item);
    printPilha(&pilha);

    printf("Retirando elemento: %d\n", pop(&pilha));
    printf("Retirando elemento: %d\n", pop(&pilha));
    printPilha(&pilha);
    printf("Retirando elemento: %d\n", pop(&pilha));
    printf("Retirando elemento: %d\n", pop(&pilha));
    printPilha(&pilha);

    return 0;
}