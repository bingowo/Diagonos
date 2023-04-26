#include <stdio.h>

#define OUT 0
#define IBC 1 //In block comment
#define ILC 2 //In line comment
#define IS 3 //In string
#define IC 4 //In character
#define ISCO 5 //In string can't out
#define ICCO 6 //In character can't out
#define MIBCOILC 7 //Maybe in block comment or in line comment
#define MOBC 8 //Maybe out block comment

int main()
{
    short state = OUT;
    short cntbackslash = 0, followbackslash = 0;
    char c = 0;
    while ((c=getchar())!= EOF)
    {
        switch (state)
        {
        case OUT:
            switch (c)
            {
            case '"':
                state = IS;
                printf("%c", c);
                break;
            case '\'':
                state = IC;
                printf("%c", c);
                break;
            case '/':
                state = MIBCOILC;
                break;
            default:
                printf("%c", c);
                break;
            }
            break;
        case IS:
            if (c== '\\')
                state = ISCO;
            else if (c== '"')
                state = OUT;
            printf("%c", c);
            break;
        case ISCO:
            state = IS;
            printf("%c", c);
            break;
        case IC:
            if (c== '\\')
                state = ICCO;
            else if (c== '\'')
                state = OUT;
            printf("%c", c);
            break;
        case ICCO:
            state = IC;
            printf("%c", c);
            break;
        case MIBCOILC:
            if (c== '/')
            {
                state = ILC;
            }
            else if (c== '*')
            {
                state = IBC;
            }
            else
            {
                state = OUT;
                printf("%c", '/');
                printf("%c", c);
            }
            break;
        case ILC:
            if (c== '\n')
            {
                printf("%c", c);
                state = OUT;
            }
            break;
        case IBC:
            if (c== '*')
                state = MOBC;
            break;
        case MOBC:
            if (c== '/')
                state = OUT;
            else if (c!= '*')
                state = IBC;
            break;
        default:
            printf("wrong state");
            break;
        }
    }
    return 0;
}
