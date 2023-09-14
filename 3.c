#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int rows, cols;
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);
    // создание матрицы
    int matrix[rows][cols];
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    double porog = 1; // порог близких числе
    int chet;
    for (int i = 0; i < rows; i++) {
        chet = 0;
        double colSum = 0;
        // Суммируем элементы столбца
        for (int j = 0; j < cols; j++) {
            colSum += matrix[i][j];
        }
        // средне арфмитическая
        double cred = colSum / cols;
        // fabs возвращает модуль игнорируя минусы,подсчет чисел близких к средене арифметическому
        for (int j = 0; j < cols; j++) {
            if (fabs(matrix[i][j] - cred) < porog) {
                chet++;
            }
        }
        printf("Строка %d: %d чисел близки к среднему арифметическому столбца.\n", i + 1, chet);
    }

    return 0;
}