#include <stdio.h>

int
main()
{
    int state = 0;
    char c;
    
    while (c=getchar(),c!=EOF)
    {
        switch (state)
        {
            case (0):
                if (c == '/')
                {
                    state = 1;
                }
                else if (c == '"')
                {
                    state = 7;
                    printf("%c",c);
                }
                else if (c == '\\')
                {
                    printf("%c",c);
                    state = 4;
                }
                else
                {
                    printf("%c",c);
                }
                break;
            case (1):
                if (c == '*')
                {
                    state = 2;
                }
                else if (c == '/')
                {
                    state = 5;
                }
                else
                {
                    printf("/");
                    printf("%c",c);
                    state = 0;
                }
                break;
            case (2):
                if (c == '*')
                {
                    state = 3;
                }
                else
                {
                    state = 2;
                }
                break;
            case (3):
                if (c == '*')
                {
                    state = 3;
                }
                else if (c == '/')
                {
                    state = 0;
                }
                else
                {
                    state = 2;
                }
                break;
            case (4):
                printf("%c",c);
                state = 0;
                break;
            case (5):
                if (c == '\n')
                {
                    printf("\n");
                    state = 0;
                }
                else
                {
                    state = 5;
                }
                break;
            case (7):
                if (c == '"')
                {
                    state = 0;
                    printf("%c",c);
                }
                else if (c == '\\')
                {
                    state = 8;
                    printf("%c",c);
                }
                else
                {
                    state = 7;
                    printf("%c",c);
                }
                break;
            case (8):
                printf("%c",c);
                state = 7;
        }
    }
    
    return 0;
}