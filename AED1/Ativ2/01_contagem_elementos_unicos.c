#include <stdio.h>

int main (){
    int n, j;
    int igual, unicos = 0;

    //printf("Digite a quantidade de numeros que deseja inserir: ");
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        igual = 0;
        for (j = 0; j < n; j++){
            if(vetor[i] == vetor[j]){
                igual += 1;
            } 
        }
        if(igual == 1){
                unicos ++;
            }
    }
    printf("%d\n", unicos);

    return (0);
}