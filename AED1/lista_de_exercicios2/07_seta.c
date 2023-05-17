#include <stdio.h>
#define max 500

int rotas_viaveis(char matriz[max][max], int n, int l, int c) {
    if (l < 0 || l >= n || c < 0 || c >= n) {
        return 0;  // Fora
    }

    if (matriz[l][c] == 'V' && l + 1 < n) {
        return 1 + rotas_viaveis(matriz, n, l + 1, c);  //pra baixo
    } else if (matriz[l][c] == '<' && c - 1 >= 0) {
        return 1 + rotas_viaveis(matriz, n, l, c - 1);  //pra esquerda
    } else if (matriz[l][c] == '>' && c + 1 < n) {
        return 1 + rotas_viaveis(matriz, n, l, c + 1);  //pra direita
    } else if (matriz[l][c] == 'A' && l - 1 >= 0) {
        return 1 + rotas_viaveis(matriz, n, l - 1, c);  // pra cima
    }

    return 0;
}

int main() {
    int n, viaveis = 0, i, j;
    char matriz[max][max];

    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            viaveis += rotas_viaveis(matriz, n, i, j);
        }
    }
    printf("%d", viaveis);

    return 0;
}
