#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_rota, c_anterior = 0, c_posterior = 0;
    int soma = 0;
    int matriz[6][6];

    scanf("%d", &size_rota);
    int vetor[size_rota];

    for(int i = 0; i < size_rota; i++){
        scanf("%d", &vetor[i]);
    }

    matriz[0][0] = 0;
    matriz[0][1] = 63;
    matriz[0][2] = 210;
    matriz[0][3] = 190;
    matriz[0][4] = - 1;
    matriz[0][5] = 190;

    matriz[1][0] = 63;
    matriz[1][1] = 0;
    matriz[1][2] = 160;
    matriz[1][3] = 150;
    matriz[1][4] = 95;
    matriz[1][5] = 10;

    matriz[2][0] = 210;
    matriz[2][1] = 160;
    matriz[2][2] = 0;
    matriz[2][3] = 10;
    matriz[2][4] = 1;
    matriz[2][5] = 10;

    matriz[3][0] = 190;
    matriz[3][1] = 150;
    matriz[3][2] = 10;
    matriz[3][3] = 0;
    matriz[3][4] = 10;
    matriz[3][5] = 20;

    matriz[4][0] = 10;
    matriz[4][1] = 95;
    matriz[4][2] = 7;
    matriz[4][3] = 21;
    matriz[4][4] = 0;
    matriz[4][5] = 80;

    matriz[5][0] = 190;
    matriz[5][1] = 2;
    matriz[5][2] = - 1;
    matriz[5][3] = 41;
    matriz[5][4] = 80;
    matriz[5][5] = 0;

    
    for(int i = 0; i < size_rota -1; i++){
        c_anterior = vetor[i];
        c_posterior = vetor[i+1]; 
        
        if((matriz[c_anterior][c_posterior]) == -1){
            printf("rota invalida!");
            exit(1);
        }
        soma += matriz[c_anterior][c_posterior];

    }
    printf("\n%d", soma);

    return 0;
}