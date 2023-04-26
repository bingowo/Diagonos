#include <stdio.h>

int main()
{
    char c;
    int state = 0;
    while ((c = getchar()) != EOF)
    {
        switch (state)
        {
        case 0:
            if (c == '/')
                state = 1;
            else if (c == '\'')
                state = 5;
            else if (c == '\"')
                state = 7;
            else
            {
                putchar(c);
            }
            break;
        case 1:
            if (c == '/')
                state = 2;
            else if (c == '*')
                state = 3;
            else
            {
                putchar('/');
                putchar(c);
                state = 0;
            }
            break;
        case 2:
            if (c == '\n')
            {
                putchar(c);
                state = 0;
            }
            break;
        case 3:
            if (c == '*')
                state = 4;
            else
                state = 3;
            break;
        case 4:
            if (c == '/')
                state = 0;
            else if (c == '*')
                state = 4;
            else
                state = 3;
            break;
        case 5:
            if (c == '\\')
                state = 6;
            else if (c == '\'')
            {
                putchar(c);
                state = 0;
            }
            break;
        case 6:
            state = 5;
            break;
        case 7:
            if (c == '\\')
                state = 8;
            else if (c == '\"')
            {
                putchar(c);
                state = 0;
            }
            break;
        case 8:
            state = 7;
            break;
        }
        if (state == 5 || state == 6 || state == 7 || state == 8)
        {
            putchar(c);
        }
    }
    return 0;
}