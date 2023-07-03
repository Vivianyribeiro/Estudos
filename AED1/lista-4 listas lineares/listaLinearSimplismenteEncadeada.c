/*---------------------------------------------------------------------------*/
/* UNIVERSIDADE FEDERAL DE GOIÁS - UFG                                       */
/* INSTITUTO DE INFORMÁTICA - INF                                            */
/*                                                                           */
/* Disciplina: Algoritmos e Estruturas de Dados - 1                          */
/* Professor.: Wanderley de Souza Alencar                                    */
/*                                                                           */
/* Observacoes:                                                              */
/*                                                                           */
/* Este programa implementa, de maneira simples, um conjunto basico de ope-  */
/* racoes sobre a estrutura de LISTAS LINEARES SIMPLES ENCADEADAS            */
/*                                                                           */
/* 0) Criar uma lista vazia                 -> CriarLista                    */
/* 1) Insercao de Celula no inicio da lista -> InsInicio                     */
/* 2) Insercao de Celula no final  da lista -> InsFinal                      */
/* 3) Remocao  de Celula no inicio da lista -> RemInicio                     */
/* 4) Remocao  de Celula no final  da lista -> RemFinal                      */
/* 5) Mostrar, no video, a lista            -> MostraLista                   */
/* 6) Tamanho (numero de NOS) da lista      -> TamLista                      */
/* 7) Insercao de NO por ordem de chave     -> InsOrdem                      */
/* 8) Remocao de NO por chave               -> RemChave                      */
/* 9) Ordenar lista por ordem de chave      -> OrdenaLista                   */
/* A) Concatena duas listas                 -> ConcatLista                   */
/*                                                                           */
/*                                                                           */
/* A estrutura da lista obedece o seguinte lay-out:                          */
/*                                                                           */
/*   numero in-  <---------+       +--> ApontadorCelula para a proxima       */
/*   teiro                 |       |    Celula                               */
/*   (exemplo)         +-------+------+                                      */
/*                     | dado  | prox |                                      */
/*                     +-------+------+                                      */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* Observação: Intencionalmente não há comentários nos códigos das funções   */
/*             para fazer com que o estudante tenha que minuciosamente       */
/*             analisá-los para compreender como cada funcionalidade é       */
/*             implementada.                                                 */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define SUCESSO          1
#define FALHA           -1

#define CHAVE_INVALIDA   0 

typedef struct Celula*  ApontadorCelula;

typedef struct Celula { 
     int             chave;
     int             dado;
     ApontadorCelula prox;
} Celula;  

int  CriarListaVazia    (ApontadorCelula * p); 
int  CriarListaChave    (ApontadorCelula * p, Celula celula);
int  InsInicio          (ApontadorCelula * p, Celula celula);
int  InsFinal           (ApontadorCelula * p, Celula celula);
int  InsOrdem           (ApontadorCelula * p, Celula celula);
int  RemInicio          (ApontadorCelula * p);
int  RemFinal           (ApontadorCelula * p);
int  RemChave           (ApontadorCelula * p, Celula celula);
int  ConcatListas       (ApontadorCelula p, ApontadorCelula q, ApontadorCelula * lista);
int  TamLista           (ApontadorCelula p);
int  MostraLista        (ApontadorCelula * p);

int CriarListaVazia(ApontadorCelula * p) {
    (*p) = (ApontadorCelula) NULL;
    return (SUCESSO);
}
 
int CriarListaChave(ApontadorCelula * p, Celula celula) {
    int statusOperacao;

    (*p) = (ApontadorCelula) NULL;
    statusOperacao = InsInicio(p, celula);
    return (statusOperacao);
}

int InsInicio (ApontadorCelula *p, Celula celula) {
      ApontadorCelula q;

      q = (ApontadorCelula) malloc( sizeof (Celula) );
      if (q == NULL) {
         return (FALHA);
      }
      else {
         q->chave = celula.chave;
         q->dado  = celula.dado;
         q->prox  = (ApontadorCelula) (*p);
         (*p)     = q;
         return (SUCESSO);
     }
}

int InsFinal (ApontadorCelula * p, Celula celula) {
     ApontadorCelula q, r;

     if ((*p) == NULL)
        return (InsInicio (p, celula));
     else {
           q = (ApontadorCelula) malloc( sizeof (Celula) );
           if (q == NULL) {
              return (FALHA); 
           } 
           else {
              q->chave = celula.chave;                
              q->dado  = celula.dado;
              q->prox  = (ApontadorCelula) NULL;
              r = (*p);
              while (r->prox != NULL) {
                    r = r->prox;
              }
              r->prox = q;
              return (SUCESSO);
          }
    }
}


int InsOrdem (ApontadorCelula * p, Celula celula) {
     ApontadorCelula q, r, s;
     
     if ((*p) == NULL) {
        return (InsInicio (p, celula));
     }
     else 
     {
           if ((*p) -> prox == NULL) 
           {
              if (celula.chave < (*p)->chave) 
              { 
                  return (InsInicio (p, celula)); 
              }
              else 
              { 
                  return (InsFinal (p, celula)); 
              }
           }
           else 
           {
                 if (celula.chave < (*p) -> chave) 
                 { 
                     return (InsInicio (p, celula)); 
                 }
                 else 
                 {
                        q = (ApontadorCelula) malloc( sizeof (Celula) );
                        if (q == NULL) 
                        { 
                           return (FALHA); 
                        }
                        q->chave = celula.chave;
                        r =  (*p);
                        while (((r->chave) < celula.chave) && ((r->prox) != NULL)) 
                        {
                           s = r; 
                           r = r->prox;
                        }
                        if (r->chave < celula.chave) 
                        { 
                           q->prox = (ApontadorCelula) NULL; 
                           r->prox = q;
                        }
                        else
                        {
                           q->prox = r;
                           s->prox = q;
                        }
                 }
           }
     }
     return(SUCESSO);
}

