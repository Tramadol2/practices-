#include <stdio.h>
#include <stdlib.h>

int main() {
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

    return 0;
}