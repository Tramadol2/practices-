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

// Функция для вывода массива
int printArray(int array[], int size) {
    printf("Массив после замены отрицательных чисел их квадратами:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int size;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int array[size];

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Вызываем рекурсивную функцию для замены отрицательных чисел
    recyrsiv(array, size, 0);

    // Выводим массив после замены
    printArray(array, size);

    return 0;
}
