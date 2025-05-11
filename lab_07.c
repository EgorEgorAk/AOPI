#include <stdio.h>
#include <time.h>

// Алгоритм 1: Перебор от a до 1
long gcd01(long a, long b) {
    for (long i = a; i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

// Алгоритм 2: Перебор от min(a, b)
long gcd02(long a, long b) {
    long min = (a < b) ? a : b;
    for (long i = min; i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

// Алгоритм 3: Разложение на множители
long gcd03(long a, long b) {
    long gcd = 1;
    long min = (a < b) ? a : b;
    for (long i = 2; i <= min; i++) {
        while (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

// Алгоритм 4: Рекурсивный Евклид (по разности)
long gcd04(long a, long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b)
        return gcd04(a - b, b);
    return gcd04(a, b - a);
}

// Алгоритм 5: Итерационный Евклид (по разности)
long gcd05(long a, long b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// Алгоритм 6: Рекурсивный бинарный Евклид
long gcd06(long a, long b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;
    if ((a & 1) == 0 && (b & 1) == 0)
        return gcd06(a >> 1, b >> 1) << 1;
    else if ((a & 1) == 0)
        return gcd06(a >> 1, b);
    else if ((b & 1) == 0)
        return gcd06(a, b >> 1);
    else if (a > b)
        return gcd06((a - b) >> 1, b);
    else
        return gcd06((b - a) >> 1, a);
}

// Алгоритм 7: Итерационный бинарный Евклид
long gcd07(long a, long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift;
    for (shift = 0; ((a | b) & 1) == 0; ++shift) {
        a >>= 1;
        b >>= 1;
    }

    while ((a & 1) == 0)
        a >>= 1;

    do {
        while ((b & 1) == 0)
            b >>= 1;

        if (a > b) {
            long temp = a;
            a = b;
            b = temp;
        }

        b = b - a;
    } while (b != 0);

    return a << shift;
}

// Функция бенчмарка
void benchmark(long (*func)(long, long), long a, long b, const char* name, int n) {
    clock_t start = clock();
    long result = 0;
    for (int i = 0; i < n; i++) {
        result = func(a, b);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: GCD = %ld, Time = %.6f sec (x%d)\n", name, result, time_spent, n);
}

int main() {
    long a = 123456;
    long b = 789012;
    int n_slow = 100;      // Меньше итераций для медленных алгоритмов
    int n_fast = 100000;   // Больше итераций для быстрых алгоритмов

    printf("Сравнение алгоритмов вычисления НОД для a = %ld, b = %ld\n\n", a, b);

    benchmark(gcd01, a, b, "gcd01 (перебор от a)", n_slow);
    benchmark(gcd02, a, b, "gcd02 (перебор от min)", n_slow);
    benchmark(gcd03, a, b, "gcd03 (разложение на множители)", n_slow);
    benchmark(gcd04, a, b, "gcd04 (рекурсивный Евклид)", n_fast);
    benchmark(gcd05, a, b, "gcd05 (итерационный Евклид)", n_fast);
    benchmark(gcd06, a, b, "gcd06 (рекурсивный бинарный)", n_fast);
    benchmark(gcd07, a, b, "gcd07 (итерационный бинарный)", n_fast);

    return 0;
}