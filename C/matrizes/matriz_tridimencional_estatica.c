#include <stdlib.h>
#include <stdio.h>
#define n_slices 2
#define n_rows 2
#define n_cols 3

int main () {
    // 2 fatias , 2 linhas , 2 colunas
    int m[n_slices][n_rows][n_cols] = {
        {    //fatia [0]
            {0, 1, 2}, //linha [0]
            {4, 25, 5} // linha [1]
        },
        // fatia [1]
        {
            {6, 7, 8}, // linha [0]
            {9, 10, 12} // linha [1]
        }        
    };

    printf("&m = %p, m = %p\n\n", &m, m);

    //para cada fatia
    for(int k = 0; k < n_slices; k++){
        //para cada linha
        for(int i = 0; i < n_rows; i++){
            //para cada coluna
            for(int j = 0; j < n_cols; j++){
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n\n",
                k, i, j, &m[k][i][j],
                k, i, j, m[k][i][j]);
            }
        }
    }
    
    return 0;
}

