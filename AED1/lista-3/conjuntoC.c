//
// conjunto.h
//
#include <stdio.h>
#include <math.h>
#define TAM 100
 
typedef struct conjunto Conjunto;
 
struct conjunto {
    int elementos[TAM];
};
int qtd1, qtd2;

void inserir(int x, Conjunto *a, int qtd);
 
int pertence(int x, Conjunto a, int qtd);
 
void uniaoC(Conjunto a, Conjunto b); 
 
void interC(Conjunto a, Conjunto b);
 
void inicializar(Conjunto *a);
//
// conjunto.c
//
void inicializar(Conjunto *a){
    int i;
    for(i = 0; i<100; i++)
        a->elementos[i]=0;
}
void inserir(int x, Conjunto *a, int qtd){
    int i, ok = 0;
    for( i =0; i < qtd; i++){
       if( a->elementos[i] == x) {
        ok = 1;
       }
    }
    if(ok){
        return;
    } else {
        for(i =0 ; i < qtd; i++){
            if(a->elementos[i] == 0){
                a->elementos[i] = x;
                break;
            }
        }
    }
}
 
int pertence(int x, Conjunto a, int qtd){
    int i;
    for(i = 0; i < qtd; i++){
        if(a.elementos[i] == x){
            return 1;
        }
    }
    return 0;
}
 
void uniaoC(Conjunto a, Conjunto b){
    int i;
    for(i = 0; i < qtd1; i++){
        printf("%d ", a.elementos[i]);
    }
    for(i = 0; i < qtd2; i++){
        if( pertence(b.elementos[i], a, qtd1) == 0){
            printf("%d ", b.elementos[i]);
        }
    }
    printf("\n");
}
 
void interC(Conjunto a, Conjunto b){
    int i;
    for(i = 0; i < qtd1; i++){
        // printf("%d %d\n", pertence(a.elementos[i], b, qtd2), a.elementos[i]);
        if(pertence(a.elementos[i], b, qtd2) == 1){
            printf("%d ", a.elementos[i]);
        }
 
    }
    printf("\n");
}
 
//
// MAIN
//
int main() {
    int i, a;
    Conjunto c1, c2;
    inicializar(&c1);
    inicializar(&c2);
    scanf("%d", &qtd1);
    for(i = 0; i < qtd1; i++){
        scanf("%d", &a);
        inserir(a, &c1, qtd1);
    }
    scanf("%d", &qtd2);
    for(i = 0; i < qtd2; i++){
        scanf("%d", &a);
        inserir(a, &c2, qtd2);
    }
 
    int casos, resp;
    scanf("%d", &casos);
    while(casos--){
        int tipo;
        scanf("%d", &tipo);
        if(tipo == 1){
            scanf("%d", &a);
            resp = pertence(a, c1, qtd1);
            if(resp == 1){
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
        if (tipo ==2){
            scanf("%d", &a);
            resp = pertence(a, c2, qtd2);
            if(resp == 1){
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
        if(tipo == 3){
            uniaoC(c1, c2);
        }
        if(tipo==4){
            interC(c1, c2);
        }
    }
 
 
    return 0;
}
