#include<stdio.h>
#include<stdlib.h>
#include "aluno.h"
#include "turma.h"

int main(){
	int tamTurma;
	printf("Digite o numero de alunos da turma\n");
	scanf("%d", &tamTurma);
	printf("Tamanho da turma %d\n", tamTurma);
	int i;
	//Criar uma turma para tamTurma alunos
	TURMA* t = cria_turma(tamTurma);
	if(!t){
		fprintf(stderr, "Nao foi possivel criar uma tumrma\n");
		exit(1);
	}
	unsigned int matricula;	
	char nome[1000];
	int numNotas;	
	if(t){
		printf("Digite o numero de notas de cada aluno\n");
		scanf("%d", &numNotas);
		double vetNotas[numNotas];
		for(i=0;i<tamTurma;i++){
			printf("Digite a matricula de um aluno\n");
			scanf("%u", &matricula); getchar();
			printf("Digiete o nome do aluno\n");
			scanf("%[^\n]", nome);getchar();
			int j;
			for(j=0;j<numNotas;j++){
			   printf("Digite a nota %d do aluno\n",j+1);
			   scanf("%lf", &vetNotas[j]);
			}
			
			if(!insere_aluno_turma(matricula, nome, numNotas,vetNotas,t)){
				fprintf(stderr, "Nao foi possivel inserir dados do aluno na turma\n");
				return(0);
			}
		}
		lista_turma(t);	
		return(0);		
	}
	printf("A turma nao pode ser criada - Encerrando o programa\n");
}
