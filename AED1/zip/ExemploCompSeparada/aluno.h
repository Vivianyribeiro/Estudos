#ifndef ALUNO_H
#define ALUNO_H
	struct aluno{
		unsigned int matricula;
		char * nome;
		int numNotas;
		double* notas;
		double mediaFinal;// Media da numNotas notas
		short int situacao;// Aprovado||Reprovado
	};
	typedef struct aluno TALUNO;
	void inicializa_aluno(TALUNO* p, unsigned int matricula, char* nome, double* notas, int numNotas);
	int altera_nome_aluno(TALUNO* p, char* nome);
	int altera_matricula_aluno(TALUNO* p, unsigned int matricula);
	int altera_notas_aluno(TALUNO* p, double*  notas, int numNotas);
	char * acessa_nome_aluno(TALUNO* p); 
	unsigned int  acessa_matricula_aluno(TALUNO* p); 
	int acessa_numNotas_aluno(TALUNO* p);
	double * acessa_notas_aluno(TALUNO* p);
	double  acessa_media_aluno(TALUNO* p);
	short int acessa_situacao_aluno(TALUNO* p);
	//void elimina_aluno(TALUNO* p);
#endif
