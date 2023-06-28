#include "llse.h"

void criaListaVazia(TCelula **inicio){
    *inicio = NULL;
}

int InsInicio (TCelula **inicio, int chave, int valor) {
      TCelula* aux;

      aux = (TCelula*) malloc(sizeof (TCelula));
      if (aux) {
		aux -> chave = chave;   
		aux -> dado  = valor;
		aux -> prox  =  (*inicio); //aux->prox aponta para o inicio da lista
		*inicio = aux; //o inicio da lista passa a apontar para a nova celula
		return (SUCESSO);
	  }
      return (FALHA);
}

int InsFinal (TCelula **inicio, int chave, int valor) {
     TCelula *aux, *p;

     if (*inicio == NULL){
        return (InsInicio (inicio, chave, valor));
     }
     aux = (TCelula*) malloc( sizeof (TCelula) );
     if (aux){         
        aux -> chave = chave;                
        aux -> dado  = valor;
        aux -> prox  = NULL; //A nova celula sera a ultima, logo seu campo prox deve ser NULL
		//usar o ponteiro auxiliar p para encontrar o ultimo elemento da lista
        p = (*inicio);
        while (p -> prox != NULL){
             p = p -> prox;
		}
        p -> prox = aux;// o campo prox do atual ultimo elemento passa a apontar para a nova celula
        return (SUCESSO);
	 }
	 return (FALHA);
        
}

int RemChave (TCelula **inicio, int chave) {
     TCelula *r, *s;
     if (*inicio == NULL) return(FALHA); 
     else {
           r = *inicio; s = *inicio;
           if(r->chave==chave){
			   *inicio=r->prox;
			   free(r);
			   return(SUCESSO);
		   }
           while( (r->prox!=NULL) && (r -> chave != chave)) {
               s = r; //s aponta para a celula anterior a apontada por r
               r = (r -> prox);
           }
           if (r -> chave == chave) {
               s -> prox = r -> prox;//o campo prox da celula anteriro a celula a ser removida
               // passa a apontar para a celula posterior à célula a ser removida.
               free(r);
               return(SUCESSO);
           }
           return(FALHA);
     }
}
int Imprime(TCelula *inicio){
	TCelula *p = inicio;
	if(p){
		while(p){
			printf("Chave: %d, dado: %d --> ", p->chave, p->dado);
			p=p->prox;
		}
		printf("\n");
		return(SUCESSO);
	}
	return(FALHA);
}

int RemoveInicio(TCelula **inicio){
	TCelula * p;//p usado para apontar para a primeira celula,se existir
	if(*inicio){//a lista nao esta vazia
		p=*inicio;
		*inicio=p->prox;
		free(p);
		return(SUCESSO);
	}
	return(FALHA);
}	

int DestroiLista(TCelula **inicio){
		int res;
		if(*inicio){
			do
				res=RemoveInicio(inicio);
			while(res!=FALHA);
			return(SUCESSO);
		}
		return(FALHA);
	}
