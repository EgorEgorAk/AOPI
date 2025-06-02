#include <stdio.h>

int main() 
{
    enum states { before, inside, after } state = before;
    int c;

    while ((c = getchar()) != EOF) 
    {
        switch (state) 
        {
            case before:
                if (c == ' ') 
                {
                    // игнорируем пробелы
                }
                else if (c == '\n') 
                {
                    putchar('\n');  // пустая строка — просто перевод строки
                }
                else 
                {
                    putchar(c);    // первый символ слова
                    state = inside;
                }
                break;

            case inside:
                if (c == ' ') 
                {
                    // конец первого слова
                    state = after;
                }
                else if (c == '\n') 
                {
                    putchar('\n');
                    state = before;
                }
                else 
                {
                    putchar(c);
                }
                break;

            case after:
                if (c == '\n') 
                {
                    putchar('\n');
                    state = before;
                }
                // остальные символы игнорируем
                break;
        }
    }

    return 0;
}