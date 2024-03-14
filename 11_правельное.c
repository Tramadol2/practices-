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
};

void push_stack(void* arg) {
    struct {
        struct Stack* stack;
        void* elem;
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
    struct Student* one = initstudent("Иванов", "Иван", "м", 17, 207, 5.0, 5.0, 5.0);
    struct Student* two = initstudent("Петров", "Петр", "м", 16, 207, 5.0, 5.0, 2.2);
    struct Student* three = initstudent("Сидоров", "Сидор", "м", 18, 207, 5.0, 5.0, 5.0);

    struct Stack* students = init();
    struct {
        struct Stack* stack;
        void* elem;
    } args;

    args.stack = students;
    args.elem = one;
    push_stack(&args);

    args.elem = two;
    push_stack(&args);

    args.elem = three;
    push_stack(&args);

    while (students->size > 0) {
        struct Student* q = (struct Student*)pop_stack(students);
        if (q->age >= 16 && q->age <= 18) {
            q->infoOutput(q);
            free(q);
        }
    }

    return 0;
}