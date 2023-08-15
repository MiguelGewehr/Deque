#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

const int initial_size = 5;
const int growth_step = 5;

Deque *deque_construct(){

    Deque *deque = (Deque*) malloc(sizeof(Deque));

    deque->allocad = initial_size;
    deque->size = 0;
    deque->end = 0;
    deque->start = 0;
    
    deque->array = (int*) calloc(deque->allocad, sizeof(int));

    return deque;
}

int isEmpty(Deque *deque){
    return deque->size == 0;
}

int isFull(Deque *deque){
    return deque->size == deque->allocad; 
}

void _deque_realloc( Deque *deque){
    
    if(isFull(deque)){
        
        int *prev = deque->array;

        deque->allocad += growth_step;
        deque->array = (int*) calloc(deque->allocad ,sizeof(int));
        
        int i = deque->start;
        int c = 0;

        while(c < deque->size){
            deque->array[c] = prev[i];
            i = (i+1) % deque->size;
            c++;
        }
        deque->start = 0;
        deque->end = deque->size;
        free(prev);
    }
}

void deque_push_back(Deque *deque, int elemento){
    
    _deque_realloc(deque);

    deque->array[deque->end] = elemento;
    deque->end = (deque->end+1) % deque->allocad;

    deque->size++;
}

void deque_push_front(Deque *deque, int elemento){

    _deque_realloc(deque);

    deque->start = (deque->start -1 + deque->allocad) % deque->allocad;
    deque->array[deque->start] = elemento;

    deque->size++;
}

int deque_pop_back(Deque *deque){

    if(isEmpty(deque)){
        printf("Deque vazio!\n");
        return -1;
    }

    int data = deque->array[deque->end-1];

    deque->end = (deque->end -1) % deque->allocad;

    deque->size--;

    return data;
}

int deque_pop_front(Deque* deque){

    if(isEmpty(deque)){
        printf("Deque vazio!\n");
        return -1;
    }

    int data = deque->array[deque->start];

    deque->start = (deque->start + 1) % deque->allocad;

    deque->size--;

    return data;
}

int frenteDeque(Deque* deque){
    return deque->start;
}

int finalDeque(Deque* deque){
    return deque->end;
}

void liberarDeque(Deque* deque){

    free(deque->array);
    free(deque);
}

void printDeque(Deque* deque) {
    printf("Deque content: ");
    for (int i = 0; i < deque->size; i++) {
        int index = (deque->start + i) % deque->allocad;
        printf("%d ", deque->array[index]);
    }
    printf("\n");
}