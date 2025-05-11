#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define NUM_GRADES 5

typedef struct {
    char lastName[MAX_NAME];
    char firstName[MAX_NAME];
    char group[MAX_NAME];
    int grades[NUM_GRADES];
} STUDENT;

void inputStudents(const char *filename, int count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка открытия файла для записи");
        exit(1);
    }

    STUDENT student;
    for (int i = 0; i < count; i++) {
        printf("Студент %d:\n", i + 1);
        printf("Фамилия: ");
        scanf("%s", student.lastName);
        printf("Имя: ");
        scanf("%s", student.firstName);
        printf("Группа: ");
        scanf("%s", student.group);
        printf("Оценки по 5 предметам (через пробел): ");
        for (int j = 0; j < NUM_GRADES; j++) {
            scanf("%d", &student.grades[j]);
        }
        fwrite(&student, sizeof(STUDENT), 1, file);
    }

    fclose(file);
}

void outputAllStudents(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла для чтения");
        return;
    }

    STUDENT student;
    while (fread(&student, sizeof(STUDENT), 1, file)) {
        printf("Фамилия: %s, Имя: %s, Группа: %s, Оценки: ",
               student.lastName, student.firstName, student.group);
        for (int i = 0; i < NUM_GRADES; i++) {
            printf("%d ", student.grades[i]);
        }
        printf("\n");
    }

    fclose(file);
}

int hasOnlyGoodGrades(const STUDENT *student) {
    for (int i = 0; i < NUM_GRADES; i++) {
        if (student->grades[i] < 4)
            return 0;
    }
    return 1;
}

void outputExcellentStudents(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла для чтения");
        return;
    }

    STUDENT student;
    printf("Студенты с оценками только 4 и 5:\n");
    while (fread(&student, sizeof(STUDENT), 1, file)) {
        if (hasOnlyGoodGrades(&student)) {
            printf("Фамилия: %s, Имя: %s, Группа: %s\n",
                   student.lastName, student.firstName, student.group);
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "students.dat";
    int choice, count;

    do {
        printf("\nМеню:\n");
        printf("1. Ввод данных в файл\n");
        printf("2. Вывод всех студентов\n");
        printf("3. Вывод студентов с оценками только 4 и 5\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Сколько студентов ввести? ");
                scanf("%d", &count);
                inputStudents(filename, count);
                break;
            case 2:
                outputAllStudents(filename);
                break;
            case 3:
                outputExcellentStudents(filename);
                break;
            case 0:
                break;
            default:
                printf("Неверный выбор!\n");
        }
    } while (choice != 0);

    return 0;
}