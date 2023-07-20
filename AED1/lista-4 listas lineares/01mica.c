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
int InsEsquerda (ApontadorContact *r, ApontadorContact *s, Contact contato);
int InsDireita (ApontadorContact *p, Contact contato);
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
        
        /*abaixo o next do novo nó q vai apontar pro primeiro*guardado em *p */
        q->next = (ApontadorContact) (*p);
        
        /*o ponteiro que deve guardar o primeiro aponta para o novo primeiro*/
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
    else 
    { /*se nao tiver vazia insere no final*/
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
 
int InsEsquerda (ApontadorContact *r, ApontadorContact *s, Contact contato)
{
    ApontadorContact q;
    q = (ApontadorContact) malloc (sizeof(Contact));
                        
        if(q == NULL)
        {
            return (FAILURE);
        }
        else if (q != NULL)
        {
            strcpy(q->nome, contato.nome);
            strcpy(q->number, contato.number);
            q->v = contato.v;
            
            if (*s == NULL) 
            {
                
                q->next = *r;
                *r = q;
            } 
            else if (q->v != (*r)->v)
            {
                
                q->next = *r;
                (*s)->next = q;
                
            } else
            {
                
                return InsDireita(r, contato);
            }

        return (SUCESS);
        }
}

int InsDireita (ApontadorContact *p, Contact contato)
{
    ApontadorContact q, r;
 
    /*se lista estiver vazia isere no inicio mesmo*/
    if ((*p) == NULL)
        return InsInicio (p, contato);
    else 
    { /*se nao tiver vazia insere no final*/
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
    
            q->next = (*p)->next;
            (*p)->next = q;
        
            return (SUCESS);
        }
    }
}
 
