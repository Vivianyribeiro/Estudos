#include <stdio.h>
#include <stdlib.h>

typedef struct lanch {
    int valor_cafe;
    struct lanch *next;
}Lanch;

//.h

Lanch *criaLanch(int a);

void inserirFinal(Lanch **l, int a);

void printfLista(Lanch *l);

int confereMoedas(Lanch **l, int m);

void desalocaLista(Lanch *l);

//main

int main () {
    int n_lanchonetes;
    int cafe;
    int k_dias, i, moedas, qtd_lanch = 0;
    Lanch *l;
    l = NULL;

    scanf("%d", &n_lanchonetes);
    for(i = 0; i < n_lanchonetes; i++){
        scanf("%d", &cafe);
        inserirFinal(&l, cafe);
    }

    scanf("%d", &k_dias);
    for(i = 0; i < k_dias; i++){
        scanf("%d", &moedas);
        qtd_lanch = confereMoedas(&l, moedas);
        printf("%d\n", qtd_lanch);
    }
    desalocaLista(&l);

    return 0;
}

//.c

Lanch *criaLanch(int a){
    Lanch *p = (Lanch*) calloc (1,sizeof(Lanch));
    p->valor_cafe = a;
    p->next = NULL;

    return p;
}

void inserirFinal(Lanch **l, int a){
    Lanch *new = criaLanch(a);

    if (*l == NULL){
        *l = new;
    }
    else {
        Lanch *aux = (*l);
        while (aux->next != NULL){
            aux = aux->next;
        }
        
        aux->next = new;
    }
}

void printfLista(Lanch *l){
    if(l != NULL){
        Lanch *aux = l;
        while(aux != NULL){
            printf("%d ", aux->valor_cafe);
            aux = aux->next;
        }
    }   
}

int confereMoedas(Lanch **l, int m){
    if(*l != NULL){
        Lanch *aux = *l;
        int qtd = 0;
        while(aux != NULL){
            if((m - aux->valor_cafe) >= 0){
                qtd++;
            }
            aux = aux->next;
        }
        return qtd;
    }
}

void desalocaLista(Lanch *l){
    while (l != NULL){
        Lanch *aux = l;
        l= l->next;
        free(aux);
    }
}