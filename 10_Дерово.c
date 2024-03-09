 #include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student {
    char *surname;
    char *name;
    char *sex;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    void (*infoOutput)(struct Student *student);
};

struct Tree {
    struct Student **data;
    int count;
    struct Tree *left;
    struct Tree *right;
    void (*add_node)(struct Tree *node, struct Student *data);
    void (*clear)(struct Tree *node);
};

void tree_add_node(struct Tree *node, struct Student *data);
void tree_clear(struct Tree *node);

struct Tree *tree_init(struct Student *data) {
    struct Tree *result = malloc(sizeof(struct Tree));
    result->data = malloc(sizeof(struct Student *));
    result->data[0] = data;
    result->count = 1;
    result->add_node = tree_add_node;
    result->right = NULL;
    result->left = NULL;
    result->clear = tree_clear;

    return result;
}

void tree_add_node(struct Tree *node, struct Student *data) {
    if (node->data[0]->age < data->age) {
        if (node->left == NULL) {
            node->left = tree_init(data);
            return;
        }
        node->left->add_node(node->left, data);
        return;
    }
    if (node->data[0]->age > data->age) {
        if (node->right == NULL) {
            node->right = tree_init(data);
            return;
        }
        node->right->add_node(node->right, data);
        return;
    }
    if(node->data[0]->age == data->age){
        node->count++;
        node->data = realloc(node->data, node->count * sizeof(struct Student *));
        node->data[node->count - 1] = data;
    }

}

void tree_clear(struct Tree *node) {
    if (node->left != NULL)
        tree_clear(node->left);
    if (node->right != NULL)
        tree_clear(node->right);

    for (int i = 0; i < node->count; i++) {
        free(node->data[i]->surname);
        free(node->data[i]->name);
        free(node->data[i]->sex);
        free(node->data[i]);

    }
    free(node->data);
    free(node);
}

void infoOutput(struct Student *student) {
    printf("Фамилия: %s\n", student->surname);
    printf("Имя: %s\n", student->name);
    printf("Пол: %s\n", student->sex);
    printf("Возраст: %d\n", student->age);
    printf("Группа: %d\n", student->group);
    printf("Отметка по математике: %f\n", student->mathMark);
    printf("Отметка по физике: %f\n", student->physicsMark);
    printf("Отметка по химии: %f\n", student->chemistryMark);
}

struct Student *initstudent(char *surname, char *name, char *sex, int age, int group, float mathMark, float physicsMark, float chemistryMark) {
    struct Student *result = malloc(sizeof(struct Student));
    result->surname = strdup(surname);
    result->name = strdup(name);
    result->sex = strdup(sex);
    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physicsMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    return result;
}

void filter_students(struct Tree *node, int min_age, int max_age) {
    if (node == NULL) {
        return;
    }

    filter_students(node->left, min_age, max_age);

    if (node->data[0]->age >= min_age && node->data[0]->age <= max_age) {
        for (int i = 0; i < node->count; i++) {
            node->data[i]->infoOutput(node->data[i]);
        }
    }

    filter_students(node->right, min_age, max_age);
}

int main() {
    system("chcp 65001");
    struct Tree *students[100];
    students[0] = tree_init(initstudent("тест1", "тест1", "м", 17, 207, 5.0, 5.0, 5.0));
    students[0]->add_node(students[0], initstudent("тест1", "тест1", "м", 17, 207, 5.0, 5.0, 5));
    students[0]->add_node(students[0], initstudent("тест3", "тест3", "м",18, 207, 5.0, 5.0, 5.0));


    filter_students(students[0], 16, 18);
    students[0]->clear(students[0]);

    return 0;
}