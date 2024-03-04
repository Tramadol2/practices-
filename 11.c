#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student {
    char *surname;
    char *name;
    char *sex;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    void (*infoOutput)(void*);
};

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

void infoOutput(void* student) {
    struct Student* s = (struct Student*)student;
    printf("Фамилия: %s\n", s->surname);
    printf("Имя: %s\n", s->name);
    printf("Пол %s\n", s->sex);
    printf("Возраст: %d\n", s->age);
    printf("Группа: %d\n", s->group);
    printf("Отметка по математике: %f\n", s->mathMark);
    printf("Отметка по физике: %f\n", s->physicsMark);
    printf("Отметка по химии: %f\n", s->chemistryMark);
}

struct Student* initstudent(char* surname, char* name, char* sex, int age, int group, float mathMark, float physickMark, float chemistryMark) {
    struct Student* result = malloc(sizeof(struct Student));
    result->surname = surname;
    result->name = name;
    result->sex = sex;
    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physickMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    return result;
}

int main() {
    system("chcp 65001");
    struct Student* one = initstudent("test2", "test2", "m", 17, 207, 5.0, 5.0, 5.0);
    struct Student* two = initstudent("test2", "test2", "m", 16, 207, 5.0, 5.0, 2.2);
    struct Student* three = initstudent("test3", "test3", "m", 18, 207, 5.0, 5.0, 5.0);

    struct Stack* students = init(students);
    students->push(students, (void*) one);
    students->push(students, (void*) two);
    students->push(students,  (void*) three);

    while (students->size > 0) {
        struct Student* q = (struct Student*)students->pop(students);
        if (q->age >= 16 && q->age <= 18) {
            q->infoOutput(q);
            free(q);
        }
    }

    return 0;
}
