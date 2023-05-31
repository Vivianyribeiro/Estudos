#ifndef TURMA_H
#define TURMA_H

typedef struct turma TURMA;

TURMA* cria_turma(int tamTurma);
int insere_aluno_turma(unsigned int mat, char* nome, int numNotas, double* notas, TURMA* t);
void lista_turma(TURMA* t);
#endif
