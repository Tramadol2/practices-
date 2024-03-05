#include "stack.h"
#include "student.h"
#include <stdlib.h>

void push_stack(struct Stack* stack, void* elem) {
    struct Node* new_head = malloc(sizeof(struct Node));
    new_head->data = *((struct Student*)elem);
    new_head->next = stack->head;
    stack->head = new_head;
    stack->size += 1;
}

void* pop_stack(struct Stack* stack) {
    if (stack->size == 0) {
        return NULL;
    }
    struct Node* elem = stack->head;
    struct Student* result = malloc(sizeof(struct Student));
    *result = stack->head->data;
    stack->head = stack->head->next;
    stack->size -= 1;
    free(elem);
    return result;
}

struct Stack* init(struct Stack* result) {
    result = malloc(sizeof(struct Student));
    result->head = NULL;
    result->size = 0;
    result->push = push_stack;
    result->pop = pop_stack;
    return result;
}