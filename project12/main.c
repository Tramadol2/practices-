#include "stack.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    struct Student* one = initstudent("test2", "test2", "m", 17, 207, 5.0, 5.0, 5.0);
    struct Student* two = initstudent("test2", "test2", "m", 11, 207, 5.0, 5.0, 2.2);
    struct Student* three = initstudent("test3", "test3", "m", 11, 207, 5.0, 5.0, 5.0);

    struct Stack* students = init(students);
    students->push(students, (void*)one);
    students->push(students, (void*)two);
    students->push(students, (void*)three);

    while (students->size > 0) {
        struct Student* q = (struct Student*)students->pop(students);
        if (q->age >= 16 && q->age <= 18) {
            q->infoOutput(q);
            free(q);
        }
    }

    return 0;
}
