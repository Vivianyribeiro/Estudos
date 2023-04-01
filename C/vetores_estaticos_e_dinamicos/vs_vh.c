#include <stdio.h>
#include <stdlib.h> // contem o NULL, calloc, malloc e free.

void soma_vetor_com_escalar( int v[], int n, int escalar){
    for(int i = 0; i< n; i++){
        v[i] += escalar;
    }
}

void print_vetor(const int *v, int n ){
    for(int i = 0; i< n; i++){
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
    puts("");
}

void desaloca_vetor(int **v) {
    free(*v);//acessa o conteudo de v, e v esta apontando p vh(q guarda o endereço base na heap) o v pega o endereço q vh quarda q e o indice base na heap, com isso faz free da heap.
    *v = NULL; // faz o conteudo de vh virar NULL, tipo agora agora vh nao guarda mais endereço.
}

int main() {
    //alocação de um vetor estatico (stack)
    puts("### Vetor estatico");
    int vs[5] = {0, 10, 20, 30, 40};

    print_vetor(vs, 5);
    soma_vetor_com_escalar(vs, 5, 9);
    print_vetor(vs, 5);

    puts("### VETOR DINAMICO COM ESCALAR");

    int *vh = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++){
        vh[i] = i * 100;
    }

    print_vetor(vh, 5);
    soma_vetor_com_escalar(vh, 5, 9);
    print_vetor(vh, 5);

    //desalocando o vetor dinâmico
    //free(vh);
    //vh = NULL;
    puts("##> Antes da funcao de desalocar vetor dinamico:");
    printf("&vh = %p, vh = %p\n", &vh, vh);
    desaloca_vetor(&vh);
    puts("##> Depois da funcao de desalocar vetor dinamico:");
    printf("&vh = %p, vh = %p\n", &vh, vh);

    return 0;
}
