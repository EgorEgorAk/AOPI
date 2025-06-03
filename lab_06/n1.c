#include <stdio.h>
#include <string.h>

#define N 1000
#define start 500

typedef struct str {
    char tape[N];
    int head;
    int status;
} Tmashine;

void initTM(Tmashine *TM) {
    memset(TM->tape, '0', N);
    TM->head = start;
    TM->status = 1;

    int index = start;
    char sym = 0;
    printf("input numb (format) 01^x01^y0\n> ");
    while (sym != '\n') {
        sym = getchar();
        if (sym == '\n') {
            break;
        }
        TM->tape[index++] = sym;
    }


}

void print(Tmashine *TM) {
    for (int i = 3; i > 0; i-- ) {
        printf("%c", TM->tape[start-i]);
    }
    for (int i = 0; i < 15; i++ ) {
        printf("%c", TM->tape[start+i]);
    }

    printf(" - state: %d\n", TM->status);
}

int main() {
    Tmashine TM;
    initTM(&TM);
    
    while (TM.status != 0) {
        print(&TM);

        switch (TM.status) {
            case 1:  // Ищем первую 1 в 1 массиве (двигаемся вправо)
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                } else {
                    TM.status = 2;
                }
                break;
                
            case 2:  // Идем по 1 массиву до разделителя 0
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 3;
                } else {
                    TM.head++;
                }
                break;
                
            case 3: // Ищем первую 1 во 2 массиве (двигаемся вправо)
                if (TM.tape[TM.head] == '1') {
                    TM.head--;
                    TM.status = 4;
                }
                break;
                
            case 4:   // Возвращаемся к последней 1 в 1 массиве (влево)
                if (TM.tape[TM.head] == '0') {
                    TM.head--;
                    TM.status = 5;
                }
                break;
                
            case 5:  // Проверяем два 0 подряд
                if (TM.tape[TM.head] == '0') {
                    TM.status = 13;
                } else {
                    TM.head--;
                    TM.status = 6;
                }
                break;
                
            case 6: // Копируем 1 из 1 массива (заменяем 0 на 1)
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head++;
                    TM.status = 7;
                } else {
                    TM.head--;
                }
                break;
                
            case 7: // (меняем 1 на 0
                if (TM.tape[TM.head] == '1') {
                    TM.tape[TM.head] = '0';
                    TM.head++;
                    TM.status = 8;
                }
                break;
                
            case 8:  // Идем к разделителю через 1 массив (вправо)
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 9;
                } else {
                    TM.head++;
                }
                break;
                
            case 9: // Идем через 2 массив к месту для 3 массива (вправо)
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 10;
                } else {
                    TM.head++;
                }
                break;
                
            case 10: // Добавляем 1 в 3 массив (пишем 1 и идем влево)
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head--;
                    TM.status = 11;
                } else {
                    TM.head++;
                }
                break;
                
            case 11: // Возвращаемся через 3 массив (влево)
                if (TM.tape[TM.head] == '0') {
                    TM.head--;
                    TM.status = 12;
                } else {
                    TM.head--;
                }
                break;
                
            case 12: // Возвращаемся к началу цикла (влево)
                if (TM.tape[TM.head] == '0') {
                    TM.status = 4;
                } else {
                    TM.head--;
                }
                break;
                
            case 13: // добавляем 1
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head--;
                    TM.status = 14;
                }
                break;
                
            case 14: // Возврат к началу x1 (влево)
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 15;
                } else {
                    TM.head--;
                }
                break;
                
            case 15: // меняем 1 на 0 и останавливаемся
                if (TM.tape[TM.head] == '1') {
                    TM.tape[TM.head] = '0';
                    TM.status = 0;
                }
                break;
        }
    }

    printf("Result: \n");
    print(&TM);

    return 0;
}