//
// ponto.h
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct ponto Ponto; 
//
// Definindo o tipo de dado
//
struct ponto {
   float x;
   float y;
   bool  visibilidade;
};

Ponto*  ponto_cria(float x, float y, bool visibilidade); 

void    ponto_libera(Ponto* p); 

void    ponto_acessa(Ponto* p, float* x, float* y);

void    ponto_atribui(Ponto* p, float x, float y);

float   ponto_distancia(Ponto* p1, Ponto* p2); 

void    ponto_oculta(Ponto* p); 

void    ponto_mostra(Ponto* p); 

void    ponto_move(Ponto* p, float x, float y); 

//
// ponto.c
//

//
// Cria um ponto
//
Ponto* ponto_cria (float x, float y, bool visibilidade) {
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p != NULL) {
		p->x = x;
		p->y = y;
		p->visibilidade = visibilidade;
	}

	return (p);
}
//
// Libera (desaloca) um ponto...
//
void ponto_libera (Ponto* p) {
    if (p != NULL) {
     	free(p);
    }
}
//
// Acessa um ponto, coletando suas coordenadas
//
void ponto_acessa (Ponto* p, float* x, float* y) {
    if (p != NULL) {
	   *x=p->x;
	   *y=p->y;
	}
}
//
// Atribui coordenadas a um ponto, modificando-o
//
void ponto_atribui (Ponto* p, float x, float y) {
    if (p != NULL) {
    	p->x=x;
	    p->y=y;
	}
}
//
// Retorna a distancia entre dois pontos
//
float ponto_distancia (Ponto* p1, Ponto* p2) {
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return (sqrt(dx*dx+dy*dy));
}

//
// Oculta (torna invisivel) o ponto
//
void ponto_oculta (Ponto* p) {

     p->visibilidade = false;    
}
//
// Mostra (torna visivel) o ponto
//
void ponto_mostra (Ponto* p) {

     p->visibilidade = true;    
}

void ponto_move(Ponto * p, float x, float y) {
     //
     // Codigo para movimentacao do ponto
     //
}
//
// Corpo principal
//

int main(){
	float xp,yp,xq,yq,d;	
	Ponto *p,*q;	
	
	printf("digite as coordenadas x e y para o ponto 1: ");
	scanf("%f %f",&xp,&yp);
	printf("digite as coordenadas x e y para o ponto 2: ");
	scanf("%f %f",&xq,&yq);
	p = ponto_cria(xp,yp, true);
	q = ponto_cria(xq,yq, true);
	d = ponto_distancia(p,q);
	ponto_acessa(p,&xp,&yp); ponto_acessa(q,&xq,&yq);
	printf("Distancia entre os pontos (%.2f,%.2f) e (%.2f,%.2f) = %.5f\n",xp,yp,xq,yq,d);
	ponto_libera(p); ponto_libera(q);
	return (0);
}
