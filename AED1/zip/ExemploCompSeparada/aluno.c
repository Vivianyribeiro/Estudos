#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "aluno.h"
   
//Implementacao das funcoes:
void inicializa_aluno(TALUNO*p, unsigned int matricula, char* nome, double* notas, int numNotas){
	int i;
	p->numNotas=numNotas;
	p->matricula=matricula;
	if(strlen(nome)==0)//nao foi informado o nome do aluno durante a criacao do aluno
		p->nome=NULL;
	else{
		p->nome=(char*)malloc(strlen(nome)+1);
		if(p->nome){
			strcpy(p->nome, nome);	
		}
	}
	p->notas=(double*)malloc(numNotas*sizeof(double));
	if(notas==NULL){ //As notas não foram informadas. Criar um vetor com todas as notas igual a zero
		for(i=0;i<numNotas;i++){
			p->notas[i]=0.0;
		}
		p->situacao=0;
		p->mediaFinal=0.0;
	}
	else{
		p->mediaFinal=0.0;
		for(i=0;i<numNotas;i++){
			p->notas[i]=notas[i];
			p->mediaFinal+=notas[i];
		}
		p->mediaFinal/=(double)numNotas;
		if(p->mediaFinal>=6.0){
			p->situacao=1;
		}
		else{
			p->situacao=0;
		}	
	}		
	printf("Passou aqui\n");			
}

int altera_nome_aluno(TALUNO* p, char* nome){
	if(!p)
		return(0);
	if(p->nome)
		free(p->nome);//libera espaco ocupado pelo nome atual
	p->nome=(char*)malloc(strlen(nome)+1);
	if(!p->nome)
			return(0);//o nome nao pode ser alterado - falta de memoria
	strcpy(p->nome,nome);
	return(1);//nome alterado;	
}

int altera_matricula_aluno(TALUNO* p, unsigned int matricula){
	if(!p)
		return(0);
	p->matricula=matricula;
	return(1);
}

int altera_notas_aluno(TALUNO* p, double*  notas, int numNotas){
   if(!p)
	   return(0);
   if(numNotas!=p->numNotas)
		return(0); //nao altera notas pois o numero de notas difere do numero de notas da criacao do aluno
   int i;
   for(i=0;i<numNotas;i++){
	   p->notas[i]=notas[i];
   }
   return(1);//alterou as notas
}	
char * acessa_nome_aluno(TALUNO* p){
	if(!p)
		return(NULL);
	return(p->nome);	
}
unsigned int acessa_matricula_aluno(TALUNO* p){
	if(!p)
		return(0); //estamos considerando que as matriculas se iniciam a partir de 1;
	return(p->matricula);
}

int acessa_numNotas_aluno(TALUNO* p){
	return(p->numNotas);
}

double * acessa_notas_aluno(TALUNO* p){
	if(!p)
		return(NULL);
	return(p->notas);
}
double  acessa_media_aluno(TALUNO* p){	
	return(p->mediaFinal);
}
short int acessa_situacao_aluno(TALUNO* p){
	return(p->situacao);
}
void elimina_aluno(TALUNO* p){
	if(!p)
		return;
	free(p->nome);
	free(p->notas);
}	
	

