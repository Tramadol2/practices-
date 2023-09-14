#include <stdio.h>
#include <math.h>
int main() {
    int array[1000];
    int chet = 0;    
    for (int i = 0; i < 1000; i++) {
        printf("Введите число #%d (или любой нечисловой символ для завершения): ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            break;
        }
        chet++; 
    }
    printf("В массиве %d чисел:\n", chet);
    for (int i = 0; i < chet; i++) {
        if (array[i]<0){
            array[i]= pow(array[i], 2);
        }
        printf("Элемент %d: %d\n", i, array[i]);
    }
    return 0;
}
