#include <stdio.h>

int fatorial_duplo (int n) {
    
    if (n <= 1){
        return 1;
    } else {
        if (n%2 != 0){
            return n * fatorial_duplo (n - 2);
        } else {
            return fatorial_duplo (n - 1);
        }
    }
}

int main(){
    int n;

    scanf("%d", &n);
    if (n <= 100 ){
        printf("%d", fatorial_duplo(n));
    } else
    {
        return -1;
    }

    return 0;
}