#include <stdio.h>


int main() {
    int a = 10;
    int b, c;

    printf("&a = %p a= %d\n", &a, a); // %p pra emprimir endereço de memoria
    printf("&b = %p b= %d\n", &b, b);
    printf("&c = %p c= %d\n\n", &c, c);

    b =20;
    c = a + b;

    printf("&a = %p a= %d\n", &a, a); // %p pra emprimir endereço de memoria
    printf("&b = %p b= %d\n", &b, b);
    printf("&c = %p c= %d\n\n", &c, c);printf("&a = %p a= %d\n", &a, a); // %p pra emprimir endereço de memoria
    printf("&b = %p b= %d\n", &b, b);
    printf("&c = %p c= %d\n\n", &c, c);

    return 0 ;
}