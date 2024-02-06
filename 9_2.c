#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Структура, представляющая информацию о студенте
struct Student {
    char surname[50];
    char name[50];
    char gender;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    void (*infoOutput)(struct Student *student);
    bool (*StudentGroup)(struct Student *student, int group);
};
// Структура, представляющая узел в стеке
struct Node {
    struct Student data;
    struct Node* next;
};
// Структура, представляющая стек студентов
struct Stack {
    struct Node* head;
    unsigned long int size;
    void (*push)(struct Stack* stack, struct Student elem);
    struct Student (*pop)(struct Stack* stack);
};
// Функция добавления элемента в стек
void push_stack(struct Stack* stack, struct Student elem) {
    struct Node* new_head = malloc(sizeof(struct Node));
    new_head->data = elem;
    new_head->next = stack->head;
    stack->head = new_head;
    stack->size += 1;
}
// Функция извлечения элемента из стека
struct Student pop_stack(struct Stack* stack) {
    if (stack->size == 0) {
        struct Student student;
        return student;
    }
    struct Node* elem = stack->head;
    struct Student result = stack->head->data;
    stack->head = stack->head->next;
    stack->size -= 1;
    free(elem);
    return result;

}
// Функция инициализации стека
struct Stack* init(struct Stack* result) {
    result = malloc(sizeof(struct Student));
    result->head = NULL;
    result->size = 0;
    result->push = push_stack;
    result->pop = pop_stack;
    return result;
};
// Функция вывода информации о студенте
void infoOutput(struct Student *student) {
    printf("Фамилия: %s\n", student->surname);
    printf("Имя: %s\n", student->name);
    printf("Пол: %c\n", student->gender);
    printf("Возраст: %d\n", student->age);
    printf("Группа: %d\n", student->group);
    printf("Отметка по математике: %f\n", student->mathMark);
    printf("Отметка по физике: %f\n", student->physicsMark);
    printf("Отметка по химии: %f\n", student->chemistryMark);
    printf("\n");
}



int main() {
    struct Student student1 = {"Фамилия", "Имя", 'm', 17, 111, 5.0, 5.0, 5.0};
    struct Student student2 = {"Фамилия", "Имя", 'm', 21, 222, 5.0, 5.0, 5.0};
    struct Student student3 = {"Фамилия", "Имя", 'm', 16, 333, 5.0, 5.0, 5.0};
    struct Student student4 = {"Фамилия", "Имя", 'm', 17, 444, 5.0, 5.0, 5.0};
    struct Student student5 = {"Фамилия", "Имя", 'm', 18, 555, 5.0, 5.0, 5.0};
    struct Student student6 = {"Фамилия", "Имя", 'm', 16, 666, 5.0, 5.0, 5.0};
    struct Student student7 = {"Фамилия", "Имя", 'm', 17, 777, 5.0, 5.0, 5.0};
    struct Student student8 = {"Фамилия", "Имя", 'm', 15, 888, 5.0, 5.0, 5.0};
    struct Student student9 = {"Фамилия", "Имя", 'm', 14, 999, 5.0, 5.0, 5.0};

    struct Stack* students = init(students);

    students->push(students, student1);
    students->push(students, student2);
    students->push(students, student3);
    students->push(students, student4);
    students->push(students, student5);
    students->push(students, student6);
    students->push(students, student7);
    students->push(students, student8);
    students->push(students, student9);

    while (students->size > 0) {
        struct Student tmp = students->pop(students);
        if (tmp.age>=16 && tmp.age <=18) {
            infoOutput(&tmp);
        }
    }

    return 0;
}