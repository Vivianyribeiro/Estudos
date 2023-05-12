#include <stdio.h>

int f_ack(int m, int n){
    
    if (m == 0){
        return n + 1;
    }
    if (n == 0 && m > 0){
        return f_ack(m-1, 1);
    }
    if (n > 0 && m > 0){
        return f_ack(m-1, f_ack(m, n-1));
    }
}

int main () {
    int m, n;
    int resultado_ack; 
    scanf("%d %d", &m, &n);
    resultado_ack = f_ack(m,n);

    printf("%d", resultado_ack);

    return 0;
}
