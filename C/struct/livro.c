/*Crie uma struct Livro que contenha os campos titulo, autor e ano. Em seguida, escreva uma função que receba um vetor de livros e determine qual deles foi publicado mais recentemente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
    char titulo[200];
    char autor[100];
    int ano;
}Livro;

/*FUNCAO PARA VERIFICAR LIVRO PUBLICADO MAIS RECENTEMENTE*/
void newest (Livro *livro1, Livro *livro2){
    if(livro1->ano > livro2->ano) {
        printf("\nLivro mais recente:\nLivro: %s  Autor: %s\n\n", livro1->titulo, livro1->autor);
    } else if(livro2->ano > livro1->ano){
        printf("\nLivro mais recente:\nLivro: %s  Autor: %s\n\n", livro2->titulo, livro2->autor);
    } else {
        printf("\nOs dois livros foram publicados no mesmo ano!");
    }
    
}

void print() {
    printf("");
}

int main (){
    Livro livro1;
    Livro livro2;

    strcpy(livro1.titulo, "vida_belissima");
    strcpy(livro1.autor, "autor X");
    livro1.ano = 2000;

    strcpy(livro2.titulo, "tempo_estatico");
    strcpy(livro1.autor, "autor Y");
    livro1.ano = 1995;

    newest(&livro1, &livro2);

    return 0;
}