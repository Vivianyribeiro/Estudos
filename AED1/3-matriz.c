/*Faça um programa que leia uma matriz de tamanho 3x3 que o usuário digitar. Em
seguida, calcule um novo valor para cada elemento da matriz: cada elemento da matriz
deve ser multiplicado pelo número da linha a qual pertence. Imprima como saída todos os
novos valores da matriz (respeitando a linha e coluna de cada valor*/

#include <stdio.h>
#define MAX 100

int main() {
    int matriz[MAX][MAX];
    int matriz2[MAX][MAX];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
            matriz2[i][j] = matriz[i][j] * i; 
        }
    }

    puts("A nova matriz eh: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz2[i][j]);
            
        }
        puts("");
    }

    return 0;
}
