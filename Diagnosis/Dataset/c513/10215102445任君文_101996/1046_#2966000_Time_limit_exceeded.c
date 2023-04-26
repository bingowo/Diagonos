#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    int T;
    int i, j, k;
    int n = 0;
    char c;
    char s;
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        scanf("%s", &s);
        s = tolower(s);
        n = 0;
        while ((c = getchar()) != '\n')
        {
            if (strcmp(&s, "the") == 0)
            {
                ;
            }
            else if (strcmp(&s, "a") == 0)
            {
                ;
            }
            else if (strcmp(&s, "an") == 0)
            {
                ;
            }
            else if (strcmp(&s, "of") == 0)
            {
                ;
            }
            else if (strcmp(&s, "and") == 0)
            {
                ;
            }
            else if (strcmp(&s, "for") == 0)
            {
                ;
            }
            else
            {
                n++;
            }
            scanf("%s", &s);
            s = tolower(s);
        }
        if (strcmp(&s, "the") == 0)
        {
            ;
        }
        else if (strcmp(&s, "a") == 0)
        {
            ;
        }
        else if (strcmp(&s, "an") == 0)
        {
            ;
        }
        else if (strcmp(&s, "of") == 0)
        {
            ;
        }
        else if (strcmp(&s, "and") == 0)
        {
            ;
        }
        else if (strcmp(&s, "for") == 0)
        {
            ;
        }
        else
        {
            n++;
        }
        printf("case #%d:\n", i);
        printf("%d\n", n);
    }
    return 0;
}