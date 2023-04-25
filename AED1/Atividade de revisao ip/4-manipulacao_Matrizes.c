#include <stdio.h>
#define MAX 100

void soma_matrizes(int **m1, int **m2, int m, int n){
    int soma[MAX][MAX];
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            soma[i][j] = m1[i][j] + m1[i][j];
            printf("%d", soma[i][j]);
        }
    }
}

void multiplica_matrizes(int **m1, int **m2, int m, int n){
    int mult[MAX][MAX];
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mult[i][j] = m1[i][j] * m1[i][j];
            printf("%d", mult[i][j]);
        }
    }
}


int main(){
    int m, n;
    int matriz1[MAX][MAX];
    int matriz2[MAX][MAX];
    char operacao;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        for(int j; j < n; j++){
            scanf("%d", matriz[i][j]);
        }
    }
    puts("Digite a operacao que deseja (+ ou *): ");
    scanf("%c", &operacao);
    operacao == '+' ? soma_matrizes(&matriz1, &matriz2, m, n): multiplica_matrizes(&matriz1, &matriz2, m, n);


    return 0;
}