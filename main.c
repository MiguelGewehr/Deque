#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Deque* deque = deque_construct();

    deque_push_back(deque, 10);
    deque_push_back(deque, 20);
    deque_push_back(deque, 30);
    deque_push_front(deque, 5);
    deque_push_front(deque, 2);
    deque_push_front(deque, 3);

    printDeque(deque);

    printf("Element popped from the back: %d\n", deque_pop_back(deque));
    printf("Element popped from the front: %d\n", deque_pop_front(deque));

    printDeque(deque);

    liberarDeque(deque);
    return 0;
}
