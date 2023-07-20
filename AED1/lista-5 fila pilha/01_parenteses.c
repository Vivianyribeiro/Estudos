#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct polinomio {
    char character;
    struct polinomio *next;
} Polinomio;

typedef struct descritor {
    Polinomio *begin;
    Polinomio *end;
}Descritor;

Descritor *CriaListaVazia();

Polinomio *criaPolinomio(Polinomio new);

bool seListaVazia(const Descritor *l);

void InsereInicio (Descritor *l, Polinomio new);

void insFinal (Descritor *l, Polinomio new);

void printLista(Descritor *l);

void BalanceParenteses(Descritor *l);

// main

int main () {

    Polinomio polinomio;
    Descritor *L;
    char c;

    L = CriaListaVazia();

    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            polinomio.character = c;
            insFinal(L, polinomio);
        }
    }
    BalanceParenteses (L);

    Polinomio *aux = L->begin;
    while (aux != NULL) {
        Polinomio *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(L);
    
    //printLista(L);

    return 0;
}

// Funcões:

Descritor *CriaListaVazia(){
    Descritor *L = (Descritor *) calloc (1, sizeof(Descritor));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

Polinomio *criaPolinomio(Polinomio new) {
    Polinomio *q = (Polinomio *) calloc (1, sizeof(Polinomio)); 
    q->character = new.character;
    q->next = NULL;

    return q;
}

bool seListaVazia(const Descritor *l) {
    return (l->begin == NULL && l->end == NULL);
}

void InsereInicio (Descritor *l, Polinomio new) {
    Polinomio *p = criaPolinomio(new);
    p->next = l->begin;
    
    if (seListaVazia(l)){
        l->end = p;
    }
    l->begin = p;

}

void insFinal (Descritor *l, Polinomio new) {
    Polinomio *p = criaPolinomio (new);

    if (seListaVazia(l)) {
        l->begin = p;
        l->end = p;
    }
    else {
        l->end->next = p;
        l->end = p;
    }
}

void printLista(Descritor *l) {
    if (!seListaVazia(l)) {
        Polinomio *aux = l->begin;

        while (aux != NULL) {
            printf("%c ", aux->character);
            aux = aux->next;   
        }
    }
}

void BalanceParenteses(Descritor *l) {
    if (!seListaVazia(l)) {
        int abreP = 0, fechaP = 0;
        Polinomio *aux = l->begin;
        while (aux != NULL) {
    
            if (aux->character == '(') {
                abreP += 1;
            }

            if (aux->character == ')') {
                fechaP += 1;
            }
            aux = aux->next;
        }

        if (abreP == fechaP) {
            printf ("Correta\n");
        }
        else {
            printf("Incorreta\n");
        }
    }
}
