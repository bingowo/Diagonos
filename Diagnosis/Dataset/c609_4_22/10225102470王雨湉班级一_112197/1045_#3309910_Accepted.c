#include <stdio.h>

int main()
{
    int state=0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(state==0)
        {
            if(ch=='/')
                state=1;
            else if(ch=='"')
            {
                state=5;
                printf("%c",ch);
            }
            else if(ch=='\'')
            {
                state=7;
                printf("%c",ch);
            }
            else
                printf("%c",ch);
        }
        else if(state==1)
        {
            if(ch=='*')
                state=2;
            else if(ch=='/')
                state=4;
            else
            {
                state=0;
                printf("/%c",ch);
            }
        }
        else if(state==2)
        {
            if(ch=='*')
                state=3;
            else
                state=2;
        }
        else if(state==3)
        {
            if(ch=='*')
                state=3;
            else if(ch=='/')
                state=0;
            else
                state=2;
        }
        else if(state==4)
        {
            if(ch=='\n')
            {
                state=0;
                printf("%c",ch);
            }
            else
                state=4;
        }
        else if(state==5)
        {
            if(ch=='\\')
                state=6;
            else if(ch=='"')
                state=0;
            else
                state=5;
            printf("%c",ch);
        }
        else if(state==6)
        {
            state=5;
            printf("%c",ch);
        }
        else if(state==7)
        {
            if(ch=='\\')
                state=8;
            else if(ch=='\'')
                state=0;
            else
                state=7;
            printf("%c",ch);
        }
        else if(state==8)
        {
            state=7;
            printf("%c",ch);
        }
    }
    return 0;
}