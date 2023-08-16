#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int if_emptyLista(Descritor *l);

Aluno *criaAluno(Aluno aluno);

void inserirFinal(Descritor *l, Aluno *a);

void OrdenarLista(Descritor *l);

void printLista(Descritor *l);

void desaloca(Descritor *l);


// main

int main() {
    int n_alunos;
    int i;
    Aluno aluno, *a;
    Descritor *lista;
    char nome[20];

    scanf("%d", &n_alunos);

    lista = criaListaVazia(&lista);

    for( i = 0; i < n_alunos; i++) {
        scanf("%s", aluno.nome);
        scanf("%d", &aluno.n_prob);
        a = criaAluno(aluno);
        inserirFinal(lista, a);
    }
    OrdenarLista(lista);
    printLista(lista);
    desaloca(lista);

    return 0;
}


// .c

Descritor *criaListaVazia() {
    Descritor *l = (Descritor*) calloc(1,sizeof(Descritor));
    l->begin = NULL;
    l->end = NULL;

    return l;
}

int if_emptyLista(Descritor *l){
    return (l->begin == NULL && l->end == NULL);
}

Aluno *criaAluno(Aluno aluno){
    Aluno *a = (Aluno*) calloc(1,sizeof(Aluno));
    strcpy(a->nome, aluno.nome);
    a->n_prob = aluno.n_prob;
    a->next = NULL;
    return a;
}

void inserirFinal(Descritor *l, Aluno *a){
    
    if(if_emptyLista(l)){
        l->begin = a;
        l->end = a;
    }
    else {
        l->end->next = a;
        l->end = a;
    }
}

void OrdenarLista(Descritor *l) {
    Aluno *atual, *max;
    
    if (!if_emptyLista(l)) {
        atual = l->begin;
        while (atual != NULL) {
            max = atual;
            Aluno *comparar = atual->next;
            while (comparar != NULL) {
                if (comparar->n_prob > max->n_prob ||
                    (comparar->n_prob == max->n_prob && strcmp(comparar->nome, max->nome) < 0)) {
                    max = comparar;
                }
                comparar = comparar->next;
            }
            // Troca os dados dos alunos atual e max
            if (max != atual) {
                int temp_n_prob = atual->n_prob;
                char temp_nome[20];
                strcpy(temp_nome, atual->nome);

                atual->n_prob = max->n_prob;
                strcpy(atual->nome, max->nome);

                max->n_prob = temp_n_prob;
                strcpy(max->nome, temp_nome);
            }
            atual = atual->next;
        }
    }
}

void printLista(Descritor *l){
    if(if_emptyLista(l)){
        return;
    }
    else{
        Aluno *aux;
    aux = l->begin;
        while (aux != NULL) {
        printf("%s %d\n", aux->nome, aux->n_prob);
        aux = aux->next;
        }
    }
}

void desaloca(Descritor *l){
    Aluno *atual = l->begin;
    while (atual != NULL){
        Aluno *temp = atual;
        atual = atual->next;
        free(temp);
    }
    free(l);
}
