void OrdenarLista(Descritor *l){
    Aluno *atual;
    Aluno *max;
    if(!if_empty(l)){ // verificando se alista esta vazia
        max = l->begin;
        atual = l->begin->next;
        while (atual != NULL) {
            if (atual->n_prob > max->n_prob){ //se atual for maior deve trocar com o max
                //Aluno *temp = max;
                max = atual;
                //l->begin = max;
                //atual = atual->next;
            }
            else if(atual->n_prob == max->n_prob){ // se atual for igual, devemos comparar o nome por ordem alfabetica
                if(strcmp(atual->nome, max->nome) < 0){
                    max = atual;
                }
            }
            atual = atual->next;
        }   
        if (max != l->begin) {
            Aluno *temp = max;
            l->begin = temp;
        } 
    }
}