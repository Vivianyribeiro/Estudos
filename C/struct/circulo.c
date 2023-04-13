/*Crie uma struct Circulo que contenha os campos raio e centro. O campo centro deve ser uma struct que represente as coordenadas x e y do centro do círculo. Em seguida, escreva uma função que calcule e retorne a área do círculo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas {
    float coordenada_x;
    float coordenada_y;
}Coordenadas;

typedef struct circulo {
    float raio;
    Coordenadas centro;
}Circulo;

float calcula_area( Circulo c){
    float area = 3.14159 * c.raio * c.raio;

    return area;
}

int main () {
    Circulo c1;

    c1.raio = 2.2;
    c1.centro.coordenada_x = 1.0;
    c1.centro.coordenada_y = 2.5; 

    printf ("\nA area do circulo eh: %f\n", calcula_area (c1));


    return 0;
}