#ifndef LLSE_H
#define LLSE_H
#include <stdio.h>
#include <stdlib.h>
#define SUCESSO  1
#define FALHA   -1

struct celula {int chave; int dado; struct celula *prox;};
	  
typedef struct celula TCelula;
void criaListaVazia(TCelula **inicio);
int InsInicio (TCelula **inicio, int chave, int valor);
int InsFinal (TCelula **inicio, int chave, int valor);
int RemChave (TCelula **inicio, int chave);
int Imprime(TCelula *inicio);
int RemoveInicio(TCelula **inicio);
int DestroiLista(TCelula **inicio);
#endif
