#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_NOME 20
#define TAM_NUMBER 9


typedef struct contact {
    char nome  [TAM_NOME];
    char  number[TAM_NUMBER];
    int  n;
    struct contact *next;
}Contact;

// nó descritor
typedef struct linked_list {
    Contact *begin;
    Contact *end;
}LinkedList;

LinkedList *CriaListaVazia () {
    LinkedList *L = (LinkedList *) calloc (1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}
//lista vazia?
bool seListaVazia(const LinkedList *l) {
    return (l->begin == NULL && l->end == NULL);

}

//cria contato
Contact *CriaContact (Contact contato) {
    Contact *q = (Contact *) calloc (1, sizeof(Contact));

    strcpy(q->nome,contato.nome);
    strcpy(q->number,contato.number);
    q->n = contato.n;
    q->next = NULL;

    return q;
}

void addInicio (LinkedList *l, Contact contato) {
    Contact *p = CriaContact (contato);
    p->next = l->begin;
        
    if (seListaVazia(l)) {
        l->end = p;
    }
    l->begin = p;
}

void addFinal (LinkedList *l, Contact contato) {
    Contact *p = CriaContact(contato);
    
    if(seListaVazia(l)) {

        l->begin = p;
        l->end = p;
    }
    else {
        
        l->end->next = p;
        l->end = p; 
    }
}

void RemoveNome(LinkedList *l, Contact contato)
{
    if (seListaVazia(l)) {
        return;
    }
    if (strcmp(l->begin->nome, contato.nome) == 0) {
        Contact *atual = l->begin;
        if (l->end == l->begin) {
            l->end = NULL;
        }
        l->begin = l->begin->next;
        free (atual);
    }
    else {
        Contact *anterior = l->begin;
        Contact *atual = l->begin->next;

        while (atual != NULL && strcmp(atual->nome, contato.nome)!= 0) {
            anterior = atual;
            atual = atual->next;
        }
        if(atual != NULL) {
            anterior->next = atual->next;

            if(atual->next == NULL) {
                l->end = anterior;
            }
            free (atual);
        }
    }
}

void Adiciona(LinkedList *l, Contact contato)
{
    Contact *aux = l->begin;
    if(!seListaVazia(l)){
        while (aux != NULL) {
            if (strcmp (aux->nome, contato.nome) == 0) {
                aux->n += 1;
            }
            aux = aux->next;
        }
    }
}

void OrdenaLista(LinkedList *l) {
    if (seListaVazia(l) || l->begin == l->end) {
        return;
    }

    bool trocou;
    Contact *atual;
    Contact *anterior = NULL;
    Contact *auxiliar;

    do {
        trocou = false;
        atual = l->begin;

        while (atual->next != NULL) {
            if (atual->n < atual->next->n) {
                trocou = true;

                if (anterior == NULL) {
                    l->begin = atual->next;
                } else {
                    anterior->next = atual->next;
                }

                auxiliar = atual->next->next;
                atual->next->next = atual;
                atual->next = auxiliar;

                if (anterior == NULL) {
                    anterior = l->begin;
                } else {
                    anterior = anterior->next;
                }
            } else {
                anterior = atual;
                atual = atual->next;
            }
        }
    } while (trocou);
}

void gerenciaInsercao ( LinkedList *l, char tipo) {
    Contact contato, *p;
    int resultado = 0;
    
    //insere nova pessoa com nome number e n
    if (tipo == 'I')
    {   scanf("%s", contato.nome);
        scanf("%s", contato.number);
        scanf("%d", &contato.n);
        p = CriaContact (contato);
        addFinal(l,*p);
        
    } else
    // remove pessoa com tal nome da lista
    if (tipo == 'R') {
        resultado = 0;
        scanf("%s", contato.nome);
        RemoveNome(l, contato);
    } else
    //L aumenta o numero de ligaçoes q tal nome possui
    if (tipo == 'L')
    {
        scanf("%s", contato.nome);
        Adiciona(l, contato);
    } else
    //finaliza
    if (tipo == 'F')
    {
        OrdenaLista(l);
    }
}

//printar lista
void printList (LinkedList *l) {
    if(!seListaVazia(l)) {
        Contact *aux = l->begin;

        while (aux != NULL) {
            printf("%s - %s\n", aux->nome, aux->number);
            aux = aux->next;
        }
    }
}

void ApagaLista(LinkedList *l)
{
    LinkedList *atual = l;
    LinkedList *proximo;
 
    while (atual != NULL)
    {
        proximo->begin = atual->begin->next;
        free(atual);
        atual = proximo;
    }
 
    l->begin = NULL; // Atualiza o ponteiro para a lista vazia
    l->end = NULL; // Atualiza o ponteiro para a lista vazia

}

int main() {
    Contact pessoa;
    LinkedList *L;
    char tipo;
    
    L = CriaListaVazia();

    strcpy(pessoa.nome, "Hermanoteu");
    strcpy(pessoa.number, "4523-2248");
    pessoa.n = 300;

    addInicio(L, pessoa);

    strcpy(pessoa.nome, "Ooloneia");
    strcpy(pessoa.number, "4523-4587");
    pessoa.n = 299;

    addFinal(L, pessoa);
    
    // ler o tipo
    scanf(" %c", &tipo);

    do {
    // se I, L, R ou F
    gerenciaInsercao(L, tipo);
    scanf(" %c", &tipo);
    } while (tipo != 'F');
    
    gerenciaInsercao(L, tipo);
    printList(L);
    ApagaLista(L);

    return 0;
}
