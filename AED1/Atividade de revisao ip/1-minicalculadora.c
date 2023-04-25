#include <stdio.h>
#include <stdlib.h>

int main(){
    float resultado=0.0, x, y;
    int opcao;
    printf("\nDigite o primeiro numero: ");
    scanf("%f", &x);
    printf("Digite o segundo numero: ");
    scanf("%f", &y);

    printf("Digite qual das opcoes vc deseja realizar: \n\n");
    puts("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    puts("Oque deseja fazer?\n");
    printf("Opcao 1: Calcular %.2f elevado a %.2f.\n", x, y);
    printf("Opcao 2: Calcular %.2f * %.2f.\n", x, y);
    printf("Opcao 3: Calcular %.2f / %.2f.\n\n", x, y);
    puts("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    scanf("%d", &opcao);


    if(opcao == 1){
        resultado = x;
        for(int i = 0; i < (y - 1); i++){
            resultado *= x;
        }
    }
    else if(opcao == 2){
            resultado = x * y;
    }
    else if(opcao == 3){
            resultado = x / y;
    }   
    else {
        printf("opcao invalida!");
    }
    printf("O resultado do calculo eh: %.2f\n\n", resultado);

    return 0;
}