#include <stdio.h>

// Наивный метод нахождения GCD
int gcd_naive(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}

// Метод Евклида
int gcd_euclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    // Ввод двух чисел
    printf("Введите два целых числа: ");
    scanf("%d %d", &a, &b);

    // Вывод результата обоими методами
    printf("Наивный метод: GCD = %d\n", gcd_naive(a, b));
    printf("Метод Евклида: GCD = %d\n", gcd_euclid(a, b));

    return 0;
}