#include "tad-cilindro.h"

struct cilindro {
    float raio;
    float altura;

};

Cilindro* createCilindro(Cilindro *cilindro, float raio, float altura) {
    cilindro->raio = raio;
    cilindro->altura = altura;
    
    return cilindro;
}
/*
Cilindro cilindro1;  // Declaração do objeto cilindro1
Cilindro* ptrCilindro1 = &cilindro1;  // Ponteiro para o objeto cilindro1

float raio1 = 2.5;
float altura1 = 5.0;

createCilindro(ptrCilindro1, raio1, altura1);
*/

Cilindro createCilindro(float raio, float altura) {
    Cilindro c;
    c.raio = raio;
    c.altura = altura;
    
    return c;
}

/*
float raio2 = 3.0;
float altura2 = 6.0;

Cilindro cilindro2 = createCilindro(raio2, altura2);
*/