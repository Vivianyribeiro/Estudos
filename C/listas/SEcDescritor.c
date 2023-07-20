#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int val;
    struct _node *next;//ponteiro para nó
} Node;

// nó descritor
typedef struct _linked_list { 
    Node *begin;
    Node *end;
}LinkedList;

Node *Node_create (int val) {
    Node *node = (Node *) calloc (1,sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

 //lista vazia ?
bool LinkedList_is_empty(const LinkedList *L) {
    return (L->begin == NULL && L->end == NULL);
}

LinkedList *LinkedList_create () {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

void LinkedList_add_first(LinkedList *L, int val) {
    Node *p = Node_create(val);
    p->next = L->begin;

    if (LinkedList_is_empty(L)) {
        L->end = p;
    }
    L->begin = p;
}

//ADICIONAR NO FINAL
void LinkedList_add_last (LinkedList *L, int val) {
    Node *q = Node_create(val);

    //se a lista estiver vazia 
    if (LinkedList_is_empty(L)) {
        L->begin = q;
        L->end = q;
    }
    else {// se ja tiver elementos
        L->end->next = q; //o campo next do ultimo aponta pro novo nó ultimo
        L->end = L->end->next; // L end agora vai apontar para o ultimo anterior next, ou seja o next do antigo ultimo
    }
}

void LinkedList_add_last_LOW (LinkedList *L, int val) { // funcao pra adicionar no final so que é mais lenta q a anterior por nao usar o no descritor com o endereço do fim
    Node *q = Node_create(val);

    //se a lista estiver vazia 
    if (LinkedList_is_empty(L)) {
        
        L->begin = q;
    }
    else {// se ja tiver elementos
        Node *p = L->begin;
        
        //enquanto p nao for o ultimo
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q; // ultimo aponta para o novo;
    }
}

void printList(LinkedList *L) {
    Node *aux = L->begin;
    //enquanto p estiver apontando para um nó da lista

    printf("L -> ");
    while (aux != NULL) {
        printf("%d -> ", aux->val);
        aux = aux->next;
    }
    printf("NULL\n");

    if(L->end == NULL) {
    printf("L->end = NULL\n");
    } 
    else {
    printf("L->end = %d\n", L->end->val);

    }
}

void LinkedList_remove(LinkedList *L, int val) {
    //se a lista NAO ! estiver vazia
    if(!LinkedList_is_empty(L)) {

        // caso 1 = se estiver na primeira posicao
        if(L->begin->val == val) {
            Node *atual = L->begin; 

            //Se tiver só um elemento
            if (L->end == L->begin) {
                L->end = NULL;
            } 
            L->begin = L->begin->next;
            free(atual);
        } 
        //caso 2 = elemento no meio da lista ou no final
        else {
            Node *anterior = L->begin;
            Node *atual = L->begin->next;

            // enquanto nao chegar no final e enquanto nao achar o valor
            while (atual != NULL && atual->val != val) {
                anterior  = atual;
                atual = atual->next;
            }
            // achei o valor
            if (atual != NULL) {
                anterior->next = atual->next;

                //Se é o ultimo nó
                if (atual->next == NULL) {
                    L->end = anterior;
                }
                free (atual);
            }
        }
    }
}

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_first(L, 10);
    printList(L);
    LinkedList_add_first(L, 2);
    printList(L);
    LinkedList_add_first(L, 4);
    printList(L);
    LinkedList_add_first(L, 5);
    printList(L);
    LinkedList_add_last(L, 7); // este esta inserindo no final ao inves do inicio
    
    printList(L);
    // SAIDA : L -> 5 -> 4 -> 2 -> 10 -> 7 -> NULL

    LinkedList_remove (L, 7);
    printList(L);
    

    return 0;
}

