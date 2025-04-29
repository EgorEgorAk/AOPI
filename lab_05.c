#include <stdio.h>


enum State { BEFORE, INSIDE, AFTER };

int main() 
{
    int c;
    enum State state = BEFORE; 

    printf("Enter string:\n");
    printf("Exit: <Ctrl>+<D> for Linux/Unix, <Ctrl>+<Z> for Windows\n");

    while ((c = getchar()) != EOF) 
    {
        switch (state) 
        {
            case BEFORE:
                if (c == ' ') {
                } 
                else if (c == '\n') {
                    putchar('\n');
                } 
                else {
                    putchar(c);
                    state = INSIDE;
                }
                break;

            case INSIDE:
                if (c == ' ') {
                    state = AFTER;
                } 
                else if (c == '\n') {
                    putchar('\n');
                    state = BEFORE;
                } 
                else {
                    putchar(c);
                }
                break;

            case AFTER:
                if (c == '\n') {
                    putchar('\n');
                    state = BEFORE;
                }
                break;
        }
    }

    return 0;
}