int InsOrdem (ApontadorContact *p, Contact contato) 
{
    ApontadorContact q, r, s;
    int resultado;
 
    if ((*p) == NULL) /*se lista fazia insere no inicio*/
    {
        resultado = InsInicio(p, contato);
        return (resultado);
    }
    else
    {
        if ((*p)->next == NULL) /*se ten apenas 1 nó*/
        {
            if ((*p)->v < contato.v)
            {
                resultado = InsInicio (p, contato);
                return(resultado);  
            }
            else if ((*p)->v >= contato.v)
            {
                resultado  = InsFinal (p, contato);
                return(resultado);  
            }
        }
        else /*se o proximo nao for null/ se tiver de 2 ou mais nó*/
        {
            if ((*p)->v < contato.v ) /*se o primeiro for menor que o novo contato*/
            {
                resultado = InsInicio (p, contato);
                return(resultado); 
            } 
            else if ((*p)->v == contato.v ) /*se o primeiro for igual o novo contato*/
            {
                
                resultado = InsDireita (p, contato);
                return(resultado); 
            }
            else if ((*p)->v > contato.v ) /*se o novo for menor ele vem depois*/
            {
                
                r = (*p)->next; /*r aponta para o segundo*/
                s = (*p);
                while (r->next != NULL)
                { /*enquanto nao chegar no ultimo*/
                    if (r->v == contato.v ) /*se o primeiro for igual o novo contato*/
                    {
                        
                        resultado = InsDireita (p, contato);
                        return(resultado); 
                    }
                    
                    else if(r->v < contato.v)/*se este proximo for menor, coloque na frente dele*/
                    { /*INSERIR NA FRENTE A ESQUERDA*/
                        
                        resultado = InsEsquerda(&r, &s, contato);
                        return(resultado);  
                    }
                    s = r;
                    r = r->next;
                }

                if(r->v > contato.v) /*para o ultimo que saiu do laço*/
                {
                    
                    resultado = InsFinal(p, contato);
                    return(resultado);  
                }
                else
                {
                    resultado = InsEsquerda(&r, &s, contato);
                    return(resultado);  
                }
            }
            else if((*p)->v < contato.v) /*se este novo for maior (*p)->v < contato.v )*/
            {
                resultado = InsInicio(p, contato);
                return(resultado);  
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
    } else
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
    } else
    /*L aumenta o numero de ligaçoes q tal nome possui*/
    if (tipo == 'L')
    {
        scanf("%s", contato.nome);
        resultado = Adiciona(p, contato);
        if(resultado == SUCESS)
            return (SUCESS);
    } else
    /*finaliza*/
    if (tipo == 'F')
    {
        MostraLista(p);
        return(SUCESS);
        
    } else
     /*nao for valor TIPO valido*/
    {
        return(FAILURE);
    }
}
 
void OrdenaLista(ApontadorContact *p) {
    ApontadorContact r, s;
    
    if (*p == NULL){
        return;
    }
    else 
    {
        r = (*p);
        while (r->next != NULL) /*enquanto ainda nao for o ultimo*/
        { 
            s = r->next; /*s recebe o seguinte*/
            if (r->v < s->v) { /*se r for menor deve trocar*/
                // Troca os valores dos nós
                Contact temp = *r; /*temporario guarda o valor q ta em r*/
                *r = *s; /*r aponta pro s q tem o valor maior*/
                *s = temp;/*s agora pega o valor menor*/
    
            }
            r = r->next;/*para o while rodar*/
        }
    }
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

/*
if (l->begin->n < seguinte->n) {
        puts ("trocando o primeiro");
        anterior = l->begin;
        printf("* Ante %p - %d, atual %p - %d, seguinte %p - %d\n", anterior, anterior->n, atual, atual->n, seguinte, seguinte->n);
        l->begin = atual->next;
        printf("**Ante %p - %d, atual %p - %d, seguinte %p - %d\n", anterior, anterior->n, atual, atual->n, seguinte, seguinte->n);
        atual->next = seguinte->next;
        printf("***Ante %p - %d, atual %p - %d, seguinte %p - %d\n", anterior, anterior->n, atual, atual->n, seguinte, seguinte->n);
        seguinte->next = atual;
        printf("****Ante %p - %d, atual %p - %d, seguinte %p - %d\n", anterior, anterior->n, atual, atual->n, seguinte, seguinte->n);
*/

/* ordena q tentei 

void OrdenaLista (LinkedList *l) {
    puts("oi ordena");
    Contact *anterior, *atual, *seguinte, *aux;
    atual = l->begin;
    seguinte = l->begin->next;
    anterior = l->begin;

    // so para saber para quem cada um esta apontando no momento
    printf("****##Ante %s - %d, atual %s - %d, seguinte %s - %d\n", anterior->nome, anterior->n, atual->nome, atual->n, seguinte->nome, seguinte->n);

        puts ("se entra no ordena");

    if (seListaVazia(l) || l->begin == l->end) {
        puts ("teste vazia");

        return;
    }

    // primeira posicao é menor q segunda
    if (l->begin->n < seguinte->n) {
        puts ("trocando o primeiro");
        
        aux = l->begin;
        l->begin = atual->next;
        atual->next = seguinte->next;
        seguinte->next = aux; 
        
        // so para saber para quem cada um esta apontando no momento
        printf("****##Ante %s - %d, atual %s - %d, seguinte %s - %d\n", anterior->nome, anterior->n, atual->nome, atual->n, seguinte->nome, seguinte->n);
    }
    while (atual->next != NULL) {
        if (atual->n < seguinte->n && seguinte->next != NULL) {
            
            atual = seguinte;
            seguinte = atual->next;
            if (atual->n < seguinte->n) {
                aux = anterior->next;
                anterior = atual->next;
                atual->next = seguinte->next;
                seguinte->next = aux;
            }
        }
        atual = atual->next;
    }     
    
    if (atual->n < seguinte->n && seguinte->next == NULL)
    {
        aux = anterior->next;
        anterior->next = atual->next;
        atual->next = seguinte->next;
        seguinte->next = aux;
        l->end = atual;
    } 
}
*/