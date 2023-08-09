#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 
typedef struct paciente {
    int hora;
    int min;
    int minCondicao;
    struct paciente *next;
}Paciente;
 
typedef struct descritor {
    Paciente *begin;
    Paciente *end;
    int size;
}Descritor;
 

//.h

Paciente* criaPaciente(Paciente paciente);
// tipo Fila (Queue)
Descritor* criateQueue();
 
bool ifListEmpty(Descritor *D);
 
void enqueue(Descritor *D, Paciente paciente);
 
int calculaCondicao(Descritor *D, Paciente p,  int qtd);
 
int dequeue(Descritor *D, int qtd);
 
 
//main

int main () {
    int count;
    Descritor D;
    Paciente p;
 
    D = *criateQueue();
 
    scanf("%d", &count);
    int qtd = count;
    while (count--) {
        scanf("%d", &p.hora);
        scanf("%d", &p.min );
        scanf("%d", &p.minCondicao);
        enqueue(&D, p);
    }
     int res = dequeue (&D, qtd);
    printf ("%d\n", res);
 
}

//.c
 
Paciente* criaPaciente(Paciente paciente) {
    Paciente *p = (Paciente*) calloc (1, sizeof(Paciente));
    p->hora = paciente.hora;
    p->min = paciente.min;
    p->minCondicao = paciente.minCondicao;
    p->next = NULL;
 
    return p;
}
 
// tipo Fila (Queue)
 
Descritor* criateQueue() {
    Descritor *d = (Descritor*) calloc (1,sizeof(Descritor));
    d->begin = NULL;
    d->end = NULL;
    d->size = 0;
 
    return d;
}
 
bool ifListEmpty(Descritor *D) { // lista vazia?
    return (D->size == 0);
}
 
void enqueue(Descritor *D, Paciente paciente) { // enfileirar sempre inserindo no final
    Paciente *p = criaPaciente(paciente);
    if (ifListEmpty(D)) {
        D->begin = p;
        D->size +=1;
        D->end = p;
    }
    else {
        D->end->next = p;
        D->end = D->end->next;
        D->size +=1; 
    }
}
 
int calculaHorarios(Descritor *D, Paciente p, int qtd) {
    Descritor horarios; //faz uma fila de horarios e vai tirando de acordo com os pacientes que vao pegando os horarios
    criateQueue(horarios);
    horarios.begin->hora
}
 
int dequeue(Descritor *D, int qtd) { // desenfileirar removendo do inicio
    int cont=0, res = 0;
    if(!ifListEmpty(D)) {
        Paciente *aux;
        aux = D->begin;
 
        if (D->begin == D->end) {
            res = calculaCondicao(D, *aux, qtd);
            if (res == 1) {
                cont +=1;
            }
            D->end = NULL;
            free (aux);
            D->begin = NULL;
            D->size --;
        }
        else {
            while (aux != NULL) {
            res = calculaCondicao(D, *aux, qtd);
                if (res == 1) {
                    cont += 1;
                    D->begin = aux->next;
                    free(aux);
                    D->size --;
                }
                if (res == 0) {
                    D->begin = aux->next;
                    free (aux);
                    D->size --;
                }
                aux = D->begin;
            }
        }
    }
    return cont;
}