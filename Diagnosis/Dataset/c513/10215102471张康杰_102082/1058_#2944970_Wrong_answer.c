#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int flag1 = 0,flag2 = 0,flag3 = 0;
    while((ch = getchar()) != EOF)
    {
        switch(ch)
        {
            case '/':
                if((ch = getchar()) == '/' && !flag3)
                    flag1 = 1;
                else if((ch = getchar()) == '*' && !flag3)
                    flag2 = 1;
                else
                {
                    putchar('/');
                    putchar(ch);
                }  
                break;
            case '"':
                if(!flag1 && !flag2)
                {
                    if(flag3)
                    {
                        flag3 = 0;
                        putchar('"');

                    }
                    else
                    {
                        flag3 = 1;
                        putchar('"');
                    }
                }
                break;
            case '\n':
                flag1 = 0;
                flag3 = 0;
                putchar('\n');
                break;
            case '*':
                if((ch = getchar()) == '/')
                    flag2 = 0;
                else if(!flag1 && !flag2)
                {
                    putchar('*');
                    putchar(ch);
                }
                break;
            default:
                if(!flag1 && !flag2)
                    putchar(ch);
                else
                    continue;
            
        }

    }
}