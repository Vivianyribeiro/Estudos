/*Crie uma struct para representar um retângulo, com largura e altura. Faça um programa que leia do usuário quantos retângulos ele deseja cadastrar, crie um vetor dinâmico de retângulos e preencha as informações de cada um. Em seguida, exiba na tela a área de cada retângulo e a soma das áreas de todos os retângulos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct retangulo{
    float largura;
    float altura;
}Retangulo;

Retangulo* create_retangulo(float largura, float altura){
    Retangulo *r = (Retangulo*) calloc (1, sizeof(Retangulo));
    if ( r==NULL) {
        printf("Erro ao alocar memoria!!");
        exit(1);   
    }
    r->largura = largura;
    r->altura = altura;

    return r;
}

void reader(Retangulo *retangulo, int n){
    
    for(int i = 0; i < n; i++){
        printf("Digite a Largura do Retangulo %d", i+1);
        scanf("%f", &retangulo[i].largura);

        printf("Digite a Altura do Retangulo %d", i+1);
        scanf("%f", &retangulo[i].altura);

        Retangulo *r = create_retangulo(retangulo[i].largura, retangulo[i].altura);
        retangulo[i] = *r;
        free(r); 
        //create_retangulo(retangulo[i].largura, retangulo[i].altura); 
    }
}

void print_retangulo(Retangulo *retangulo, int n){
    float area_total =0.0;
    for(int i = 0; i < n; i++){
        printf("A area do retangulo %d eh: %.2f\n", i+1, retangulo[i].largura * retangulo[i].altura);
        area_total += (retangulo[i].largura * retangulo[i].altura);
    }
    printf("Area total eh: %.2f\n", area_total);
}

void *free_retangulo (Retangulo *retangulo, int n){
    for(int i = 0; i < n; i++){
        free(&retangulo[i]);
    }
}

int main() {
    int n;
    Retangulo retangulos;
    printf("Quantos retangulos voce deseja cadastrar? ");
    scanf("%d", &n);

    reader(&retangulos, n);
    print_retangulo(&retangulos, n);
    free_retangulo(&retangulos, n);
    
    return 0;
}