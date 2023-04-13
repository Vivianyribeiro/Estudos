/*Crie uma struct Pessoa que contenha os campos nome, idade e endereco. Em seguida, escreva uma função que leia os dados de uma pessoa do usuário e os armazene em uma variável do tipo Pessoa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[100];
    int idade;
    char endereco[200];
}Pessoa;

/*FUNCAO PARA CRIAR/ALOCAR UMA PESSOA*/
Pessoa creat_pessoa (char *nome, int idade, char *endereco) {
    Pessoa *pessoa = (Pessoa*) calloc(1, sizeof(Pessoa));
    strcpy(pessoa->nome, nome);
    pessoa->idade= 24;
    strcpy(pessoa->endereco, endereco);

    return *pessoa;
}

void print_pessoa (Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("idade: %d\n", pessoa->idade);
    printf("endereco: %s\n", pessoa->endereco);

}

void desaloca_pessoa (Pessoa **pessoa_ref){
    Pessoa *pessoa = *pessoa_ref;
    free(pessoa);
    *pessoa_ref= NULL;
}

int main () {
    Pessoa vivi;
    /*
    strcpy(vivi.nome, "Vivi");
    vivi.idade = 24;
    strcpy(vivi.endereco, "rua cinza qd j");*/

    vivi = creat_pessoa("Vivi", 24, "rua cinza qd j");

    print_pessoa(&vivi);
    desaloca_pessoa(&vivi);

    return 0;
}

/* EXEMPLO EM ALOCACAO ESTATICA

#include <stdio.h>
#include <string.h>

typedef struct pessoa {
    char nome[100];
    int idade;
    char endereco[200];
} Pessoa;

void creat_pessoa(Pessoa *pessoa, char *nome, int idade, char *endereco) {
    strcpy(pessoa->nome, nome);
    pessoa->idade = idade;
    strcpy(pessoa->endereco, endereco);
}

void print_pessoa(Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Endereco: %s\n", pessoa->endereco);
}

int main() {
    Pessoa vivi;
    creat_pessoa(&vivi, "Vivi", 24, "rua cinza qd j");
    print_pessoa(&vivi);
    return 0;
}


*/