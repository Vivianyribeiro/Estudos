#include <stdio.h>
#define n_rows 2
#define n_column 3

int main (){

    int m[n_rows][n_column] = {{0, 1, 2},{3, 4, 5}};

    for (int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_column; j++){
            printf("[%d][%d] = %p, [%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }
    return 0;
}