#include <stdio.h>
#define max 500

int rotas_viaveis(char matriz[max][max], int n, int l, int c){
    
    
    if (matriz[l][c] == 'V' || matriz[l][c] == 'v' && l + 1 >= n) {
        return 0; /*baixo fora*/
    } else

    if (matriz[l][c] == '<' && c - 1 < 0) {
        return 0; /*lado esquerdo fora */
    } else

    if (matriz[l][c] == '>' && c + 1 >= n) {
        return 0; /*lado direito fora */
    } else

    if (matriz[l][c] == 'A' && l - 1 < 0) {
        return 0; /*cima fora */
    }

    int celulas = 1; 
    if (matriz[l][c] == 'v' || matriz[l][c] == 'V') {
        celulas += rotas_viaveis (matriz, n, l + 1, c);
    } else
    if (matriz[l][c] == '>') {
        celulas += rotas_viaveis (matriz, n, l , c + 1);
    } else
    if (matriz[l][c] == '<') {
        celulas += rotas_viaveis (matriz, n, l, c - 1);
    } else
    if (matriz[l][c] == 'A') {
        celulas += rotas_viaveis (matriz, n, l - 1, c);
    }

    return celulas;

}

int main () {
    int n, viaveis = 0;
    char matriz[max][max];

    scanf("%d", &n);

    for(int i=0; i< n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    for(int i=0; i< n; i++){
        for(int j = 0; j < n; j++){
            viaveis += rotas_viaveis(matriz, n, i, j);
        }
    }
    printf("%d", viaveis);

    return 0;
}