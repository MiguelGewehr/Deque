#ifndef DEQUE_ARRAY_CIRCULAR_H
#define DEQUE_ARRAY_CIRCULAR_H

// Definição da estrutura do deque circular
typedef struct {
    int *array;
    int start;
    int end;
    int size;
    int allocad;
} Deque;

// Função para criar um novo deque circular vazio
Deque *deque_construct();

// Função para verificar se o deque circular está vazio
int isEmpty(Deque *deque);

// Função para verificar se o deque circular está cheio
int isFull(Deque *deque);

void deque_push_back(Deque *deque, int elemento);

void deque_push_front(Deque *deque, int elemento);

int deque_pop_back(Deque *deque);

int deque_pop_front(Deque* deque);

// Função para obter o elemento da frente do deque circular (sem remover)
int frenteDeque(Deque* deque);

// Função para obter o elemento do final do deque circular (sem remover)
int finalDeque(Deque* deque);

// Função para liberar a memória alocada pelo deque circular
void liberarDeque(Deque* deque);

void printDeque(Deque* deque);

#endif // DEQUE_ARRAY_CIRCULAR_H
