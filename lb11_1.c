
#include <stdio.h>
#include <locale.h>

#define N 10

int main() {
    setlocale(LC_ALL, "RUS");

    float A[N], B[N];
    float sum = 0, average;

    // Ввод массива
    printf("Введите 10 элементов массива:\n");

    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i + 1);
        scanf_s("%f", &A[i]);

        B[i] = A[i];
    }

    // Преобразование массива
    for (int i = 0; i < N; i++) {
        if ((int)B[i] % 2 == 0 && B[i] == (int)B[i]) {
            B[i] = 1;
        }
    }

    // Вывод таблицы
    printf("\n");
    printf("---------------------------------------------\n");
    printf("| Индекс | Исходное значение | Новое значение |\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("| %6d | %17.2f | %14.2f |\n",
            i + 1, A[i], B[i]);
    }

    printf("---------------------------------------------\n");

    // Вычисление среднего арифметического
    for (int i = 0; i < N; i++) {
        sum += B[i];
    }

    average = sum / N;

    printf("\nСреднее арифметическое преобразованного массива: %.2f\n",
        average);

    return 0;
}
