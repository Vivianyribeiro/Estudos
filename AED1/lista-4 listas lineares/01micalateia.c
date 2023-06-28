#include <stdio.h>
#include <stdlib.h>

#define TAM_NUMBER 10
#define TAM_NOME 21

#define SUCESS 1
#define FAILURE -1

#define CHAVE_INVALIDA 0

typedef struct contact* ApontadorContact;

typedef struct contact 
{
    char nome[TAM_NOME];
    char number[TAM_NUMBER];
    int  v;
    ApontadorContact next;
}Contact;

int CriarListaVazia (ApontadorContact *p)
{
    (*p) = (ApontadorContact) NULL;
    return (SUCESS);
}

int CriarListaChave (ApontadorContact *p, Contact contato)
{
    int status = 0;
    (*p) = (ApontadorContact) NULL;
    status = InsInicio (p, contato);
    return (status);
}

int InsInicio (ApontadorContact *p, Contact contato)
{
    ApontadorContact q;
    int i;

    q =(ApontadorContact) malloc( sizeof(Contact));
    if (q == NULL)
    {
        return (FAILURE);
    }
    else 
    {
        strcpy(q->nome, contato.nome);
        strcpy(q->number, contato.number);
        q->v = contato.v;
        /*abaixo o no atual *p vai para o ponteiro next virando o proximo e nao mais o atual, estamos atualizando o ponteiro next do novo nó q para apontar para o nó que estava anteriormente no início da lista.*/
        q->next = (ApontadorContact) (*p);
        
        /*o ponteiro para atual aponto pro novo q que é agora o atual*/
        (*p) = q;
        return (SUCESS);
    }
}

int InsFinal (ApontadorContact *p, Contact contato)
{
    ApontadorContact q, r;

    /*se lista estiver vazia isere no inicio mesmo*/
    if ((*p) == NULL)
        return (InsInicio (p, contato));
     else { /*se nao tiver vazia insere no final*/
        q = (ApontadorContact) malloc (sizeof(Contact));
        if(q == NULL)
        {
            return (FAILURE);
        }
        else
        {
            strcpy(q->nome, contato.nome);
            strcpy(q->number, contato.number);
            q->v = contato.v;
            q->next = (ApontadorContact) NULL;
            /* abaixo o r recebe o endereço do primeiro nó*/
            r = (*p);
            // Enquanto ainda nao chegar no ultimo nó da lista
            while(r->next != NULL)
            {
                r->next;
            }
            /*tendo chego ao ultimo faz ele apontar pro novo ultimo*/
            r->next = q;
            return (SUCESS);
        }
    }
}

int gerenciaInsercao (char tipo, ApontadorContact *p, Contact contato)
{
    /*insere nova pessoa com nome number e v*/
    if (tipo == 'I')
    {
        insereNomeNumberV(p, contato);
        Return (SUCESS);
    }
    /*remove pessoa com tal nome da lista*/
    if (tipo == 'R')
    {
        int result = 0;
        result = RemoveNome(p, contato);
        if (result == 1)
        Return (SUCESS);
        else
        return (FAILURE);
    }
    /*L aumenta o numero de ligaçoes q tal nome possui*/
    if (tipo == 'L')
    {
        insereNome(p, contato);
        Return (SUCESS);
    }
    /*finaliza*/
    if (tipo == 'F')
    {
        Return (0);
    }
}

int main(void)
{
    int resultado;
    Contact contato;
    ApontadorContact inicio;

    resultado = CriarListaVazia(&inicio);

    if(resultado == FAILURE)
    {
        //printf("erro nao foi possivel criar lista");
        return(EXIT_FAILURE);
    } 
    else
    {
        strcpy(contato.nome, "hermanoteu");
        strcpy(contato.number,"4523-2248");
        contato.v = 300;

        strcpy(contato.nome, "Ooloneia");
        strcpy(contato.number,"4523-4887");
        contato.v = 299;

    }
}



