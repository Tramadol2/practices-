#include <stdio.h>
#include <string.h>

// Определение структуры для представления информации о студенте
struct Student {
    char lastName[50];
    char firstName[50];
    char gender; // 'M' - мужской, 'W' - женский
    int age;
    char group[10];
    float mathGrade;
    float physicsGrade;
    float chemistryGrade;
    void(*printStudent)(struct Student *student);
};

// Функция для вывода информации о студенте
void printStudentInfo(struct Student *student) {
    printf("Student Information:\n");
    printf("Last Name: %s\n", student->lastName);
    printf("First Name: %s\n", student->firstName);
    printf("Gender: %c\n", student->gender);
    printf("Age: %d\n", student->age);
    printf("Group: %s\n", student->group);
    printf("Math Grade: %.2f\n", student->mathGrade);
    printf("Physics Grade: %.2f\n", student->physicsGrade);
    printf("Chemistry Grade: %.2f\n", student->chemistryGrade);
    printf("\n");
}

int main() {
    // Создание массива из 10 структур Student
    struct Student students[10];

    // Ввод информации с клавиатуры для каждого студента
    for (int i = 0; i < 10; ++i) {
        printf("Enter information for student %d (or type 'End' to exit):\n", i + 1);

        printf("Last Name: ");
        if (scanf("%s", students[i].lastName) != 1 || strcmp(students[i].lastName, "End") == 0) {
            // Если пользователь ввел "End", завершаем цикл
            printf("Exiting input loop.\n");
            break;
        }


        printf("First Name: ");
        scanf("%s", students[i].firstName);

        printf("Gender (M/W): ");
        scanf(" %c", &students[i].gender);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Group: ");
        scanf("%s", students[i].group);

        printf("Math Grade: ");
        scanf("%f", &students[i].mathGrade);

        printf("Physics Grade: ");
        scanf("%f", &students[i].physicsGrade);

        printf("Chemistry Grade: ");
        scanf("%f", &students[i].chemistryGrade);

        printf("\n");
    }
    // Вывод информации о студентах в возрасте от 16 до 18 лет
    printf("Students aged 16 to 18:\n");
    for (int i = 0; i < 10; ++i) {
        if (students[i].age >= 16 && students[i].age <= 18) {
            printStudentInfo(&students[i]);
        }
    }
    // Вывод информации о каждом студенте
//    for (int i = 0; i < 10; ++i) {
//        printStudentInfo(&students[i]);
//    }

    return 0;
}