int RemInicio (ApontadorCelula * p) {
     ApontadorCelula r;
   
     if ((*p) == NULL) {
        return (FALHA);
     }
     else {
         r = (*p);
         (*p) = (*p)->prox;
         free(r); 
         return(SUCESSO);
     }
}

int RemFinal (ApontadorCelula * p) {
     ApontadorCelula r, s;

     if ((*p) == NULL) { 
        return(FALHA);
     }
     else {
           r = (*p); 
           s = (*p);
           if ((r->prox) == NULL) { 
              return (RemInicio(p));
           }
           else {
                while ((r->prox) != NULL) {
                   s = r;
                   r = (r->prox);
                }
                (s ->prox) = (ApontadorCelula) NULL;
                free(r);

                return(SUCESSO);
           }
     }   
}

int RemChave (ApontadorCelula * p, Celula celula) {
     ApontadorCelula r, s;
     if ((*p) == NULL) {
         return(FALHA);
     } 
     else {
           r = (*p); 
           s = (*p);
           if ((r ->prox) == NULL) {  
              if (r->chave == celula.chave) { 
                  return (RemInicio(p)); 
              } 
              else { 
                  return(FALHA); 
              }
           }
           else {
                if (r->chave == celula.chave) { 
                   return (RemInicio(p)); 
                }
                else {
                   while (((r->prox) != NULL) && (r->chave != celula.chave)) {
                     s = r;
                     r = r->prox;
                   }
                   if (r->chave == celula.chave) {
                      s->prox = r->prox;
                      free(r);
                      return(SUCESSO);
                   }
                   else { 
                      return(FALHA);
                   }
                }
           }   
     }
}

int  ConcatListas (ApontadorCelula p, ApontadorCelula q, ApontadorCelula * lista) {
  //
  // Para o estudante elaborar...
  //
  return(SUCESSO);
}

int TamLista(ApontadorCelula p) {
     ApontadorCelula r;
     int      tam;

     tam = 0;
     if (p == NULL) {
        return (tam);
     }
     else {
        tam = 1;
        r   = p;
        while (r->prox != NULL) {
           ++tam;
           r = r->prox;
        }
        return (tam);
     }
}

int MostraLista (ApontadorCelula * p) {
     ApontadorCelula r;

     if ((*p) == NULL) {
        printf("A lista está VAZIA.\n\n");
     }
     else {
          r = (*p);
          while (r->prox != NULL) {
             printf("[%d, (%d)] -> ", (r -> chave), (r -> dado));
             r = r->prox;
          }
          printf("[%d, (%d)] -| \n\n", (r -> chave), (r -> dado));
     }
     return(SUCESSO);
}



int main (void) {
    
    int             intResultado;
    Celula          celula;
    ApontadorCelula prim;
    
    printf("Lista Linear Simplesmente Encadeada\n\n\n");
    intResultado = CriarListaVazia(&prim); 
    if (intResultado == FALHA) {
        printf("Erro: Não foi possível criar a lista.");
        return(EXIT_FAILURE);
    }
    else { 
        MostraLista(&prim);
        printf("Realizando INSERÇÕES...\n\n");
        do {
           printf("Informe a chave a ser inserida no INÍCIO da lista ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              printf("Informe o valor do DADO a ser inserido: ");
              scanf("%d",&celula.dado); 
              intResultado = InsInicio(&prim, celula);
              if (intResultado == FALHA) {
                 printf("Erro: Inserção no início não pode ser realizada.\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
       
       do {
           printf("Informe a chave a ser inserida no FINAL da lista ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              printf("Informe o valor do DADO a ser inserido: ");
              scanf("%d",&celula.dado); 
              intResultado = InsFinal(&prim, celula);
              if (intResultado == FALHA) {
                 printf("Erro: Inserção no final não pode ser realizada.\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
       
       do {
           printf("Informe a chave a ser inserida EM ORDEM CRESCENTE DE CHAVES ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              printf("Informe o valor do DADO a ser inserido: ");
              scanf("%d",&celula.dado); 
              intResultado = InsOrdem(&prim, celula);
              if (intResultado == FALHA) {
                 printf("Erro: Inserção em ordem crescente de chaves não pode ser realizada.\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
       printf("\n\n\nRealizando REMOÇÕES...\n\n\n");
       do {
           printf("Informe [1] para remover célula no INÍCIO da lista ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              intResultado = RemInicio(&prim);
              if (intResultado == FALHA) {
                 printf("Erro: Remoção no início não pode ser realizada (lista vazia).\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
       
       do {
           printf("Informe [1] para remover célula no FINAL da lista ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              intResultado = RemFinal(&prim);
              if (intResultado == FALHA) {
                 printf("Erro: Remoção no final não pode ser realizada (lista vazia).\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
       
       do {
           printf("Informe a chave a ser removida da lista ou [0] para finalizar: ");
           scanf("%d",&celula.chave);
           if (celula.chave != CHAVE_INVALIDA) {
              intResultado = RemChave(&prim, celula);
              if (intResultado == FALHA) {
                 printf("Erro: Remoção da chave não pode ser realizada.\n\n"); 
                 return(EXIT_FAILURE);
              }
              else {
                 MostraLista(&prim); 
                 printf("=====================\n\n");
              }
           }
       } while (celula.chave != CHAVE_INVALIDA);
    }
    return (EXIT_SUCCESS);
}
