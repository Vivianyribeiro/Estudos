#include <stdio.h>
#include <time.h>

int main(){
    int anoBase = 1986;
    int periodo = 76;
    int proximo;
    time_t data_atual = time(NULL); // retorna data e hora atual
    struct tm *pdata_atual = localtime(&data_atual); // isto converte para tipo data

    int ano_atual = pdata_atual->tm_year + 1900; // pega apenas o ano que e contado a partir de 1900

    int anosAteProximaPassagem;
    if (ano_atual < anoBase) {
        anosAteProximaPassagem = anoBase - ano_atual;
    } else {
        anosAteProximaPassagem = periodo - ((ano_atual - anoBase) % periodo);
    }
    
    proximo = ano_atual + anosAteProximaPassagem;

    printf("Poximo ano sera: %d\n", proximo);

    return 0;
}