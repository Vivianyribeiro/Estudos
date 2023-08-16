//Implemente uma lista simplesmente encadeada em C. Inclua operações para inserção, remoção e exibição de elementos.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[20];
    int idade;
    struct pessoa *next; 
}Pessoa;

void printLista(Pessoa *l);


Pessoa *criaPessoa(char name[], int idade){
    Pessoa *p = (Pessoa*) calloc (1, sizeof(Pessoa));
    strcpy(p->nome, name);
    p->idade = idade;
    p->next = NULL;
     

    return p;
}

int listaVazia(Pessoa *lista){
    return lista == NULL;
}

Pessoa *insereInicio(Pessoa *p, char name[], int idade){
    
    Pessoa *a = criaPessoa(name, idade);
    
    a->next = p;

    return a;
}

void printLista(Pessoa *l){
    Pessoa *aux = l;

    while (aux != NULL){
        printf("%s - %d\n", aux->nome, aux->idade);
        aux = aux->next;
    }
}

void removeN(Pessoa **p, int n){
    Pessoa *anterior = NULL;
    Pessoa *aux = *p;

    while (aux != NULL && aux->idade != n) {
        anterior = aux;
        aux = aux->next;
    }
    if(aux != NULL){
        if(anterior == NULL){
            *p = aux->next;
        }
        else {
            anterior->next = aux->next;
        }
        free(aux);
    }
}

int main(){
    char nome[20];
    int idade, cont, n;
    Pessoa *lista;

    lista = NULL;

    scanf("%d", &cont);
    while (cont--){
        scanf("%s", nome);
        scanf("%d", &idade);
        lista = insereInicio(lista, nome, idade);

    }

    printLista(lista);
    scanf("%d", &n);
    removeN(&lista, n);
    printLista(lista);
}
