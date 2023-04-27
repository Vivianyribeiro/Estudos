/**/

#include <stdio.h>

int main() {
    int a[3];

    printf("Endereco inicial: %p", a);

    //a[0] = 10;
    //a[1] = 20;
    //a[2] = 30;
    *(a + 0) = 10; // e a mesma coisa q a[0];
    *(a + 1) = 20; // conteudo de a + 1 recebe 20
    *(a + 2) = 30;

    for(int i = 0; i < 3; i++){
        //printf("\n%d", a[i]);
        printf("\n%d", *(a + i));
    }
    puts("");
    return 0;
}
