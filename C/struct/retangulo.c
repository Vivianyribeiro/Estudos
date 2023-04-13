/*Crie uma struct Retangulo que contenha os campos largura e altura. Em seguida, escreva uma função que calcule e retorne a área do retângulo.*/

#include <stdio.h>

typedef struct retangulo {
    float width;
    float height;
    float area;
} Retangulo;

/*FUNCAO QUE CALCULA A AREA DO RETANGULO*/
void area_retangulo (Retangulo *r) {
    r->area = r->width * r->height;

}

int main() {
    Retangulo a;
    a.width = 10.0;
    a.height = 5.0;
    area_retangulo(&a);
    printf("Area do retangulo: %2.f\n", a.area);

    return 0;
}