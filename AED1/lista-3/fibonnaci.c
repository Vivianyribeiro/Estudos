#include <stdio.h>

int n_fibonacci(int n){
if (n == 0) {
    return 0;
} else {
    if (n == 1) {
        return 1;
    } else {
        return n_fibonacci(n - 1) + n_fibonacci(n - 2);
    }
}


}

int main() {
    int n;

    scanf ("%d", &n);
    printf("%d\n",n_fibonacci(n));

    return 0;
}