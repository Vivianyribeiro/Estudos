#include <stdio.h>

int reversoN(int n, int reverso){
    if (n == 0){
        return reverso;
    } else
        reverso = reverso *10 + (n%10); 
        return reversoN(n/10, reverso);
}

int main(){
    int n, reverso = 0;
    scanf("%d", &n);
    printf("%d\n",reversoN(n, reverso));


    return 0;
}
