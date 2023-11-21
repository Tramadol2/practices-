#include <stdio.h>
#include <string.h>


// Функция котороя добавляет симл '_' в массив перед каждым словом
void niz(char words[][100], int size) {
    for (int i = 0; i < size; i++) {
        char result[200];  // Создаем временный буфер для результата

        strcpy(result, "");  // Инициализируем буфер пустой строкой

        strcat(result, "_");    // Добавляем '_' в начало

        strcat(result, words[i]);  // Добавляем исходное слово

        strcat(result, "_");   // Добавляем '_' в конец

        strcpy(words[i], result);   // Копируем результат обратно в исходное слово
    }
}

int main() {
    int size;
    printf("Введите количество слов в массиве: ");
    scanf("%d", &size);

    char words[size][100];

    // Вводим слова в массив
    printf("Введите слова в массив:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s", words[i]);
    }

    // Вызываем функцию для добавления символов '_'
    niz(words, size);

    // Выводим измененный массив
    printf("Измененный массив:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

