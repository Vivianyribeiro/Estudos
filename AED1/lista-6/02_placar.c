#include <stdio.h>
#include <stdbool.h>

typedef struct aluno {
    char nome[20];
    int n_prob;
    struct aluno* next;
}Aluno;

typedef struct descritor {
    Aluno *begin;
    Aluno *end;
}Descritor;

//.h

Descritor *criaListaVazia();

bool if_empty(Descritor *l);

Aluno *criaAluno(Aluno aluno);

void inserirInicio();

void inserirFinal();

void desaloca(Descritor *l);


// main

int main() {
    int n_alunos;
    int i;
    Aluno aluno, *a;
    Descritor lista;
    char nome[20];

    scanf("%d", &n_alunos);

    criaListaVazia(lista);

    for( i = 0; i < n_alunos; i++) {
        scanf("%s", aluno.nome);
        scanf("%s", &aluno.n_prob);
        a = criaAluno(aluno);
        inserirFinal(&lista, *a);
    }

    return 0;
}


// .c

Descritor *criaListaVazia() {
    Descritor *l = (Descritor*) calloc(1,sizeof(Descritor));
    l->begin = NULL;
    l->end = NULL;

    return l;
}

bool if_empty(Descritor *l){
    if(l->begin == NULL && l->end == NULL);
}

Aluno *criaAluno(Aluno aluno){
    Aluno *a = (Aluno*) calloc(1,sizeof(Aluno));
    strcpy(a->nome, aluno.nome);
    a->n_prob = aluno.n_prob;
    a->next = NULL;
    return a;
}

void inserirInicio(Descritor *l, Aluno a){
    Aluno *p = criaAluno(a);
    p->next = l->begin;

    if(if_empty(l)){
        l->end = p;
    }
    l->begin = p;
}

void inserirFinal(Descritor *l, Aluno a){
    Aluno *p = criaAluno(a);
    
    if(if_empty(l)){

        l->begin = p;
        l->end = p;
    }
    else {
        l->end->next = p;
        l->end = p;
    }
}

void desaloca(Descritor *l);