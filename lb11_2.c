
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 100

// Функция из задания 8
double F(double x)
{
    return x * x * x + 3 * x * x - 3;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double A[N];
    double sum_positive = 0;
    double sum_negative = 0;
    double average = 0;

    int count_positive = 0;
    int count_negative = 0;

    srand((unsigned int)time(NULL));

    // Генерация массива из 100 элементов
    for (int i = 0; i < N; i++)
    {
        double x = 2.0 + (double)rand() / RAND_MAX * 2.0;

        A[i] = F(x);

        if (A[i] > 0)
        {
            sum_positive += A[i];
            count_positive++;
        }
        else if (A[i] < 0)
        {
            sum_negative += A[i];
            count_negative++;
        }
    }

    // Вычисление среднего положительных элементов
    if (count_positive > 0)
    {
        average = sum_positive / count_positive;
    }

    // Вывод массива
    printf("Массив A:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%.2f ", A[i]);

        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }

    // Вывод результатов
    printf("\nРезультаты:\n");

    printf("Сумма положительных элементов: %.2f\n",
        sum_positive);

    printf("Сумма отрицательных элементов: %.2f\n",
        sum_negative);

    printf("Количество положительных элементов: %d\n",
        count_positive);

    printf("Количество отрицательных элементов: %d\n",
        count_negative);

    if (count_positive > 0)
    {
        printf("Среднее значение положительных элементов: %.2f\n",
            average);
    }
    else
    {
        printf("Положительных элементов нет.\n");
    }

    return 0;
}
