#include<stdio.h>
#include<stdlib.h>
#include "llse.h"

int main(){
	TCelula * prim;
	criaListaVazia(&prim);
	printf("Inserindo 2 no inicio da lista vazia \n");
	if (InsInicio (&prim, 2, 2)==SUCESSO){
		printf("Inserindo 1 no inicio da lista\n");
		if (InsInicio (&prim, 1, 1)==SUCESSO){
			printf("Inserindo 3 no fim da lista\n");
			if(InsFinal (&prim, 3, 3)==SUCESSO){
				printf("Inserindo 4 no fim da lista\n");
				if(InsFinal (&prim, 4, 4)==SUCESSO){
					printf("Inserindo 5 no fim da lista\n");
					if(InsFinal (&prim, 5, 5)==SUCESSO){
						Imprime(prim);
					}
					else
						return(0);
				}
				else 
					return(0);
			}
			else
				return(0);
		}
		else
			return(0);
	}
	else
		return(0);
	printf("Remover a chave 3\n");
	if(RemChave(&prim, 3)==SUCESSO){
	 printf("Chave 3 removida, veja:\n");	
	 Imprime(prim);
	}
	else
		printf("Chave 3 nao pode ser removida\n");
	printf("Remover a chave 5\n");
	if(RemChave(&prim, 5)==SUCESSO){
	 printf("Chave 5 removida, veja:\n");	
	 Imprime(prim);
	}
	else
		printf("Chave 5 nao pode ser removida\n");
	printf("Remover a chave 1\n");
	if(RemChave(&prim, 1)==SUCESSO){
	 printf("Chave 1 removida, veja:\n");	
	 Imprime(prim);
	}
	else
		printf("Chave 1 nao pode ser removida\n");
	
	
}

