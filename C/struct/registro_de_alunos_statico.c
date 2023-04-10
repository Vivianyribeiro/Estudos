#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    int idade;
}Aluno; //apelido do novo "tipo"

int main(){

    Aluno ted; //coloco o tipo (apelido ) e crio a variavel ted.
    strcpy(ted.nome, "Ted");// ted recebe Ted como nome e para acessar o campo usamos ponto, mas quando acessamos struct partindo de um ponteiro usamos seta
    ted.idade = 10;
    /*OUTRA FORMA DE CONCEDER OS VALORES AS VARIAVEIS:*/

    // Aluno ted = {.nome = "Ted", .idade=10};

    printf("sizeof(Aluno)=%lu bytes\n", sizeof(Aluno));

    return 0;
}