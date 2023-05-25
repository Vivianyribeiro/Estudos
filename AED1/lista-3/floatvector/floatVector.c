#include "floatVector.h"
#include <stdlib.h>

struct floatVector {
    int capacity; //num maximo de elementos 
    int size; // qtde de elesmtos armazenados atualemnte
    float *data;// vetor de float
};

/**
 * @brief cria (aloca) um vetor de floats com uma dada capacidade
 * @param capacity capacidade do vetor
 * 
 * @return FloatVector* um ponteiro para o vetor alocado/criado
 * 
 */

FloatVector *create(int capacity){
    FloatVector *vec =(FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));
    return vec;
}

void destroy(FloatVector **vec_Ref){
    FloatVector *vec = *vec_Ref;
    free(vec->data);
    free(vec);
    *vec_Ref = NULL;
    
}