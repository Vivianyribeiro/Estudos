#include <stdio.h>
#include <stdlib.h>

void torreHanoi(int n, char origem, char destino, char auxiliar){
    if(n == 1){
        printf("(%c,%c)\n", origem, destino);
    } else {
        torreHanoi(n - 1, origem, auxiliar, destino);
        printf("(%c,%c)\n", origem, destino);
        torreHanoi(n - 1, auxiliar, destino, origem);
    }

}

int main (){
    int n;

    scanf("%d", &n);
    if(n <= 1000 && n >= 2){
        torreHanoi(n, 'O', 'D', 'A');
    } else {
        exit (1);
    }

    return (0);
}