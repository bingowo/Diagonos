#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int state;
    char ch,preCh;
    state=0;
    while((ch=getchar())!=EOF)
    {
        switch(state)
        {
        case(0):
            if(ch=='/')    state=1;
            else if(ch=='\''||ch=='\"')
            {
                state=6;
                preCh=ch;
            }
            else    putchar(ch);
            break;
        case(1):
            if(ch=='/')     state=2;
            else if(ch=='*')    state=4;
            else
            {
                state=0;
                putchar('/');
                putchar(ch);
            }
            break;
        case(2):
            if(ch=='\n')
            {
                putchar(ch);
                state=0;
            }
            else if(ch=='\\')
            {
                state=3;
            }
            break;
        case(3):
            if(ch=='\\');
            else if(ch=='\n')
            {
                putchar(ch);
                state=2;
            }
            else
            {
                state=2;
            }
            break;
        case(4):
            if(ch=='*') state=5;
            break;
        case(5):
            if(ch=='/') state=0;
            else if(ch=='*') state=5;
            else state=4;
            break;
        case(6):
            if(ch=='\\')
            {
                putchar(ch);
                state=7;
            }
            else if(ch==preCh)
                state=0;
            break;
        case(7):
            putchar(ch);
            state=6;
            break;
        }
    }
    return 0;
}

