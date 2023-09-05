#include <stdio.h>

int main() {
    int number;
    printf("Введите число: ");
    scanf("%d", &number);
    if (number > 0) {
        printf("Число %d является положительным.", number);
    } else if (number < 0) {
        printf("Число %d является отрицательным.", number);
    } else {
        printf("Число %d является нулем.", number);
    }
    return 0;
}