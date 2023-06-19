#include <stdio.h>

int expo(int x, int y){
    if(y == 0){
        return 1;
    } else {
        return x*expo(x, y-1);
    }
}

int main (){
    int x, y;
    int res = 0;
    scanf("%d %d", &x, &y);
    res = expo(x, y);
    printf("%d", res);

    return 0;
}