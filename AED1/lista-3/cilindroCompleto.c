//
// cilindro.h
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.1415

typedef struct cilindro{
    float raio;
    float altura;
    bool visibilidade;
}Cilindro;

Cilindro* criarCilindro(float raio, float altura, bool vis);

void deletarCilindro(Cilindro* c);

void mostraCilindro(Cilindro* c);

float alturaCilindro(Cilindro* c);

float raioCilindro(Cilindro* c);

float areaCilindro(Cilindro* c);

float volumeCilindro(Cilindro* c);

//
//cilindro.c
//

//
//Cria um Cilindro  
//
Cilindro* criarCilindro(float raio, float altura, bool vis){
    Cilindro* c = (Cilindro*)calloc(1,sizeof(Cilindro));
    if(c != NULL){
        c->raio = raio;
        c->altura = altura;
    }
    
    return c;
}
//
// libera (desaloca) um cilindro
//
void deletarCilindro(Cilindro* c){
    if(c != NULL){
        free(c);
    }
}
//
//imprime um cilindro
//
void mostraCilindro(Cilindro* c){
    if(c != NULL){
        c-> visibilidade = true;
    }
}
//
//altura do cilindro
//
float alturaCilindro(Cilindro* c){
    if(c != NULL){
        return c->altura;
    }
    return 0;
}
//
//raio do cilindro
//
float raioCilindro(Cilindro* c){
    if(c != NULL){
        return c->raio;
    }
    return 0;
}
//
//area da base do cilindro
//
float areaCilindro(Cilindro* c){
    if(c != NULL){
        return PI * pow(c->raio,2);
    }
    return 0;
}
//
//volume do cilindro
//
float volumeCilindro(Cilindro* c){
    if(c != NULL) {
        return PI * pow(c->raio,2) * c->altura;
    }

}
//
// Main
//

int main () {
    float h, r;
    Cilindro *c1 = 0;

    printf ("Digite o raio e a altura do cilindro: ");
    scanf("%f %f", &r, &h);
    c1 = criarCilindro(r, h, true);

    if (c1 != NULL) {
        mostraCilindro(c1);
        printf ("Altura: %.2f\n", alturaCilindro(c1));
        printf ("Raio: %.2f\n", raioCilindro(c1));
        printf ("Area: %.2f\n", areaCilindro(c1));
        printf ("Volume: %.2f cm3\n", volumeCilindro(c1));
    }

    deletarCilindro(c1); 

    return 0;
}




