#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int CriarListaVazia (ApontadorContact *p);
/*int CriarListaChave (ApontadorContact *p, Contact contato);*/
int InsInicio (ApontadorContact *p, Contact contato);
int InsFinal (ApontadorContact *p, Contact contato);
int InsOrdem (ApontadorContact *p, Contact contato);
int RemoveNome(ApontadorContact *p, Contact contato);
int Adiciona(ApontadorContact *p, Contact contato);
int gerenciaInsercao (char tipo, ApontadorContact *p);
void OrdenaLista(ApontadorContact *p);
int MostraLista (ApontadorContact *p);
void ApagaLista(ApontadorContact *p);


int main(void)
{
    char tipo;
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
        strcpy(contato.nome, "Hermanoteu");
        strcpy(contato.number,"4523-2248");
        contato.v = 300;

        resultado = InsInicio(&inicio, contato);
        if(resultado == FAILURE)
        {
            return(EXIT_FAILURE);
        }


        strcpy(contato.nome, "Ooloneia");
        strcpy(contato.number,"4523-4887");
        contato.v = 299;

        resultado = InsFinal(&inicio, contato);
        if(resultado == FAILURE)
        {
            return(EXIT_FAILURE);
        }
    }

    /*Qual comando ira receber (I, L, R ou F)*/
    do 
    {
        scanf(" %c", &tipo);
        resultado = gerenciaInsercao (tipo, &inicio);
        if (resultado == FAILURE)
        {
        return(EXIT_FAILURE);
        }
    }    
    while (tipo != 'F');

    return(0);
}

int CriarListaVazia (ApontadorContact *p)
{
    (*p) = (ApontadorContact) NULL;
    return (SUCESS);
}

/*int CriarListaChave (ApontadorContact *p, Contact contato)
{
    int status = 0;
    (*p) = (ApontadorContact) NULL;
    status = InsInicio (p, contato);
    return (status);
}*/

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
        
        /*abaixo o nó atual *p vai para o ponteiro next virando o proximo e nao mais o atual, estamos atualizando o ponteiro next do novo nó q para apontar para o nó que estava anteriormente no início da lista.*/
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
                r = r->next;
            }
            /*tendo chego ao ultimo faz ele apontar pro novo ultimo*/
            r->next = q;
            
            return (SUCESS);
        }
    }
}

int InsOrdem (ApontadorContact *p, Contact contato) 
{
    ApontadorContact q, r, s;
    int resultado;

    if ((*p) == NULL) 
    {
        resultado = InsInicio(p, contato);
        return (SUCESS);
    }
    else
    {
        if ((*p)->next == NULL)
        {
            if ((*p)->v < contato.v)
            {
                resultado = InsInicio (p, contato);
                return (SUCESS);
            }
            else
            {
                resultado  = InsFinal (p, contato);
                return (SUCESS);
            }
        }
        else /*se o proximo nao for null/ se tiver mais de 2 nó*/
        {
            if ((*p)->v > contato.v ) 
            {
                r = (*p)->next;
    
                while (r->next != NULL){
                    if (r->v > contato.v)
                    {
                        r = r->next;
                    }
                    else
                    {
                        resultado = InsInicio(p, contato);
                    }
                }
                if(r->v > contato.v)
                {
                    resultado = InsFinal(p, contato);
                }
                else
                {
                    resultado = InsInicio(p, contato);
                }
            }
            else
            {
                q = (ApontadorContact) malloc (sizeof(Contact));
                if (q == NULL)
                {
                    return (FAILURE);
                }
                q->v = contato.v;
                r = (*p);
                /*Enquanto o primeiro da lista for maior que oque esta chegando e o proximo apos o primeiro ainda nao for o ultimo faça...*/
                while (((r->v) > contato.v) && ((r->next) != NULL))
                {
                    s = r;/*s aponta para o anterior ao r*/
                    r = r->next; /*o r agora recebe o proximo da lista e vai rodando ate que nao seja mais verdade que o r é maior que o novo alocado*/
                }

                if(r->v < contato.v)
                {
                    q->next = s; /*##*/
                    s->next = q;/*##*/
                    return (SUCESS);
                }
                else
                {
                    q->next =  (ApontadorContact) NULL;
                    r->next = q;
                    return (SUCESS);
                }
            }
        }
    }
    return (SUCESS);
}

