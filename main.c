#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include "math_df.h"
#include "math_f.h"


int main() {
    // Налаштування мови для виводу кирилиці
    setlocale(LC_ALL, "uk_UA.UTF-8");
    //Оголошення змінних та ініціалізування
    int choice = 0;
    double X1 = 0.0, X2 = 0.0, delta = 0.0;
    int N = 0;

    // Текстовий інтерфейс
    do{
    system("cls");
    printf("Оберіть варіант введення початкових даних:\n");
    printf("1. X1 (початкове), X2 (кінцеве), N (кількість точок)\n");
    printf("2. X1 (початкове), X2 (кінцеве), delta (крок зміни)\n");
    printf("Ваш вибір (1 або 2): ");
    scanf("%d", &choice);
    }while(choice<1||choice>2);

    if (choice == 1) {

        printf("\n--- Введення даних (Варіант 1) ---\n");
        printf("Введіть X1 (початкове значення): ");
        scanf("%lf", &X1);
        printf("Введіть X2 (кінцеве значення): ");
        scanf("%lf", &X2);
        printf("Введіть N (кількість точок): ");
        scanf("%d", &N);

        // Обчислення кроку delta
        delta = (X2 - X1) / (N - 1);
    }
    else {
        printf("\n--- Введення даних (Варіант 2) ---\n");
        printf("Введіть X1 (початкове значення): ");
        scanf("%lf", &X1);
        printf("Введіть X2 (кінцеве значення): ");
        scanf("%lf", &X2);
        printf("Введіть delta (крок зміни): ");
        scanf("%lf", &delta);

        // Обчислення кількості точок N
        N = (int)((X2 - X1) / delta) + 1;
    }

    // Вивід початкових даних
    printf("\n========================================\n");
    printf("            ПОЧАТКОВІ ДАНІ              \n");
    printf("========================================\n");
    printf("Обраний режим : Варіант %d\n", choice);
    printf("X1 (початкове): %.4f\n", X1);
    printf("X2 (кінцеве)  : %.4f\n", X2);
    printf("delta (крок)  : %.4f\n", delta);
    printf("N (кількість) : %d\n", N);
    printf("========================================\n\n");

    // Вивід таблиці псевдографікою
    printf("┌───────┬────────────┬────────────┬────────────┐\n");
    printf("│   N   │     X      │    Y(X)    │   Y'(X)    │\n");
    printf("├───────┼────────────┼────────────┼────────────┤\n");

    //Вивіди даних на консоль
    for (int i = 0; i < N; ++i)
    {


        double x_current = X1 + i * delta;



        double y = f(x_current);
        double dy = df(x_current);


        printf("│ %5d │ %10.4f │ %10.4f │ %10.4f │\n", i + 1, x_current, y, dy);
    }

    printf("└───────┴────────────┴────────────┴────────────┘\n");

    return 0;
}
