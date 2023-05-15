#include <stdio.h>
#define max 500



int main () {
    int n, celulas = 0;
    char matriz[max][max];

    scanf("%d", &n);

    for(int i=0; i< n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    celulas = rotas_viaveis(matriz);
    /*
        puts("");
        for(int i= 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf(" %c", matriz[i][j]);
            }
            puts("");
        }
    */

    return 0;
}