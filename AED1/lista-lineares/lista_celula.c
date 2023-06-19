#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_LISTA 100
#define CHAVE_INVALIDA 0
#define SUCESS 1
#define FAILURE -1

typedef struct celula 
{
    int chave;
    int valor;
}Celula;

typedef struct lista 
{
    Celula celula[TAM_MAX_LISTA];
    int tam;
}Lista_Linear;

//criar lista inicialmente vazia
int criarListaVazia(Lista_Linear* lista, int t)
{
    int i;
    for(i = 0; i < TAM_MAX_LISTA; i++)
    {
        lista->celula[i].chave = CHAVE_INVALIDA;
    }
    lista->tam = 0;
    return(SUCESS);
}

//Criar lista com uma unica celula, por contiguidade
int criarListaChave(Lista_Linear *lista, Celula celula)
{
    for(int i =0; i < TAM_MAX_LISTA; i++)
    {
        lista->celula[i].chave = CHAVE_INVALIDA;
    }
    lista->celula[0] = celula;
    lista->tam = 1;
    return (SUCESS);
}

//determinar o tamanho da lista
int tamanhoLista(Lista_Linear lista)
{
    if(lista.tam >= 0)
    {
        return(lista.tam);
    }
    else 
    {
        return(FAILURE);
    }
}

//mostra una determinada celula da lista
void mostrarCelula(Celula celula)
{
    printf("Chave...: %d\n", celula.chave);
    printf("Valor...: %d", celula.valor);
}

// mostrar lista inteira
void mostrarTodaLista(Lista_Linear lista)
{
    if(lista.tam == 0)
        printf("Atenção: Lista Vazia.\n");
    else 
    {
        for(int i =0; i < lista.tam; i++)
        {
            printf("Elemento n.: %d\n", (i+1));
            mostrarCelula(lista.celula[i]);
        }
    }    
}

//consultar celula baseado na posição dela
Celula consultaListaPosicao(Lista_Linear lista, int posicao)
{
    Celula resultadoCelula;
    if(posicao > 0 && posicao <= lista.tam)
    {
        resultadoCelula = lista.celula[posicao - 1];
    }
    else
    {
        resultadoCelula.chave = CHAVE_INVALIDA;
    }
    return(resultadoCelula);
}

//consultar celula baseado na chave
//Chave invalida se nao existir
Celula consultaListaChave (Lista_Linear lista, Celula celula)
{
    for (int i = 0; i < lista.tam; i++)
    {   
        if(lista.celula[i].chave == celula.chave)
        {
            return(lista.celula[i]);
        }
    }
    celula.chave = CHAVE_INVALIDA;
    return (celula);
}

//inserir celulaInicio da lista
int inserirInicio(Lista_Linear * lista, Celula celula)
{
    int i;
    //se a lista ja tiver cheia saia
    if(lista->tam == TAM_MAX_LISTA)
        return(FAILURE);
    else
    {
        for(i = lista->tam; i > 0; i--)
        {
            //chega pra direita
            lista->celula[i] = lista->celula[i-1];
        }
        lista->celula[0] = celula;
        lista->tam++;
        return(SUCESS);
    }
}

//inserir celula no final da lista
int inserirFinal (Lista_Linear * lista, Celula celula)
{
    // se lista cheia sai
    if (lista->tam == TAM_MAX_LISTA)
        return(FAILURE);
    else 
    {
        //coloca no final
        lista->celula[lista->tam] = celula;
        lista->tam++;
        return (SUCESS);
    }
}

//inserir celula por chave ascendente (crescente, ordem)
int insOrdenado(Lista_Linear *lista, Celula celula)
{
    int i, j;
    if(lista->tam == TAM_MAX_LISTA)
        return (FAILURE);
    else 
    {
        if(lista->tam ==0)
        {
            return (inserirInicio(lista, celula));
        }
        else 
        {
            if(celula.chave < lista->celula[0].chave)
            {
                return (inserirInicio(lista, celula));
            }
            else 
            {
                if(celula.chave >= lista->celula[lista->tam-1].chave)
                {
                    return (inserirFinal(lista, celula));
                }
                else
                {
                    i =0;
                    //caminho ate chegar no final da lista
                    while((celula.chave >= lista->celula[i].chave)&& (i < lista->tam))
                    {
                        i++;
                    }
                    if(i == lista->tam)
                    {
                        return(inserirFinal(lista, celula));
                    }
                    else 
                    {
                        for(j = lista->tam; j > i; j++)
                        {
                            //chega a lista pra direita pra liberar espaço no inicio
                            lista->celula[j] = lista->celula[j -1];
                        }
                        lista->celula[i] = celula; // tenho a impressao que aqui em vez de i é 0
                        lista->tam++;
                        return(SUCESS);
                    }
                }
            }
        }
    }
}

//Remover celula no inicio


int main ()
{
    int tm;
    Lista_Linear c;
    printf("Digite o tamanho a quantidade que deseja inserir: ");
    scanf("%d", &tm);
    return 0;
}

