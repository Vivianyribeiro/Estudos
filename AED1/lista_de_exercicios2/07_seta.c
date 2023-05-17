#include <stdio.h>
#define max 500

int dp[max][max];  // Matriz de programação dinâmica para armazenar resultados intermediários

int rotas_viaveis(char matriz[max][max], int n, int l, int c) {
    if (l < 0 || l >= n || c < 0 || c >= n) {
        return 0;  // Fora do tabuleiro
    }

    if (dp[l][c] != -1) {
        return dp[l][c];  // Retorna o resultado armazenado na programação dinâmica
    }

    int celulas = 0;

    if (matriz[l][c] == 'V' && l + 1 < n) {
        celulas = 1 + rotas_viaveis(matriz, n, l + 1, c);  // Setas para baixo
    } else if (matriz[l][c] == '<' && c - 1 >= 0) {
        celulas = 1 + rotas_viaveis(matriz, n, l, c - 1);  // Setas para a esquerda
    } else if (matriz[l][c] == '>' && c + 1 < n) {
        celulas = 1 + rotas_viaveis(matriz, n, l, c + 1);  // Setas para a direita
    } else if (matriz[l][c] == 'A' && l - 1 >= 0) {
        celulas = 1 + rotas_viaveis(matriz, n, l - 1, c);  // Setas para cima
    }

    dp[l][c] = celulas;  // Armazena o resultado na programação dinâmica
    return celulas;
}

int main() {
    int n, viaveis = 0;
    char matriz[max][max];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &matriz[i][j]);
            dp[i][j] = -1;  // Inicializa a matriz de programação dinâmica com -1
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            viaveis += rotas_viaveis(matriz, n, i, j);
        }
    }
    printf("%d", viaveis);

    return 0;
}
