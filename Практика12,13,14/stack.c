#include "stack.h"
#include <stdlib.h>
\
    } *args = arg;

    struct Node* new_head = malloc(sizeof(struct Node));
    new_head->data = *((struct Student*)args->elem);
    new_head->next = args->stack->head;
    args->stack->head = new_head;
    args->stack->size += 1;
}

void* pop_stack(void* stack) {
    struct Stack* s = (struct Stack*)stack;
    if (s->size == 0) {
        return NULL;
    }
    struct Node* elem = s->head;
    struct Student* result = malloc(sizeof(struct Student));
    *result = s->head->data;
    s->head = s->head->next;
    s->size -= 1;
    free(elem);
    return result;
}
struct Stack* init() {
    struct Stack* res = malloc(sizeof(struct Stack));
    res->head = NULL;
    res->size = 0;
    return res;
}


