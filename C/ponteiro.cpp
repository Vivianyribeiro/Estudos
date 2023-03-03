#include <iostream> /*em c++ reservar espaço usa new e em c uso malloc*/
/*sempre q reserva espaço em c e c++ e fundamental deslocar, em c desalocamos com free e em c++ usamos delete */

int main() {
    int x = 2049;
    int *px = &x; // criei ponteiro px q vai receber endereço da variavel x
    printf("O tamanho de x : %d bytes\n", sizeof(int));// da o tamanho q e 4 byte
    printf("O valor de x: %d\n", x);// da o valor de 2049
    printf("O endereço de x: %d\n", px); //da o endereço exemplo 73545344
    printf("o ponteiro de x: %d\n", *px); // da o valor 2049
    printf("Soma de x + 1: %d\n", px + 1); //da o endereço soma a 4 byte exemplo 73545348
    printf("Soma de px + 1: %d\n", *(px + 1)); //qro o endereco da localizacao desse px esse vai der errado e lixo de memoria
    
    char *y = (char*)px;//ponteiro y vai receber o conteudo d px q e endereco de x e converter para char
    printf("O tamanho de y : %d bytes\n ", sizeof(char)); // o tamanho da 1 byte
    printf("O endereço de y: %d\n", y); // da o endereço de x
    printf("O valor de y: %d\n", *y); // do 2049 em binario ele so pega a preira parte e converte, no caso deu 1 
    printf("Soma de y + 1: %d\n", y + 1); //da o endereço + 1 : 73545645

    return 0;
}