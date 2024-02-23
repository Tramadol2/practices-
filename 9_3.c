#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Student{
    char *surname;
    char *name;
    char *sex;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    void(*infoOutput)(struct  Student *student);


};

struct Node {
    struct Student data;
    struct Node* next;
};

struct Stack {
    struct Node* head;
    unsigned long int size;
    void (*push)(struct  Stack* stack, struct  Student elem);
    struct  Student(*pop)(struct Stack* stack);

};


void push_stack (struct Stack* stack, struct Student elem){
    struct  Node* new_head = malloc(sizeof (struct Node));
    new_head->data =elem;
    new_head->next = stack->head;
    stack->head=new_head;
    stack->size+=1;
}

struct Student pop_stack(struct Stack* stack){
    if (stack->size == 0) {
        struct  Student student;
        return student;
    }
    struct Node* elem = stack->head;
    struct Student result = stack->head->data;
    stack->head = stack->head->next;
    stack->size -=1;
    free(elem);
    return result;

}
struct  Stack* init(struct Stack* result){
    result = malloc(sizeof (struct Student));
    result->head= NULL;
    result->size= 0;
    result->push = push_stack;
    result->pop = pop_stack;
    return result;
}


void  infoOutput ( struct Student *student){
    printf("Фамилия: %s\n", student->surname);
    printf("Имя: %s\n", student->name);
    printf("Пол %s\n",student->sex);
    printf("Возраст: %d\n",student->age);
    printf("Группа: %d\n",student->group);
    printf("Отметка по математике: %f\n",student->mathMark);
    printf("Отметка по физеке: %f\n", student->physicsMark);
    printf("Отметка по химии: %f\n",student->chemistryMark);
}

struct Student* initstudent(char *surname, char *name, char *sex, int age,int group,float mathMark,float physickMark,float chemistryMark){
    struct Student* result = malloc(sizeof (struct  Student));
    result->surname = surname;
    result->name =name;
    result->sex =  sex;
    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physickMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    return  result;

}

int main(){
    system("chcp 65001");
    struct Student* one = initstudent("test2", "test2", "m", 17, 207, 5.0, 5.0, 5.0);
    struct Student* two = initstudent("test2", "test2", "m", 11, 207, 5.0, 5.0, 2.2);
    struct Student* three = initstudent("test3", "test3", "m", 11, 207, 5.0, 5.0, 5.0);

    struct Stack* students = init(students);
    students->push(students, *one);
    students->push(students, *two);
    students->push(students, *three);

    while (students->size > 0){
        struct Student q = students->pop(students);
        if(q.age>=16 && q.age<=18){
            q.infoOutput(&q);
        }
    }

}