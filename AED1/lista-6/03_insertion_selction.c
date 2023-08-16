#include <stdio.h>
#include <string.h>
 
#define TAM_VETOR 100
 
int insertion(int *v, int n);
 
int selection(int *v, int n);
 
 
int main() {
    int vetor1[TAM_VETOR];
    int vetor2[TAM_VETOR];
    int n, i, ins = 0, sel = 0;
 
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%d", &vetor1[i]);
    }
    for(i = 0; i < n; i++){
        vetor2[i] = vetor1[i];
    }
    
    ins = insertion(vetor1, n);
    sel = selection(vetor2, n);
 
    printf("%d\n", ins - sel);
 
    return 0;
}
 
int insertion(int *v, int n){
    int i = 0;
    int j = 1;
    int aux = 0;
    int troca_insertion = 0;
 
    while (j < n){
        i = j -1;
        aux = v[j];
        while ((i >=0) && (v[i] > aux)){
            v[i+1] = v[i];
            i = i - 1;
            troca_insertion ++;
        }
        v[i+1] = aux;
        troca_insertion++;
        j = j + 1;
    }
 
    return troca_insertion;
}
 
int selection(int *v, int n){
    int i, j, min, aux;
    int troca_slection = 0;
 
    for(i = 0; i < (n-1); i++){
        min = i;
        for(j = (i + 1); j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(v[i] != v[min]){
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            troca_slection ++;
        }
    }
 
    return troca_slection;
}