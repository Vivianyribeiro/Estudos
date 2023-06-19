#include <stdio.h>

struct retangulo
{
    float base, altura;
};

typedef struct retangulo Retangulo;

Retangulo criar_retangulo(float base, float altura)
{
    Retangulo r;
    r.base = base;
    r.altura = altura;
    return r;
}

float retorna_altura(Retangulo r)
{
    return r.altura;
}

float retorna_base(Retangulo r)
{
    return r.base;
}

float perimetro(Retangulo r)
{
    return r.altura * 4 + r.base * 8;
}

float area(Retangulo r)
{
    float area;
    area = r.altura * r.base * 4 + r.base * r.base;
    return area;
}

float volume(Retangulo r)
{
    return r.altura * r.base * r.base;
}

void main()
{
    float altura, base;

    printf("Digite a altura do retangulo: ");
    scanf("%f", &altura);
    printf("Digite a base do retangulo: ");
    scanf("%f", &base);

    Retangulo a = criar_retangulo(base, altura);
    printf("A altura do retangulo tem tamanho %.2f\n", retorna_altura(a));
    float area_a = area(a);
    float volume_a = volume(a);
    float perimetro_a = perimetro(a);
    printf("Area: %.2f \n Volume: %.2f \n Perimetro: %.2f\n", area_a, volume_a, perimetro_a);
}