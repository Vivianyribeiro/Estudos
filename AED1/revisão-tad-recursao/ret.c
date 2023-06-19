#include <stdio.h>

typedef struct retangulo Retangulo;

struct retangulo {
    float base;
    float altura;
};

Retangulo criaRet(float b, float h);

Retangulo criaRet(float b, float h){
    Retangulo r;
    r.base = b;
    r.altura = h;

    return r;
}

float areaRet(Retangulo r);

float areaRet(Retangulo r){
    float area =0;
    area = r.base * r.altura;
    return area;
}

int main (){
    float base, altura;
    scanf("%f %f", &base, &altura);
    Retangulo a = criaRet(base, altura);
    float area = areaRet(a);
    printf("%.2f", area);

    return 0;
}