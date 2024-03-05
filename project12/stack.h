#ifndef STACK_H
#define STACK_H

#include "student.h"

struct Node {
    struct Student data;
    struct Node* next;
};

struct Stack {
    struct Node* head;
    unsigned long int size;
    void (*push)(struct Stack* stack, void* elem);
    void* (*pop)(struct Stack* stack);
};

struct Stack* init(struct Stack* result);

#endif
