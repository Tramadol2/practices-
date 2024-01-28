#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Структура, представляющая информацию о студенте
typedef struct Student {
    char lastName[50];
    char firstName[50];
    char gender;
    int age;
    char group[10];
    float mathGrade;
    float physicsGrade;
    float chemistryGrade;

    // Указатели на функции
    void (*displayInfo)(struct Student *);   // Функция для вывода информации о студенте
    void (*updateInfo)(struct Student *);    // Функция для обновления информации о студенте

    struct Student *next;  // Указатель на следующего студента в связанном списке
} Student;

// Функция для отображения информации о студенте
void displayStudentInfo(Student *student) {
    printf("Last Name: %s\n", student->lastName);
    printf("First Name: %s\n", student->firstName);
    printf("Gender: %c\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math Grade: %.2f\n", student->mathGrade);
    printf("Physics Grade: %.2f\n", student->physicsGrade);
    printf("Chemistry Grade: %.2f\n", student->chemistryGrade);
}

// Функция для обновления информации о студенте
void updateStudentInfo(Student *student) {
    printf("Enter new Last Name: ");
    scanf("%s", student->lastName);

    printf("Enter new First Name: ");
    scanf("%s", student->firstName);

    printf("Enter new Gender (M/W): ");
    scanf(" %c", &student->gender);

    printf("Enter new Age: ");
    scanf("%d", &student->age);

    printf("Enter new Group: ");
    scanf("%s", student->group);

    printf("Enter new Math Grade: ");
    scanf("%f", &student->mathGrade);

    printf("Enter new Physics Grade: ");
    scanf("%f", &student->physicsGrade);

    printf("Enter new Chemistry Grade: ");
    scanf("%f", &student->chemistryGrade);
}

// Функция для поиска и отображения студентов в возрасте от 16 до 18 лет
void displayStudentsInRange(Student *firstStudent) {
    printf("\nStudents in the age range of 16 to 18:\n");

    Student *currentStudent = firstStudent;
    while (currentStudent != NULL) {
        if (currentStudent->age >= 16 && currentStudent->age <= 18) {
            currentStudent->displayInfo(currentStudent);
            printf("--------------------\n");
        }
        currentStudent = currentStudent->next;
    }
}

int main() {
    // Создание первого студента
    Student *firstStudent = (Student *)malloc(sizeof(Student));
    if (!firstStudent) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Инициализация информации о первом студенте
    printf("Enter information for the first student:\n");
    printf("Last Name: ");
    scanf("%s", firstStudent->lastName);
    printf("First Name: ");
    scanf("%s", firstStudent->firstName);
    printf("Gender (M/W): ");
    scanf(" %c", &firstStudent->gender);
    printf("Age: ");
    scanf("%d", &firstStudent->age);
    printf("Group: ");
    scanf("%s", firstStudent->group);
    printf("Math Grade: ");
    scanf("%f", &firstStudent->mathGrade);
    printf("Physics Grade: ");
    scanf("%f", &firstStudent->physicsGrade);
    printf("Chemistry Grade: ");
    scanf("%f", &firstStudent->chemistryGrade);

    // Установка указателей на функции
    firstStudent->displayInfo = displayStudentInfo;
    firstStudent->updateInfo = updateStudentInfo;
    firstStudent->next = NULL;

    Student *currentStudent = firstStudent;

    // Создание и инициализация информации о следующих 9 студентах
    for (int i = 1; i < 10; i++) {
        currentStudent->next = (Student *)malloc(sizeof(Student));
        if (!currentStudent->next) {
            printf("Memory allocation failed\n");
            // Освобождение уже выделенной памяти
            while (firstStudent != NULL) {
                Student *nextStudent = firstStudent->next;
                free(firstStudent);
                firstStudent = nextStudent;
            }
            return 1;
        }

        currentStudent = currentStudent->next;
        currentStudent->next = NULL;

        // Инициализация информации о следующем студенте
        printf("\nEnter information for student %d:\n", i + 1);
        printf("Last Name: ");
        scanf("%s", currentStudent->lastName);
        printf("First Name: ");
        scanf("%s", currentStudent->firstName);
        printf("Gender (M/W): ");
        scanf(" %c", &currentStudent->gender);
        printf("Age: ");
        scanf("%d", &currentStudent->age);
        printf("Group: ");
        scanf("%s", currentStudent->group);
        printf("Math Grade: ");
        scanf("%f", &currentStudent->mathGrade);
        printf("Physics Grade: ");
        scanf("%f", &currentStudent->physicsGrade);
        printf("Chemistry Grade: ");
        scanf("%f", &currentStudent->chemistryGrade);

        // Установка указателей на функции
        currentStudent->displayInfo = displayStudentInfo;
        currentStudent->updateInfo = updateStudentInfo;
    }

    // Вывод информации о каждом студенте
//    printf("\nAll Students Information:\n");
//    currentStudent = firstStudent;
//    while (currentStudent != NULL) {
//        currentStudent->displayInfo(currentStudent);
//        printf("--------------------\n");
//        currentStudent = currentStudent->next;
//    }

    // Поиск и вывод студентов в возрасте от 16 до 18 лет
    displayStudentsInRange(firstStudent);

    // Освобождение памяти
    currentStudent = firstStudent;
    while (currentStudent != NULL) {
        Student *nextStudent = currentStudent->next;
        free(currentStudent);
        currentStudent = nextStudent;
    }

    return 0;
}
