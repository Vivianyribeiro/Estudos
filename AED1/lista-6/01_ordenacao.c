#include <stdio.h>

#define TAM_MAX 100

void insertionSort(int v[], int n);

int main() {
    int vetor[TAM_MAX];
    int n;
    int k, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    insertionSort(vetor, n);

    scanf("%d", &k);

    i = 0;
    while(i < (k - 1)) {
        i++;
    }
    printf("%d", vetor[i]);

    return 0;
}

void insertionSort(int v[], int n){
    int i = 0, j = 1, aux = 0;

    while (j < n) {
        aux = v[j];
        i = j - 1;
        while ((i >= 0) && (v[i] > aux))  {
            v[i+1] = v[i];
            i = i - 1;
        }
        v[i+1] = aux;
        j = j + 1;
    }
}

