#include <stdio.h>


//функция котора добавляет _  в нчало и конец каждого символа
void add(char array[100][100], int size) {
    for (int i = 0; i < size; ++i) {
        printf("_%s_", array[i]);

        // Добавляем запятую после каждого элемента, кроме последнего
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    int size;

    printf("Введите размер массива: ");
    scanf("%d", &size);

    char inputArray[100][100];// массив на 100 строк на 100 символов каждая

    //заполняем массив
    for (int i = 0; i < size; ++i) {
        printf("Введите строку %d: ", i + 1);
        scanf("%99s", inputArray[i]);
    }
    // используем наше функцию
    add(inputArray, size);

    return 0;
}
