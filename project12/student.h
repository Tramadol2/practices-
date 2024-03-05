#ifndef STUDENT_H
#define STUDENT_H

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

struct Student* initstudent(char* surname, char* name, char* sex, int age, int group, float mathMark, float physickMark, float chemistryMark);

#endif
