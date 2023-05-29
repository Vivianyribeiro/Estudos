#include <stdio.h>

int transforma_binario(long long int n){
if (n == 0) {
    return 0;
}  else 
    return (n % 2 + 10 * transforma_binario(n / 2));
}

int main () {
    long long int decimal;
    

    scanf("%lld", &decimal);
    printf("%d",transforma_binario(decimal));

    return 0;
}