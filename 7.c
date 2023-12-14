#include <stdio.h>

// Рекурсивная функция для замены отрицательных чисел их квадратами
int recyrsiv(int array[], int size, int index) {
    // Базовый случай: если индекс превысил размер массива, завершаем рекурсию
    if (index >= size) {
        return;
    }

    // Заменяем отрицательное число его квадратом
    if (array[index] < 0) {
        array[index] = array[index] * array[index];
    }

    // Рекурсивный вызов для следующего элемента массива
    recyrsiv(array, size, index + 1);
}

// Функция для ввода элементов массива
int wod(int array[], int size, int i) {
    if (i < size) {
        printf("Введите элемент массива #%d: ", i + 1);
        scanf("%d", &array[i]);
        wod(array, size, i + 1);
    }
}

// Функция для вывода массива
int printArray(int array[], int size, int index) {
    printf("Массив после замены отрицательных чисел их квадратами:\n");
    if (index < size) {
        printf("%d ", array[index]);
        printArray(array, size, index + 1);
    }
}

int main() {
    int size;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int array[size];

    // Ввод элементов массива
    wod(array, size, 0);

    // Вызываем рекурсивную функцию для замены отрицательных чисел
    recyrsiv(array, size, 0);

    // Выводим массив после замены
    printArray(array, size, 0);

    return 0;
}
