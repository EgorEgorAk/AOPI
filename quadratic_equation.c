#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// Функция для решения квадратного уравнения
void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        printf("Ошибка: коэффициент 'a' не может быть равен 0 (это не квадратное уравнение).\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;
    printf("Дискриминант: %.2f\n", discriminant);

    if (discriminant >= 0) {
        // Действительные корни
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Уравнение имеет действительные корни:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else {
        // Комплексные корни
        if (discriminant < 0) {
            printf("Уравнение не имеет действительных корней\n");
        }
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);

        printf("Уравнение не имеет действительных корней, имеет только комплексные корни:\n");
        printf("x1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("x2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }
}

int main() {
    double a, b, c;

    printf("Введите коэффициенты a, b, c через пробел: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Ошибка ввода! Введите три числа.\n");
        return 1;
    }

    solve_quadratic(a, b, c);

    return 0;
}