int RemoveNome(ApontadorContact *p, Contact contato)
{
    ApontadorContact r, s;

    if ((*p) == NULL)
    {
        return(FAILURE);
    }
    else
    {
        r = (*p);
        s=(*p);
        if ((r->next) == NULL)
        {
            if(strcmp(r->nome, contato.nome) == 0)
            {
                free(*p);
                free(r);
                (*p) = NULL;

                return(SUCESS);
            }
        }
        else
        {
            while (r->next != NULL) /*##*/
            {
                s = r;
                r = (r->next);
            }
            (s ->next) = r->next;
            free(r);

            return(SUCESS);
        }
    }
}

int Adiciona(ApontadorContact *p, Contact contato)
{
    ApontadorContact r;
    if ((*p) == NULL)
    {
        return(FAILURE);
    }
    else
    {
        r = (*p);
        if(strcmp(r->nome,contato.nome) != 0)
        {
            while ((strcmp(r->nome,contato.nome) != 0) && r->next != NULL)
            {
                r = r->next;
                if (strcmp(r->nome,contato.nome) == 0)
                {
                    r->v ++;
                    return (SUCESS); 
                }
            }

            return(FAILURE);/*nao achou o nome*/
        }
        else
        {
            r->v ++;
            return (SUCESS); 
        }
    }
}

int gerenciaInsercao (char tipo, ApontadorContact *p)
{
    Contact contato;
    int resultado = 0;
    
    /*insere nova pessoa com nome number e v na ordem de maior para menor v*/
    if (tipo == 'I')
    {   scanf("%s", contato.nome);
        scanf("%s", contato.number);
        scanf("%d", &contato.v);
        InsOrdem(p, contato);
        
        return (SUCESS);
    }
    /*remove pessoa com tal nome da lista*/
    if (tipo == 'R')
    {
        resultado = 0;
        scanf("%s", contato.nome);
        resultado = RemoveNome(p, contato);
        if (resultado == 1)
        return (SUCESS);
        else
        return (FAILURE);
    }
    /*L aumenta o numero de ligaçoes q tal nome possui*/
    if (tipo == 'L')
    {
        scanf("%s", contato.nome);
        resultado = Adiciona(p, contato);
        if(resultado == SUCESS)
            return (SUCESS);
    }
    /*finaliza*/
    if (tipo == 'F')
    {
        
        resultado = MostraLista(p);
        if(resultado == FAILURE)
        {
            ApagaLista(p);
            return (EXIT_FAILURE);
        }
        return(SUCESS);
    }
    else /*nao for valor valido*/
    {
        resultado = MostraLista(p);
        exit;
    }
}

void OrdenaLista(ApontadorContact *p) {
    ApontadorContact atual, proximo;
    int trocado;
    
    if (*p == NULL)
        return;

    do {
        trocado = 0;
        atual = *p;
        while (atual->next != NULL) {
            proximo = atual->next;
            if (atual->v < proximo->v) {
                // Troca os valores dos nós
                Contact temp = *atual;
                *atual = *proximo;
                *proximo = temp;
                trocado = 1;
            }
            atual = atual->next;
        }
    } while (trocado);
}


int MostraLista (ApontadorContact *p)
{
    ApontadorContact r;

    if((*p) == NULL)
    {
        //printf("Lista esta vazia!\n\n");
        return(FAILURE);
    }
    else 
    {
        r = (*p);
        OrdenaLista(p);
        while (r->next != NULL)
        {
            printf("%s - %s\n", r->nome, r->number);
            r = r->next;
        }
        printf("%s - %s\n", r->nome, r->number);
    }
    return (SUCESS);
}

void ApagaLista(ApontadorContact *p)
{
    ApontadorContact atual = *p;
    ApontadorContact proximo;

    while (atual != NULL)
    {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    *p = NULL; // Atualiza o ponteiro para a lista vazia
}



