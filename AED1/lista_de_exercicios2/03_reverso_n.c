#include <stdio.h>

int digitos(int n)
{
    int i;
    for (i = 1; n >= 10; i++)
    {
        n /= 10;
    }
    return i;
}

int reverso(int n, int n_reverso){
    int aux = 0;
    if (n == 0 ){
        return n_reverso;
    } else {
        int digito = n % 10;
        n_reverso = (n_reverso * 10) + digito;
        return reverso(n / 10, n_reverso);
    }
    
}   

int main(){
    int n;
    int n_reverso = 0;
    scanf ("%d", &n);
    if ( n >= 1 && n <= 10000000) {
        n_reverso = reverso (n, n_reverso);
        printf("%d\n", n_reverso);
    }
    return 0;
}
