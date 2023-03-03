#include <stdio.h>
#include <stdlib.h>

int main () {
    int a = 10;
    int *p1 = NULL;
    int *p2;

    printf("Endereço da variavel a: %p, valor de a = %d\n", &a, a);
    printf("Endereço do ponteiro p1: %p, valor de p1 = %p\n", &p1, p1);
    printf("Endereço da variavel p2: %p, valor de p2 = %p\n\n", &p2, p2);

    p1 = &a;
    p2 = p1;
    *p2 = 4;

    printf("Endereço da variavel a: %p, valor de a = %d\n", &a, a);
    printf("Endereço do ponteiro p1: %p, valor de p1 = %p, conteudo apontado = %d\n", &p1, p1, *p1);
    printf("Endereço da variavel p2: %p, valor de p2 = %p , conteudo apontado = %d \n\n", &p2, p2, *p2);
    return 0;
}