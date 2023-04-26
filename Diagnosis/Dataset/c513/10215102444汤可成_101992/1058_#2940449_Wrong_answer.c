#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type = 0;
    int in_str = 0;
    int in_comd = 0;
    char c1 = 0;
    char c2 = 0;
    while((c1 = getchar()) != EOF)
    {
        if(in_str == 0 &&in_comd == 0)
        {
            if(c1 == '/')
            {
                c2 = getchar();
                if(c2 == '/')
                {
                    in_comd = 1;
                    type = 1;
                }
                else if(c2 == '*')
                {
                    in_comd = 1;
                    type = 2;
                }
                else
                {
                    printf("%c%c", c1, c2);
                }
            }
            else if(c1 == '"')
            {
                c2 = getchar();
                if(c2 == '"') in_str = 1;
                printf("%c%c", c1, c2);
            }
            else if(c1 == '/')
            {
                c2 = getchar();
                printf("%c%c", c1, c2);
            }
            else
                printf("%c", c1);
        }
        else if(in_comd)
        {
            if(type == 1)
            {
                if(c1 == '\n')
                {
                    printf("%c", c1);
                    type = 0;
                    in_comd = 0;
                }
            }
            else if(type == 2)
            {
                if(c1 == '\\')
                {
                    c2 = getchar();
                }
                else if(c1 == '*')
                {
                    c2 = getchar();
                    if(c2 == '*')
                    {
                        c2 =getchar();
                    }
                    while(c2 == '*')
                    {
                        c2 = getchar();
                    }
                    if(c2 == '/')
                    {
                        in_comd = 0;
                        type = 0;
                    }
                }
            }
        }
        else if(in_str)
        {
            if(c1 == '\\')
            {
                c2 = getchar();
                printf("%c%c", c1, c2);
            }
            else if(c1 == '"')
            {
                in_str = 0;
                printf("%c", c1);
            }
        }
    }
    return 0;
}
