#include <stdio.h>

int mdc(){
    


}

int main() {
    int a, b;
    int resultado = 0;

    printf("Digite os numeros a serem calculados o mdc: ");
    scanf("%d %d", &a, &b);

    resultado = mdc(a, b);
    printf("%d", resultado);
    return 0;
}