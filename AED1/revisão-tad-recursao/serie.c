#include <stdio.h>

float serie(int n){
    if(n == 0){
        return 0;
    } else {
        float termo = (1 + n*n)/ (float)n;
        return termo + serie(n - 1);
    }
}

int main (){
    int n;
    float res = 0 ;
    scanf("%d", &n);
    res = serie(n);
    printf("%.2f", res);
    return 0;
}