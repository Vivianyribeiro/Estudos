#include <stdio.h>
#define MAX 100

int main(){
    int vetor[MAX];
    int maior = 0;
    int menor = 1000;
    puts("Digite 10 numeros: \n");
    for(int i= 0; i < 10; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] > maior){
            maior = vetor[i];
        }
        if (vetor[i] < menor){
            menor = vetor[i];
        }
    }
    printf("O maior numero eh: %d\nO menor numero eh: %d\n", maior, menor);
    return 0;
}
