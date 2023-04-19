#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, fib;
    printf("Digite o numero que deseja: ");
    scanf("%d", &n);

    fib = fibonacci(n);
    printf("%d", fib);

    return 0;
}