/*Faça um programa que solicite para o usuário o tamanho de um vetor a ser lido.
Faça a alocação dinâmica desse vetor com o tipo char e solicite que o usuário digite uma
string e armazene nesse vetor. Por último, imprima a string digitad*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho;

    puts("Qual o tamanho do vetor a ser lido? ");
    scanf("%d", &tamanho);

    char *vetor = (char*) calloc (tamanho, sizeof(char));
    if (vetor == NULL){
        puts("Erro de alocaçao!!");
        exit(1);
    }
    puts("Digite o argmento que deseja: ");
    getchar();
    scanf("%[^\n]%*c", vetor);
    printf("%s \n", vetor);
    free(vetor);
    
    return 0;
}
