#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


void add(int number) {
    if (number > 0) {
        printf("qqqqЧисло %d является положительным.\n", number);
    } else if (number < 0) {
        printf("wwwwЧисло %d является отрицательным.\n", number);
    } else {
        printf("eeeeЧисло %d является нулем.\n", number);
    }
}

void add2(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            array[i] = (int)pow(array[i], 2);  // Преобразование результата к целому типу
        }
        printf("Элемент %d: %d\n", i, array[i]);
    }
}

void add3(int matrix[1000][1000],int rows, int cols ){
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
}


void add4(int mainarray [1000],int size ,int n){
    int j = 0;

    //создания динамического массива
    int *dinamickarray;
    dinamickarray = (int *)malloc(size * sizeof(int));

    // отбор чисел по критерию из главного масива в динамический
    for (int i = 0; i < size; i++) {
        if (mainarray[i] > n) {
            dinamickarray[j] = mainarray[i];
            ++j;
        }
    }
    // меняем местами числа в масиве
    for (int i = 0; i < j / 2; i++) {
        int temp = dinamickarray[i];
        dinamickarray[i] = dinamickarray[j - i - 1];
        dinamickarray[j - i - 1] = temp;
    }
    //выводим масив
    printf("Второй массив с элементами, удовлетворяющими критерию:\n");
    for (int i = 0; i < j; i++) {
        printf("%d ", dinamickarray[i]);
    }
    //очищяем масив
    free(dinamickarray);
}


int main() {
    while (true) {
        printf("Введите номер функции 1, 2 (для массива), 0 (для выхода): ");
        int b;
        scanf("%d", &b);

        if (b == 0) {
            printf("Программа завершена.\n");
            break;
        } else if (b == 1) {
            int c;
            printf("Введите число для проверки на положительность или отрицательность: ");
            scanf("%d", &c);

            if (c != 1) {
                while (getchar() != '\n');
                continue;
            }

            add(c);

        } else if (b == 2) {
            int c;
            printf("Введите размер массива: ");
            int chet;
            scanf("%d", &chet);
            int mainarray[1000];

            printf("Введите значения массива: ");
            for (int i = 0; i < chet; i++) {
                scanf("%d", &mainarray[i]);
                if (mainarray[i] != 1) {
                    while (getchar() != '\n');
                    continue;
                }
            }

            add2(mainarray, chet);
        }

        else if (b == 3){
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
                    if (matrix[i][j] != 1) {
                        while (getchar() != '\n');
                        continue;
                    }
                }

            }
            add3(matrix, rows, cols);
        }

        else if (b == 4){
            int size;
            printf("Введите размер массива: ");
            scanf("%d", &size);
            int mainarray[size];
            printf("Заполните массив:\n");

            //заполнение главного массива
            for (int i = 0; i < size; i++) {
                scanf("%d", &mainarray[i]);
            }


            //вводим критерии
            printf("Введите критерии заполнения второго массива: ");
            int n;
            scanf("%d", &n);
            add4 (mainarray,size,n);
        }
    }

    return 0;
}
