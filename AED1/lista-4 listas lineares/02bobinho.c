#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 20
#define SUCESS 1
#define FAILURE -1

typedef struct Jogador* ApontadorJogador; 

typedef struct Jogador {
    char nome[NOME_TAM];
    int perdidas;
    int roubos;
    ApontadorJogador next;
}Jogador;

int criarListaVzia(ApontadorJogador *j);

int insInicio(ApontadorJogador *j, Jogador jogador);

void Insroubadas(ApontadorJogador *j, char j1[], char j2[]);

//int voltaInicio(ApontadorJogador *j, char bobinho[]);

void calculaVencedor(ApontadorJogador *j);

int removeJogador(ApontadorJogador *j);

int ImprimeLista(ApontadorJogador *j);

void apagaLista(ApontadorJogador *j);


int main(void)
{
    Jogador j;
    ApontadorJogador inicio;
    int resultado = 0, roubo = 0;
    int roubadas =0, contador =0;
    char bobinho1[NOME_TAM], bobinho2[NOME_TAM],j1[NOME_TAM], j2[NOME_TAM];
    

    resultado = criarListaVzia(&inicio);
    if (resultado == FAILURE)
    {
        return FAILURE;
    }

    
    scanf("%s", j.nome);
    //insere os jogadores ate que digite Fim
    while (strcmp(j.nome, "Fim") != 0)
    {
        resultado = insInicio(&inicio, j);
        if(resultado == FAILURE)
        {
            return (EXIT_FAILURE);
        }
        scanf("%s", j.nome);
    }
    //ler quem é o bobinho
    //puts("ler bobinho");
    scanf("%s", bobinho1);

    //Fazer bobinho receber uma perdida por ser o bobo
    ApontadorJogador aux = inicio;
    while (aux !=NULL) {
        if(strcmp(aux->nome, bobinho1) == 0){
            aux->perdidas += 1;
        }
        aux = aux->next;
    }
    
    //ler numero de roubadas de bola
    //puts("ler qtd de roubada");
    scanf("%d", &roubadas);

    while (roubadas--)
    {
        //puts("ler roubada:");
        scanf("%s %s", j1, j2);

        if(strcmp(j2, bobinho1) ==0)
        {
            Insroubadas(&inicio, j1, j2);
            strcpy(bobinho2, j1);
            contador++;
            
        } 
        else 
        {
            Insroubadas(&inicio, j1, j2);
            strcpy(bobinho1, bobinho2);
            contador--;
        }

    }
    removeJogador(&inicio);
    apagaLista(&inicio);
    return SUCESS;
}

// FUNÇÕES

int criarListaVzia(ApontadorJogador *j)
{
    (*j) = (ApontadorJogador) NULL;
    return (SUCESS);
}

int insInicio(ApontadorJogador *j, Jogador jogador)
{
    ApontadorJogador p;

    p = (ApontadorJogador) malloc ( sizeof( Jogador));
    if(p == NULL)
    {
        return (FAILURE);
    }
    else 
    {
        strcpy(p->nome, jogador.nome);
        p->perdidas = 0;
        p->roubos = 0;
        p->next = (ApontadorJogador) *j;
        (*j) = p;

        return (SUCESS);
    }
}

void Insroubadas(ApontadorJogador *j, char j1[], char j2[])
{
    ApontadorJogador p;

    p = (*j);
    while(p != NULL)
    {
        if(strcmp(p->nome, j1) == 0)
        {
            //printf("%s perdeu para %s, ", j1, j2);
            p->perdidas ++;
            //printf("perdida do %s = %d\n", p->nome, p->perdidas);
        }
        if(strcmp(p->nome, j2) == 0)
        {
            p->roubos ++;
        }
        p = p->next;
    }
}

/*int voltaInicio(ApontadorJogador *j, char bobinho[])
{
    ApontadorJogador p;

    if((*j) == NULL){
        return (FAILURE);
    }

    while (p != NULL)
    {
        if(strcmp(p->nome, bobinho) == 0)
        {

        }
    }

}*/

void calculaVencedor(ApontadorJogador *j)
{
    ApontadorJogador p;
    int contador =0;

    if ((*j) == NULL){
        //printf("to calcula lista vazia\n");
        return ;
    }
    p = (*j);
    while(p != NULL)
    {
        if (p->perdidas == 0)
        {
            contador++;
            //printf("contador ta de : %d \n", contador);
        }
        p = p->next;
    }
    p = (*j);
    
    if(contador == 1)
    {
        printf("Vencedor: %s", p->nome);
            
    }
    else
    {
        ImprimeLista(j);
    }
}

int removeJogador(ApontadorJogador *j)
{
    ApontadorJogador p, s, anterior;
    int resultado;
    
    if(*j == NULL)
    {
        return (FAILURE);
    }

    p = (*j);
    anterior = NULL;
    while (p != NULL)
    {
        s = p->next;
        if(p->perdidas > 0 &&  p->roubos <= 2)
        {
            
            if(anterior == NULL) // se tiver na 1
            {
                *j = s;
                //printf("** apaguei o : %s\n", p->nome);
            }
            else
            {
                anterior->next = s;
            }
            //printf("** apaguei: %s  \n", p->nome);
            free(p);      
        } 
        else 
        {
            anterior = p;
        }
            p = s;
    }
    calculaVencedor(j);
    return (FAILURE);  
}

int ImprimeLista(ApontadorJogador *j)
{
    ApontadorJogador p;

    if ((*j) == NULL){
        return (FAILURE);
    }
    else
    {
        p = (*j);
        while(p != NULL)
        {
            printf("%s\n", p->nome);
            p=p->next; 
        }        
        return (SUCESS);
    }
}

void apagaLista(ApontadorJogador *j)
{
    ApontadorJogador atual = (*j), proximo;

    while (atual != NULL) 
    {
        proximo = atual->next;
        free(atual);
        atual=proximo;
    }
    *j = NULL;
    return;

}
