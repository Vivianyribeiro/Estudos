#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct aluno{
    char nome[20];
    int matricula;
    struct aluno *next;
}Aluno;

typedef struct descritor{
    Aluno *begin;
    Aluno *end;
    int tam;
}Descritor;

Descritor *criarFilaVazia(){
    Descritor *f = (Descritor*) calloc (1, sizeof(Descritor));
    f->begin = NULL;
    f->end = NULL;
    f->tam = -1;
}

Aluno *criaAluno(char nome[], int mat){
    Aluno *a = (Aluno*) calloc (1, sizeof(Aluno));
    strcpy(a->nome, nome);
    a->matricula = mat;
    a->next = NULL;
    return a;
}

bool vazia(Descritor *f){
    return(f->begin == NULL && f->end == NULL && f->tam == -1);
}

void enfileirar(Descritor *f, Aluno *a){
    puts("entra enf");
    if(vazia(f)){
        f->begin = a;
        f->end = a;
    }
    else {
        f->end->next = a; 
    }
    f->end = a;
    f->tam++;
}

void desenfileirar(Descritor *f){
    if(!vazia(f)){  
        Aluno *aux;
        aux = f->begin;
        f->begin = f->begin->next;
        free(aux);
        f->tam--;
    }
}

void printFila(Descritor *f){
    if(!vazia(f)){
        Aluno *aux;
        aux = f->begin;
        while (aux != NULL){
            printf("%s - %d\n", aux->nome, aux->matricula);
            aux = aux->next;
        }
    }
}

int main (){
    int n, i;
    char nome[20];
    int mat;
    Descritor *f;
    Aluno *a;

    f = criarFilaVazia();

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", nome);
        scanf("%d", &mat);
        a = criaAluno(nome, mat);
        enfileirar(f, a);
        puts("saiu do enf");
    }

    printFila(f);
    desenfileirar(f);
    printFila(f);

    return 0;
}
