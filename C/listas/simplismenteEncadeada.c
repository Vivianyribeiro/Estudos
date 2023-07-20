#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;//ponteiro para nó
} Node;

// nó descritor
typedef struct _linked_list { 
    Node *begin;
}LinkedList;

Node *Node_create (int val) {
    Node *node = (Node *) calloc (1,sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

LinkedList *LinkedList_create () {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

void LinkedList_add_first(LinkedList *L, int val) { //Adicionar no inicio
    //novo nó aponta para o mesmo lugar de begin e depois faz begin apontar para o novo inserido que é p
    Node *p = Node_create(val);
    p->next = L->begin;
    L->begin = p;
}

void LinkedList_add_last (LinkedList *L, int val) {
    Node *q = Node_create(val);

    //se a lista estiver vazia 
    if (L->begin == NULL) {
        
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
    printf("NULL");
}

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 2);
    LinkedList_add_first(L, 4);
    LinkedList_add_first(L, 5);
    LinkedList_add_last(L, 7); // este esta inserindo no final ao inves do inicio

    printList(L);
    // SAIDA : L -> 5 -> 4 -> 2 -> 10 -> 7 -> NULL
    return 0;
}

