#include <stdlib.h>
#include <stdio.h>
#define n_slices 2
#define n_rows 2
#define n_cols 3

int main () {
    
    /******** ALOCACAO DINAMICA ******/
    int ***m = (int***) calloc(n_slices, sizeof(int**));//tu alocou um ponteiro de ponteiro para um ponteiro de ponteiro de um ponteiro.

    //para cada fatia
    for(int k = 0; k < n_slices; k++){
        m[k] = (int**) calloc(n_rows, sizeof(int*));

        //para cada linha
        for(int i = 0; i < n_rows; i++){
            m[k][i] = (int*) calloc( n_cols, sizeof(int));
        }

    }
    /*88888888888888888888888888888888*/

    int count = 0;

    printf("&m = %p, m = %p\n\n", &m, m);

    //para cada fatia
    for(int k = 0; k < n_slices; k++){
        printf("&n[%d] = %p, m[%d] = %p\n\n", k, &m[k], k, m[k]);

        //para cada linha
        for(int i = 0; i < n_rows; i++){
            printf("&n[%d][%d] = %p, m[%d][%d] = %p\n\n", k, i, &m[k][i], k, i, m[k][i]);
            //para cada coluna
            for(int j = 0; j < n_cols; j++){
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n\n",
                k, i, j, &m[k][i][j],
                k, i, j, m[k][i][j]);
            }
            puts("");
        }
        puts("");
    }
    free (m);
    free (*m);
    free (**m);
    
    m = NULL;

    return 0;
}

