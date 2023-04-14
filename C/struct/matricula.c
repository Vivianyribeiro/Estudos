/*
Crie uma struct para representar um aluno, com nome, matrícula, nota da primeira prova e nota da segunda prova. Faça um programa que leia do usuário quantos alunos ele deseja cadastrar, crie um vetor dinâmico de alunos e preencha as informações de cada um. Em seguida, exiba na tela a média de cada aluno e a média da turma.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro {
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
}Cadastro;

Cadastro *create_cadastro (char *nome, int matricula, float nota1, float nota2) {
    Cadastro *novo_aluno = (Cadastro*) calloc (1, sizeof(Cadastro));
    if(novo_aluno == NULL){
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    strcpy(novo_aluno->nome, nome);
    novo_aluno->matricula = matricula;
    novo_aluno->nota1 = nota1;
    novo_aluno->nota2 = nota2;

    return novo_aluno;

}
Cadastro *reader(Cadastro **cadastro, int n){
    *cadastro = (Cadastro*) calloc(n , sizeof(Cadastro));
    if (*cadastro == NULL) {
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        puts("");
        printf("Digite o nome do aluno %d: ", i+1);
        char nome[100];
        getchar();
        scanf("%[^\n]%*c", nome);

        printf("Digite a matricula do aluno %d: ", i+1);
        int matricula;
        scanf("%d", &matricula);

        printf("Digite a nota1 do aluno %d: ", i+1);
        float nota1;
        scanf("%f", &nota1);

        printf("Digite a nota2 do aluno %d: ", i+1);
        float nota2;
        scanf("%f", &nota2);

        (*cadastro)[i] = *create_cadastro(nome, matricula, nota1, nota2);
    }
}

void print_cadastro(Cadastro *cadastro, int n){
    float media_turma = 0.0;
    for(int i = 0; i< n; i++){
        puts("------------------------------------------------");
        printf("cadastro aluno %d\n", i+1);
        printf("Aluno: %s\n", cadastro[i].nome);
        printf("Matricula: %d\n", cadastro[i].matricula);
        printf("- Nota1: %.2f   - Nota2: %.2f   - Media: %.2f\n", cadastro[i].nota1, cadastro[i].nota2,((cadastro[i].nota1 + cadastro[i].nota2) /2));
        puts("------------------------------------------------\n");

        media_turma += ((cadastro[i].nota1 + cadastro[i].nota2) /2);
    }
    printf("\n>>>>  Media da Turma: %.2f\n\n", media_turma/n);
}

void free_cadastro (Cadastro **cadastro_ref, int n){
    Cadastro *cadastro = *cadastro_ref;
    for(int i = 0 ; i < n; i++){
        free(cadastro[i].nome);
    } 
    free(cadastro);
    *cadastro_ref= NULL;
}

int main() {
    int n;
    Cadastro *cadastro = NULL;
    printf("Digite a quantidade de cadastro que deseja fazer: ");
    scanf("%d", &n);

    reader(&cadastro, n);
    print_cadastro(cadastro, n);

    free_cadastro(&cadastro, n);

    free(cadastro);
    cadastro = NULL;

    return 0 ;
}