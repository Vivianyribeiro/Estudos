#include <stdio.h>

void imprime (int n) {
    if (n == 0){
        return;
    } else {
        imprime (n - 1);
        printf("%d ", n);
    }
}

int main () {
    int n;

    scanf("%d", &n);
    imprime (n);

    return 0;
}
