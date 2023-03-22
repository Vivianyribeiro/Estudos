#include <stdio.h>


	void somar (int x, int y, int *z){
		*z= x + y; //como o z é ponteiro de c, significa q o z altera o valor dentro do c fora da função, ai nao precisa fazer o returno de z porq ele ja altera o valor la fora.
	}
    //e tu pode fazer assim tbm:

    int soma_e_sub(int x, int y, int *sub){
        int soma = x + y;
        *sub = x - y;
        return soma;
    }
    //ou ate:
    void soma_e_sub( int x, int y, int *soma, int *sub){
        *soma = x + y;
        *sub = x - y; // ai isto alterar o valor do cara q tu mandou o endereço para os parametros.
    }
int main () {
    int a = 10;
    int b = 20;
    int c;
    int sub;
    int soma;

    somar(a,b, &c);

    soma_e_sub (a, b, &sub); //to passando uma copia de endereço de memoria para um paramentro
    soma_e_subx (a, b, &sub, &soma);

    return 0;
}