#include <stdio.h>
#include <stdlib.h>
//#define nrows 2
//#define ncolns 3
//unsigned long é size_t
int **create_int_matriz (int nrows, int ncols){
    int **m = (int**) calloc(nrows, sizeof(int*));
    for( int i =0; i < nrows; i++){
        m[i] = (int*) calloc(ncols, sizeof(int));
    }

    return m;
}

void print_int_matriz(const int **n,int nrows,int ncols){ //se tu quer uma matriz inteira tem q passar como parametro um ponteiro de ponteiro inteiro **n é o mesmo q n[][] ou int* n[]
int count = 0;
    printf("&n = %p, n = %p\n\n", &n, n);

    for(int i = 0; i < nrows; i++){
        printf("&n[%d] = %p, n[%d] = %p\n", i, &n[i], i, n[i]);

        for(int j = 0; j < ncols; j++){
            printf("&n[%d][%d] = %p, n[%d][%d] = %d\n", i, j, &n[i][j], i, j, n[i][j]);
        }
        puts("");
    }

}

void add_scalar_into_int_matriz(int **n, int nrows, int ncols, int scalar) {
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            n[i][j] += scalar;
        }
    }
}

void destroy_int_matriz(int ***mat, int nrows, int ncols){//desaloca matriz
    int **aux = *mat; //o aux recebe o endereço d cara q o mat ta apontando, o aux tem q ser ** por que ele ta apontando para um ponteiro  

    for(int i = 0; i < nrows; i++){
        free(aux[i]);
    }
    free(aux); // limpa op aux agora que ja usou ele para limpar endereços na heap
    *mat = NULL; //o endereço que o mat aponta ele é zerado ou aponta p nada
}

int main(int argc, char *argv[]) { //argumento
    /*printf("argc = %d\n", argc);
    for(int i = 0; i < argc ; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }*///aqui fiz imprimir os argumetnos no vetor, os argumentos q passamos junto com o ./ la
    if (argc != 4) {
        printf("ERROR\n%s nrows ncols scalar\n", argv[0]);//ta falando q tem q passar o numero de linhas e o numero de colunas
        exit(-1);//sair do programa/força a saida
    }

    int nrows = atoi(argv[1]); //funcao atoi convert string para inteiro
    int ncols = atoi(argv[2]);
    int scalar = atoi(argv[3]);

    //printf("nrows = %d, ncols = %d \n\n ", nrows, ncols);//vendo se funcionou!
    // alocação da matriz
    int **n =  create_int_matriz(nrows, ncols);

    //atribuição de alguns valores para a matriz
    int count = 0;

    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            n[i][j] = count++;
        }
    }

    // imprime matriz
    print_int_matriz((const int **) n, nrows, ncols);
    // aqui to falando q quero q n seja passado como constante ponteiro duplo

    //adicione scalar
    add_scalar_into_int_matriz(n, nrows, ncols, scalar);
    print_int_matriz((const int **) n, nrows, ncols);

    destroy_int_matriz(&n, nrows, ncols); //passo o endereço do n prq o mat vai apontar para este endereço d n, e o mat é com 3 *** prq o n é um ** e para pode apontar para o n ele precisa ser ***
    printf("\nn is NULL? %d\n", n == NULL); //ta pergntad se n é null e n == null retorna um condional booleano. se 1 vdd se 0 false

    return 0;
}