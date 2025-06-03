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
    memset(TM->tape, 'D', N);
    TM->status = 1;
    TM->head = start+1;
    int index = start;
    char sym = 0;
    printf("input numb (D1^xD) \n> ");
    while (sym != '\n') {
        sym = getchar();
        if (sym == '\n') {
            break;
        }
        TM->tape[index++] = sym;
    }

}

void print(Tmashine *TM) {
    for (int i = 10; i > 0; i-- ) {
        printf("%c", TM->tape[start-i]);
    }
    for (int i = 0; i < 10; i++ ) {
        printf("%c", TM->tape[start+i]);
    }

    printf(" - state: %d  (%c)\n", TM->status, TM->tape[TM->head]);
    // printf("\n");
}


int main() {
    Tmashine TM;
    char current;
    initTM(&TM);

    while (TM.status != 0) {
        print(&TM);
        current = TM.tape[TM.head];

        switch (TM.status) {
            case 1: 
                if (current == 'D') {
                    TM.status = 0;
                } else if (current = '1') {
                    TM.head++;
                    TM.status = 2;
                }
                break;
            case 2:
                if (current == 'D') {
                    TM.status = 4;
                    TM.head--;
                } else if (current == '1') {
                    TM.status = 3;
                    TM.head++;
                }
                break;
            case 3:
                if (current == 'D') {
                    TM.status = 5;
                    TM.head--;
                } else if (current == '1') {
                    TM.status = 2;
                    TM.head++;
                }
                break;
            case 4:
                if (current == 'D') {
                    TM.status = 6;
                    TM.head++;
                } else if (current == '1') {
                    TM.tape[TM.head] = 'D';
                    TM.status = 4;
                    TM.head--;
                }
                break;
            case 5:
                if (current == 'D') {
                    TM.status = 0;
                    TM.head++;
                } else if (current == '1') {
                    TM.tape[TM.head] = 'D';
                    TM.head--;
                }
                break;
            case 6:
                if (current == 'D') {
                    TM.tape[TM.head] = '1';
                    TM.status = 0;
                }
                break;
            case 0:
                break;

        }
    }
    printf("Result:\n");
    print(&TM);
    return 0;
}