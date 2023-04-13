#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[100];
    int id;
    float altura;
}Pessoa;

/*Funcao que cria n pessoas alocando na heap*/
Pessoa *create_pessoas(int n){
    Pessoa *pessoas = (Pessoa *) calloc(n, sizeof(Pessoa));
    if (pessoas == NULL){
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Digite o nome da pessoa %d: ", i+1);
        getchar();
        scanf("%[^\n]%*c", pessoas[i].nome);//le ate encontrar um \n

        printf("Digite o id da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].id);

        printf("Digite a altura da pessoa %d: ", i+1);
        scanf("%f", &pessoas[i].altura);

        puts("");
    }

    return pessoas;
}

/*Funcao para imprimir a lista de pessoas*/
void print_lista (Pessoa *pessoas, int n) {
    puts("Lista de pessoas: \n\n");
    for(int i = 0; i < n; i++){
        printf("Pessoa %d:\n\n", i+1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Id: %d\n", pessoas[i].id);
        printf("Altura: %.2f\n", pessoas[i].altura);
        puts("");
    }
}

int main(){
    int n;
    Pessoa *lista;
    printf("Quantas pessoas sao? \n");
    scanf("%d", &n);

    lista = create_pessoas(n);
    print_lista(lista, n);

    free(lista);
    lista = NULL;

    return 0;
}