#include<stdlib.h>
#include<stdio.h>
#include "aluno.h"
#include "turma.h"

struct turma{
  TALUNO* vetAlunos;
  int fimVet;//indice do ultimo aluno inserido
  int tamTurma;	//tamanho fisico do vetor de TALUNO*
};

TURMA* cria_turma(int tamTurma){
	if(tamTurma>0){
		TURMA* t= malloc(sizeof(TURMA));
		if(!t)
			return(NULL);
		t->tamTurma=tamTurma;
		t->fimVet=0;
		t->vetAlunos=(struct aluno*)malloc(sizeof(struct aluno)*tamTurma);
		if(!t->vetAlunos)//nao conseguiu alocar vetor de ponteiros para os alunos da turma
			return(NULL);
		return(t);
	}
	return(NULL);
}
int insere_aluno_turma(unsigned int mat, char* nome, int numNotas, double* notas, TURMA* t){
	if(t->fimVet==t->tamTurma)
		return (0);// nao ha mais espaco na turma para incluir aluno	
	inicializa_aluno(t->vetAlunos+t->fimVet, mat, nome, notas, numNotas);
	t->fimVet++;
	return(1);
}
void lista_turma(TURMA* t){
	int i;
	for(i=0;i<t->fimVet;i++){ 
		unsigned int mat=acessa_matricula_aluno(&(t->vetAlunos[i]));
		printf("Matricula: %d ", mat);
		char* nome=acessa_nome_aluno(&t->vetAlunos[i]); 
		if(nome)
			printf("%s ", nome);
		else
			printf(" ");
		int j, numNotas;
		numNotas=acessa_numNotas_aluno(&t->vetAlunos[i]);
		printf("Num. de Notas: %d ", numNotas);
		double* n = acessa_notas_aluno(&t->vetAlunos[i]);
		for(j=0;j<numNotas;j++){
			printf("Nota %d: %.2lf ", j+1, n[j]); 
		}
		printf("Media: %.2lf ", acessa_media_aluno(&t->vetAlunos[i])); 
		printf("Situacao: ");
		acessa_situacao_aluno(&t->vetAlunos[i])? printf("Aprovado\n") :printf("Reprovado\n");	
	}	 					
}
