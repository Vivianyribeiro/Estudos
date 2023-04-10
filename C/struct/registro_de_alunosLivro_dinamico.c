#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>//p/ a funcao bool funcionar
//xavecoding crud de struct

typedef struct _livro {
    char titulo[100];
    unsigned int paginas;
    float preco;
}Livro;

typedef struct _aluno {
    char nome[100];
    int idade;
    Livro *livro_favorito;
}Aluno;

/*FUNCAO P/ CRIAR LIVRO NA HEAP E FAZER ATRIBUICAO DE VALORES*/
Livro *create_livro(const char *titulo, unsigned int paginas, float preco) { 
    Livro *livro = (Livro*) calloc (1, sizeof(Livro));
    strcpy(livro->titulo, titulo);
    livro->paginas = paginas;
    livro->preco = preco;

    return livro;
}// essa funcao acima vai retorna um ponteiro para livro porq esta funcao sera para alocar um unico livro na memoria heap por isso é *create_livro, e o titulo e ponteiro porque criamos ele como vetor la em cima

/*A função "copy_livro" é uma função auxiliar que cria uma cópia de um livro. É uma boa prática criar uma cópia para cada livro favorito de um aluno, para que quando o livro favorito de um aluno for destruído, o livro original ainda exista.*/

/*FUNCAO P/ CRIAR COPIA DE LIVRO*/
Livro *copy_livro(const Livro *livro){ 
    return create_livro(livro->titulo, livro->paginas, livro->preco);
}

/*FUNCAO DE IMPRESSAO*/
void print_livro(const Livro *livro){
    printf("Titulo= %s\n", livro->titulo);
    printf("Num Paginas = %d\n", livro->paginas);
    printf("Preco = %.2f\n", livro->preco);
}

/*fUNCAO DE DESALOCAR LIVRO*/
void destroy_livro (Livro **livro_ref){
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}

/*FUNCAO P/ CRIAR ALUNO NA HEAP E FAZER ATRIBUICAO DE VALORES*/
Aluno *create_aluno(const char *nome, int idade, const Livro *livro_fav){
    Aluno *aluno =(Aluno *) calloc (1, sizeof(Aluno));
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro_favorito = copy_livro(livro_fav);/*ta recebendo a copia do livro*/

    return aluno;
}

/*FUNCAO DE DESALOCAR ALUNO*/
void destroy_aluno(Aluno **aluno_ref){
    Aluno *aluno = *aluno_ref;

    destroy_livro(&aluno->livro_favorito);
    free(aluno);
    *aluno_ref= NULL;
}// o uso de um ponteiro duplo permite que a função destroy_aluno modifique o ponteiro original que é passado para ela, o que é necessário para liberar corretamente a memória alocada para a estrutura Aluno.

/*FUNCAO PRA IMPRIMIR ALUNO*/
void print_aluno(const Aluno *aluno){
    printf("Nome : %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    puts("Livro Favorito");
    puts("-------");
    print_livro(aluno->livro_favorito);
}

/*VERIFICA SE E A MESMA OBRA*/
bool same_book (const Livro *livro1, const Livro *livro2) {
    if (strcmp(livro1->titulo, livro2->titulo) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main (){
    Livro *livro_harry = create_livro("Harry Potter 1", 200, 25);

    print_livro(livro_harry);
    livro_harry->preco = 10;
    print_livro(livro_harry);
    
    Aluno *ted = create_aluno("Ted", 20, livro_harry);
    print_aluno(ted);

    /*os exemplares sao iguais?*/
    puts("\nMesmo exemplar?");
    if(ted->livro_favorito == livro_harry){
        puts("TRUE");
    }
    else {
        puts("FALSE");
    }

    /*A obra é a mesma?*/
    puts("\nA obra e a mesma?");
    if (same_book(ted->livro_favorito, livro_harry)){
        puts("TRUE");
    }
    else {
        puts("FALSE");
    }
    puts("\n");

    destroy_livro(&livro_harry);

    print_aluno(ted);

    destroy_aluno(&ted);

    return 0;
}