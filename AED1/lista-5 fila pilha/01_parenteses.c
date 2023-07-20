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

int main() {

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

    printLista(L);

    return 0;
}