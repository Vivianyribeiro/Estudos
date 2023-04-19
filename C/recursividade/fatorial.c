#include <stdio.h>
#include <stdlib.h>

int fatorial (int n) {
    if (n == 0){
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }
}

int main() {
    int n, fat = 0;

    printf("Digite um numero para ser calculado o fatorial:");
    scanf("%d", &n);

    fat = fatorial(n);
    printf("O fatorial de %d eh: %d", n, fat);

    return 0;
}