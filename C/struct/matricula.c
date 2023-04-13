#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro {
    char nome[100];
    char matricula;
    float nota1;
    float nota2;
}Cadastro;

Cadastro* create_cadastro ( Cadastro *cadastro) {
    cadastro = (Cadastro*) calloc (1, sizeof(Cadastro));

    printf("Digite o nome do aluno: ");
    getchar();
    scanf("%[^\n]%*c", cadastro->nome);

    printf("Digite a matricula: ");
    scanf("%d", &cadastro->matricula);

    printf("Digite a nota1: ");
    scanf("%f", &cadastro->nota1);

    printf("Digite a nota2: ");
    scanf("%f", &cadastro->nota2);

}
void novo_cadastro(Cadastro *cadastro, int n){
    for(int i = 0 ; i < n; i++){
        Cadastro new = create_cadastro(&cadastro);
    }
}

int main() {
    int n;
    Cadastro *cadastro = NULL;
    printf("Digite a quantidade de cadastro que deseja fazer: ");
    scanf("%d", &n);

    novo_cadastro(&cadastro, n);

    return 0 ;
}