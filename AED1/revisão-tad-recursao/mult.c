#include <stdio.h>

int mult(int x, int y){
    if (y == 1) {
        return x;
    } else {
        return x + mult(x, y-1);
    }
}

int main () {
    int x, y;
    int res = 0;
    scanf("%d %d", &x, &y);
    res = mult(x, y);
    printf("%d", res);
    return 0;
}