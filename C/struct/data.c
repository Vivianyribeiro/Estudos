/*Crie uma struct Data que contenha os campos dia, mes e ano. Em seguida, escreva uma função que receba duas datas e determine qual delas é mais recente.*/

#include <stdio.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

void data_mais_recente ( Data *data1, Data *data2){
    //ano data 1 mais recente
    if (data1->ano > data2->ano) {
        printf("Data %d/%d/%d e mais recente!", data1->dia, data1->mes, data1->ano );   
    }
    //ano data2 mais recente
    else if(data1->ano < data2->ano){
        printf("Data %d/%d/%d e mais recente!", data2->dia, data2->mes, data2->ano );
    }
        //se anos iguais e mes data1 mais recente
    else {
        if(data1->mes > data2->mes){
            printf("Data %d/%d/%d e mais recente!", data1->dia, data1->mes, data1->ano );
        }
            //se anos iguais e mes data2 mais recente
        else { //mes iguais
            if(data1->mes < data2->mes){
            printf("Data %d/%d/%d e mais recente!", data2->dia, data2->mes, data2->ano );
            }
            //mes iguais dia data1 mais recente
            else if(data1->dia > data2->dia){
                printf("Data %d/%d/%d e mais recente!", data1->dia, data1->mes, data1->ano );
            }
            //mes iguais dia data2 mais recente
            else if(data1->dia < data2->dia){
                printf("Data %d/%d/%d e mais recente!", data2->dia, data2->mes, data2->ano );
            }
            else {//datas iguais
                puts("Datas sao iguais");
            }
        } 
    }
}
        
int main ( ){
    Data data1;
    Data data2;
    data1.dia = 10;
    data1.mes = 4;
    data1.ano = 2023;

    data2.dia = 1;
    data2.mes = 7;
    data2.ano = 2018;

    data_mais_recente(&data1, &data2);

    return 0;
}


/* //PODERIA TER FEITO A FUNCAO  ASSIM TBM

void data_mais_recente ( Data *data1, Data *data2){
    int data1_num = (data1->ano * 10000) + (data1->mes * 100) + data1->dia;
    int data2_num = (data2->ano * 10000) + (data2->mes * 100) + data2->dia;
    
    if (data1_num > data2_num) {
        printf("Data %d/%d/%d e mais recente!", data1->dia, data1->mes, data1->ano );
    }
    else if (data2_num > data1_num) {
        printf("Data %d/%d/%d e mais recente!", data2->dia, data2->mes, data2->ano );
    }
    else {
        printf("Datas sao iguais");
    }
}

*/