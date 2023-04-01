#include <stdio.h>
#include <stdlib.h>
#define nrows 2
#define ncolumn 3


int main(){
    // --------- ALOCACAO DINAMICA DE MATRIZES --------
    int **m = NULL; //
    //int **m = (int**) calloc(nrows, sizeof(int*)); //tu pode ir direto
    m = (int**) calloc(nrows, sizeof(int*));
    //para cada linha da matriz alocamos as colunas
    for(int i = 0; i < nrows; i++){
        m[i] = (int*) calloc(ncolumn, sizeof(int));
    }
    // --------- --------------------------------------
    int count = 0;
    printf("&m = %p, m = %p\n\n", &m, m);

    for(int i = 0; i < nrows; i++){
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
        for(int j = 0; j < ncolumn; j++){
            //m[i][j] = count;
            //count++; //essas duas linhas e a mesma q esta debaixo
            m[i][j] = count++;

            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }
    free (m);
    free (*m);
    m = NULL;
    
    return 0;
}