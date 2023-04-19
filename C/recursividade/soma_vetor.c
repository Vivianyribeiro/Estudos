#include <stdio.h>
#define TAM_MAX 100

int soma_vetor(int vetor[], int tamanho) {
   if( tamanho == 0){
        return 0;
   }
   else {
        return vetor[tamanho-1] + soma_vetor(vetor, tamanho-1);
   }
}

int main(){
    int vetor[TAM_MAX];
    int tamanho, soma = 0; 

    printf("Digite a quantidade de numeros que deseja somar: ");
    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++ ){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    soma = soma_vetor(vetor, tamanho);
    printf("A soma dos numeros eh: %d", soma);

    return 0;
}