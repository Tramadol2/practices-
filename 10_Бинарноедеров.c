#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student {
    char surname[50];
    char name[50];
    char gender;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    //казатель на функцию, которая принимает указатель на структуру Student и выполняет какие-то действия. В данном случае, она используется для динамического связывания функции вывода информации с каждым экземпляром структуры.
    void (*infoOutput)(struct Student *student);
};

// Структура, представляющая узел в дереве
struct TreeNode {
    // Данные о студенте, содержащиеся в узле. Это поле имеет тип struct Student, поэтому каждый узел хранит информацию о студенте.
    struct Student data;
    //Указатель на левого потомка узла.
    struct TreeNode* left;
    // Указатель на правого потомка узла.
    struct TreeNode* right;
};

// Структура, представляющая дерево студентов
struct Tree {
    //Указатель на корень дерева, который является начальным узлом при добавлении студентов.
    struct TreeNode* root;
    //Указатель на функцию вставки нового узла в дерево.
    void (*insert)(struct Tree* tree, struct Student elem);
    // Указатель на функцию обхода дерева с использованием функции обратного вызова для студентов в заданном возрастном диапазоне.
    void (*traverse)(struct TreeNode* node, void (*callback)(struct Student*), int minAge, int maxAge);
};

// Функция для вставки узла в дерево
void tree_insert(struct Tree* tree, struct Student elem) {
    //Создается новый узел (new_node) путем выделения памяти размером, достаточным для структуры TreeNode. malloc используется для динамического выделения памяти.
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    //Значение структуры elem (данные нового студента) копируется в поле data нового узла.
    new_node->data = elem;
    //Устанавливаются указатели на левого и правого потомков нового узла в NULL, поскольку у нового узла еще нет потомков.
    new_node->left = NULL;
    new_node->right = NULL;
    //Проверка, пустое ли дерево:сли tree->root (корень дерева) равен NULL, то дерево пусто, и новый узел становится корнем дерева.
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct TreeNode* current = tree->root;
        while (1) {
            //В каждой итерации цикла сравнивается возраст (elem.age) нового студента с возрастом текущего узла (current->data.age).
            if (elem.age < current->data.age) {
                //Если возраст нового студента меньше возраста текущего узла, мы двигаемся влево. Если левый потомок у текущего узла (current->left) равен NULL, то новый узел вставляется туда, и цикл завершается (break). В противном случае, мы присваиваем current->left текущему узлу, чтобы продолжить поиск влево.
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                }
                current = current->left;
            } else {
                //Если возраст нового студента больше или равен возрасту текущего узла, мы двигаемся вправо. Если правый потомок у текущего узла (current->right) равен NULL, то новый узел вставляется туда, и цикл завершается (break). В противном случае, мы присваиваем current->right текущему узлу, чтобы продолжить поиск вправо.
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }
}

// Функция для обхода дерева в порядке in-order с фильтрацией по возрасту
void treeMIN_MAX(struct TreeNode* node, void (*callback)(struct Student*), int minAge, int maxAge) {
    //Функция начинается с проверки, является ли текущий узел (node) непустым (node != NULL). Если узел пуст, то функция завершает свою работу, так как нет дальнейших узлов для обхода.
    if (node != NULL) {
        //Затем функция вызывает саму себя рекурсивно для левого потомка текущего узла (node->left). Это приводит к тому, что все узлы в левом поддереве будут обработаны по порядку возрастания.
        treeMIN_MAX(node->left, callback, minAge, maxAge);

        // Фильтрация и вызов callback только для студентов в заданном возрастном диапазоне
        //После обработки левого поддерева происходит проверка возраста текущего узла (node->data.age) на соответствие заданному диапазону (minAge и maxAge). Если возраст попадает в этот диапазон, вызывается функция обратного вызова (callback) для обработки студента.
        if (node->data.age >= minAge && node->data.age <= maxAge) {
            callback(&(node->data));
        }
        //Завершающим шагом является рекурсивный вызов функции для правого потомка текущего узла (node->right). Это приводит к тому, что все узлы в правом поддереве также будут обработаны по порядку возрастания.
        treeMIN_MAX(node->right, callback, minAge, maxAge);
    }
}

// Функция для вывода информации о студенте
void infoOutput(struct Student* student) {
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
    system("chcp 65001");
    struct Student student1 = {"Фамилия", "Имя", 'm', 17, 111, 5.0, 5.0, 5.0};
    struct Student student2 = {"Фамилия", "Имя", 'm', 21, 222, 5.0, 5.0, 5.0};
    struct Student student3 = {"Фамилия", "Имя", 'm', 16, 333, 5.0, 5.0, 5.0};
    struct Student student4 = {"Фамилия", "Имя", 'm', 17, 444, 5.0, 5.0, 5.0};
    struct Student student5 = {"Фамилия", "Имя", 'm', 18, 555, 5.0, 5.0, 5.0};
    struct Student student6 = {"Фамилия", "Имя", 'm', 16, 666, 5.0, 5.0, 5.0};
    struct Student student7 = {"Фамилия", "Имя", 'm', 17, 777, 5.0, 5.0, 5.0};
    struct Student student8 = {"Фамилия", "Имя", 'm', 15, 888, 5.0, 5.0, 5.0};
    struct Student student9 = {"Фамилия", "Имя", 'm', 14, 999, 5.0, 5.0, 5.0};

    // Выделяется память под указатель на структуру Tree. Этот указатель будет использоваться для работы с деревом студентов.
    struct Tree* studentsTree = malloc(sizeof(struct Tree));
    //Устанавливается указатель root в созданном дереве в NULL. Это означает, что дерево студентов в начале не содержит ни одного узла.
    studentsTree->root = NULL;
    //Указатель на функцию вставки tree_insert присваивается полю insert в структуре Tree. Таким образом, теперь studentsTree->insert указывает на функцию, которая будет использоваться для вставки новых студентов в дерево.
    studentsTree->insert = tree_insert;
    //Указатель на функцию обхода treeMIN_MAX присваивается полю traverse в структуре Tree. Теперь studentsTree->traverse указывает на функцию, которая будет использоваться для обхода дерева с учетом заданного возрастного диапазона.
    studentsTree->traverse = treeMIN_MAX;

    studentsTree->insert(studentsTree, student1);
    studentsTree->insert(studentsTree, student2);
    studentsTree->insert(studentsTree, student3);
    studentsTree->insert(studentsTree, student4);
    studentsTree->insert(studentsTree, student5);
    studentsTree->insert(studentsTree, student6);
    studentsTree->insert(studentsTree, student7);
    studentsTree->insert(studentsTree, student8);
    studentsTree->insert(studentsTree, student9);

    // Обход дерева и вывод информации о студентах в возрасте от 16 до 18 лет
    studentsTree->traverse(studentsTree->root, infoOutput, 16, 18);

    return 0;
}

